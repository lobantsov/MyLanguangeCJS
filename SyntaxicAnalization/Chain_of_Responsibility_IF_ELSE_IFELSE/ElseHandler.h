//
// Created by loban on 5/18/2024.
//

#ifndef ELSEHANDLER_H
#define ELSEHANDLER_H

#pragma once
#include "AbstractHandler_if.h"

class ElseHandler:public AbstractHandler_if
{
public:
    bool Handle()override;
};



#endif //ELSEHANDLER_H
