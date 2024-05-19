//
// Created by loban on 5/18/2024.
//

#ifndef MATHOPERATORS_HANDLER_H
#define MATHOPERATORS_HANDLER_H

#pragma once
#include "AbstractHandler_Assigment.h"

class MathOperators_Handler:public AbstractHandler_Assigment
{
public:
    bool Handle(Lex Type) override;
};




#endif //MATHOPERATORS_HANDLER_H
