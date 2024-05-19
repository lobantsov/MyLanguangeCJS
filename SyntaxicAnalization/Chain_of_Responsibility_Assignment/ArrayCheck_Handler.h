//
// Created by loban on 5/18/2024.
//

#ifndef ARRAYCHECK_HANDLER_H
#define ARRAYCHECK_HANDLER_H

#pragma once
#include "AbstractHandler_Assigment.h"

class ArrayCheck_Handler:public AbstractHandler_Assigment
{
public:
    bool Handle(Lex TypeID) override;
};




#endif //ARRAYCHECK_HANDLER_H
