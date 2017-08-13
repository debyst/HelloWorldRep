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


int maxi(int a, int b)          // Note formal parameters are     
							   //  included in function header   
{
	if (a > b)
		return(a);
	else
		return(b);
}


void changeVeloColor(struct velo *v, enum color c)
{
	printf("changed color of %s from: %i -> %i\n", (*v).name, (*v).vcolor, c); ;
	(*v).vcolor = c;
	
}


int testStructsNenums()
{

	struct velo karl = { 0,red,singlespeed,"karl" };
	changeVeloColor(&karl, blue);
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
	printf("slackline matrix = id:%i / color:%i / stype:%i / buytime:%s / name:%s\n",
		matrix.id,matrix.scolor,matrix.stype,ctime(&matrix.buytime),matrix.name);

	return 0;
}