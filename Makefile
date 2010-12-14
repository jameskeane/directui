
all: dui70_32.lib dui70_64.lib



# How to build the libraries
#=======================================
dui70_32.lib: lib/dui70_32.def
	LIB /DEF:lib/dui70_32.def /OUT:lib/dui70_32.lib /MACHINE:x86 /NOLOGO

dui70_64.lib: lib/dui70_64.def
	LIB /DEF:lib/dui70_64.def /OUT:lib/dui70_64.lib /MACHINE:x64 /NOLOGO
	
	
# Cleaning up
#=======================================
clean: clean_lib

clean_lib:
	rm -f lib/dui70_32.lib
	rm -f lib/dui70_32.exp
	rm -f lib/dui70_64.lib
	rm -f lib/dui70_64.exp
	
	