//
// Created by loban on 5/18/2024.
//

#ifndef CLIENT_IF_DECLARATOIN_H
#define CLIENT_IF_DECLARATOIN_H
#pragma once
#include "ElseHandler.h"
#include "Ifhandler.h"
#include "../../Singletone/SingletoneCurrentposition.h"

class Client_If_Declaratoin
{
public:
    Client_If_Declaratoin();
    bool Check_if();
    Ifhandler *ifhandler;
    ElseHandler *elsehandler;
    SingletoneCurrentposition* singletone_currentposition=SingletoneCurrentposition::GetInstance();
};


#endif //CLIENT_IF_DECLARATOIN_H
