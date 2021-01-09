#pragma once

#include <type_traits>

template<
    typename T,
    typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
>
struct Vector2d {
    T x = 0;
    T y = 0;
	Vector2d(T x, T y) {
        this->x = x;
        this->y = y;
    }

    bool operator==(Vector2d<T> &vector) {
        return vector.x == x && vector.y == y;
    }
};

using Size = Vector2d<int>;
