#pragma once
#include "ClassForCreateErorrs.h"
#include "../LexAnalizator/LexAnalizator.h"
#include "iostream"
#include "vector"
#include <windows.h>

ClassForCreateErorrs* ClassForCreateErorrs::create_erorrs_= nullptr;;

ClassForCreateErorrs *ClassForCreateErorrs::GetInstance()
{
    if(create_erorrs_==nullptr){
        create_erorrs_ = new ClassForCreateErorrs();
    }
    return create_erorrs_;
}

void ClassForCreateErorrs::CreateSyntaxError()
{
    error_status=true;
    const HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_INTENSITY);

    std::cout<<"Syntax error"<<'\n';
    std::cout << "The reason: '" << LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value <<
        "' is not recognized as the name of a statement, function, or other part of a program" << '\n';
    std::cout << "Check the spelling of the code and try again" << '\n';
    std::cout << "Line error: " << LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexLine << '\n';

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        
    MessageBox(NULL, LPCSTR(L"An error was detected in the code"), LPCSTR(L"Error"), MB_OK | MB_ICONERROR);
}

void ClassForCreateErorrs::CreateDeclarationError()
{
    error_status=true;
    const HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_INTENSITY);

    std::cout<<"Declaration Error"<<'\n';
    std::cout << "The reason: '" << LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value <<
        "' an error was found when compiling the program in the variable declaration" << '\n';
    std::cout << "Check the spelling of the code and try again" << '\n';
    std::cout << "Line error: " << LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexLine << '\n';

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        
    MessageBox(NULL, LPCSTR(L"An error was detected in the code"), LPCSTR(L"Error"), MB_OK | MB_ICONERROR);
}

void ClassForCreateErorrs::CreateTypeMismatchError()
{
    error_status = true;
    const HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_INTENSITY);

    std::cout << "Type Mismatch Error" << '\n';
    std::cout << "The reason: incorrect data assignment when using the READ operation";

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

    MessageBox(NULL, LPCSTR(L"An error was detected in the code"), LPCSTR(L"Error"), MB_OK | MB_ICONERROR);
}