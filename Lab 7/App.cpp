#include <iostream>

#include "TestScurt.h"
#include "TestExtins.h"
#include "TestNou.h"

int main() {
    testAllNew();
    testAll();
    testAllExtins();
    std::cout << "Finished Tests!" << std::endl;
}
