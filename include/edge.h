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

namespace graphlib {

class Edge {
public:
    Edge() {
    }

protected:
    std::pair<graphlib::node_t, graphlib::node_t> nodesPair;
};

}  // namespace graphlib

#endif  // EDGE_H
