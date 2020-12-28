#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ROW 4
#define COLUMN 4
/*Create a data lnked list data structure in order to have a limitless user input length*/

enum{FALSE,TRUE};

typedef struct node{
	char c;
	struct node* next;
} letter;
typedef double mat[ROW][COLUMN];
typedef letter * ptr;

/*Define the list functions: 
addLetter - will det the letters from the user and save them in the data structure
letters2command - will convert the list into a char array with commands as strings
isWhiteSpace - return TRUE(1) if the char variable is either ' ' or ' '\t'. 
printList - will be used for debugging 
flag - will be used for debugging*/

int addLetter(ptr *, char,int);
void list2Command(ptr *,char *);
int isWhiteSpace(char c);
void printList(ptr);
void flag(int);
void print_mat(mat );
void read_mat(mat,double *);

/************************************/

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
