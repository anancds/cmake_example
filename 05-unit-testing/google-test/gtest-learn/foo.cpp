//
// Created by cds on 2020/10/1.
//

#include "foo.h"

int Foo::foo(int a, int b) {
    if (a == 0 || b == 0) {
        throw "don't do that";
    }
    int c = a % b;
    if (c == 0)
        return b;
    return foo(b, c);
}
