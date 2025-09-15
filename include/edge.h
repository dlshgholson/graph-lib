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

#include <utility> // std::pair<>

namespace graphlib {

// Forward declaration to avoid circular includes.
class Graph;

class Edge {
public:
    Edge(id_t first_node_id, id_t last_node_id) {
        pair = std::pair<id_t, id_t>(first_node_id, last_node_id);
    }

    id_t getId() const {
        return id;
    }

    id_t getFirst() const {
        return pair.first;
    }

    id_t getLast() const {
        return pair.second;
    }

    bool operator==(const Edge other) const {
        return id == other.id;
    }

    friend class Graph;

protected:
    // Holds a pair of Node ID's. As a result the edge is graph dependent.
    std::pair<id_t, id_t> pair;

    // Unique Edge ID within the graph.
    id_t id;
};

}  // namespace graphlib

#endif  // EDGE_H
