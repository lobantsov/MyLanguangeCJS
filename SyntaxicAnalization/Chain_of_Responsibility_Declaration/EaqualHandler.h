//
// Created by loban on 5/18/2024.
//

#ifndef EAQUALHANDLER_H
#define EAQUALHANDLER_H

#pragma once
#include "AbstractHandler.h"
#include "../../Singletone/SingletoneCurrentposition.h"

class EaqualHandler:public AbstractHandler
{
public:
    bool Handle(Lex TypeID) override;
};




#endif //EAQUALHANDLER_H
