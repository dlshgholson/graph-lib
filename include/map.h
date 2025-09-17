/*
 * map.h - Adapter class for typical map data structure.
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

#ifndef MAP_H
#define MAP_H

#include <algorithm>
#include <cstddef>
#include <vector>
#include <unordered_map>

namespace graphlib {

/*
 * Adapter class for a typical associative array. We may switch out
 * std::unordered_map for another implementation.
 */
template <typename T1, typename T2>
class Map {
public:
    Map() {
    }

    T2 get(const T1 key) const {
        return map.at(key);
    }

    void set(const T1 key, const T2 value) {
        map[key] = value;
    }

    void erase(const T1 key) {
        map.erase(key);
    }

    /*
     * Returns a vector of keys in the map.
     */
    std::vector<T1> getKeys() const {
        std::vector<T1> keys(size());

        std::transform(map.begin(), map.end(), keys.begin(),
                [&](auto pair) { return pair.first; });

        return keys;
    }

    /*
     * Returns a vector of key-value std::pairs in the map.
     */
    std::vector<std::pair<T1, T2>> getPairs() const {
        // FIXME. There's gotta be a better way to do this.
        std::vector<std::pair<T1, T2>> pairs(size());

        std::transform(map.begin(), map.end(), pairs.begin(),
                [&](auto pair) { return pair; });

        return pairs;
    }

    std::size_t size() const {
        return map.size();
    }

    bool contains(const T1 key) const {
        // Since C++20.
        return map.contains(key);
    }

    bool operator==(const Map other) const {
        return map == other.map;
    }

private:
    // We use std::unordered_map for now but this may change.
    std::unordered_map<T1, T2> map;
};

}  // namespace graphlib

#endif  // MAP_H
