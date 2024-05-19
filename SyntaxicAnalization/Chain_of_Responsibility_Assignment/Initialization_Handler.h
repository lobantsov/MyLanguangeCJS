//
// Created by loban on 5/18/2024.
//

#ifndef INITIALIZATION_HANDLER_H
#define INITIALIZATION_HANDLER_H

#pragma once
#include "AbstractHandler_Assigment.h"

class Initialization_Handler:public AbstractHandler_Assigment
{
public:
    bool Handle(Lex Type) override;
    bool VarCheck(Lex Type);
};



#endif //INITIALIZATION_HANDLER_H
