//
// Created by cds on 2020/10/1.
//

#include "user.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mock-user.h"
#include "biz.h"

TEST(FirstTest, first) {
    MockUser test_user;
    EXPECT_CALL(test_user, Online()).WillOnce(testing::Return(true));
    EXPECT_CALL(test_user, Login(testing::_, testing::_)).WillRepeatedly(testing::Return(false));
    EXPECT_CALL(test_user, Pay(testing::_)).WillRepeatedly(testing::Return(true));

    Biz biz;
    biz.SetUser(&test_user);
    std::string admin_ret = biz.pay("user", "", 1);
}

TEST(FirstTest, second) {
    MockUser test_user;
    EXPECT_CALL(test_user, Online()).WillOnce(testing::Return(false));
    EXPECT_CALL(test_user, Login("admin", testing::_)).WillRepeatedly(testing::Return(false));

    Biz biz;
    biz.SetUser(&test_user);
    std::string admin_ret = biz.pay("admin", "", 1);

}

TEST(FirstTest, third) {
    MockUser test_user;
    EXPECT_CALL(test_user, Online()).WillRepeatedly(testing::Return(true));
    EXPECT_CALL(test_user, Login(testing::StrNe("admin"), testing::_)).WillRepeatedly(testing::Return(true));
    EXPECT_CALL(test_user, Pay(testing::_)).Times(3).WillOnce(testing::Return(true)).WillOnce(
            testing::Return(true)).WillRepeatedly(testing::Return(false));

    Biz biz;
    biz.SetUser(&test_user);
    std::string user_ret = biz.pay("user", "", 1);
    user_ret = biz.pay("user", "", 1);
    user_ret = biz.pay("user", "", 1);

}
