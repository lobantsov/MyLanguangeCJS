
#ifndef IHANDLER_H
#define IHANDLER_H

#pragma once
#include <string>
#include "../../Singletone/SingletoneCurrentposition.h"
#include "../../SpawnErrors/ClassForCreateErorrs.h"
#include "../SingletoneDeclaretedVariables/DeclareredVariables.h"
using namespace std;
class IHandler
{
public:
    virtual IHandler *SetNext(IHandler *handler) = 0;
    virtual bool Handle(Lex TypeID) = 0;
    ClassForCreateErorrs *create_erorrs = ClassForCreateErorrs::GetInstance();
    DeclareredVariables *declarered_variables_ = DeclareredVariables::GetInstance();
};




#endif //IHANDLER_H
