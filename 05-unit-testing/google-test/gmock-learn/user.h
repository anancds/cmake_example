//
// Created by cds on 2020/10/1.
//

#ifndef CMAKE_EXAMPLE_USER_H
#define CMAKE_EXAMPLE_USER_H

#include <string>

class User {
public:
    User() {};

    ~User() {};
public:
    // 登录
    virtual bool Login(const std::string &username, const std::string &password) = 0;

    // 支付
    virtual bool Pay(int money) = 0;

    // 是否登录
    virtual bool Online() = 0;
};

#endif //CMAKE_EXAMPLE_USER_H