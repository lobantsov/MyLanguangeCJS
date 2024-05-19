//
// Created by loban on 5/18/2024.
//

#ifndef MAINCLIENTASSIGMENT_H
#define MAINCLIENTASSIGMENT_H


#pragma once
#include "../ArrayAssingment_Handler.h"
#include "../Initialization_Handler.h"
#include "../Client_Handler/Incrementa_Client.h"
#include "../Client_Handler/Logic_Client.h"
#include "../Client_Handler/Math_Client.h"


class MainClientAssigment
{
public:
    MainClientAssigment();
    bool CheckAssigment(Lex Type, bool endSigntStatus);
    Math_Client *math_client;
    Logic_Client *logic_client;
    Incrementa_Client *incrementa_client;
    Initialization_Handler *initialization_handler;
    End_Handler *end_handler;
    ArrayAssingment_Handler *array_assingment_handler;
    SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
};



#endif //MAINCLIENTASSIGMENT_H
