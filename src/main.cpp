#include <iostream>
#include <vector>

#include "zqnum.h"

using namespace std;

int main()
{
    zqnum::Q n(19, 13);
    std::cout << n.toString();
    //zqnum::zqnumTests();
    return 0;
}
