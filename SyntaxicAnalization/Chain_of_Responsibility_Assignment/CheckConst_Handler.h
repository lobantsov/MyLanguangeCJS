//
// Created by loban on 5/18/2024.
//

#ifndef CHECKCONST_HANDLER_H
#define CHECKCONST_HANDLER_H

#pragma once
#include "AbstractHandler_Assigment.h"

class CheckConst_Handler:public AbstractHandler_Assigment
{
public:
    bool Handle(Lex Type) override;
};




#endif //CHECKCONST_HANDLER_H
