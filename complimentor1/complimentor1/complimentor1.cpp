// Complimentor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include "string.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int integer, i, remain,j,c;
	int binary[17];
	int sign;
	char loop='y';
	while(loop='y')
	{

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
		
		integer=abs(integer); //Makes the value positive and unsigned for 
		i=15;

		while(integer>0)
		{
			remain = integer % 2;
			integer = (integer-remain) / 2;
			binary[i]= remain;
			i=i-1;
		}	
		printf("\n");
		binary[16] = sign;
		binary[0]=(NULL);
		
		if(sign==1)  //if the integer is negative compliment and print
		{
			c=1;
			printf("0");
			for(j=(i+1);j<16;j++)
			{
				if (binary[j]>0)//if bit is 0 make it a 1
				{
				binary[j]=0;
				printf("%d",binary[j]);
				}
				else //if bit is a 1 make it a 0
				{
					binary[j]=1;
					printf("%d",binary[j]);
				}
			}
			j=15;
			binary[j]=binary[j]+1;
			while(c=1)
			{
				if(binary[j]>1)
				{
					binary[j]=0;
					binary[j-1]=binary[j-1]+1;
					j=j-1;
				}
				else
				{
					c=0;
				}
				
			}
			
		}
			else //if non negative just print
				{
					printf("%d",sign);
					for(j=(i+1);j<16;j++)
						{
						printf("%d",binary[j]);
						}
				printf("\n");
				}
				
			
		
		printf("respond>");
		scanf("%c",loop);
	}
	return 0;
}

