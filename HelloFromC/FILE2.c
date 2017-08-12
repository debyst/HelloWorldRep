/****************************************************************
FILE2.C - definition of max function
****************************************************************/
int u = 34;

int maxi(int a, int b)          // Note formal parameters are     
							   //  included in function header   
{
	if (a > b)
		return(a);
	else
		return(b);
}