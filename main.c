#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

//This is Mine Sweeper v1.1

int table[10][10];
int bombed[10][10];
int table1[10][10];
int tempbombed[10][10];


void settable(int *bombnum)
{
		int i, f,n=0;
		for (i = 0; i < 10; i++)
		{
			for (f = 0; f < 10; f++)
			{
				table[f][i] = 0;
			}

		}
		start:
	for (i = 0; i < 10; i++)
	{
		for (f = 0; f < 10; f++)
		{
			if (rand() % 10 == 0)
			{
				if (n <= *bombnum)
				{
					if (table[f][i] == 0)
					{
						table[f][i] = 9;
						table1[f][i] = 9;
						n = n + 1;
					}
					if (n == *bombnum) { return; }
				}
			}


		}
	}
	if (n <= *bombnum) { goto start; }

}

//puts how many bombs are around it
void tablecount()
{
	int i, f,n=0;
	for (i = 0; i < 10; i++)
	{
		for (f = 0; f < 10; f++)
		{
			if (table1[f][i] != 9) { table1[f][i] = 0; }
		}

	}
	for (i = 0; i < 10; i++)
	{
		
		for (f = 0; f < 10; f++)
		{
			n = 0;
			if (table[f][i] == 9) { goto next; }
				if (table[f][i] == 0) 
				{
					if (table[f - 1][i - 1] == 9&&f-1>=0 && i - 1 >= 0) { n = n + 1; }
					if (table[f - 1][i] == 9 && f - 1 >= 0) { n = n + 1; }
					if (table[f - 1][i + 1] == 9 && f - 1 >= 0 && i + 1 <10) { n = n + 1; }
					if (table[f][i - 1] == 9 && i - 1 >= 0) { n = n + 1; }
					if (table[f][i + 1] == 9 && i + 1 <10) { n = n + 1; }
					if (table[f + 1][i - 1] == 9 && f + 1 <10 && i - 1 >= 0) { n = n + 1; }
					if (table[f + 1][i] == 9 && f + 1 <10) { n = n + 1; }
					if (table[f + 1][i + 1] == 9 && f + 1 <10 && i + 1 <10) { n = n + 1; }
					table1[f][i] = n;

				}
			next:;
			
		}
		
	}
}


void printtable()
{
	int i, f;
	printf("This is table\n");
	printf("\n/////////////////////////////////////////////////\n\n");
	printf("   1 2 3 4 5 6 7 8 9 10\n");
	for (i = 0; i < 10; i++)
	{
		for (f = 0; f < 10; f++)
		{
			if (f == 0)
			{
				if (i == 9) { printf("%d ", i + 1); }
				else { printf("%d  ", i + 1); }
			}
			printf("%d ", table[f][i]);
		}
		printf("\n");
	}
	printf("\n/////////////////////////////////////////////////\n");
}


void printtable1()
{
	int i, f;
	printf("This is table1\n");
	printf("\n/////////////////////////////////////////////////\n\n");
	printf("   1 2 3 4 5 6 7 8 9 10\n");
	for (i = 0; i < 10; i++)
	{
		for (f = 0; f < 10; f++)
		{
			if (f == 0)
			{
				if (i == 9) { printf("%d ", i + 1); }
				else { printf("%d  ", i + 1); }
			}
			printf("%d ", table1[f][i]);
		}
		printf("\n");
	}
	printf("\n/////////////////////////////////////////////////\n");
}






void printbombed()
{
	int i, f;
	printf("This is bombed\n");
	printf("\n/////////////////////////////////////////////////\n\n");
	printf("   1 2 3 4 5 6 7 8 9 10\n");
	for (i = 0; i < 10; i++)
	{
		for (f = 0; f < 10; f++)
		{
			if (f == 0) 
			{ 
				if (i==9){ printf("%d ", i + 1); }
				else { printf("%d  ", i + 1); }
			}
			printf("%d ", bombed[f][i]);
		}
		printf("\n");
	}
	printf("\n/////////////////////////////////////////////////\n");
}



int setdiff()
{
	
	int diff=0;
    setdiff:
	printf("Enter how many bombs you want upto 25:");
	scanf("%d,\n", &diff);
	if (diff > 0 && diff <= 25) 
	{
		return diff;
	}
	printf("You have to enter between 1 and 25\n");
	goto setdiff;
}


void checknext(int reelx,int reely)
{
	
	


		
		//next chapter


		if (table1[reelx + 1][reely + 1] == 1 && reelx + 1 < 10 && reely + 1 < 10) { bombed[reelx + 1][reely + 1] = 1; }

		if (table1[reelx + 1][reely] == 1 && reelx + 1 < 10) { bombed[reelx + 1][reely] = 1; }

		if (table1[reelx + 1][reely - 1] == 1 && reelx + 1 < 10 && reely - 1 >= 0) { bombed[reelx + 1][reely - 1] = 1; }

		if (table1[reelx][reely + 1] == 1 && reely + 1 < 10) { bombed[reelx][reely + 1] = 1; }

		if (table1[reelx][reely - 1] == 1 && reely - 1 >= 0) { bombed[reelx][reely - 1] = 1; }

		if (table1[reelx - 1][reely + 1] == 1 && reely + 1 < 10 && reelx - 1 >= 0) { bombed[reelx - 1][reely + 1] = 1; }

		if (table1[reelx - 1][reely] == 1 && reelx - 1 >= 0) { bombed[reelx - 1][reely] = 1; }

		if (table1[reelx - 1][reely - 1] == 1 && reelx - 1 >= 0 && reely - 1 >= 0) { bombed[reelx - 1][reely - 1] = 1; }

		//next chapter


		if (table1[reelx + 1][reely + 1] == 2 && reelx + 1 < 10 && reely + 1 < 10) { bombed[reelx + 1][reely + 1] = 2; }

		if (table1[reelx + 1][reely] == 2 && reelx + 1 < 10) { bombed[reelx + 1][reely] = 2; }

		if (table1[reelx + 1][reely - 1] == 2 && reelx + 1 < 10 && reely - 1 >= 0) { bombed[reelx + 1][reely - 1] = 2; }

		if (table1[reelx][reely + 1] == 2 && reely + 1 < 10) { bombed[reelx][reely + 1] = 2; }

		if (table1[reelx][reely - 1] == 2 && reely - 1 >= 0) { bombed[reelx][reely - 1] = 2; }

		if (table1[reelx - 1][reely + 1] == 2 && reely + 1 < 10 && reelx - 1 >= 0) { bombed[reelx - 1][reely + 1] = 2; }

		if (table1[reelx - 1][reely] == 2 && reelx - 1 >= 0) { bombed[reelx - 1][reely] = 2; }

		if (table1[reelx - 1][reely - 1] == 2 && reelx - 1 >= 0 && reely - 1 >= 0) { bombed[reelx - 1][reely - 1] = 2; }


		//next chapter


		if (table1[reelx + 1][reely + 1] == 3 && reelx + 1 < 10 && reely + 1 < 10) { bombed[reelx + 1][reely + 1] = 3; }

		if (table1[reelx + 1][reely] == 3 && reelx + 1 < 10) { bombed[reelx + 1][reely] = 3; }

		if (table1[reelx + 1][reely - 1] == 3 && reelx + 1 < 10 && reely - 1 >= 0) { bombed[reelx + 1][reely - 1] = 3; }

		if (table1[reelx][reely + 1] == 3 && reely + 1 < 10) { bombed[reelx][reely + 1] = 3; }

		if (table1[reelx][reely - 1] == 3 && reely - 1 >= 0) { bombed[reelx][reely - 1] = 3; }

		if (table1[reelx - 1][reely + 1] == 3 && reely + 1 < 10 && reelx - 1 >= 0) { bombed[reelx - 1][reely + 1] = 3; }

		if (table1[reelx - 1][reely] == 3 && reelx - 1 >= 0) { bombed[reelx - 1][reely] = 3; }

		if (table1[reelx - 1][reely - 1] == 3 && reelx - 1 >= 0 && reely - 1 >= 0) { bombed[reelx - 1][reely - 1] = 3; }
	//next chapter 


		if (table1[reelx + 1][reely + 1] == 0 && reelx + 1 < 10 && reely + 1 < 10) { table1[reelx + 1][reely + 1] = 8; bombed[reelx + 1][reely + 1] = 8; checknext(reelx + 1, reely + 1); }

		if (table1[reelx + 1][reely] == 0 && reelx + 1 < 10) {table1[reelx + 1][reely] = 8; bombed[reelx + 1][reely] = 8; checknext(reelx + 1, reely); }

		if (table1[reelx + 1][reely - 1] == 0 && reelx + 1 < 10 && reely - 1 >= 0) {table1[reelx + 1][reely - 1] = 8; bombed[reelx + 1][reely - 1] = 8; checknext(reelx + 1, reely - 1); }

		if (table1[reelx][reely + 1] == 0 && reely + 1 < 10) {table1[reelx][reely + 1] = 8; bombed[reelx][reely + 1] = 8; checknext(reelx, reely + 1); }

		if (table1[reelx][reely - 1] == 0 && reely - 1 >= 0) {table1[reelx][reely - 1] = 8; bombed[reelx][reely - 1] = 8; checknext(reelx, reely - 1); }

		if (table1[reelx - 1][reely + 1] == 0 && reely + 1 < 10 && reelx - 1 >= 0) { table1[reelx - 1][reely + 1] = 8; bombed[reelx - 1][reely + 1] = 8; checknext(reelx - 1, reely + 1); }

		if (table1[reelx - 1][reely] == 0 && reelx - 1 >= 0) {table1[reelx - 1][reely] = 8; bombed[reelx - 1][reely] = 8; checknext(reelx - 1, reely); }

		if (table1[reelx - 1][reely - 1] == 0 && reelx - 1 >= 0 && reely - 1 >= 0) {table1[reelx - 1][reely - 1] = 8; bombed[reelx - 1][reely - 1] = 8; checknext(reelx - 1, reely - 1); }


}




int bomb(int *bombnum)
{
	int x, y,i,f,put=0,n=1;
	int reelx, reely;
    start:

	printbombed();
	printf("1.clicking\n2.putting or removing a flag\n");
	scanf("%d", &put);
	if (put == 2 )
	{ 
		printf("Enter x and y coordinats:");
		scanf("%d%d", &x, &y);
		reelx = x - 1;
		reely = y - 1;
		if (x < 1 || x > 10 || y < 1 || y > 10)
		{
			system("cls");
			printf("You must enter in the grid\n");
			goto start;
		}
		if (table[reelx][reely] == 9)
		{
			tempbombed[reelx][reely] = bombed[reelx][reely];
			bombed[reelx][reely] = 7;
			n = n + 1;
			if (n == *bombnum)
			{
				return 6;
			}
			goto start;
		}
		if (bombed[reelx][reely] == 7)
		{
			bombed[reelx][reely] = tempbombed[reelx][reely];
			if (table[reelx][reely] == 9)
			{
				n = n - 1;
			}
			goto start;
		}
		tempbombed[reelx][reely] = bombed[reelx][reely];
		bombed[reelx][reely] = 7;
		goto start;


	}

	if (put == 1)
	{
		printf("Enter x and y coordinats:");
		scanf("%d%d", &x, &y);
		reelx = x - 1;
		reely = y - 1;
		if (x < 1 || x > 10 || y < 1 || y > 10)
		{
			system("cls");
			printf("You must enter in the grid\n");
			goto start;
		}


		if (table[x - 1][y - 1] == 9)
		{
			printf("You hit a bomb,game over\n");
			Sleep(2000);
			system("cls");
			return 5;
		}

		if (table1[reelx][reely] == 0)
		{
			bombed[reelx][reely] = 8;
			//should change every zero nexto it to something else until it gets to another number
			checknext(reelx, reely);
			goto start;

		}

		if (table1[reelx][reely] == 1)
		{
			bombed[reelx][reely] = 1;
			goto start;
		}

		if (table1[reelx][reely] == 2)
		{
			bombed[reelx][reely] = 2;
			goto start;
		}

		if (table1[reelx][reely] == 3)
		{
			bombed[reelx][reely] = 3;
			goto start;
		}





	}
}



int checkif3()
{

	int i, f;
	for (i = 0; i < 10; i++)
	{
		for (f = 0; f < 10; f++)
		{
			if (table1[f][i] > 3 && table1[f][i] != 9)
			{
				return 2;
		    }
		}
		
	}
	return 3;
}



void main2()
{
	int bombnum, check = 0;
	char name[10];
	bombnum = setdiff();
	settable(&bombnum);
	printtable();
	tablecount();
	printtable1();
}





void main()
{
	int bombnum,check=0,fe;
	char name[10];
	system("color c");
	printf("Please enter your name:");
	check = 0;
	scanf("%s,\n", name);
    begining:
	bombnum = setdiff();
	tablesetting:
	settable(&bombnum);
	tablecount();	
	fe = checkif3();
	if (fe == 2) { goto tablesetting; }
	system("cls");
	printtable();
	printtable1();
	check = bomb(&bombnum);
	if (check == 5) { goto begining; }
	if (check == 6) { printf("You Win"); }

}