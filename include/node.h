/*
 * node.h - Defines the base Node class.
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

#ifndef NODE_H
#define NODE_H

#include "types.h"

#include <vector>

namespace graphlib {

// Forward declaration to avoid circular includes.
class Graph;

class Node {
public:
    Node() {
    }

    Node(id_t _id) {
        id = _id;
    }

    id_t getId() const {
        return id;
    }

    const std::vector<Node*> getChildren() const {
        return children;
    }

    const std::vector<Node*> getParents() const {
        return parents;
    }

    bool operator==(Node other) const {
        return id == other.id;
    }

    friend class Graph;

protected:
    // Unique id for node.
    id_t id;
    
    std::vector<Node*> children, parents;
};

}  // namespace graphlib

#endif  // NODE_H
