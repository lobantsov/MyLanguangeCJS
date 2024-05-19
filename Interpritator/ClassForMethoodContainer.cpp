#pragma once
#include "ClassForMethoodContainer.h"
bool ClassForMethoodContainer::IsLogicOperator(const Lex& lex)
{
    if (lex.value == "==" || lex.value == "<=" || lex.value == "<" || lex.value == ">=" || lex.value == ">" || lex.value == "!=")
        return true;
    return false;
}

bool ClassForMethoodContainer::IsMathOperator(const Lex& lex)
{
    if (lex.value == "+" || lex.value == "-" || lex.value == "*" || lex.value == "/"
                    || lex.value == "++" || lex.value == "--" || lex.value == "**" ||
                lex.value == "+=" || lex.value == "-=" || lex.value == "/=" || lex.value == "*=")
        return true;
    return false;
}
bool ClassForMethoodContainer::isOperation(const std::string& op)
{
    return op == "+" || op == "-" || op == "*" || op == "/" || 
           op == "=" || op == "+=" || op == "-=" || op == "*=" || op == "/=" ||
           op == "++" || op == "--" || op == "**" ||
           op == "<" || op == ">" || op == "<=" || op == ">=" || op == "=="||  op == "!=" ||
           op == "for" || op == "do_while" || op == "while" || op == "if" || op == "else"||
           op == "write" || op == "read";
}
std::string ClassForMethoodContainer::ExecuteStringSyntaxic(const std::string& lexValue)
{
    std::string result = lexValue;
  //  result.erase(std::remove(result.begin(), result.end(), '\"'), result.end());
    return result;
}