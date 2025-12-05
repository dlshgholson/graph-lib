/*
 * topological_sort.cpp - Definition for the topologicalSort function.
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

#include <vector>
#include <set>

#include <iostream>

namespace graphlib {

/*
 * Performs a recursive visit to child nodes. Returns true if a cycle was found,
 * false otherwise.
 */
bool visit(const Graph &g, node_id node, std::vector<node_id> &ordering,
           std::set<node_id> &checked, std::set<node_id> &unvisited) {
    if (checked.contains(node)) {
        return false;
    }
    if (!unvisited.contains(node)) {
        return true;
    }

    unvisited.erase(node);

    for (node_id child : g.getChildren(node)) {
        if (visit(g, child, ordering, checked, unvisited)) {
            return true;
        }
    }

    checked.insert(node);
    ordering.insert(ordering.begin(), node);

    return false;
}

/*
 * Basic DFS algorithm to generate topological sort. If the graph contains a
 * cycle then an empty vector is returned.
 */
std::vector<node_id> topologicalSort(const Graph &g) {
    std::vector<node_id> ordering;
    std::set<node_id> checked, unvisited;

    for (node_id i = 0; i < g.getNumNodes(); i++) {
        unvisited.insert(i);
    }

    while (unvisited.size() != 0) {
        node_id node = *(unvisited.begin());
        bool foundCycle = visit(g, node, ordering, checked, unvisited);

        if (foundCycle) {
            return std::vector<node_id>();
        }
    }

    return ordering;
}

}  // namespace graphlib
