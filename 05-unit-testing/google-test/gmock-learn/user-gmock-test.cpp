//
// Created by cds on 2020/10/1.
//

#include "user.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mock-user.h"
#include "biz.h"

TEST(PainterTest, CanDrawSomething) {
    MockUser test_user;
    EXPECT_CALL(test_user, Online()).WillOnce(testing::Return(true));
    EXPECT_CALL(test_user, Login(testing::_,testing::_)).WillRepeatedly(testing::Return(false));
    EXPECT_CALL(test_user, Pay(testing::_)).WillRepeatedly(testing::Return(true));

    Biz biz;
    biz.SetUser(&test_user);
    std::string admin_ret = biz.pay("user", "", 1);
    admin_ret = biz.pay("user", "", 1);
}
