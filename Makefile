


CC = cl
CFLAGS = 


all: x86 x64 samples test

# How to build the libraries
#=======================================
x86: lib/dui70_32.def util
	LIB /DEF:lib/dui70_32.def /OUT:lib/dui70_32.lib /MACHINE:x86 /NOLOGO

x64: lib/dui70_64.def util
	LIB /DEF:lib/dui70_64.def /OUT:lib/dui70_64.lib /MACHINE:x64 /NOLOGO
	
	
# How to build the utilities
#=======================================
util: demangler

demangler: util/demangler.cpp
	$(CC) util/demangler.cpp  /Feutil/demangler.exe /Foutil/demangler.obj
	
# How to build the samples
#=======================================
samples: x86 x64
	cd samples && $(MAKE) all && cd ..

	
# How to build the tests
#=======================================
test: x86 x64
	cd test && $(MAKE) all && cd ..

# Cleaning up
#=======================================
clean: clean_lib clean_util clean_samples clean_test

clean_lib:
	rm -f lib/dui70_32.lib
	rm -f lib/dui70_32.exp
	rm -f lib/dui70_64.lib
	rm -f lib/dui70_64.exp

clean_util:
	rm -f util/demangler.exe
	rm -f util/demangler.obj
	
clean_samples:
	cd samples && $(MAKE) clean && cd ..
	
clean_test:
	cd test && $(MAKE) clean && cd ..
	