//
// Created by loban on 5/18/2024.
//

#ifndef INCREMENTA_CLIENT_H
#define INCREMENTA_CLIENT_H


#pragma once
#include "../AbstractHandler_Assigment.h"
#include "../IncrementaOperators_Handler.h"

class Incrementa_Client:public AbstractHandler_Assigment
{
public:
    Incrementa_Client();
    IncrementaOperators_Handler *incrementa_operators_handler;
    bool Handle(Lex Type) override;
};




#endif //INCREMENTA_CLIENT_H
