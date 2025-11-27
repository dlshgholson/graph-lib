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

#include "edge.h"
#include "map.h"
#include "node.h"
#include "types.h"

#include <memory>
#include <iostream>

namespace graphlib {

class Graph {
public:
    size_t getNumNodes();
    std::vector<id_t> getChildren(id_t node);
    std::vector<id_t> getParents(id_t node);
};

class Graph {
public:
    Graph() {
        nodeCounter = 0;
        edgeCounter = 0;
    }

    Graph(size_t numNodes) {
        nodeCounter = 0;
        edgeCounter = 0;
        addNumNodes(numNodes);
    }

    void addNumNodes(size_t n) {
        for (size_t i = 0; i < n; i++) {
            nodes.set(nodeCounter + i, Node(nodeCounter + i));
        }

        nodeCounter += n;
    }

    void addEdge(id_t firstNodeId, id_t lastNodeId) {
        edges.set(edgeCounter, Edge(firstNodeId, lastNodeId, edgeCounter));
        edgeCounter++;
    }

    size_t getNumNodes() const {
        return nodes.size();
    }

    size_t getNumEdges() const {
        return edges.size();
    }

    /*
     * Does nothing if nodeId is not found.
     */
    void removeNode(id_t nodeId);

    /*
     * Strict equivalence, matching the ID of every edge and node.
     */
    bool operator==(const Graph other) const;

    bool operator!=(const Graph other) const {
        return !(*this == other);
    }

    std::ostream &print(std::ostream &os) const;

    /*
     * Checks for more loose graph equivalence that is independent of node
     * permutation.
     */
    bool isEquivalentTo(const Graph &other) const;

protected:
    Map<id_t, Node> nodes;
    Map<id_t, Edge> edges;

    // Used to assign Node id's.
    id_t nodeCounter;

    // Used to assign Edge id's.
    id_t edgeCounter;
};

// For printing.
std::ostream &operator<<(std::ostream &os, const Graph &graph);

}  // namespace graphlib

#endif  // GRAPH_H
