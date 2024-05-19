//
// Created by loban on 5/18/2024.
//

#ifndef CHECKVAR_HANDLER_H
#define CHECKVAR_HANDLER_H

#pragma once
#include "AbstractHandler_Assigment.h"

class CheckVar_Handler:public AbstractHandler_Assigment
{
public:
    bool Handle(Lex Type) override;
};




#endif //CHECKVAR_HANDLER_H
