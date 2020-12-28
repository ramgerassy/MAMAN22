#define ROW 4
#define COLUMN 4

/*Create a data lnked list data structure in order to have a limitless user input length*/


typedef struct node{
	char c;
	struct node* next;
} letter;
typedef double mat[ROW][COLUMN];
typedef letter * ptr;

enum{FALSE,TRUE};

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
