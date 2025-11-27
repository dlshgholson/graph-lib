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

#include "graph_structure.h"

namespace graphlib {

template <typename T>
class EdgeWeights : public GraphStructure {
public:
    T defaultWeight;

    EdgeWeights(Graph *_graphPtr) :
        GraphStructure{_graphPtr}, defaultWeight{T()} {}

    void setWeight(id_t edgeId, T weight) {
        if (!edgeExists(edgeId)) {
            // TODO.
        }

        weights.set(edgeId, weight);
    }

    T getWeight(id_t edgeId) {
        if (!edgeExists(edgeId)) {
            // TODO.
        }

        if weights.contains(edgeId) {
            return weights.get(edgeId);
        }
        else {
            return defaultWeight;
        }
    }

protected:
    Map<id_t, T> weights;

    /*
     * Checks the attatched graph if the edge actually exists.
     */
    bool edgeExists(id_t edgeId) {
        return graphPtr->edges.contains(edgeId);
    }
};

}  // namespace graphlib

#endif  // EDGE_WEIGHTS_H
