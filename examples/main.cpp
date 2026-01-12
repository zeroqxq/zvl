#include "../zvl.hpp"
#include <iostream>

int main(){
    std::string a = "test!";
    auto c = zvl::check(a).not_empty().in_len(5,10).contains("!");
    std::cout << c.is_valid() << " " << c.message() << std::endl;
}