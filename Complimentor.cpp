// Complimentor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int integer, i, j;
	
	short binary[17];
	int sign;
	char loop;
	
	loop = 'Y';
	
	while (loop == 'Y')
	{

	printf("Input a signed integer to be converted\n>");
		scanf("%d", &integer);
		printf("%d\n", integer);
		if (integer < 0)
		{
			sign = 1;
		}
		else
		{
			sign = 0;
		}
		while (integer > 0)
		{
			for (i=0; i<15; i++)
			{
				for(j=15;j>0;j--)
				{
					if( integer < ( 2^(j-1) ) )
					{
						binary[i+1]=1;
						integer = (integer - (2^(j-1)));
					}
					else
					{
						binary[i+1] = 0;
					}
				}
			}
			binary[0] = &sign

			printf("%s\n",binary);

			printf("Would you like to continue?\n Y or N >");
			scanf("%c", &loop);
			printf("\n");
		}
	}

	return 0;
}

