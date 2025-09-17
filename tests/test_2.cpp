/*
 * test_2.h - Test file.
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

#include <cassert>
#include <iostream>

#include "graph.h"

#define VERBOSE_STREAM \
    if (!verbose) {} \
    else std::cout

using namespace graphlib;

int main(int argc, char *argv[]) {
    bool verbose = false;

    if (argc > 1) {
        // If argv[1] is "-v".
        if (argv[1][0] == '-' && argv[1][1] == 'v') {
            verbose = true;
        }
    }

    if (!verbose) {
        std::cout << "Run with -v for verbose logging." << std::endl;
    }

    VERBOSE_STREAM << "Testing remove function." << std::endl;

    Graph graph1(1);

    Graph graph2(2);
    graph2.addEdge(0, 1);
    graph2.addEdge(1, 0);

    VERBOSE_STREAM << "Graph 2 before:" << graph2;
    graph2.removeNode(1);
    VERBOSE_STREAM << "Graph 2 after:" << graph2;

    assert(graph1 == graph2);

    graph2 = Graph(2);
    graph2.addEdge(0, 1);
    graph2.addEdge(1, 0);

    VERBOSE_STREAM << "Graph 2 before:" << graph2;
    graph2.removeNode(0);
    VERBOSE_STREAM << "Graph 2 after:" << graph2;

    assert(graph1 != graph2);
    assert(graph1.isEquivalentTo(graph2));

    std::cout << "Test 2 succeeded!" << std::endl;

    return 0;
}
