#ifndef LEX_H
#define LEX_H

#pragma once
#include <sstream>
#include <stdexcept>
#include <string>
#include <variant>
class Lex
{
public:
    std::string value;
    int lexID=-1;
    int lexLine=-1;
    int dataTypeID=-1;
    int array=-1;//-1 - is not array     0 - is array without new       1 - is array was init
    std::variant<std::string, bool, char, double, int> data;
    bool operator==(const Lex& other) const {
        return value == other.value && lexID == other.lexID && dataTypeID == other.dataTypeID;
    }
    Lex& operator+=(const Lex& other) {
        data = std::visit(overloaded{
            [](auto&& a, auto&& b) -> std::variant<std::string, bool, char, double,int> {
                using T = std::decay_t<decltype(a)>;
                using U = std::decay_t<decltype(b)>;
                if constexpr (std::is_same_v<T, std::string> && std::is_same_v<U, std::string>) {
                    return a + b;
                } else if constexpr (std::is_same_v<T, char> && std::is_same_v<U, char>) {
                    return std::string(1, a) + std::string(1, b);
                } else if constexpr (std::is_same_v<T, double> && std::is_same_v<U, double>) {
                    return a + b;
                } else {
                    throw std::invalid_argument("Unsupported types for addition");
                }
            }
        }, data, other.data);
        return *this;
    }

    Lex& operator-=(const Lex& other) {
        data = std::visit(overloaded{
            [](auto&& a, auto&& b) -> std::variant<std::string, bool, char, double,int> {
                using T = std::decay_t<decltype(a)>;
                using U = std::decay_t<decltype(b)>;
                if constexpr (std::is_same_v<T, double> && std::is_same_v<U, double>) {
                    return a - b;
                } else {
                    throw std::invalid_argument("Unsupported types for subtraction");
                }
            }
        }, data, other.data);
        return *this;
    }

    Lex& operator*=(const Lex& other) {
        data = std::visit(overloaded{
            [](auto&& a, auto&& b) -> std::variant<std::string, bool, char, double,int> {
                using T = std::decay_t<decltype(a)>;
                using U = std::decay_t<decltype(b)>;
                if constexpr (std::is_same_v<T, double> && std::is_same_v<U, double>) {
                    return a * b;
                } else {
                    throw std::invalid_argument("Unsupported types for multiplication");
                }
            }
        }, data, other.data);
        return *this;
    }

    Lex& operator/=(const Lex& other) {
        data = std::visit(overloaded{
            [](auto&& a, auto&& b) -> std::variant<std::string, bool, char, double,int> {
                using T = std::decay_t<decltype(a)>;
                using U = std::decay_t<decltype(b)>;
                if constexpr (std::is_same_v<T, double> && std::is_same_v<U, double>) {
                    if (b == 0) throw std::invalid_argument("Division by zero");
                    return a / b;
                } else {
                    throw std::invalid_argument("Unsupported types for division");
                }
            }
        }, data, other.data);
        return *this;
    }

    Lex operator+(const Lex& other) const {
        Lex result = *this;
        result += other;
        return result;
    }

    Lex operator-(const Lex& other) const {
        Lex result = *this;
        result -= other;
        return result;
    }

    Lex operator*(const Lex& other) const {
        Lex result = *this;
        result *= other;
        return result;
    }

    Lex operator/(const Lex& other) const {
        Lex result = *this;
        result /= other;
        return result;
    }

    bool equals(const Lex& other) const {
        return std::visit(overloaded{
            [](const auto& a, const auto& b) -> bool {
                using T = std::decay_t<decltype(a)>;
                using U = std::decay_t<decltype(b)>;
                if constexpr (std::is_same_v<T, U>) {
                    return a == b;
                } else {
                    throw std::invalid_argument("Unsupported types for comparison");
                }
            }
        }, data, other.data);
    }

    bool operator!=(const Lex& other) const {
        return !equals(other);
    }

    bool operator<(const Lex& other) const {
        return std::visit(overloaded{
            [](const auto& a, const auto& b) -> bool {
                using T = std::decay_t<decltype(a)>;
                using U = std::decay_t<decltype(b)>;
                if constexpr (std::is_same_v<T, U>) {
                    return a < b;
                } else {
                    throw std::invalid_argument("Unsupported types for comparison");
                }
            }
        }, data, other.data);
    }

    bool operator<=(const Lex& other) const {
        return *this < other || equals(other);
    }

    bool operator>(const Lex& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Lex& other) const {
        return !(*this < other);
    }

    std::string toString() const {
        return std::visit(overloaded{
            [](const std::string& arg) -> std::string { return arg; },
            [](bool arg) -> std::string { return arg ? "true" : "false"; },
            [](char arg) -> std::string { return std::string(1, arg); },
            [](double arg) -> std::string {
                std::ostringstream oss;
                oss << arg;
                return oss.str();
            },
            [](int arg) -> std::string {
                std::ostringstream oss;
                oss << arg;
                return oss.str();
            }
        }, data);
    }

    friend std::ostream& operator<<(std::ostream& os, const Lex& lex) {
        os << lex.toString();
        return os;
    }
private:
    template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
    template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;
};


#endif //LEX_H
