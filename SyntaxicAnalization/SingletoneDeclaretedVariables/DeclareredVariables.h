//
// Created by loban on 5/18/2024.
//

#ifndef DECLAREREDVARIABLES_H
#define DECLAREREDVARIABLES_H

#pragma once
#include <vector>
#include "../../LexAnalizator/Lex.h"
class DeclareredVariables
{
protected:
    DeclareredVariables(){}
    static DeclareredVariables *declarered_variables_;
public:
    DeclareredVariables(DeclareredVariables &other) = delete;
    static DeclareredVariables *GetInstance();
    bool ContainingLex(const Lex& lex);
    Lex ContainingLexGetLex(const Lex& lex);
    std::vector<Lex> CreatedLexemus;
};


#endif //DECLAREREDVARIABLES_H
