/*
 * default_graph.h - Quick and dirty implementation for Graph.
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

#ifndef DEFAULT_GRAPH_H
#define DEFAULT_GRAPH_H

#include "graph.h"
#include "types.h"

namespace graphlib {

class DefaultGraph : public Graph {
public:
    DefaultGraph(std::vector<std::vector<node_id>> _adjList) {
        // Verify validity.
        size_t numNodes = _adjList.size();
        for (auto &list : _adjList) {
            for (node_id entry : list) {
                if (entry >= numNodes) {
                    // Invalid entry.
                    // TODO.
                }
            }
        }

        // Copy argument.
        adjList = _adjList;
    }

    size_t getNumNodes(void) const override {
        return adjList.size();
    }

    size_t getNumEdges(void) const override {
        size_t total = 0;
        for (auto list : adjList) {
            total += list.size();
        }

        return total;
    }

    /*
     * Checks if an edge between first and last exists.
     */
    bool edgeExists(node_id first, node_id last) const override {
        auto list = adjList.at(first);

        for (node_id node : list) {
            if (node == last) {
                return true;
            }
        }

        return false;
    }

    std::vector<std::pair<node_id, node_id>> getEdges(void) const override {
        std::vector<std::pair<node_id, node_id>> edges;

        for (node_id i = 0; i < adjList.size(); i++) {
            for (node_id j : adjList.at(i)) {
                edges.push_back(std::pair<node_id, node_id>(i, j));
            }
        }

        return edges;
    }

    std::vector<node_id> getChildren(node_id node) const override {
        return adjList.at(node);
    }

    std::vector<node_id> getParents(node_id node) const override {
        std::vector<node_id> parents;

        for (node_id i = 0; i < adjList.size(); i++) {
            for (node_id n : adjList.at(i)) {
                if (n == node) {
                    parents.push_back(i);
                    break;
                }
            }
        }

        return parents;
    }

private:
    // adjList[i] holds the children of the i'th node.
    std::vector<std::vector<node_id>> adjList;
};

}  // namespace graphlib

#endif  // DEFAULT_GRAPH_H
