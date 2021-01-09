#pragma once

#include <type_traits>
#include <string>

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

    Vector2d() {
        this->x = 0;
        this->y = 0;
    }

    static std::string toString(const Vector2d<T>& vector) {
        return "(" + std::to_string(vector.x) + ";" + std::to_string(vector.y) + ")";
    }

    static Vector2d<T> clone(const Vector2d<T> &vector) {
        return Vector2d<T>(vector.x, vector.y);
    }

    bool operator==(Vector2d<T>& vector) {
        return vector.x == x && vector.y == y;
    }

    Vector2d operator+(Vector2d<T>& vector) {
        return Vector2d<T>(x + vector.x, y + vector.y);
    }

    Vector2d operator-(Vector2d<T>& vector) {
        return Vector2d<T>(x - vector.x, y - vector.y);
    }

    std::string toString() {
        return Vector2d::toString(*this);
    }

    Vector2d<T> clone() {
        return Vector2d::clone(*this);
    }
};

using Size = Vector2d<int>;
