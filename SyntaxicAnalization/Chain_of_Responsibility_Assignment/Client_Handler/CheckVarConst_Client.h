//
// Created by loban on 5/18/2024.
//

#ifndef CHECKVARCONST_CLIENT_H
#define CHECKVARCONST_CLIENT_H

#pragma once
#include "../CheckConst_Handler.h"
#include "../CheckVar_Handler.h"

class CheckVarConst_Client
{
public:
    CheckVarConst_Client();
    bool Check_var_const(Lex Type);
    CheckConst_Handler* check_const_handler;
    CheckVar_Handler* check_var_handler;
};




#endif //CHECKVARCONST_CLIENT_H
