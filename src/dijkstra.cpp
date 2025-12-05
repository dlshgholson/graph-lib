/*
 * dijkstra.cpp - Definitions for Dijkstra.
 *
 * Copyright (C) 2025 Daniel Gholson
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "dijkstra.h"

#include <limits>

#define FLOAT_MAX std::numeric_limits<float>::max()

namespace graphlib {

Dijkstra::Dijkstra(Graph *ptr, const EdgeWeights<float> _weights, node_id _start) :
        g{ptr}, weights{_weights}, start{_start} {
    unvisited.insert(start);
    distances = std::vector(g->getNumNodes(), FLOAT_MAX);
    distances.at(start) = 0;
}

/*
 * Builds the cache of shortest paths from start node to every other node.
 */
void Dijkstra::build() {
    node_id current = getMinCostUnvisited();
    while (current != INVALID_NODE) {
        for (node_id node : g->getChildren(current)) {
            float newDistance = distances.at(current) +
                                weights.getWeight(current, node);

            if (newDistance < distances.at(node)) {
                distances.at(node) = newDistance;
                parents.at(node) = current;
            }

            if (!unvisited.contains(node) && !visited.contains(node)) {
                unvisited.insert(node);
            }
        }
    }
}

/*
 * Attempts to find a min-cost path between first and last using Dijkstra's.
 * If no path exists returns an empty path.
 */
Path Dijkstra::getMinCostPath(node_id node) {
    Path path(node);
    node_id current = node;

    while (current != start) {
        current = parents.at(current);
        path.insert(path.begin(), current);
    }

    return path;
}

/*
 * Returns the distance (cost) between start and node.
 */
float Dijkstra::getDistance(node_id node) {
    float total = 0;
    node_id current = node;

    while (current != start) {
        node_id parent = parents.at(current);

        total += weights.getWeight(parent, current);
        current = parent;
    }

    return total;
}

/*
 * Attempts to find the closest unvisited node. If the unvisited set is
 * either empty or all distances are FLOAT_MAX, returns INVALID_NODE.
 */
node_id Dijkstra::getMinCostUnvisited() {
    if (unvisited.size() == 0) {
        return INVALID_NODE;
    }

    node_id candidate = *unvisited.begin();
    for (node_id node : unvisited) {
        if (distances.at(node) < distances.at(candidate)) {
            candidate = node;
        }
    }

    if (candidate < FLOAT_MAX) {
        return candidate;
    }

    return INVALID_NODE;
}


}  // namespace graphlib
