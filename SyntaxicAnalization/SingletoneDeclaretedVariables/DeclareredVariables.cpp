#pragma once
#include "DeclareredVariables.h"
DeclareredVariables* DeclareredVariables::declarered_variables_= nullptr;;

DeclareredVariables *DeclareredVariables::GetInstance()
{
    if(declarered_variables_==nullptr){
        declarered_variables_ = new DeclareredVariables();
    }
    return declarered_variables_;
}

bool DeclareredVariables::ContainingLex(const Lex& lex)
{
    for (const auto& lex1 : CreatedLexemus)
    {
        if (lex1.lexID == lex.lexID &&
            lex1.value == lex.value)
        {
            return true;
        }
    }
    return false;
}
//find lex into vector for checked init with new
Lex DeclareredVariables::ContainingLexGetLex(const Lex& lex)
{
    for (const auto& lex1 : CreatedLexemus)
    {
        if (lex1.lexID == lex.lexID && lex1.value == lex.value)
        {
            return lex1;
        }
    }
}