#include<stdio.h>
#include"mat.h"

/************************************/
/*ment for debugging. to verify that the list is getting every charecter*/
void printList(ptr head)
{
	while(head)
	{
		printf("%c",head -> c);
		head = head->next;
	}
	
}

/************************************/

/*test a char variable. if its a whitespace - \t || space, return true*/
int isWhiteSpace(char c)
{
	if(c == ' ' || c == '\t')
		return TRUE;
	else
		return FALSE;
}

/************************************/

/*ment for debugging, to raise a flag in a certin place in the code, helping me verify
  that the code is working properly*/
void flag(int iden)
{
	printf("flag: %d\n",iden);
}
