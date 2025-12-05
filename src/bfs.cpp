/*
 * bfs.cpp - Definitions for BFS.
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

#include "bfs.h"

#include <algorithm> // std::fill
#include <stack>

namespace graphlib {

BFS::BFS(const Graph &_g, node_id _start, bool strong) :
    g{&_g}, start{_start}, strongTraversal{strong} {
    parents.resize(_g.getNumNodes());
    queue.push(start);
}

/*
 * Resets the internal state to perform BFS from the start again.
 */
void BFS::reset(void) {
    queue = std::queue<node_id>();
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
node_id BFS::next(void) {
    if (queue.empty()) {
        return INVALID_NODE;
    }

    node_id current = queue.front();
    queue.pop();
    visited.insert(current);

    for (node_id node : g->getChildren(current)) {
        if (!visited.contains(node)) {
            parents.at(node) = current;
            queue.push(node);
        }
    }

    if (!strongTraversal) {
        for (node_id node : g->getParents(current)) {
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
const std::set<node_id> BFS::getVisited(void) const {
    return visited;
}

/*
 * Given a visited node, returns the path from the start node to it.
 * If the node has not been visited, returns an empty vector.
 */
std::vector<node_id> BFS::getPath(node_id node) {
    if (!visited.contains(node)) {
        return std::vector<node_id>();
    }

    // Use stack to grow the path quickly, then assign to vector in
    // reverse order.
    std::stack<node_id> stack;
    stack.push(node);
    node_id current = node;
    while (current != start) {
        current = parents.at(current);
        stack.push(current);
    }

    std::vector<node_id> path(stack.size());
    for (int i = stack.size() - 1; i >= 0; i--) {
        path.at(i) = stack.top();
        stack.pop();
    }

    return path;
}

}  // namespace graphlib
