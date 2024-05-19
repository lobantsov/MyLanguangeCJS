//
// Created by loban on 5/18/2024.
//

#ifndef POLISH_INVERSE_WRITING_H
#define POLISH_INVERSE_WRITING_H

#pragma once
#include <stack>
#include <vector>
#include "ClassForMethoodContainer.h"
#include "Strainer.h"
#include "../LexAnalizator/Lex.h"

class Polish_Inverse_Writing
{
private:
    std::stack<Lex> stack_tmp;
    std::stack<std::string> callBack;
    std::stack<Lex> tmpVectorForMovingSomeOperators;
    std::stack<Lex> callBack_mark;
    Strainer *strainer = new Strainer();
    std::vector<Lex> source_string_stack;
    ClassForMethoodContainer *class_for_methood_container_ = new ClassForMethoodContainer();

    int getPriority(const std::string& op);
    void set_right_place_into_source_line_for_math_operators(const Lex& op);
    Lex CreateNewComand(const std::string& typeComand);
    int mathOperatorPushBack=0;
    int addingIntoTmpIncrementaStack=0;
    int iterator=6;
    bool forOperator=true;
public:
    std::vector<Lex> FormingSourceLine();
};



#endif //POLISH_INVERSE_WRITING_H
