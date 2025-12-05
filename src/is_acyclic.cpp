/*
 * is_acyclic.cpp - Definition for the isAcyclic function. Despite being very
 * short, the definition needs to be in a .cpp file to avoid multiple
 * definition linker errors. Although "algos.h" uses header guards, it is
 * included in both definition files and test files, which are compiled
 * separately.
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

#include "algos.h"

namespace graphlib {

/*
 * Returns whether the graph is acyclic or not.
 */
bool isAcyclic(const Graph &g) {
    return (topologicalSort(g).size() != 0);
}

}  // namespace graphlib
