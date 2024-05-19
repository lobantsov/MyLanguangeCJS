//
// Created by loban on 5/18/2024.
//

#ifndef INCREMENTAOPERATORS_HANDLER_H
#define INCREMENTAOPERATORS_HANDLER_H


#pragma once
#include "AbstractHandler_Assigment.h"

class IncrementaOperators_Handler:public AbstractHandler_Assigment
{
public:
    bool Handle(Lex Type) override;
};



#endif //INCREMENTAOPERATORS_HANDLER_H
