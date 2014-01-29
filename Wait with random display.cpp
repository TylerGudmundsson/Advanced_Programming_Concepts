// Wait with random display.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stddef.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>


HANDLE hStdOut;						/* Handle for console window */
CONSOLE_SCREEN_BUFFER_INFO csbi;    /* Console information structure */

void main()
{

	/* data needed for the csbi structure */
	WCHAR blockcell;	// a character to print
	COORD   newcoord;				// X,Y coordinate
	WORD	attribute;				// color attribute
	DWORD   result;					// returned results
	WCHAR logo[25][80];
	WCHAR hit[25][80];
	int i,j,t,l;
	char ch,cha,flusch;


	/*initialize my random character array */
	for (i=0; i< 25; i++)
		for(j =0; j< 80; j++)
		{
			char cha= 'a'+ rand() % (('z'-'a')+1); //generate random numbers
			logo[i][j] = cha;
			
	/* get a handle to the standard output (console window) */
	hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );	

	/* Get display screen's text row and column information. */
	GetConsoleScreenBufferInfo( hStdOut, &csbi );
		}

		while(!_kbhit())//wait for key stroke
		{
			j= (rand() % 80);//generate random locations
			i= (rand() % 25);
			t= (rand() % 80);//random location in character array
			l= (rand() % 25);
			if((i>11 & i<15) & (j>36 & j<44))//prevent printing of characters around center of display
			{
				j= 1;
				i= 1;
			}
			
			newcoord.X = (short)j;			// col
			newcoord.Y = (short)i;			// row
			blockcell = (CHAR)logo[l][t];
			attribute = (WORD)0x71;			// attribute - grey background, blue forground
			WriteConsoleOutputAttribute( hStdOut, &attribute,1,newcoord, &result);
			WriteConsoleOutputCharacter( hStdOut, (LPCWSTR)&blockcell, 1, newcoord, &result );		
			
		}
			
			
		newcoord.X = (short)40;			// col
		newcoord.Y = (short)13;			// row
		blockcell = (CHAR)_getch();
		attribute = (WORD)0x0F;			// attribute - grey background, blue forground
		WriteConsoleOutputAttribute( hStdOut, &attribute,1,newcoord, &result);
		WriteConsoleOutputCharacter( hStdOut, (LPCWSTR)&blockcell, 1, newcoord, &result );

}





