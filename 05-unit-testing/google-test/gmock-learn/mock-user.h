//
// Created by cds on 2020/10/1.
//
#pragma once
#include "user.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockUser : public User {
public:
    MOCK_METHOD2(Login, bool(const std::string&, const std::string&));
    MOCK_METHOD1(Pay, bool(int));
    MOCK_METHOD0(Online, bool());
};