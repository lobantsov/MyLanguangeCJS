//
// Created by loban on 5/18/2024.
//

#ifndef ABSTRACTHANDLER_ASSIGMENT_H
#define ABSTRACTHANDLER_ASSIGMENT_H

#pragma once
#include "IHandler_assigment.h"
#include "../../LexAnalizator/Lex.h"
#include "../../Singletone/SingletoneCurrentposition.h"
class AbstractHandler_Assigment:public IHandler_assigment
{
    IHandler_assigment *next_handler_;
protected:
public:
    IHandler_assigment *SetNext(IHandler_assigment *handler) override;
    bool Handle(Lex Type) override;
    SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
};

#endif //ABSTRACTHANDLER_ASSIGMENT_H
