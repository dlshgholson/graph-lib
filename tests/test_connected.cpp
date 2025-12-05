/*
 * test_connected.h - Test the isConnected functions.
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

bool edgeInAdjList(AdjacencyList &adjList, node_id first, node_id last) {
    for (node_id i : adjList.at(first)) {
        if (i == last) {
            return true;
        }
    }

    return false;
}

/*
 * Randomly generates an adjacency list for a connected graph size n. Whether
 * the graph is strongly or weakly connected is determined by strong, and p is
 * the probability of each edge apart from the spanning tree of being added.
 */
AdjacencyList generateConnected(std::size_t n, bool strong, float p) {
    std::random_device rd;
    std::bernoulli_distribution distribution(p);
    std::bernoulli_distribution coinToss(0.5);

    // Every connected graph has a spanning tree, we generate it here and
    // randomly add additional edges.
    std::vector<std::size_t> tree = randomPermutation(n);

    AdjacencyList adjList(n);

    // Generate spanning tree.
    for (node_id i = 0; i < tree.size() - 1; i++) {
        node_id first = tree.at(i);
        node_id second = tree.at(i+1);

        if (strong) {
            adjList.at(first).push_back(second);
            adjList.at(second).push_back(first);
        }
        else {
            // Only add one edge in a random direction.
            if (coinToss(rd)) {
                adjList.at(first).push_back(second);
            }
            else {
                adjList.at(second).push_back(first);
            }
        }
    }

    // Randomly add edges.
    for (node_id i = 0; i < adjList.size(); i++) {
        for (node_id j = 0; j < adjList.size(); j++) {
            if (!edgeInAdjList(adjList, i, j) && distribution(rd)) {
                adjList.at(i).push_back(j);
            }
        }
    }

    return adjList;
}

/*
 * Randomly generates an adjacency list for a disconnected graph size n.
 */
AdjacencyList generateDisconnected(std::size_t n, float p) {
    std::random_device rd;
    std::uniform_int_distribution<> distribution(1, n-1);

    int firstSize = distribution(rd);
    int secondSize = n - firstSize;

    // Generate two random sub-graphs and combine them.
    AdjacencyList adjList1, adjList2;

    adjList1 = randomAdjacencyList(firstSize, p);
    adjList2 = randomAdjacencyList(secondSize, p);

    // Adjust node IDs before merging with adjList1.
    for (auto &list : adjList2) {
        for (node_id &node : list) {
            node += adjList1.size();
        }
    }

    adjList1.insert(adjList1.end(), adjList2.begin(), adjList2.end());

    return adjList1;
}

int main(int argc, char *argv[]) {
    std::cout << "Testing graph disconnectedness." << std::endl;
    for (int i = 0; i < 100; i++) {
        AdjacencyList adjList = generateDisconnected(30, 0.5);
        DefaultGraph graph = DefaultGraph(adjList);

        assert(!isWeaklyConnected(graph));
        assert(!isStronglyConnected(graph));
    }

    std::cout << "Testing weak graph connectedness." << std::endl;
    for (int i = 0; i < 100; i++) {
        AdjacencyList adjList = generateConnected(30, false, 0.5);
        DefaultGraph graph = DefaultGraph(adjList);

        assert(isWeaklyConnected(graph));
    }

    std::cout << "Testing strong graph connectedness." << std::endl;
    for (int i = 0; i < 100; i++) {
        AdjacencyList adjList = generateConnected(30, true, 0.5);
        DefaultGraph graph = DefaultGraph(adjList);

        assert(isWeaklyConnected(graph));
        assert(isStronglyConnected(graph));
    }

    std::cout << "Testing complete!" << std::endl;

    return 0;
}
