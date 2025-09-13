/*
 * valued.h - Introduces Valued base class that allows children to hold values.
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

#ifndef VALUED_H
#define VALUED_H

namespace graphlib {

template<typename T>
class Valued {
public:
    ValuedEdge() {
    }

    ValuedEdge(T _value) {
        value = _value;
    }

    T getValue() {
        return value;
    }

protected:
    T value;
};

}  // namespace graphlib

#endif  // VALUED_H
