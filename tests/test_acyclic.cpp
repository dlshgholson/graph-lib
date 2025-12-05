/*
 * test_acyclic.h - Test the isAcyclic function.
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

#include "test_common.h"

/*
 * Randomly generates an adjacency list for an acyclic graph size n.
 */
AdjacencyList generateAcyclic(std::size_t n, float p) {
    std::random_device rd;
    std::bernoulli_distribution distribution(p);

    AdjacencyList adjList(n);

    // Create DAG by adding only edges that point to a higher node ID, then
    // randomly permute. Don't add additional random edges to avoid
    // accidentally creating a cycle.
    
    for (node_id i = 0; i < n; i++) {
        for (node_id j = i+1; j < n; j++) {
            if (distribution(rd)) {
                adjList.at(i).push_back(j);
            }
        }
    }

    return randomlyPermute(adjList);
}

/*
 * Randomly generates an adjacency list for a cyclic graph size n.
 */
AdjacencyList generateCyclic(std::size_t n, float p) {
    AdjacencyList adjList(n);

    // Manually add cycle.
    std::vector<std::size_t> cycle = randomPermutation(n);
    cycle.push_back(cycle.at(0));

    for (node_id i = 0; i < cycle.size() - 1; i++) {
        node_id first = cycle.at(i);
        node_id last = cycle.at(i+1);
        adjList.at(first).push_back(last);
    }

    randomlyAddEdges(adjList, p);

    return adjList;
}

int main(int argc, char *argv[]) {
    std::cout << "Testing graph acyclic." << std::endl;
    for (int i = 0; i < 100; i++) {
        AdjacencyList adjList = generateAcyclic(30, 0.5);
        DefaultGraph graph = DefaultGraph(adjList);

        assert(isAcyclic(graph));
    }

    std::cout << "Testing graph cyclic." << std::endl;
    for (int i = 0; i < 100; i++) {
        AdjacencyList adjList = generateCyclic(30, 0.5);
        DefaultGraph graph = DefaultGraph(adjList);

        assert(!isAcyclic(graph));
    }

    std::cout << "Testing complete!" << std::endl;

    return 0;
}
