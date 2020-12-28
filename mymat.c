#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mat.h"



int main()
{
	/*variables decleration and initialization*/
	mat MAT_A = {0};
	char user_input;
	char * command;
	ptr head = NULL;
	int i,counter = 0;
	double values[16] = {5,6,-59.2,20,569,20.135,654.2};
	
	read_mat(MAT_A,values);
	print_mat(MAT_A);
	while((user_input = getchar()) != '\n')
	{
	/*in order to detarmine what is the array size the sentance will be, counter will be increased for every
	   letter the user inputs. addLetter will ignor white spaces to keep the memory allocation efficiant*/
		counter = addLetter(&head,user_input,counter);
	}
	command = malloc(counter);
	if(!command)
	{
		printf("not enough memory in system");
		exit(1);
	}
	
	list2Command(&head,command);
	for(i = 0; i < counter; i++)
		putchar(command[i]);
	
	printf("\n");
	return 0;
}




/************************************/


void list2Command(ptr * head, char * command)
{
		
	ptr temp;
	int index = 0;
	/*If the list is empty, do nothing*/		
	if(!(*head))
		return;
	
	
	/*building the command array with the lists values.while doing so, the list cells are being free from the
	  computer memory*/
	for(index = 0;*head; index++)
	{
		temp = *head;
		*head = temp -> next;
		command[index] = temp -> c;
		free(temp);
	}
	return;

}

/************************************/

int addLetter(ptr * lpointer,char c,int counter)
{
	/*Declaring a temp node to hold the next list cell and a p node to iterate through the list*/
	ptr p , t;
	
	/*creating the memroy needed to hold the new list cell, if the computer doesnt have enough memory, the 
		program will alert the user and exit*/
	t = (ptr) malloc(sizeof(letter));
	if(!t)
	{
		printf("not enough memory in system");
		exit(1);
	}
		
	/*assigning the new charecter to new list cell.*/
	t -> c = c;

	/*if there is no cell in the list(heads point o null) connect this new cell - t to the head of the list*/
	if(!(*lpointer))
	{
		if(isWhiteSpace(c))
		{
			free(t);
			return counter;	
		}	
		t -> next = NULL;
		*lpointer = t;
		counter++;
		return counter;
	}
	
	
	/* assign the first cell to p and itterate trogh the list until p points to null in order to connect the 	
	   new cell - t to the list*/
	
	p = *lpointer;
	
	while(p->next)	
		p = p->next;

	/*in case the user enter 2 whitespaces, the program will ignore the seconde one to be more memory
	  efficiant*/
	if(isWhiteSpace(p->c) && isWhiteSpace(c))
	{
		free(t);
		return counter;
	}
	p-> next = t;
	t -> next = NULL;
	counter++;
	return	counter;
}


