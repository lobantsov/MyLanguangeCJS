//
// Created by loban on 5/18/2024.
//

#ifndef CODE_EXECUTION_H
#define CODE_EXECUTION_H
#pragma once
#include "Polish_Inverse_Writing.h"
#include "../SyntaxicAnalization/SingletoneDeclaretedVariables/DeclareredVariables.h"

class Code_execution
{
private:
    Polish_Inverse_Writing *inverse_writing = new Polish_Inverse_Writing();
    std::vector<Lex> source_string_stack;
    std::stack<Lex> tmp_stack;
    ClassForMethoodContainer *class_for_methood_container_ = new ClassForMethoodContainer();
    DeclareredVariables *declarered_variables_ = DeclareredVariables::GetInstance();
    int iterator=0;
public:
    void Execution();
    void EqualExecute(Lex tmp1, Lex tmp2);
    Lex MathOperators(Lex operator_, Lex tmp2, Lex tmp1);
    bool CheckLogicSentence(Lex operator_, Lex tmp1, Lex tmp2);
    bool CheckVarOrConst(const Lex& lex);
    Lex FindLex(Lex lex);
    std::string CheckTypeOfConst(Lex lex);
    std::string CheckTypeOfVar(Lex lex);
    void EaserMyLive();
    double stringToNumber(const std::string& str);
};



#endif //CODE_EXECUTION_H
