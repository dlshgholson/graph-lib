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

#include <vector> // std::erase_if()

void graphlib::Graph::removeNode(graphlib::id_t nodeId) {
    // ID out of bounds.
    if (nodeId < 0 || nodeId >= getNumNodes()) {
        return;
    }

    // Remove node in question and decrement counter.
    // Erase incident edges.
    // Shift back ID of succeeding nodes.

    nodes.erase(nodes.begin() + nodeId);
    nodeCounter--;

    // C++20 and up.
    std::erase_if(edges, [&](graphlib::Edge edge) {
            return (edge.getFirst() == nodeId) || (edge.getLast() == nodeId);
            });

    for (auto &node : nodes) {
        if (node.id > nodeId) {
            node.id--;
        }
    }
}

bool graphlib::Graph::operator==(const graphlib::Graph other) const {
    // std containers have == overload, but evaluation order suggests the
    // entire node containers could be checked before simply comparing the
    // sizes of edge containers. So we manually do that first.
    if (getNumNodes() != other.getNumNodes() ||
            getNumEdges() != other.getNumEdges()) {
        return false;
    }

    return (nodes == other.nodes) && (edges == other.edges);
}

bool graphlib::Graph::isEquivalentTo(const graphlib::Graph &other) const {
    // TODO.
    return false;
}


bool graphlib::Graph::isStronglyConnected() const {
    // TODO.
    return false;
}

bool graphlib::Graph::isWeaklyConnected() const {
    // TODO.
    return false;
}

