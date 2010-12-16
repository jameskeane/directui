
!IFNDEF PLATFORM
PLATFORM=x86
!ENDIF

all: $(PLATFORM)
	
x86: main.cpp 
	cl main.cpp /I../../include /EHsc /Zc:wchar_t- /link "..\..\lib\dui70_32.lib" /machine:x86 /out:helloworld.exe

x64: main.cpp
	cl main.cpp /I../../include /EHsc /Zc:wchar_t- /link "..\..\lib\dui70_64.lib" /machine:x64 /out:helloworld.exe

clean:
	rm -f helloworld.exe
	rm -f main.obj