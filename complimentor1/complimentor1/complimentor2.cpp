// Complimentor.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "math.h"
#include "string.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int integer,integer2, i, remain,j,c;
	int binary2[17];
	int binary[17];
	int sign, sign2;

	printf("Input a signed integer to be converted\n>");
	scanf("%d", &integer);
	if (integer < 0) //Determins sign bit of binary number
		{
			sign = 1;				
		}
	else
		{
			sign = 0;
		}	
	integer2=abs(integer); //Makes the value positive and unsigned for conversion process, as well as hold the original signed value for future version of program
	i=15;
	if(sign==1)  //if the integer is negative complimented bit is 0
		{
			sign2=0;
		}
	else //if non negative complimented bit is 1
		{
			sign2=1;
		}
	binary[0]=(NULL); //assures a null bit in string due to previous problems
			
	while(integer2>0) //mods integer and stores result in an array
		{
			remain = integer2 % 2;
			integer2 = (integer2-remain) / 2;
			binary[i]=remain;
			if(remain==1) //flips the mod value and stores in compliment array
				{
					binary2[i]= 0;
				}
			else
				{
					binary2[i]=1;
				}
			i=i-1;
		}
	printf("Binary>%d",sign);  //prints binary array 
	for(j=(i+1);j<16;j++)
		{
			printf("%d",binary[j]);
		}
	printf("\n");
	printf("2's Compliment>%d",sign2); //prints compliment array
	for(j=(i+1);j<16;j++)
		{
			printf("%d",binary2[j]);
		}
	printf("\n");
	return 0;
}

