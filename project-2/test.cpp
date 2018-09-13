#include "Set.h"
#include <iostream>

int main() {
    Set<int> intSet;
    std::cout << std::boolalpha;
    std::cout << intSet.getCurrentSize() << '\n';
    std::cout << intSet.isEmpty()<< '\n';
    std::cout << intSet.add(1)<< '\n';
    std::cout << intSet.isEmpty()<< '\n';
    std::cout << intSet.contains(1)<< '\n';
    std::cout << intSet.remove(1)<< '\n';
    std::cout << intSet.contains(1)<< '\n';
    return 0;
}
