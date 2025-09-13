/*
 * edge.h - Defines the base edge class.
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

#ifndef EDGE_H
#define EDGE_H

#include "types.h"

#include <pair>

namespace graphlib {

class Edge {
public:
    Edge(graphlib::id_t first_node_id, graphlib::id_t last_node_id) {
        pair = std::pair<graphlib::id_t, graphlib::id_t>(first_node_id, last_node_id);
    }

    graphlib::id_t getId() {
        return id;
    }

protected:
    // Holds a pair of Node ID's. As a result the edge is graph dependent.
    std::pair<graphlib::id_t, graphlib::id_t> pair;

    // Unique Edge ID within the graph.
    graphlib::id_t id;
};

}  // namespace graphlib

#endif  // EDGE_H
