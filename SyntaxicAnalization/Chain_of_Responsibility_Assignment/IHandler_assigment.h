//
// Created by loban on 5/18/2024.
//

#ifndef IHANDLER_ASSIGMENT_H
#define IHANDLER_ASSIGMENT_H

#pragma once
#include "../../SpawnErrors/ClassForCreateErorrs.h"
#include "../SingletoneDeclaretedVariables/DeclareredVariables.h"
class IHandler_assigment
{
public:
    virtual IHandler_assigment *SetNext(IHandler_assigment *handler) = 0;
    virtual bool Handle(Lex Type) = 0;
    ClassForCreateErorrs *create_erorrs = ClassForCreateErorrs::GetInstance();
    DeclareredVariables *declarered_variables_ = DeclareredVariables::GetInstance();
    std::string parent_chain;
    static Lex *tmpLex;
};

#endif //IHANDLER_ASSIGMENT_H
