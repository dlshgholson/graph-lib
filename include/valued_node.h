/*
 * valued_node.h - Introduces a Node child that can store values.
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

#ifndef VALUED_NODE_H
#define VALUED_NODE_H

namespace graphlib {

template<typename T>
class ValuedNode : public Node, public Valued {
public:
    ValuedNode() {
    }
};

}  // namespace graphlib

#endif  // VALUED_NODE_H
