/*
 * graph_structure.h - Defines the base GraphStructure class, which allows us
 * to easily extend the structure of a Graph object.
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

#ifndef GRAPH_STRUCTURE_H
#define GRAPH_STRUCTURE_H

#include "graph.h"

namespace graphlib {

/*
 * Interface to extend the structure of a graph. The graph structure cannot
 * exist on its own, and must be "attached" to an existing Graph by the
 * constructor.
 */
class GraphStructure {
public:
    GraphStructure(graphlib::Graph *_graphPtr) {
        assert(_graphPtr != nullptr);
        graphPtr = _graphPtr;
    }

    bool isAttachedTo(graphlib::Graph *_graphPtr) {
        return graphPtr == _graphPtr;
    }

protected:
    // Pointer of attached graph.
    graphlib::Graph *graphPtr;
};

}  // namespace graphlib

#endif  // GRAPH_STRUCTURE_H
