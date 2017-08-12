
int testPointerNfiles() 
{
	printf("\nfilename of this program="); printf(__FILE__);
	printf("\ntime/date of compilation=%s / %s", __TIME__, __DATE__);
	printf("\nvalue of macro constant EOF=%i", EOF);
	
	// some small pointer experiments
	char bla[] = "b"; // declare and initialize variable with a character
	char *pbla = bla; // &bla[0]; // must (!) initialize pointer as char, not int. beware: indices start with 0!
	char zliste[3] = "asdfasdf"; // here the array is not dynamically enlarged, but the compiler throws an overflow warning.
	printf(zliste);
	
	printf("\n\n//// some small pointer experiments /////");
	printf("\n\nprint character array variable bla="); printf(bla);  // print this character to stout
	printf("\npointer value of variable bla as integer/pointer: pbla=%i / %p",(int)pbla,pbla); // printing pointer value, only possible by casting to (int)
	printf("\npointer value of variable bla as string: pbla=%s", pbla); // printing pointer value as string prints the object value!!
	printf("\nstring variable as character accessed by pointer: bla=%c", *pbla); //accessing the object value via the pointer


	// some integer experiments
	int grZahl;

	printf("\n\n//// some integer experiments ////");
	printf("\n\n____...enter an integer:\n");
	scanf("%i", &grZahl); // scanf("%5c",&IOtext); ...here again,  scanf needs the pointer value of the integer!
	printf("\n%i w. size:%i", grZahl, sizeof(grZahl)); // sizeof gives size of data type in bytes!!! => int = 32 bit = 4 bytes


	// some IO experiment with type casting
	char IOtext[5] = { 0 }; // declare character variable with 5 fields, it's best to initialize with 0 to not confuse oneself
	char text[5] = { 0 };
	int zahlen[5] = { 0 }; // declare integer array with 5 fields

	printf("\n\n//// some character input/output experiments //// ");
	printf("\n\nprint empty character array variable text:\n"); printf(text);  // print empty variable text to stout
	printf("\nwhy does the empty variable text store  some characters?? ...print integer value of each charachter field:\n");
	for (int i = 0; i < sizeof(IOtext); i++)
	{
		printf("%i,", (int)text[i]);
	}
	printf("\nwhy does the empty variable zahlen store some characters??"
		"...print integer value of each (#%i) array field:\n",sizeof(zahlen)/sizeof(int));
	for (int i = 0; i < sizeof(zahlen)/sizeof(int); i++) // sizeof(zahlen) = 20, weil int hat 32 bit = 4 byte ==> 5 fields * 4 byte = 20 byte.
	{
		printf("%i,", zahlen[i]);
	}

	printf("\n\n____helloWold...enter max 6 characters:\n");
	scanf("%6s",IOtext); // scanf("%5c",&IOtext); ==> if using scanf with %c, scanf needs the pointer value of the charachter array!!
	int sizeTxt = strchr(IOtext, '\0') - IOtext; // determine the size of the character array dynamically
	printf("\n%s w. size:%d / %d", IOtext, sizeTxt,strlen(IOtext)); // 1 char field = 8 bit = 1 byte => sizeof gives variable size in [bytes], which equals the field size

	int it = 0;
	int iz = 0;
	for (int i = 0; i < sizeTxt; i++)
	{
		printf("\n %i-th element:%c <-> %d", i, IOtext[i], (int)IOtext[i]);
		if ((int)IOtext[i] > 47 && (int)IOtext[i] < 58)
		{
			zahlen[iz] = (int)IOtext[i]-48; // TODO: ist das die richtige typenkonvertierung?? 
					// ...NOPE: better use strtol() !!
			printf("\nzahl:%d",zahlen[iz]);
			iz++;
		}
		else if ((int)IOtext[i] > 32)
		{	
			text[it] = IOtext[i];
			it++;
		}
	}

	printf("\n entered ASCII characters only were:");
	for (int i = 0; i < it; i++)
	{
		printf("%c,", text[i]); 
	}
	printf("\n");
	printf(text); // TODO: why is text storing also IOtext???!!

	printf("\n entered integer number only were:");
	for (int i = 0; i < iz; i++) 
	{
		printf("%i,", zahlen[i]);
	}
	printf("\nwhy does zahlen store the whole text??: ");
	for (int i = 0; i < sizeof(zahlen) / sizeof(int); i++)
	{
		printf("%i,", zahlen[i]);
	}



	/* FEOF example */
	char fname[15];
	FILE * pFile;  // declare pointer for a new FILE object
	char buffer[100];
	clock_t t1, t2;
	char *p;

	printf("\n\n//// a copy and past example with reading from a file and output all to stdout ////");
	printf("\n\n____...enter an existing filename (max.15chars):\n");
	scanf("%15s", fname); // scanf("%5c",&IOtext);

	pFile = fopen(fname, "r");
	t1 = clock();
	printf("\nt1=%d\n", t1);
	if (pFile == NULL) perror("Error opening file");
	else
	{
		while (!feof(pFile))
		{
			if (fgets(buffer, 100, pFile) == NULL) break;
			p = strchr(buffer, ' ');
			while (p != NULL)
			{
				*p = '_';
				p = strchr(p+1, ' ');
			}
			fputs(buffer, stdout);
		}
		fclose(pFile);
	}
	t2 = clock();
	printf("\nt1=%d ==> dt=%d\n", t2, t2 - t1);

	return 0;

}