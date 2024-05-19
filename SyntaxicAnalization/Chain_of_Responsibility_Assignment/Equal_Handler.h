//
// Created by loban on 5/18/2024.
//

#ifndef EQUAL_HANDLER_H
#define EQUAL_HANDLER_H

#pragma once
#include "AbstractHandler_Assigment.h"

class Equal_Handler:public AbstractHandler_Assigment
{
public:
    bool Handle(Lex Type) override;
};




#endif //EQUAL_HANDLER_H
