//
// Created by cds on 2020/10/1.
//
#include <gtest/gtest.h>
#include "foo.h"


class fooTest : public ::testing::Test {
};

TEST_F(fooTest, abc) {
    Foo foo;

    EXPECT_EQ(1 , foo.foo(1, 2)) << "failed.";
}

TEST_F(fooTest, throw) {
    Foo foo;

    EXPECT_ANY_THROW(foo.foo(10, 0));
}
