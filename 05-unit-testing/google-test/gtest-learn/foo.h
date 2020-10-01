//
// Created by cds on 2020/10/1.
//

#ifndef CMAKE_EXAMPLE_FOO_H
#define CMAKE_EXAMPLE_FOO_H

#include <gtest/gtest.h>

class Foo {
public:
    int foo(int a, int b);
};

template<typename T>
class FooType {
public:
    void Bar() { testing::StaticAssertTypeEq<int, T>(); }
};

#endif //CMAKE_EXAMPLE_FOO_H
