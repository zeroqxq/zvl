#pragma once
#include <string>
#include <type_traits>

namespace zvl{

    template <typename T>
    class ValidateObject {
        private:
            const T& obj;

        public:
            bool is_valid = true;
            std::string message;
            
            ValidateObject(const T& o) : obj(o) {}

            ValidateObject& in_range(int min, int max){
                static_assert(std::is_arithmetic_v<T>,
                "in_range() available only for numeric types");
                if (obj < min || obj > max) {
                    is_valid = false;
                    message = "value out of range";
                }
                return *this;
            }
        
    };

    template <typename T>
        ValidateObject<T> check(T& obj){
            return ValidateObject<T>(obj);
        }


}