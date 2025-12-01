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
    DefaultGraph(std::vector<std::vector<id_t>> _adjacencyList) {
        // Verify validity.
        size_t numNodes = _adjacencyList.size();
        for (auto &list : _adjacencyList) {
            for (id_t entry : list) {
                if (entry >= numNodes) {
                    // Invalid entry.
                    // TODO.
                }
            }
        }

        // Copy argument.
        adjacencyList = _adjacencyList;
    }

    size_t getNumNodes(void) const override {
        return adjacencyList.size();
    }

    size_t getNumEdges(void) const override {
        size_t total = 0;
        for (auto list : adjacencyList) {
            total += list.size();
        }

        return total;
    }

    /*
     * Checks if an edge between first and last exists.
     */
    bool edgeExists(id_t first, id_t last) const override {
        auto list = adjacencyList.at(first);

        for (id_t node : list) {
            if (node == last) {
                return true;
            }
        }

        return false;
    }

    std::vector<std::pair<id_t, id_t>> getEdges(void) const override {
        std::vector<std::pair<id_t, id_t>> edges;

        for (id_t i = 0; i < adjacencyList.size(); i++) {
            for (id_t j : adjacencyList.at(i)) {
                edges.push_back(std::pair<id_t, id_t>(i, j));
            }
        }

        return edges;
    }

    std::vector<id_t> getChildren(id_t node) const override {
        return adjacencyList.at(node);
    }

    std::vector<id_t> getParents(id_t node) const override {
        std::vector<id_t> parents;

        for (id_t i = 0; i < adjacencyList.size(); i++) {
            for (id_t n : adjacencyList.at(i)) {
                if (n == node) {
                    parents.push_back(i);
                    break;
                }
            }
        }

        return parents;
    }

private:
    // adjacencyList[i] holds the children of the i'th node.
    std::vector<std::vector<id_t>> adjacencyList;
};

}  // namespace graphlib

#endif  // DEFAULT_GRAPH_H
