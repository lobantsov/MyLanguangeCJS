#pragma once
#include <chrono>

#include "Interpritator/Code_execution.h"
#include "LexAnalizator/LexAnalizator.h"
#include "SyntaxicAnalization/SynAnalizator.h"
#include <iostream>

int main() {
  string command;
  ClassForCreateErorrs *create_erorrs = ClassForCreateErorrs::GetInstance();
  SingletoneCurrentposition *aa = SingletoneCurrentposition::GetInstance();
  DeclareredVariables *declarered_variables_ =
      DeclareredVariables::GetInstance();
  Code_execution *code_execution = new Code_execution();

  LexAnalizator *analizator = new LexAnalizator();
  string path[] = {
      // "C:\\Users\\loban\\OneDrive\\Desktop\\declaratoion.txt",
      // "C:\\Users\\loban\\OneDrive\\Desktop\\DoWhileOperator.txt",
      // "C:\\Users\\loban\\OneDrive\\Desktop\\ForOperator.txt",
      // "C:\\Users\\loban\\OneDrive\\Desktop\\Foreach.txt",
      // "C:\\Users\\loban\\OneDrive\\Desktop\\Assigment.txt",
      // "C:\\Users\\loban\\OneDrive\\Desktop\\if.txt",
       //"D:\\VSJ\\MyLanguageCJS\\Testing and project plan\\testing\\IfElse.txt",
      // "C:\\Users\\loban\\OneDrive\\Desktop\\WhileOperator.txt",
      // "C:\\Users\\loban\\OneDrive\\Desktop\\write.txt",
      // "C:\\Users\\loban\\OneDrive\\Desktop\\read.txt",
      // "C:\\Users\\loban\\OneDrive\\Desktop\\13.txt",
    "D:\\VSJ\\MyLanguageCJS\\Testing and project plan\\testing\\Test1.txt"
    //"D:\\VSJ\\MyLanguageCJS\\Testing and project plan\\testing\\13.txt"
      // "C:\\Users\\loban\\OneDrive\\Desktop\\Test3.txt",
      //   "C:\\Users\\loban\\OneDrive\\Desktop\\Test4.txt"
  };

  // analizator->Print();

  for (const string &a : path) {
    analizator->readCode(a);

    SynAnalizator *syn_analizator = new SynAnalizator();

    cout << "Do check- " << a << endl;
    if (syn_analizator->MainCheck()) {
      while (SingletoneCurrentposition::currentPosition <
             LexAnalizator::FinalLexConfig.size()) {
        if (syn_analizator->OperatorCheck(true)) {
          // start timer
          auto start = chrono::high_resolution_clock::now();

          code_execution->Execution();

          // end timer
          auto end = chrono::high_resolution_clock::now();
          auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

          cout << a << " - checked in " << duration << " seconds" << endl;
          break;
          cout << a << "- checked" << endl;
          break;
        }
        if (create_erorrs->error_status) {
          cout << "Error hear:" << a << endl;
          break;
        }
      }
    }
    cout << endl;
    LexAnalizator::FinalLexConfig.clear();
    aa->currentPosition = 0;
    declarered_variables_->CreatedLexemus.clear();
    create_erorrs->error_status = false;
  }
}