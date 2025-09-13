/*
 * graph.h - Defines the base graph class.
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

#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include "types.h"

#include <list>
#include <memory>
#include <vector>

namespace graphlib {

class Graph {
public:
    Graph() {
        nodeCounter = 0;
    }

    Graph(size_t numNodes) {
        nodeCounter = 0;
        nodes.resize(numNodes);

        for (size_t i = 0; i < numNodes; i++) {
            nodes[i].id = nodeCounter++;
        }
    }

    void addNumNodes(size_t n) {
        nodes.resize(nodes.size() + n);

        for (size_t i = 0; i < n; i++) {
            nodes[i].id = nodeCounter++;
        }
    }

    void addEdge(graphlib::id_t first_node_id, graphlib::id_t last_node_id) {
        graphlib::Edge tempEdge(first_node_id, last_node_id);
        tempEdge.id = edgeCounter++;

        edges.push_back(tempEdge);
    }

    size_t getNumNodes() {
        return nodes.size();
    }

    size_t getNumEdges() {
        return edges.size();
    }

    /*
     * Checks for graph equivalence. Two different graph objects can be
     * equivalent if they have the same number of nodes, and the relationship
     * between nodes is equivalent (permutation independent).
     */
    bool operator==(const Graph &other);

protected:
    // Used vector since we typically don't add nodes at runtime, and want
    // quick indexing (access by ID).
    std::vector<graphlib::node_t> nodes;

    // Conversely, we use list here because edges are typically added a lot and
    // we don't need fast indexing.
    std::list<graphlib::edge_t> edges;

    // Used to assign Node id's.
    graphlib::id_t nodeCounter;

    // Used to assign Edge id's.
    graphlib::id_t edgeCounter;
};

}  // namespace graphlib

#endif  // GRAPH_H
