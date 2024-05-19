#pragma once
#include "Client_If_Declaratoin.h"
Client_If_Declaratoin::Client_If_Declaratoin()
{
    elsehandler=new ElseHandler();
    ifhandler = new  Ifhandler();
    ifhandler->SetNext(elsehandler);
}

bool Client_If_Declaratoin::Check_if()
{
    if(ifhandler->Handle())
        return true;
    return false;
}
