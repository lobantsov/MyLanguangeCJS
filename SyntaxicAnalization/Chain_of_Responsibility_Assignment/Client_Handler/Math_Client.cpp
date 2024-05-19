#pragma once
#include "Math_Client.h"
#include "../../../LexAnalizator/LexAnalizator.h"

Math_Client::Math_Client()
{
    check_const_handler = new CheckConst_Handler();
    check_var_handler = new CheckVar_Handler();
    eaqual_handler = new Equal_Handler();
    math_operators_handler = new MathOperators_Handler();
    end_handler = new End_Handler();
    array_check_handler = new ArrayCheck_Handler();
    check_var_handler->SetNext(check_const_handler)->SetNext(array_check_handler)->SetNext(math_operators_handler)->SetNext(end_handler);
}

bool Math_Client::Handle(Lex Type)
{
    if(eaqual_handler->Handle(Type) && !singletone_currentposition->isLogicOperator)
    {
        while(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID!=0)
        {
            if(check_var_handler->Handle(Type))
            {
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
                {
                    return true;
                }
            }
            if(create_erorrs->error_status)
                return false;
        }
    }
    return AbstractHandler_Assigment::Handle(Type);
}