#pragma once
#include "Incrementa_Client.h"
Incrementa_Client::Incrementa_Client()
{
    incrementa_operators_handler = new IncrementaOperators_Handler();;
}

bool Incrementa_Client::Handle(Lex Type)
{
    if(incrementa_operators_handler->Handle(Type))
        return true;
    return AbstractHandler_Assigment::Handle(Type);
}

