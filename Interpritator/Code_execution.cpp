#pragma once
#include "Code_execution.h"

#include <iostream>
#include <sstream>
#include "../LexAnalizator/LexAnalizator.h"

void Code_execution::Execution() {
    source_string_stack = inverse_writing->FormingSourceLine();
    EaserMyLive();
    while (source_string_stack.size() != iterator) {
        Lex &lex = source_string_stack[iterator];
        int constantID = LexAnalizator::SingleLexConfig.size() + LexAnalizator::MultiplyLexConfig.size() + 1;
        int variableID = LexAnalizator::SingleLexConfig.size() + LexAnalizator::MultiplyLexConfig.size() + 2;

        if (lex.lexID == constantID or lex.lexID == variableID) {
            tmp_stack.push(lex);
            //operators
        } else if (class_for_methood_container_->isOperation(lex.value)) {
            //=
            if (lex.value == "=") {
                Lex tmp1, tmp2;
                tmp1 = tmp_stack.top();
                tmp_stack.pop();
                tmp2 = tmp_stack.top();
                tmp_stack.pop();
                EqualExecute(tmp2, tmp1);
                //+ - / * += -= *= /=
            } else if (class_for_methood_container_->IsMathOperatorWhitoutIncrement(lex)) {
                Lex tmp1, tmp2;
                tmp1 = tmp_stack.top();
                tmp_stack.pop();
                tmp2 = tmp_stack.top();
                tmp_stack.pop();
                tmp_stack.push(MathOperators(lex, tmp2, tmp1));
            }
            //++ -- **
            else if (class_for_methood_container_->IsIncrementa(lex)) {
                Incrementa(lex, tmp_stack.top());
                tmp_stack.pop();
            }
            // < > <= >= == !=
            else if (class_for_methood_container_->IsLogicOperator(lex)) {
                Lex tmp1, tmp2;
                tmp1 = tmp_stack.top();
                tmp_stack.pop();
                tmp2 = tmp_stack.top();
                tmp_stack.pop();
                tmp_stack.push(CheckLogicSentence(lex, tmp2, tmp1));
            } else if (lex.value == "write") {
                Write(tmp_stack.top());
                tmp_stack.pop();
            } else if (lex.value == "read") {
                Read(tmp_stack.top());
                tmp_stack.pop();
            }
        }


        iterator++;
    }
}

void Code_execution::EqualExecute(Lex tmp2, Lex tmp1) {
    // for (Lex &op: declarered_variables_->CreatedLexemus) {
    //     if (tmp2.value == op.value) {
    //         op.data = tmp1.data;
    //         break;
    //     }
    // }

    for (int i = 0; i < source_string_stack.size(); i++) {
        if (source_string_stack[i].value == tmp2.value)
            source_string_stack[i].data = tmp1.data;
    }
}

Lex Code_execution::MathOperators(Lex operator_, Lex tmp2, Lex tmp1) {
    Lex result;

    if (operator_.value == "+") {
        result = tmp1 + tmp2;
    } else if (operator_.value == "-") {
        result = tmp1 - tmp2;
    } else if (operator_.value == "*") {
        result = tmp1 * tmp2;
    } else if (operator_.value == "/") {
        result = tmp1 / tmp2;
    } else if (operator_.value == "+=") {
        tmp1 += tmp2;
        result = tmp1;
    } else if (operator_.value == "-=") {
        tmp1 -= tmp2;
        result = tmp1;
    } else if (operator_.value == "/=") {
        tmp1 /= tmp2;
        result = tmp1;
    } else if (operator_.value == "*=") {
        tmp1 *= tmp2;
        result = tmp1;
    }

    result.value = result.toString();
    result.lexID = 202;
    result.lexLine = operator_.lexLine;
    return result;
}

Lex Code_execution::CheckLogicSentence(Lex operator_, Lex tmp1, Lex tmp2) {
    Lex result;

    if (operator_.value == "==") {
        result.data = tmp1.equals(tmp2);
    } else if (operator_.value == "<=") {
        result.data = tmp1 <= tmp2;
    } else if (operator_.value == "<") {
        result.data = tmp1 < tmp2;
    } else if (operator_.value == ">=") {
        result.data = tmp1 >= tmp2;
    } else if (operator_.value == ">") {
        result.data = tmp1 > tmp2;
    } else if (operator_.value == "!=") {
        result.data = tmp1 != tmp2;
    }

    result.value = result.toString();
    result.lexID = 202;
    result.lexLine = operator_.lexLine;
    return result;
}

void Code_execution::Incrementa(Lex operator_, Lex var) {
    Lex tmp;
    tmp.data = 1.0;
    if (operator_.value == "++") {
        var += tmp;
    } else if (operator_.value == "--") {
        var -= tmp;
    } else if (operator_.value == "**") {
        var *= var;
    }
    for (int i = 0; i < source_string_stack.size(); i++) {
        if (source_string_stack[i].value == var.value)
            source_string_stack[i].data = var.data;
    }
}

void Code_execution::Write(Lex var) {
    std::cout << var;
}

void Code_execution::Read(Lex var) {
    std::string line;
    std::cin >> line;

    switch (var.dataTypeID) {
        case 35: // int
            try {
                var.data = std::stoi(line);
            } catch (const std::invalid_argument &e) {
                class_for_create_erorrs_->CreateTypeMismatchError();
            }
            break;
        case 36: // float
            try {
                var.data = std::stof(line);
            } catch (const std::invalid_argument &e) {
                class_for_create_erorrs_->CreateTypeMismatchError();
            }
            break;
        case 37: // double
            try {
                var.data = std::stod(line);
            } catch (const std::invalid_argument &e) {
                class_for_create_erorrs_->CreateTypeMismatchError();
            }
            break;
        case 38: // string
            var.data = line;
            break;
        case 39: // char
            try {
                if (line.length() == 1) {
                    var.data = line[0];
                } else {
                    throw std::invalid_argument("Invalid input for char type");
                }
            } catch (const std::invalid_argument &e) {
                class_for_create_erorrs_->CreateTypeMismatchError();
            }
            break;
        default:
            class_for_create_erorrs_->CreateTypeMismatchError();
    }
    UpdataVariableData(var);
}

void Code_execution::EaserMyLive() {
    for (Lex &a: source_string_stack) {
        if (a.lexID == LexAnalizator::SingleLexConfig.size() + LexAnalizator::MultiplyLexConfig.size() + 2) {
            switch (a.dataTypeID) {
                case 341:
                    if (a.value == "true") a.data = true;
                    else if (a.value == "false") a.data = false;
                    break;
                case 351:
                case 361:
                    a.data = stringToNumber(a.value);
                    break;
                case 381:
                    a.data = a.value;
                    break;
                case 391: a.data = a.value[0];
                    break;
            }
        }
    }
    for (int i = 0; i < source_string_stack.size(); i++) {
        for (int k = 0; k < declarered_variables_->CreatedLexemus.size(); k++) {
            if (source_string_stack[i].value == declarered_variables_->CreatedLexemus[k].value) {
                source_string_stack[i].dataTypeID = declarered_variables_->CreatedLexemus[k].dataTypeID;
            }
        }
    }
}

void Code_execution::UpdataVariableData(Lex lex) {
    for (Lex& line1: source_string_stack) {
        if(line1.value == lex.value) {
            line1.data = lex.data;
        }
    }
}

std::variant<std::string, bool, char, double, int> Code_execution::stringToNumber(const std::string &str) {
    std::stringstream ss(str);
    double number;
    ss >> number;
    if (ss.fail() || !ss.eof()) {
        throw std::invalid_argument("Invalid input string");
    }
    return number;
}