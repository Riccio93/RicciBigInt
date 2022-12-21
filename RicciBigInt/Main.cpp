#include <iostream>
#include <cassert>
#include "BigInt.h"

void Tests()
{
    BigInt pos1 = +99999999;
    BigInt pos2 = 5555;
    assert(pos1.Sum(pos2) == 100005554);
}

int main()
{
    Tests();

    BigInt a();
    BigInt b(150);
    BigInt c(b);
    BigInt d(200);
    //std::cout << b.Sum(d).data[0] << std::endl;
    int x;
    std::cin >> x;
}