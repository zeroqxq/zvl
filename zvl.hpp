#pragma once
#include <string>
#include <type_traits>
#include <vector>
#include <typeinfo>

namespace zvl {

    template <typename T>
    class ValidateObject {
        private:
            const T& obj;
            bool valid = true;
            std::string msg;
            std::vector<std::string> msgs;
            
        public:
            
            ValidateObject(const T& o) : obj(o) {}

            template <typename U, typename V>
            ValidateObject& in_range(U min, V max){
                if (obj < min || obj > max) {
                    valid = false;
                    msg = "value out of range";
                    msgs.push_back(msg);
                }
                return *this;
            }

            template <typename U, typename V>
            ValidateObject& in_len(U min, V max){
                if (obj.length() < min || obj.length() > max) {
                    valid = false;
                    msg = "len out of range";
                    msgs.push_back(msg);
                }
                return *this;
            }

            
            ValidateObject& contains(std::string sym){
                if (!(obj.find(sym) != std::string::npos)) {
                    valid = false;
                    msg = "obj not contains sym";
                    msgs.push_back(msg);
                }
                return *this;
            }

            template <typename Expected>
            ValidateObject& is_type() {
                if constexpr (!std::is_same_v<std::decay_t<T>, std::decay_t<Expected>> &&
                            !std::is_convertible_v<T, Expected>) {
                    
                    valid = false;
                    msg = "type mismatch";
                    msgs.push_back(msg);
                }
                return *this;
            }

            ValidateObject& not_empty() {
                if (obj.empty()) {
                    valid = false;
                    msg = "string is empty";
                    msgs.push_back(msg);
                }
                return *this;
            }


            bool is_valid() {
                return valid;
            }

            std::string message() {
                return msg;
            }

            std::vector<std::string> messages() {
                return msgs;
            }
        
    };

    template <typename T>
        ValidateObject<T> check(const T& obj){
            return ValidateObject<T>(obj);
        }


}