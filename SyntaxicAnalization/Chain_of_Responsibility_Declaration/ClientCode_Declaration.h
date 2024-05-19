//
// Created by loban on 5/18/2024.
//

#ifndef CLIENTCODE_DECLARATION_H
#define CLIENTCODE_DECLARATION_H

#pragma once
#include "EaqualHandler.h"
#include "EnumerationHandler.h"
#include "VariableHandler.h"

class ClientCode_Declaration
{
public:
    ClientCode_Declaration();
    bool CheckDataType(Lex TypeID);
    VariableHandler *variable_handler;
    EnumerationHandler *enumeration_handler;
    EaqualHandler *eaqual_handler;
    SingletoneCurrentposition* singletone_currentposition=SingletoneCurrentposition::GetInstance();
};


#endif //CLIENTCODE_DECLARATION_H
