#pragma once
#include <string>
#include <type_traits>

namespace zvl{

    template <typename T>
    class ValidateObject {
        private:
            const T& obj;
            bool valid = true;
            std::string msg;
            
        public:
            
            ValidateObject(const T& o) : obj(o) {}

            template <typename U, typename V, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
            ValidateObject& in_range(U min, V max){
                if (obj < min || obj > max) {
                    valid = false;
                    msg = "value out of range";
                }
                return *this;
            }

            bool is_valid() {
                return valid;
            }

            std::string message() {
                return msg;
            }
        
    };

    template <typename T>
        ValidateObject<T> check(T& obj){
            return ValidateObject<T>(obj);
        }


}