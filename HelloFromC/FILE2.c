/****************************************************************
FILE2.C - definition of max function
****************************************************************/

#include <time.h>
#include <stdint.h>

int u = 34;

enum color { red, black, green, blue, white, yellow };
enum vtype { rennvelo, cyclocross, singlespeed, mtb };
enum stype { jumpline, longline, beginnerline };

struct velo {
	const int id;
	enum color vcolor;
	enum vtype vtype;
	char name[];
};

typedef struct  {
	const int id;
	enum color scolor;
	enum stype stype;
	time_t buytime;
	char name[];
} slackline ;

typedef slackline *pSlackline; // define the pointer type pSlackline of type struct slackline *

typedef int II2I(int, int); // we define a function type II2I

II2I maxi; // we declare the function maxi of type II2I

int maxi(int a, int b)          // Note formal parameters are     
							   //  included in function header   
{
	if (a > b)
		return(a);
	else
		return(b);
}


typedef void fv(int), (*pfv)(int);  /* typedef declarations */

void(*signal(int, void(*) (int))) (int);
fv *signal(int, fv *);   /* Uses typedef type */
pfv signal(int, pfv);    /* Uses typedef type */

void changeVeloColor(struct velo *v, enum color c)
{
	printf("changed color of %s from: %i -> %i\n", (*v).name, (*v).vcolor, c); ;
	(*v).vcolor = c;
	
}


int testStructsNenums()
{
	struct velo velo = { 1,blue,mtb,"velo" }; // the name of the struct is located in a different namespace 
												// as the name of the struct, thus they can be named the same.
	struct velo karl = { 0,red,singlespeed,"karl" };
	struct velo *pKarl; // declare the pointer of karl
	pKarl = &karl;
	changeVeloColor(pKarl, blue);
	//karl.id = 3;
	karl.vtype = mtb;
	karl.vcolor = white;
	changeVeloColor(&karl, red);

	time_t mtime_t;
	time(&mtime_t);
	struct tm *mtime = localtime(&mtime_t);
	mtime->tm_year = 2014;  // -> is equivalent to (*mtime).tm_year
	mtime->tm_yday = 300;
	mtime->tm_hour = 14;
	mtime_t = mktime(mtime);

	slackline matrix = { 0,red,jumpline,time(&mtime_t),"matrix"};
	pSlackline pMatrix = &matrix; // define the pointer of type pSlackline of the struct matrix
	printf("slackline matrix = id:%i / color:%i / stype:%i / buytime:%s / name:%s\n",
		matrix.id,matrix.scolor,matrix.stype,ctime(&matrix.buytime),matrix.name);

	return 0;
}


//declare a function that calls the lookup table
uint8_t getSigma(uint8_t cn0, uint8_t eleDeg, uint8_t speedMpS)
{
	static const uint8_t lookup[2][3][2] =  // keyword __flash does not exist here
	{
		1,2,   // [last][mid][first] -> first: horizontal. mid: vertical. last: up.
		3,4, 
		5,6,
		10,11, 
		12,13, 
		14,15
	};
	if (cn0 >= 0 && cn0 < 20)
	{
		cn0 = 0;
	}
	else if (cn0 >= 20 && cn0 < 50)
	{
		cn0 = 1;
	}
	if (eleDeg >= 0 && eleDeg < 20)
	{
		eleDeg = 0;
	}
	else if (eleDeg >= 20 && eleDeg < 30)
	{
		eleDeg = 1;
	}
	else if (eleDeg >= 30 && eleDeg < 90)
	{
		eleDeg = 2;
	}
	if (speedMpS >= 0 && speedMpS < 20)
	{
		speedMpS = 0;
	}
	else if (speedMpS >= 10 && speedMpS < 200)
	{
		speedMpS = 1;
	}
	// now look up the mapped values
	if (cn0 <= 1 && eleDeg <= 2 && speedMpS <= 1)
	{
		return lookup[cn0][eleDeg][speedMpS];
	}
	else
	{
		return 0;
	}
}

void testLookupTable()
{
	uint8_t cn0 = 5;
	uint8_t eleDeg = 20;
	uint8_t speedMpS = 10;
	printf("cn0:%i,eleDeg:%i,speedMpS:%i ==> Sigma=%i\n", cn0, eleDeg, speedMpS,
		getSigma(cn0, eleDeg, speedMpS));
}

