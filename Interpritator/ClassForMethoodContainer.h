//
// Created by loban on 5/18/2024.
//

#ifndef CLASSFORMETHOODCONTAINER_H
#define CLASSFORMETHOODCONTAINER_H
#pragma once
#include "../LexAnalizator/Lex.h"

class ClassForMethoodContainer
{
public:
    bool isOperation(const std::string& op);
    std::string ExecuteStringSyntaxic(const std::string& lexValue);
    bool IsLogicOperator(const Lex& lex);
    bool IsMathOperator(const Lex& lex);
};


#endif //CLASSFORMETHOODCONTAINER_H
