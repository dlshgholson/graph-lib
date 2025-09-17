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

bool Graph::operator==(const Graph other) const {
    // Map containers have == overload, but evaluation order suggests the
    // entire node containers could be checked before simply comparing the
    // sizes of edge containers. So we manually do that first.
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

bool Graph::isEquivalentTo(const Graph &other) const {
    // TODO.
    return true;
}

// For printing.
std::ostream &operator<<(std::ostream &os, const Graph &graph) {
    return graph.print(os);
}

}  // namespace graphlib
