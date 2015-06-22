#include <iostream>
#include "clang/Sema/CodeCompleteConsumer.h"
#include "clang/Sema/CodeCompleteOptions.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/Allocator.h"
#include "cling/Interpreter/Transaction.h"

class Completer : public clang::PrintingCodeCompleteConsumer {


public:
Completer(const CodeCompleteOptions &CodeCompleteOpts):PrintingCodeCompleteConsumer(CodeCompleteOpts,llvm::outs()){}

  void callBack(cling::Transaction **T){
    
    //cling::Transaction diags;
    cling::Transaction::IssuedDiags diags;
    diags = (*T)->getIssuedDiags();
    
           //   T->setIssuedDiags()
  }

};
