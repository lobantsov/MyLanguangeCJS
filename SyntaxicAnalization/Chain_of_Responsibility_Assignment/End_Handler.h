//
// Created by loban on 5/18/2024.
//

#ifndef END_HANDLER_H
#define END_HANDLER_H


#pragma once
#include "AbstractHandler_Assigment.h"

class End_Handler:public AbstractHandler_Assigment
{
public:
    bool Handle(Lex Type) override;
};



#endif //END_HANDLER_H
