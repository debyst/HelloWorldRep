/*****************************************************************
FILE1.C - main function
*****************************************************************/
#define ONE     1  
#define TWO     2  
#define THREE   3  
#ifndef TEST_PI
#define TEST_PI 3.175
#endif

//here i just add some comments to provoke a conflict

int testExternKeyword()                       // Function definition         
{                                //  for main function          
	int c;                       // Definitions for      
	int d;                       //  two uninitialized  
								 //  local variables  

	extern int u;                // Referencing declaration     
								 //  of external variable       
								 //  defined elsewhere          
	static int v;                // Definition of variable      
								 //  with continuous lifetime   

	// just print TEST_PI
	printf_s("TEST_PI=%f\n",TEST_PI);

	int w = ONE, x = TWO, y = THREE;
	int z = 0;
	u = 44;

	z = maxi(x, y);             // Executable statements      
	w = maxi(u, w);
	printf_s("%i %i\n", z, w);  // printf_s is MS VS specific and checks for the correct datatypes
	return 0;
}
