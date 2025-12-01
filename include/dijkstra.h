/*
 * dijkstra.h - Class implementing Dijkstra's shortest path.
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

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "edge_weights.h"
#include "graph.h"
#include "types.h"

#include <limits>
#include <set>
#include <vector>

#define FLOAT_MAX std::numeric_limits<float>::max()

namespace graphlib {

class Dijkstra {
public:
    Dijkstra(Graph *ptr, const EdgeWeights<float> _weights, id_t _start) :
            g{ptr}, weights{_weights}, start{_start} {
        unvisited.push(start);
        distances = std::vector(g->getNumNodes(), FLOAT_MAX);
        distances.at(start) = 0;
    }

    /*
     * Builds the cache of shortest paths from start node to every other node.
     */
    void build() {
        id_t current = getMinCostUnvisited();
        while (current != INVALID_NODE) {
            for (id_t node : g->getChildren(current)) {
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
    Path getMinCostPath(id_t node) {
        Path path(node);
        id_t current = node;

        while (current != start) {
            current = parents.at(current);
            path.insert(0, current);
        }

        return path;
    }

    /*
     * Returns the distance (cost) between start and node.
     */
    float getDistance(id_t node) {
        float total = 0;
        id_t current = node;

        while (current != start) {
            id_t parent = parents.at(current);

            total += weights.getWeight(parent, current);
            current = parent;
        }

        return total;
    }

private:
    /*
     * Attempts to find the closest unvisited node. If the unvisited set is
     * either empty or all distances are FLOAT_MAX, returns INVALID_NODE.
     */
    id_t getMinCostUnvisited() {
        if (unvisited.size() == 0) {
            return INVALID_NODE;
        }

        id_t candidate = *unvisited.begin();
        for (id_t node : unvisited) {
            if (distances.at(node) < distances.at(candidate)) {
                candidate = node;
            }
        }

        if (candidate < FLOAT_MAX) {
            return candidate;
        }

        return INVALID_NODE;
    }

protected:
    const Graph *g;
    const EdgeWeights<float> weights;
    std::set<id_t> unvisited, visited;
    std::vector<float> distances;
    std::vector<id_t> parents;
    const id_t start;
};

}  // namespace graphlib

#endif  // DIJKSTRA_H
