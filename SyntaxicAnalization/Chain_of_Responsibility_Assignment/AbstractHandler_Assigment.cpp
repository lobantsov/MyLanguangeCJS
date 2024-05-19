#pragma once
#include "AbstractHandler_Assigment.h"
IHandler_assigment* AbstractHandler_Assigment::SetNext(IHandler_assigment* handler)
{
    this->next_handler_ = handler;
    return handler;
}

bool AbstractHandler_Assigment::Handle(Lex Type)
{
    if (this->next_handler_)
    {
        return this->next_handler_->Handle(Type);
    }
    return false;
}
