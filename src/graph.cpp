/*
 * graph.cpp - Definitions for graph.h.
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

// For printing.
std::ostream &operator<<(std::ostream &os, const Graph &graph) {
    return graph.print(os);
}

}  // namespace graphlib
