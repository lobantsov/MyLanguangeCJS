#ifndef LEX_H
#define LEX_H

#pragma once
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
    std::string data_string;
    double data_number;
    bool data_bool;
    char data_char;
    std::variant<int, float, double, std::string, bool, char> data;
    bool operator==(const Lex& other) const {
        return value == other.value && lexID == other.lexID && dataTypeID == other.dataTypeID;
    }
};



#endif //LEX_H
