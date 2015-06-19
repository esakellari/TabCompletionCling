#include <iostream>
#include "clang/Sema/CodeCompleteConsumer.h"
#include "clang/Sema/CodeCompleteOptions.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/Allocator.h"

class Completer : public clang::PrintingCodeCompleteConsumer {

	cling::Transaction *T;

	public:
	 Completer(const CodeCompleteOptions &CodeCompleteOpts, cling::Transaction &T):PrintingCodeCompleteConsumer(CodeCompleteOpts,llvm::outs()){
		 cling::Transaction *T = 0;
	 }

	void callBack(){
		T->setIssuedDiags()
	}

};
