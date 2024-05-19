//
// Created by loban on 5/18/2024.
//

#ifndef ARRAYASSINGMENT_HANDLER_H
#define ARRAYASSINGMENT_HANDLER_H


#pragma once
#include "AbstractHandler_Assigment.h"

class ArrayAssingment_Handler:public AbstractHandler_Assigment
{
public:
    bool Handle(Lex Type) override;
};




#endif //ARRAYASSINGMENT_HANDLER_H
