/*
 * bfs.h - Breadth-first search structure.
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

#ifndef BFS_H
#define BFS_H

#include "graph.h"
#include "types.h"

#include <algorithm> // std::fill
#include <queue>
#include <set>
#include <stack>
#include <vector>

namespace graphlib {

class BFS {
public:
    BFS(Graph *ptr, id_t start, bool strong) :
        g{ptr}, strongTraversal{strong} {
        queue.push(start);
    }

    /*
     * Resets the internal state to perform BFS from the start again.
     */
    void reset(void) {
        queue = std::queue<id_t>();
        queue.push(start);

        visited.clear();

        std::fill(parents.begin(), parents.end(), INVALID_NODE);
        parents.at(start) = start;
    }

    /*
     * On the first call, returns the start. On subsequent calls, returns a
     * new node not visited previously. After all nodes have been visited
     * returns INVALID_NODE.
     */
    id_T next(void) {
        if (queue.empty()) {
            return INVALID_NODE;
        }

        id_t current = queue.pop();
        visited.insert(current);

        for (id_t node : g->getChildren(current)) {
            if (!visited.contains(node)) {
                parents.at(node) = current;
                queue.push(node);
            }
        }

        if (!strongTraversal) {
            for (id_t node : g->getParents(current)) {
                if (!visited.contains(node)) {
                    parents.at(node) = current;
                    queue.push(node);
                }
            }
        }

        return current;
    }

    /*
     * Returns the nodes that were visited so far.
     */
    const std::set<id_t> getVisited(void) const {
        return visited;
    }

    /*
     * Given a visited node, returns the path from the start node to it.
     * If the node has not been visited, returns an empty vector.
     */
    std::vector<id_t> getPath(id_t node) {
        if (!visited.contains(node)) {
            return std::vector<id_t>();
        }

        // Use stack to grow the path quickly, then assign to vector in
        // reverse order.
        std::stack<id_t> stack(node);
        id_t current = node;
        while (current != start) {
            current = parents.at(current);
            stack.push(current);
        }

        std::vector<id_t> path(stack.size());
        for (int i = stack.size() - 1; i >= 0; i--) {
            path.at(i) = stack.pop();
        }

        return path;
    }

protected:
    const Graph *g;

    std::queue<id_t> queue;
    std::set<id_t> visited;

    // Stores the visitor parent node of each visited node. This is used to
    // trace a visited node back to the start node.
    std::vector<id_t> parents;

    const bool strongTraversal; // If false, we can travel against directed edges.
};

}  // namespace graphlib

#endif  // BFS_H
