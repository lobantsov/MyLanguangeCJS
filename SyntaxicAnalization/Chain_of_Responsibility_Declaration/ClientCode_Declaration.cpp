#pragma once
#include "ClientCode_Declaration.h"

ClientCode_Declaration::ClientCode_Declaration()
{
    variable_handler=new VariableHandler();
    eaqual_handler=new EaqualHandler();
    enumeration_handler=new EnumerationHandler();
    variable_handler->SetNext(eaqual_handler)->SetNext(enumeration_handler);
}

bool ClientCode_Declaration::CheckDataType(Lex TypeID)
{
    if(variable_handler->Handle(TypeID))
        return true;
    return false;
}
