/*
 * algos.h - Declares common algorithms that don't depend on structure.
 * Algorithms that rely on additional structure will be put in other files.
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

#ifndef ALGOS_H
#define ALGOS_H

#include "graph.h"

namespace graphlib {

/*
 * Checks for loose graph equivalence that is independent of node
 * permutation.
 */
bool isEquivalent(const Graph &g1, const Graph &g2);

bool isStronglyConnected(const Graph &g);

bool isWeaklyConnected(const Graph &g);

/*
 * Attempts to find a path between first and last using BFS. If no path exists
 * returns an empty path.
 */
Path findPath(const Graph &g, id_t first, id_t last);

bool isAcyclic(const Graph &g);

std::vector<id_t> topologicalSort(const Graph &g);

}  // namespace graphlib

#endif  // ALGOS_H
