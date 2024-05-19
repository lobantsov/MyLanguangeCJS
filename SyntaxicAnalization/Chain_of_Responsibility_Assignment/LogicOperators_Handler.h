//
// Created by loban on 5/18/2024.
//

#ifndef LOGICOPERATORS_HANDLER_H
#define LOGICOPERATORS_HANDLER_H

#pragma once
#include "AbstractHandler_Assigment.h"

class LogicOperators_Handler:public AbstractHandler_Assigment
{
public:
    bool Handle(Lex Type) override;
};



#endif //LOGICOPERATORS_HANDLER_H
