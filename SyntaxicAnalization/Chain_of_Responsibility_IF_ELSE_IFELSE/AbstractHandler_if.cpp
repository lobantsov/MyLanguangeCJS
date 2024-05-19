#pragma once
#include "AbstractHandler_if.h"
IHandler_if* AbstractHandler_if::SetNext(IHandler_if* handler)
{
    this->next_handler_ = handler;
    return handler;
}

bool AbstractHandler_if::Handle()
{
    if (this->next_handler_)
    {
        return this->next_handler_->Handle();
    }
    return {};
}
