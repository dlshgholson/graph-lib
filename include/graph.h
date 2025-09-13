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

#include <memory>
#include <set>

namespace graphlib {

class Graph {
public:
    Graph() {
    }

    void addNode(graphlib::node_t *node) {
        // TODO.
    }

    void addNode(std::shared_ptr<graphlib::Node> node) {
        // TODO.
    }

    void addEdge(graphlib::Node *node1, graphlib::Node *node2) {
        // TODO.
    }

    void addEdge(std::shared_ptr<graphlib::Node> node1, std::shared_ptr<graphlib::Node> node2) {
        // TODO.
    }

protected:
    std::set<std::shared_ptr<graphlib::node_t>> nodes;
    std::set<std::shared_ptr<graphlib::edge_t>> edges;
};

}  // namespace graphlib

#endif  // GRAPH_H
