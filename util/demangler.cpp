// demangler.cpp : Demangles decorated VC++ export using UnDecorateSymbolName
//

#include <stdio.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#pragma comment(lib, "Dbghelp.lib")
#include <dbghelp.h>

int main(int argc, char* argv[])
{
	if( argc != 2 )
	{
		printf("usage: demangler <file>\n");
		return -1;
	}

	FILE *file = fopen(argv[1], "r");
	if( file == NULL ) {
		printf("demangler: couldn't open file: %s\n", argv[1]);
		return -1;
	}
	char line[2048] = {0};
	char demangled[2048] = {0};

	while( fgets(line, 2048, file) ) {
		line[strlen(line)-1] = '\0';

		if( UnDecorateSymbolName(line, demangled, 2048, UNDNAME_COMPLETE) )
			printf("%s\n", demangled);
	}

	fclose(file);

	return 0;
}

