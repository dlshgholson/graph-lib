/*
 * test_1.h - Test file.
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

using namespace graphlib;

int main(int argc, char *argv[]) {
    std::cout << "Testing basic graph equivalence." << std::endl;

    Graph graph1(1);
    Graph graph2(1);

    assert(graph1 == graph2);

    graph1 = Graph(2);
    graph1.addEdge(0, 1);

    graph2 = Graph(2);
    graph2.addEdge(1, 0);

    assert(graph1 != graph2);

    return 0;
}
