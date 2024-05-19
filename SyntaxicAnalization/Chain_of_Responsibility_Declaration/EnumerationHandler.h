//
// Created by loban on 5/18/2024.
//

#ifndef ENUMERATIONHANDLER_H
#define ENUMERATIONHANDLER_H

#pragma once
#include "AbstractHandler.h"
#include "../../Singletone/SingletoneCurrentposition.h"
#include "../../SpawnErrors/ClassForCreateErorrs.h"


class EnumerationHandler:public AbstractHandler
{
public:
    bool Handle(Lex TypeID) override;
};




#endif //ENUMERATIONHANDLER_H
