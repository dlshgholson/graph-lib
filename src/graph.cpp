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

#include "graph.h"

#include <vector>

namespace graphlib {

/*
 * Does nothing if nodeId is not found.
 */
void Graph::removeNode(id_t nodeId) {
    // ID out of bounds.
    if (!nodes.contains(nodeId)) {
        return;
    }

    // Erase node and incident edges. We intentionally do not shift ID's to
    // maintain stability for external structures.

    nodes.erase(nodeId);

    for (id_t id : edges.getKeys()) {
        const Edge edge = edges.get(id);

        if (edge.getFirst() == nodeId ||
                edge.getLast() == nodeId) {
            edges.erase(id);
        }
    }
}

/*
 * Strict equivalence, matching the ID of every edge and node.
 */
bool Graph::operator==(const Graph other) const {
    if (getNumNodes() != other.getNumNodes() ||
            getNumEdges() != other.getNumEdges()) {
        return false;
    }

    return (nodes == other.nodes) && (edges == other.edges);
}

std::ostream &Graph::print(std::ostream &os) const {
    os << "\n\n";
    os << "====================\n";
    os << "Number of nodes: " << getNumNodes() << ".\n";
    os << "Number of edges: " << getNumEdges() << ".\n";

    os << "\n";

    for (auto &pair : nodes.getPairs()) {
        id_t id = pair.first;

        os << "Node ID: " << id << ".\n";
    }

    os << "\n";

    for (auto &pair : edges.getPairs()) {
        id_t id = pair.first;
        const Edge edge = pair.second;

        os << "Edge ID, first, last: ";
        os << id << ", " << edge.getFirst() << ", " << edge.getLast() << ".\n";
    }

    os << "====================\n";
    os << std::endl;

    return os;
}

/*
 * Checks for more loose graph equivalence that is independent of node
 * and edge ID's.
 */
bool Graph::isEquivalentTo(const Graph &other) const {
    // More formally, we can reframe this to another question:
    // "Does there exist a bijection on the node and edge ID's that
    // makes this graph equal to the other?"
    //
    // Note that transforming the ID of a node should also update the ID
    // within any incident edges as well.
    //
    // I BELIEVE that the solution is to check if there are the same number
    // of nodes of each degree.

    // TODO.

    if (getNumNodes() != other.getNumNodes()) {
        return false;
    }
    if (getNumEdges() != other.getNumEdges()) {
        return false;
    }

    return true;
}

// For printing.
std::ostream &operator<<(std::ostream &os, const Graph &graph) {
    return graph.print(os);
}

}  // namespace graphlib
