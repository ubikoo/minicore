//
// test-matrix3.h
//
// Copyright (c) 2020 Carlos Braga
// This program is free software; you can redistribute it and/or modify it
// under the terms of the MIT License. See accompanying LICENSE.md or
// https://opensource.org/licenses/MIT.
//

#ifndef TEST_MATH_MATRIX3_H_
#define TEST_MATH_MATRIX3_H_

#include "minicore/math/math.h"
#include "common.h"

///
/// @brief Mat3 test client.
///
template<typename T>
void test_matrix3(void)
{
    // Constructor and assignment.
    {
        Math::Mat3<T> a{};
        Math::Mat3<T> b = {
            static_cast<T>(1),
            static_cast<T>(1),
            static_cast<T>(1),

            static_cast<T>(1),
            static_cast<T>(1),
            static_cast<T>(1),

            static_cast<T>(1),
            static_cast<T>(1),
            static_cast<T>(1)};
        Math::Mat3<T> c = Math::Mat3<T>::Zeros;
        Math::Mat3<T> d = Math::Mat3<T>::Ones;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(a[i] == c[i]);
            REQUIRE(b[i] == d[i]);
        }
    }

    // Compound assignment operators (matrix).
    {
        Math::Mat3<T> a = {};
        a += Math::Mat3<T>::Ones;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(a[i] == static_cast<T>(1));
        }

        a -= Math::Mat3<T>::Ones;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(a[i] == static_cast<T>(0));
        }

        Math::Mat3<T> b = {
            static_cast<T>(2),
            static_cast<T>(2),
            static_cast<T>(2),

            static_cast<T>(2),
            static_cast<T>(2),
            static_cast<T>(2),

            static_cast<T>(2),
            static_cast<T>(2),
            static_cast<T>(2)};
        a = Math::Mat3<T>::Ones;
        a *= b;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(a[i] == static_cast<T>(2));
        }

        a /= b;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(a[i] == static_cast<T>(1));
        }
    }

    // Compound assignment operators (scalar).
    {
        Math::Mat3<T> a = {};
        a += static_cast<T>(1);
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(a[i] == static_cast<T>(1));
        }

        a -= static_cast<T>(1);
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(a[i] == static_cast<T>(0));
        }

        a = Math::Mat3<T>::Ones;
        a *= static_cast<T>(2);
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(a[i] == static_cast<T>(2));
        }

        a /= static_cast<T>(2);
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(a[i] == static_cast<T>(1));
        }
    }

    // Arithmetic operators (matrix).
    {
        Math::Mat3<T> a = Math::Mat3<T>::Ones * static_cast<T>(2);
        Math::Mat3<T> b = Math::Mat3<T>::Ones * static_cast<T>(4);
        Math::Mat3<T> c = a + b;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(6));
        }

        c = b - a;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(2));
        }

        c = b * a;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(8));
        }

        c = b / a;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(2));
        }
    }

    // Arithmetic operators (scalar).
    {
        Math::Mat3<T> a = Math::Mat3<T>::Ones * static_cast<T>(4);
        Math::Mat3<T> c = a + static_cast<T>(2);
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(6));
        }

        c = a - static_cast<T>(2);
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(2));
        }

        c = a * static_cast<T>(2);
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(8));
        }

        c = a / static_cast<T>(2);
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(2));
        }
    }

    // Arithmetic operators (scalar).
    {
        Math::Mat3<T> a = static_cast<T>(2) * Math::Mat3<T>::Ones;
        Math::Mat3<T> c = static_cast<T>(2) + a;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(4));
        }

        c = static_cast<T>(4) - a;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(2));
        }

        c = static_cast<T>(2) * a;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(4));
        }

        c = static_cast<T>(2) / a;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(1));
        }
    }

    // Unary and increment operators
    {
        Math::Mat3<T> a = Math::Mat3<T>::Ones * static_cast<T>(2);

        Math::Mat3<T> c = +a;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(2));
        }

        c = -a;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(-2));
        }

        c = a++;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(2));
        }

        c = a--;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(3));
        }

        c = ++a;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(3));
        }

        c = --a;
        for (size_t i = 0; i < a.length; ++i) {
            REQUIRE(c[i] == static_cast<T>(2));
        }
    }
}

#endif // TEST_MATH_MATRIX3_H_
