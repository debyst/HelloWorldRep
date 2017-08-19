/*****************************************************************
FILE1.C - main function
*****************************************************************/
#define ONE     1  
#define TWO     2  
#define THREE   3  

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

	int w = ONE, x = TWO, y = THREE;
	int z = 0;
	u = 44;

	z = maxi(x, y);             // Executable statements      
	w = maxi(u, w);
	printf("%i %i\n", z, w);  // printf is MS VS specific and checks for the correct datatypes
	return 0;
}

void testFunctionPointer()
{
	/* Function prototypes */
	
	long lift(int), step(int), drop(int);
	void work(int number, long(*function)(int i));

	long (*plift)(int) = &lift;

	printf("pointer of lift:%p\n", lift);
	printf("value of plift:%p\n", plift);
	// ...therefore, the function name contains the pointer value!!

	int select, count;
	
	count = 3;
	select = 2;
	switch (select)
	{
	case 1: work(count, plift);
		printf("case lift\n");
		break;

	case 2: work(count, step); // the function pointer can be accessed by only calling the pure function name
		printf("case step\n");
		break;

	case 3: work(count, drop);
		printf("case drop\n");
		
		/* Fall through to next case */
	default:
		break;
	}

}

/* Function definition */

void work(int number, long(*function)(int i))
{
	int i;
	long j;

	for (i = j = 0; i < number; i++)
	{
		j = (*function)(i);
		printf("j=%li\n",j);
	}
}


static long lift(int i)
{
	return (long)i++;
}

long step(int i)
{
	return (long)i*2;
}

long drop(int i)
{
	return (long)i--;
}