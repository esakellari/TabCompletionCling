CXXFLAGS := $(shell llvm-config --cxxflags) -Wall
LDFLAGS := $(shell llvm-config --ldflags)
# To make binary symbols available to the interpreter:
LDFLAGS += -Wl,--export-dynamic 
SYSLIBS := $(shell llvm-config --system-libs)
LLVMRESDIR := $(shell llvm-config --prefix)
LIBS := -lclingInterpreter -lclingUtils -lclangFrontend -lclangSerialization -lclangDriver -lclangCodeGen -lclangParse -lclangSema -lclangEdit -lclangAnalysis -lclangAST -lclangLex -lclangBasic $(shell llvm-config --libs bitwriter mcjit orcjit native option ipo profiledata instrumentation objcarcopts) $(SYSLIBS)

codecompletion: cling-demo.cxx
	$(CXX) -o $@ '-DLLVMRESDIR="$(LLVMRESDIR)"' $(CXXFLAGS) $^ $(LDFLAGS) $(LIBS)

clean:
	rm -f codecompletion
