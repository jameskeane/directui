all: dui70_32.lib dui70_64.lib

dui70_32.lib: lib/dui70_32.def
	LIB /DEF:lib/dui70_32.def /OUT:lib/dui70_32.lib /MACHINE:x86 /NOLOGO

dui70_64.lib: lib/dui70_64.def
	LIB /DEF:lib/dui70_64.def /OUT:lib/dui70_64.lib /MACHINE:x64 /NOLOGO