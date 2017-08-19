// this is my first C script

/* #pragma once
#include "targetver.h" */


//#include "mydefs.h" // including mydefs.h from a local header file (which is not included in the default C library)



#include <stdlib.h>
#include <stdio.h> // include stdio.h from the default C library
#include <time.h>
#include <string.h>
#include "FILE1.c"
#include "FILE2.c"
#include "consoleOps.c"


extern int maxi(int a, int b);  // Function prototype     

extern void changeVeloColor(struct velo *v, enum color c);

extern int testExternKeyword();
extern int testPointerNfiles();
extern void testFunctionPointer();

void main()
{
	printf("Hello From Visual Studio\n");

	testExternKeyword();

	//testStructsNenums();

	//testPointerNfiles();

	testFunctionPointer();
	
}