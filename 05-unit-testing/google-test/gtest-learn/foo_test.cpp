//
// Created by cds on 2020/10/1.
//
#include <gtest/gtest.h>
#include "foo.h"
#include <ctime>

class fooTest : public ::testing::Test {
protected:
    void SetUp() override {
        std::cout << "Foo FooEnvironment SetUP" << std::endl;
        start_time_ = time(nullptr);
    }

    void TearDown() override {
        std::cout << "Foo FooEnvironment TearDown" << std::endl;
        const time_t end_time = time(nullptr);

        // Asserts that the test took no more than ~5 seconds.  Did you
        // know that you can use assertions in SetUp() and TearDown() as
        // well?
        EXPECT_TRUE(end_time - start_time_ <= 5) << "The test took too long.";
    }

    time_t start_time_;
};

TEST_F(fooTest, abc) {
    Foo foo;

    sleep(1);
    std::cout << "test" << std::endl;
    EXPECT_EQ(1, foo.foo(1, 2)) << "failed.";
}

TEST_F(fooTest, throw) {
    Foo foo;

    EXPECT_ANY_THROW(foo.foo(10, 0));
}

TEST_F(fooTest, Predicate_Assertions) {
    Foo foo;

    int m = 5;
    int n = 6;
//    EXPECT_PRED2(foo.foo(m, n), m, n);
}

TEST_F(fooTest, Demo) {
    FooType<bool> fooType;
//    fooType.Bar();
}