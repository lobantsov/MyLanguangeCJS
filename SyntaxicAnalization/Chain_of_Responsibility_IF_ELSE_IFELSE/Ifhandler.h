//
// Created by loban on 5/18/2024.
//

#ifndef IFHANDLER_H
#define IFHANDLER_H

#pragma once
#include "AbstractHandler_if.h"

class Ifhandler:public AbstractHandler_if
{
public:
    bool Handle()override;
};



#endif //IFHANDLER_H
