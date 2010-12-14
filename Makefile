


CC = cl
CFLAGS = 


all: x86 x64

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
	
# Cleaning up
#=======================================
clean: clean_lib clean_util

clean_lib:
	rm -f lib/dui70_32.lib
	rm -f lib/dui70_32.exp
	rm -f lib/dui70_64.lib
	rm -f lib/dui70_64.exp

clean_util:
	rm -f util/demangler.exe
	rm -f util/demangler.obj
	