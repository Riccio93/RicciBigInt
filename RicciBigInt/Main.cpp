#include <iostream>
#include "BigInt.h"

int main()
{
    std::cout << "Ricci BigInt!\n";
    BigInt a();
    BigInt b(150);
    BigInt c(b);
    BigInt d(200);
    std::cout << b.Sum(d).data[0] << std::endl;
    int x;
    std::cin >> x;
}