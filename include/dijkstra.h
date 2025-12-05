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

#include <set>
#include <vector>

namespace graphlib {

class Dijkstra {
public:
    Dijkstra(Graph *ptr, const EdgeWeights<float> _weights, node_id _start);

    /*
     * Builds the cache of shortest paths from start node to every other node.
     */
    void build();

    /*
     * Attempts to find a min-cost path between first and last using Dijkstra's.
     * If no path exists returns an empty path.
     */
    Path getMinCostPath(node_id node);

    /*
     * Returns the distance (cost) between start and node.
     */
    float getDistance(node_id node);

private:
    /*
     * Attempts to find the closest unvisited node. If the unvisited set is
     * either empty or all distances are FLOAT_MAX, returns INVALID_NODE.
     */
    node_id getMinCostUnvisited();

protected:
    const Graph *g;
    const EdgeWeights<float> weights;
    std::set<node_id> unvisited, visited;
    std::vector<float> distances;
    std::vector<node_id> parents;
    const node_id start;
};

}  // namespace graphlib

#endif  // DIJKSTRA_H
