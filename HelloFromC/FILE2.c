/****************************************************************
FILE2.C - definition of max function
****************************************************************/

#include <time.h>

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