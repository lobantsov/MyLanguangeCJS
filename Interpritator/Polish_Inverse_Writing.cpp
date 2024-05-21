#pragma once
#include "Polish_Inverse_Writing.h"
#include "../LexAnalizator/LexAnalizator.h"

std::vector<Lex> Polish_Inverse_Writing::FormingSourceLine() {
    strainer->groupQuotedLexemes();
    while (iterator < LexAnalizator::FinalLexConfig.size() - 1) {
        Lex &lex = LexAnalizator::FinalLexConfig[iterator];
        int constantID = LexAnalizator::SingleLexConfig.size() +
                         LexAnalizator::MultiplyLexConfig.size() + 1;
        int variableID = LexAnalizator::SingleLexConfig.size() +
                         LexAnalizator::MultiplyLexConfig.size() + 2;

        bool isOperatorBefore =
                (iterator > 0) &&
                class_for_methood_container_->isOperation(
                    LexAnalizator::FinalLexConfig[iterator - 1].value);
        bool isOperatorAfter =
                (iterator + 1 < LexAnalizator::FinalLexConfig.size()) &&
                (class_for_methood_container_->isOperation(
                     LexAnalizator::FinalLexConfig[iterator + 1].value) ||
                 LexAnalizator::FinalLexConfig[iterator + 1].value == ")");

        if ((lex.lexID == constantID || lex.lexID == variableID) &&
            (isOperatorBefore || isOperatorAfter)) {
            if (!callBack.empty() and callBack.top() == "for" and
                (source_string_stack.size() > 2 and
                 class_for_methood_container_->IsLogicOperator(
                     source_string_stack[source_string_stack.size() - 2])) and
                forOperator) {
                tmpVectorForMovingSomeOperators.push(CreateNewComand("Move"));
                tmpVectorForMovingSomeOperators.push(lex);
                addingIntoTmpIncrementaStack++;
                forOperator = false;
            } else {
                source_string_stack.push_back(lex);
            }
        } else if (lex.value == "(") {
            stack_tmp.push(lex);
            if (!callBack.empty() and callBack.top() == "while" or
                callBack.top() == "if") {
                CurrentMetka++;
                vector_of_metkes.push_back(-1);
                vector_of_metkes[CurrentMetka] = source_string_stack.size();
            } else if (!callBack.empty() and callBack.top() == "do_while") {
                tmpMetkaForDoWhile = source_string_stack.size();
            }
        } else if (lex.value == "{") {
            stack_tmp.push(lex);
        }
        // operators
        else if (class_for_methood_container_->isOperation(lex.value)) {
            // math and logic operators
            if (class_for_methood_container_->IsLogicOperator(lex) or
                class_for_methood_container_->IsMathOperator(lex) or
                lex.value == "=") {
                set_right_place_into_source_line_for_math_operators(lex);
            }
            // check write operator
            else if (lex.value == "write") {
                // skip ( and write
                iterator++;
                iterator++;
                // string or char data type
                if (LexAnalizator::FinalLexConfig[iterator].dataTypeID == 381 or
                    LexAnalizator::FinalLexConfig[iterator].dataTypeID == 391) {
                    // create new lex without " "
                    Lex tmp;
                    tmp.value = class_for_methood_container_->ExecuteStringSyntaxic(
                        LexAnalizator::FinalLexConfig[iterator].value);
                    tmp.lexLine = LexAnalizator::FinalLexConfig[iterator].lexLine;
                    tmp.dataTypeID = LexAnalizator::FinalLexConfig[iterator].dataTypeID;
                    tmp.lexID = LexAnalizator::SingleLexConfig.size() +
                                LexAnalizator::MultiplyLexConfig.size() + 2;
                    source_string_stack.push_back(tmp);
                    source_string_stack.push_back(lex);

                    // skip )
                    iterator++;
                } else {
                    source_string_stack.push_back(
                        LexAnalizator::FinalLexConfig[iterator]);
                    source_string_stack.push_back(lex);

                    // skip )
                    iterator++;
                }
            }
            // check read
            else if (lex.value == "read") {
                // skip ( and write
                iterator++;
                iterator++;

                source_string_stack.push_back(LexAnalizator::FinalLexConfig[iterator]);
                source_string_stack.push_back(lex);

                // skip )
                iterator++;
            }
            // loop
            else if (lex.value == "for" or lex.value == "while" or
                     lex.value == "do_while") {
                callBack.push(lex.value);
                stack_tmp.push(lex);
                access = true;
            } else if (lex.value == "if" or lex.value == "else") {
                if(lex.value=="if" and arrayOfMarkersAndCommandForIF[0]!=0) {
                    stack_of_array_of_markers_and_command_for_IF.push(arrayOfMarkersAndCommandForIF);
                }
                stack_tmp.push(lex);
                callBack.push(lex.value);
                if (lex.value == "else") {
                    arrayOfMarkersAndCommandForIF[2] = source_string_stack.size();
                }
            }
        } else if (lex.value == ")") {
            while (stack_tmp.top().value != "(") {
                source_string_stack.push_back(stack_tmp.top());
                stack_tmp.pop();
            }
            if (mathOperatorPushBack != 0 and
                class_for_methood_container_->IsLogicOperator(
                    source_string_stack[source_string_stack.size() - 1]))
                mathOperatorPushBack = 0;
            if (callBack.top() == "while") {
                source_string_stack.push_back(CreateNewComand("Condition"));
                Comamnds.push(source_string_stack[source_string_stack.size() - 1]);

                CurrentMetka++;
                vector_of_metkes.push_back(-1);
                vector_of_metkes[CurrentMetka] = -1;
            } else if (callBack.top() == "do_while") {
                Lex tmp = CreateNewComand("Condition");
                tmp.IndexOfMarkIntoMarkVectorFOR_COMMAND_MOVE = tmpMetkaForDoWhile;
                tmpVectorForMovingSomeOperators.push(tmp);
                //Comamnds.push(source_string_stack[source_string_stack.size() - 1]);
            } else if (callBack.top() == "if") {
                source_string_stack.push_back(CreateNewComand("Condition"));
                //save_commandIF
                arrayOfMarkersAndCommandForIF[0] = source_string_stack.size() - 1;
            }
            stack_tmp.pop();
        } else if (lex.value == "}") {
            while (stack_tmp.top().value != "{") {
                stack_tmp.pop();
            }
            stack_tmp.pop();

            // for while
            if (!callBack.empty() and callBack.top() == "while") {
                source_string_stack.push_back(CreateNewComand("Move"));
                int tmpIndex = FindMarkIndex(-1, true);
                source_string_stack[source_string_stack.size() - 1]
                        .IndexOfMarkIntoMarkVectorFOR_COMMAND_MOVE = vector_of_metkes[tmpIndex];
                vector_of_metkes[tmpIndex] *= -1;
                vector_of_metkes[tmpIndex + 1] = source_string_stack.size();
            } else if (!callBack.empty() and callBack.top() == "do_while") {
                tmpVectorForMovingSomeOperators.top().IndexOfMarkIntoMarkVectorFOR_COMMAND_IF =
                        source_string_stack.size() + 1;
                source_string_stack.push_back(tmpVectorForMovingSomeOperators.top());
                tmpVectorForMovingSomeOperators.pop();
            } else if (!callBack.empty() and callBack.top() == "if") {
                source_string_stack.push_back(CreateNewComand("Move"));
                arrayOfMarkersAndCommandForIF[1] = source_string_stack.size() - 1;
                if (LexAnalizator::FinalLexConfig[iterator + 1].value != "else") {
                    arrayOfMarkersAndCommandForIF[2] = source_string_stack.size();
                    arrayOfMarkersAndCommandForIF[3] = source_string_stack.size();
                   DoWithIF();
                }
            } else if (!callBack.empty() and callBack.top() == "else") {
                arrayOfMarkersAndCommandForIF[3]=source_string_stack.size();
                DoWithIF();
            } else if (callBack.top() == "for") {
                // for for
                for (int i = 0; i < 3; i++) {
                    source_string_stack.push_back(tmpVectorForMovingSomeOperators.top());
                    tmpVectorForMovingSomeOperators.pop();
                    addingIntoTmpIncrementaStack--;
                }
                int tmpIndex = FindMarkIndex(-1, true);
                source_string_stack[source_string_stack.size() - 1]
                        .IndexOfMarkIntoMarkVectorFOR_COMMAND_MOVE = vector_of_metkes[tmpIndex];
                vector_of_metkes[tmpIndex] *= -1;
                vector_of_metkes[tmpIndex + 1] = source_string_stack.size();
            }

            stack_tmp.pop();
            callBack.pop();
        } else if (lex.value == ";") {
            // check math singt
            if (mathOperatorPushBack > 0) {
                while (mathOperatorPushBack != 0) {
                    source_string_stack.push_back(stack_tmp.top());
                    stack_tmp.pop();
                    mathOperatorPushBack--;
                }
            }
            // check callBack
            if (!callBack.empty()) {
                if (callBack.top() == "for") {
                    // check i<10
                    if (access) {
                        CurrentMetka++;
                        vector_of_metkes.push_back(-1);
                        vector_of_metkes[CurrentMetka] = source_string_stack.size();
                        access = false;
                        forOperator = true;
                    }
                    if (class_for_methood_container_->IsLogicOperator(
                        source_string_stack[source_string_stack.size() - 1])) {
                        source_string_stack.push_back(CreateNewComand("Condition"));
                        Comamnds.push(source_string_stack[source_string_stack.size() - 1]);

                        CurrentMetka++;
                        vector_of_metkes.push_back(-1);
                        vector_of_metkes[CurrentMetka] = -1;
                    }
                    // check and add to tmp stack i++
                    else if (class_for_methood_container_->IsMathOperator(
                        source_string_stack[source_string_stack.size() - 1])) {
                        Lex tmp = tmpVectorForMovingSomeOperators.top();
                        tmpVectorForMovingSomeOperators.pop();
                        tmpVectorForMovingSomeOperators.push(
                            source_string_stack[source_string_stack.size() - 1]);
                        source_string_stack.pop_back();
                        tmpVectorForMovingSomeOperators.push(tmp);
                        addingIntoTmpIncrementaStack++;
                        addingIntoTmpIncrementaStack++;
                    }
                }
            }
        }
        iterator++;
    }

    while (!Comamnds.empty()) {
        int tmp = FindMarkIndex(-1, false);
        vector_of_metkes[tmp] *= -1;
        SetValue(vector_of_metkes[tmp], vector_of_metkes[tmp + 1]);
        Comamnds.pop();
    }

    return source_string_stack;
}


int Polish_Inverse_Writing::getPriority(const std::string &op) {
    if (op == "=" || op == "+=" || op == "-=" || op == "*=" || op == "/=")
        return 1; // Присвоєння
    if (op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==" ||
        op == "!=")
        return 4; // Порівняння
    if (op == "+" || op == "-")
        return 5; // Додавання та віднімання
    if (op == "*" || op == "/")
        return 6; // Множення та ділення
    if (op == "++" || op == "--" || op == "**")
        return 7; // Інкремент, декремент, степінь
    if (op == "(" || op == "{" || op == ")" || op == "}")
        return -1; // Дужки
    return 0; // За замовчуванням
}

void Polish_Inverse_Writing::
set_right_place_into_source_line_for_math_operators(const Lex &op) {
    int priority = getPriority(op.value);

    while (!stack_tmp.empty() && getPriority(stack_tmp.top().value) >= priority) {
        source_string_stack.push_back(stack_tmp.top());
        stack_tmp.pop();
        mathOperatorPushBack--;
    }
    stack_tmp.push(op);
    mathOperatorPushBack++;
}

Lex Polish_Inverse_Writing::CreateNewComand(const std::string &typeComand) {
    Lex tmp;
    if (typeComand == "Condition") {
        tmp.value = "Command_if";
        tmp.lexID = 200;
    } else if (typeComand == "Move") {
        tmp.value = "Command_move";
        tmp.lexID = 201;
    }
    return tmp;
}

int Polish_Inverse_Writing::FindMarkIndex(int iteratorValue, bool swithwer) {
    int iterator = iteratorValue;
    int a = vector_of_metkes[CurrentMetka + iterator];
    if (swithwer) {
        if (iterator == -1) {
            while (a < 0) {
                iterator -= 2;
                a = vector_of_metkes[CurrentMetka + iterator];
            }
        } else if (iterator == 0) {
            while (a != -1) {
                iterator -= 2;
                a = vector_of_metkes[CurrentMetka + iterator];
            }
        }
        return CurrentMetka + iterator;
    } else {
        if (iterator == -1) {
            while (a > 0) {
                iterator -= 2;
                a = vector_of_metkes[CurrentMetka + iterator];
            }
        }
        return CurrentMetka + iterator;
    }
}

void Polish_Inverse_Writing::SetValue(int equeal, int border) {
    for (int i = equeal; i < border; i++) {
        if (source_string_stack[i].IndexOfMarkIntoMarkVectorFOR_COMMAND_IF == -1 and
            source_string_stack[i].IndexOfMarkIntoMarkVectorFOR_COMMAND_MOVE == -1 and
            source_string_stack[i].lexID == 200) {
            source_string_stack[i].IndexOfMarkIntoMarkVectorFOR_COMMAND_IF = border;
            break;
        }
    }
}

void Polish_Inverse_Writing::DoWithIF() {
    source_string_stack[arrayOfMarkersAndCommandForIF[0]].IndexOfMarkIntoMarkVectorFOR_COMMAND_IF = arrayOfMarkersAndCommandForIF[2];
    source_string_stack[arrayOfMarkersAndCommandForIF[1]].IndexOfMarkIntoMarkVectorFOR_COMMAND_MOVE = arrayOfMarkersAndCommandForIF[3];
    arrayOfMarkersAndCommandForIF[0]=0;
    arrayOfMarkersAndCommandForIF[1]=0;
    arrayOfMarkersAndCommandForIF[2]=0;
    arrayOfMarkersAndCommandForIF[3]=0;
    if(!stack_of_array_of_markers_and_command_for_IF.empty()) {
        arrayOfMarkersAndCommandForIF = stack_of_array_of_markers_and_command_for_IF.top();
        stack_of_array_of_markers_and_command_for_IF.pop();
    }
}