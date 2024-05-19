//
// Created by loban on 5/18/2024.
//

#ifndef VARIABLEHANDLER_H
#define VARIABLEHANDLER_H


#pragma once
#include "AbstractHandler.h"
#include "../../Singletone/SingletoneCurrentposition.h"
#include "../../SpawnErrors/ClassForCreateErorrs.h"

class VariableHandler:public AbstractHandler
{
public:
    bool Handle(Lex type_id)override;
};



#endif //VARIABLEHANDLER_H
