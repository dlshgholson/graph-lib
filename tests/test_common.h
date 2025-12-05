/*
 * test_common.h - Common testing utilities.
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

#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include <algorithm> // std::shuffle
#include <cassert>
#include <iostream>
#include <random>    // std::random_device, std::mt19937
#include <vector>

#include "algos.h"
#include "default_graph.h"
#include "types.h"

using namespace graphlib;

typedef std::vector<std::vector<node_id>> AdjacencyList;

/*
 * Given a positive integer n, generates a random permutation of integers from
 * 0 to n. For example, when n = 4 a possible output is [3, 1, 2, 0].
 */
std::vector<std::size_t> randomPermutation(std::size_t n) {
    std::vector<std::size_t> permutation(n);
    for (std::size_t i = 0; i < n; i++) {
        permutation.at(i) = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(permutation.begin(), permutation.end(), g);

    return permutation;
}

/*
 * Given an adjacency list, returns a randomly permuted equivalent list.
 * Adjacency lists of equivalent graphs must be a permutation of each other.
 */
AdjacencyList randomlyPermute(AdjacencyList adjList) {
    std::vector<std::size_t> permutation = randomPermutation(adjList.size());

    for (auto &list : adjList) {
        for (node_id &node : list) {
            node = permutation.at(node);
        }
    }

    return adjList;
}

/*
 * Generates a random adjacency list with n nodes, and each possible edge has
 * uniform probability p of getting added.
 */
AdjacencyList randomAdjacencyList(std::size_t n, float p) {
    std::random_device rd;
    std::bernoulli_distribution distribution(p);

    AdjacencyList adjList(n);
    // Flip a coin whether to add each edge or not.
    for (std::size_t i = 0; i < n; i++) {
        for (std::size_t j = 0; j < n; j++) {
            if (distribution(rd)) {
                adjList.at(i).push_back(j);
            }
        }
    }

    return adjList;
}

#endif  // TEST_COMMON_H
