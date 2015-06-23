#include <iostream>
#include "cling/Interpreter/Interpreter.h"
#include "cling/Interpreter/Value.h"

#include "clang/Frontend/CompilerInstance.h"
#include "clang/Basic/LangOptions.h"
#include "clang/Lex/Preprocessor.h"

#include "clang/Parse/RAIIObjectsForParser.h"
#include "clang/Sema/CodeCompleteConsumer.h"
#include "clang/Sema/CodeCompleteOptions.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/Allocator.h"
#include "cling/Interpreter/Transaction.h"
#include "clang/Sema/Sema.h"

class Completer : public clang::PrintingCodeCompleteConsumer {

  cling::Transaction *T;
public:
  
  Completer(const CodeCompleteOptions &CodeCompleteOpts):PrintingCodeCompleteConsumer(CodeCompleteOpts,llvm::outs()){}
  void setTransaction(cling::Transaction *tr){
    T = tr;
  }
  
  void ProcessCodeCompleteResults(clang::Sema &S, clang::CodeCompletionContext Context,
                                  clang::CodeCompletionResult *Results,
                                  unsigned NumResults);

};

void Completer::ProcessCodeCompleteResults(clang::Sema &S, clang::CodeCompletionContext Context,clang::CodeCompletionResult *Results, unsigned NumResults){
  clang::PrintingCodeCompleteConsumer::ProcessCodeCompleteResults(S, Context, Results, NumResults);

}