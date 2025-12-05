/*
 * edge_weights.h - The term traditionally comes from weighted edges on a
 * graph, but the template allows the structure to hold any type.
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

#ifndef EDGE_WEIGHTS_H
#define EDGE_WEIGHTS_H

#include "graph.h"
#include "types.h"

#include <map>
#include <utility>

namespace graphlib {

template <typename T>
class EdgeWeights {
public:
    T defaultWeight;

    EdgeWeights(Graph *ptr) :
        g{ptr}, defaultWeight{T()} {}
    EdgeWeights(Graph *ptr, T _defaultWeight) :
        g{ptr}, defaultWeight{defaultWeight} {}

    void setWeight(node_id first, node_id last, T weight) {
        if (!g->edgeExists(first, last)) {
            // TODO.
        }

        weights.set(std::pair<node_id, node_id>(first, last), weight);
    }

    T getWeight(node_id first, node_id last) const {
        if (!g->edgeExists(first, last)) {
            // TODO.
        }

        auto edgeId = std::pair<node_id, node_id>(first, last);
        if (weights.contains(edgeId)) {
            return weights.at(edgeId);
        }
        else {
            return defaultWeight;
        }
    }

protected:
    /*
     * Points to the graph this structure is connected to.
     */
    const Graph *g;

    std::map<std::pair<node_id, node_id>, T> weights;
};

}  // namespace graphlib

#endif  // EDGE_WEIGHTS_H
