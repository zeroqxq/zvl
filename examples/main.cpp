#include "../zvl.hpp"
#include <iostream>

int main(){
    int b = 2;
    auto c = zvl::check(b).in_range(18,100);
    std::cout << c.is_valid() << " " << c.message() << std::endl;
}