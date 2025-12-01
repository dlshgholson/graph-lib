/*
 * equivalent.cpp - Definition for the equivalent function.
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
 * Checks for loose graph equivalence that is independent of node
 * permutation.
 */
bool isEquivalent(const Graph &g1, const Graph &g2) {
    // More formally, we can reframe this to another question:
    // "Does there exist a bijection on the node and edge ID's that
    // makes this graph equal to the other?"
    //
    // Note that transforming the ID of a node should also update the ID
    // within any incident edges as well.
    //
    // I BELIEVE that the solution is to check if there are the same number
    // of nodes of each degree.

    if (g1.getNumNodes() != g2.getNumNodes()) {
        return false;
    }
    if (g1.getNumEdges() != g2.getNumEdges()) {
        return false;
    }

    // TODO.

    return true;
}

}  // namespace graphlib
