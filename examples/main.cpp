#include "../zvl.hpp"
#include <iostream>

int main(){
    int a = 2;
    auto c = zvl::check(a).in_range(18,100);
    std::cout << c.is_valid << " " << c.message << std::endl;
}