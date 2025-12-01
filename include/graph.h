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

#include "types.h"

#include <iostream>

namespace graphlib {

class Graph {
public:
    virtual size_t getNumNodes(void) const = 0;
    virtual size_t getNumEdges(void) const = 0;

    /*
     * Checks if an edge between first and last exists.
     */
    virtual bool edgeExists(id_t first, id_t last) const = 0;
    virtual std::vector<std::pair<id_t, id_t>> getEdges(void) const = 0;

    virtual std::vector<id_t> getChildren(id_t node) const = 0;
    virtual std::vector<id_t> getParents(id_t node) const = 0;

    std::ostream &print(std::ostream &os) const;
};

// For printing.
std::ostream &operator<<(std::ostream &os, const Graph &graph);

}  // namespace graphlib

#endif  // GRAPH_H
