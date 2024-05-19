#pragma once
#include "CheckVarConst_Client.h"
CheckVarConst_Client::CheckVarConst_Client()
{
    check_const_handler = new CheckConst_Handler();
    check_var_handler = new CheckVar_Handler();
    check_const_handler->SetNext(check_var_handler);
}

bool CheckVarConst_Client::Check_var_const(Lex Type)
{
    if(check_const_handler->Handle(Type))
        return true;
    return false;

}
