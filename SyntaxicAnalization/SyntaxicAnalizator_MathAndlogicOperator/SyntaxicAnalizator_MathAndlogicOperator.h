//
// Created by loban on 5/18/2024.
//

#ifndef SYNTAXICANALIZATOR_MATHANDLOGICOPERATOR_H
#define SYNTAXICANALIZATOR_MATHANDLOGICOPERATOR_H

#pragma once
#include "../../Singletone/SingletoneCurrentposition.h"
#include "../../SpawnErrors/ClassForCreateErorrs.h"
#include "../SingletoneDeclaretedVariables/DeclareredVariables.h"

class SyntaxicAnalizator_MathAndlogicOperator
{
    int tmpConst;
public:
    SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
    ClassForCreateErorrs *create_erorrs = ClassForCreateErorrs::GetInstance();
    DeclareredVariables *declarered_variables_ = DeclareredVariables::GetInstance();

    bool SelfMathAdiction();
    bool MathOperatorCheck();
    bool ConditionCheck(bool isloop);
    bool IncrementAndDicremental();
};



#endif //SYNTAXICANALIZATOR_MATHANDLOGICOPERATOR_H
