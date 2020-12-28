#include<stdio.h>
#include "mat.h"
/************************************/

void read_mat(mat matrix,double * values)
{
	int i,j,counter = 0;
	/*assign the value from the values array inside the matrix. 
	  assigning by rows*/
	for(i = 0; i < COLUMN;i++)
	{
		for(j = 0; j < ROW; j++)
		{
			matrix[i][j] = values[counter];
			counter++;
		}
	printf("\n");	
	}
	
}

/************************************/

void print_mat(mat matrix)
{
	/*prints out matrix in the specified format of 7 digit field length, 2 decimal digit
	  and a tab spacing between every column and anew lin between every row.*/
	int i, j;
	for(i = 0; i < ROW;i++)
	{
		for(j = 0; j < COLUMN; j++)
			printf("%7.2f\t",matrix[i][j]);
	printf("\n");	
	}
	return;
}
