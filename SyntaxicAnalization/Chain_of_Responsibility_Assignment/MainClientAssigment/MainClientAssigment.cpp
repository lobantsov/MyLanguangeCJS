#pragma once
#include "MainClientAssigment.h"
#include "../../../LexAnalizator/LexAnalizator.h"

MainClientAssigment::MainClientAssigment()
{
    incrementa_client = new Incrementa_Client();
    logic_client = new Logic_Client();
    math_client = new Math_Client();
    initialization_handler = new Initialization_Handler();
    end_handler=new End_Handler();
    array_assingment_handler = new ArrayAssingment_Handler();
    array_assingment_handler->SetNext(math_client)->SetNext(incrementa_client)->SetNext(logic_client);
}

bool MainClientAssigment::CheckAssigment(Lex Type, bool endSigntStatus)
{
    singletone_currentposition->currentPosition_backup=singletone_currentposition->currentPosition;
    bool a = array_assingment_handler->Handle(Type);
    if(a)
    {
        //singletone_currentposition->currentPosition++;
        if(endSigntStatus)
        {
            if(end_handler->Handle(Type))
            {
                return true;
            }
            else
            {
                //missing ;
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        singletone_currentposition->currentPosition = singletone_currentposition->currentPosition_backup;
        return false;
    }
}
