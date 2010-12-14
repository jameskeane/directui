
!IFNDEF PLATFORM
PLATFORM=x86
!ENDIF

all: $(PLATFORM)
	
x86: main.cpp 
	cl main.cpp /I../../include /Zc:wchar_t- /link "..\..\lib\dui70_32.lib" /machine:x86

x64: main.cpp
	cl main.cpp /I../../include /Zc:wchar_t- /link "..\..\lib\dui70_64.lib" /machine:x64
