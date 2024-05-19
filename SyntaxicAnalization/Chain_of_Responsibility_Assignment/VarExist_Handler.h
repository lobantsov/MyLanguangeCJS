//
// Created by loban on 5/18/2024.
//

#ifndef VAREXIST_HANDLER_H
#define VAREXIST_HANDLER_H


#pragma once
#include "AbstractHandler_Assigment.h"

class VarExist_Handler:public AbstractHandler_Assigment
{
public:
    bool Handle(Lex Type) override;
};




#endif //VAREXIST_HANDLER_H
