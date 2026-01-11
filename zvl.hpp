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

            template <typename U, typename V, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
            ValidateObject& in_range(U min, V max){
                if (obj < min || obj > max) {
                    valid = false;
                    msg = "value out of range";
                }
                return *this;
            }

            template <typename U, typename V>
            ValidateObject& in_len(U min, V max){
                if (obj.length() < min || obj.length() > max) {
                    valid = false;
                    msg = "len out of range";
                }
                return *this;
            }

            
            ValidateObject& contains(std::string sym){
                if (!(obj.find(sym) != std::string::npos)) {
                    valid = false;
                    msg = "obj not contains sym";
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