/**
 * BinarySearchTree.c
 * The binary search tree asks for a text file and then proceeds
 * to read every word of the file. Splitting words with symbols at the
 * start middle and end.
 * Inserts the words into a binary search tree then prints all words to
 * console and a textfile " output.txt".
 * Quit the program
 * @ "Kyle Harrison"
 * @ (02/11/2011)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;
typedef char* String;

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty( SearchTree Tree );
Position Find( ElementType ElementAt, SearchTree Tree );
Position FindMin( SearchTree Tree );
Position FindMax( SearchTree Tree );
SearchTree Insert( char* StringAt,ElementType ElementAt, SearchTree Tree );
SearchTree Delete( ElementType ElementAt, SearchTree Tree );
SearchTree Print ( SearchTree Tree );
ElementType Retrieve( Position Ptr );
int RetrieveWordCount( Position Ptr );
String RetrieveString( String Ptr );
Position readFromFile(SearchTree Tree);

struct TreeNode{
	ElementType Element;		// key
    SearchTree  LeftNode;		// pointer to left node
    SearchTree  RightNode;		// pointer to right node
 //   char *string;
    char *strPtr;
    int wordCount;
};

char* temparray;

/**
 * MakeEmpty
 * Accepts a tree node and adds the left and right child nodes as null
 * @param SearchTree Tree
 * @return null
 */
Position
MakeEmpty( SearchTree Tree )
{
	if( Tree != NULL )
    {
		MakeEmpty( Tree->LeftNode );
		MakeEmpty( Tree->RightNode );
		free( Tree );
    }
	return NULL;
}

/**
 * Find
 * Find searches the tree by first going through all the left most nodes,
 * then the right to search the entire tree for the value "ElementAt".
 * Returns the node the value is at otherwise null if it does not exist
 * @param SearchTree Tree
 * @return null, tree
 */
Position
Find( ElementType ElementAt, SearchTree Tree )
{
	if( Tree == NULL )
		return NULL;
	if( ElementAt < Tree->Element )
		return Find( ElementAt, Tree->LeftNode );
	else if( ElementAt > Tree->Element )
		return Find( ElementAt, Tree->RightNode );
	else
		return Tree;
}

/**
 * FindMin
 * Finds the minimum by recursively searching down the left most node .
 * Returns the tree when the leftmost node equals null
 * returns null if tree has no nodes.
 * @param SearchTree Tree
 * @return null, tree
 */
Position
FindMin( SearchTree Tree )
{
	if( Tree == NULL )
		return NULL;
	else if( Tree->LeftNode == NULL )
		return Tree;
	else
		return FindMin( Tree->LeftNode );
}

/**
 * FindMax
 * Finds the minimum by iteration - searching down the right most node .
 * Returns tree when the right most node equals null
 * returns tree when node is found or tree at node = null
 * @param SearchTree Tree
 * @return tree
 */
Position
FindMax( SearchTree Tree )
{
	if( Tree != NULL )
		while( Tree->RightNode != NULL )
			Tree = Tree->RightNode;
	return Tree;
}

/**
 * Insert
 * If the current tree is equal to null then malloc memory for size of struct treenode
 * If tree is still equal to null after mallow then print out outta of space
 * else set the element in the tree to the element being inserted and the leftnode and right node = null
 * @param ElementType ElementAt , SearchTree Tree
 * @return tree
 */
Position
Insert( char* StringAt, ElementType ElementAt, SearchTree Tree )
{
	if( Tree == NULL )
	{
		// Create and return a one-node tree
		Tree = malloc( sizeof( struct TreeNode ) );

		if( Tree == NULL ) { // If no space is available tree cannot be  malloced
			printf("\n Out of space!!!");
		}
		else{ // Adding the element into the tree and creating null left and right nodes.
			(*Tree).Element = ElementAt;
			(*Tree).LeftNode = (*Tree).RightNode = NULL;
			(*Tree).wordCount= (*Tree).wordCount +1;


			// Malloc tree node string pointer
			Tree->strPtr = ((char*)malloc(256*sizeof(char)));
			strcpy(Tree->strPtr,temparray);
		//	printf(" strPtr     : %s",Tree->strPtr);

			//printf(" Element : %d inserted in table\n\n",  ElementAt);
		}
	}
	else if( ElementAt < (*Tree).Element ) {
		// Inserting a element when the tree exists and element being
		//inserted is less than element at the current tree element
		(*Tree).LeftNode = Insert(StringAt, ElementAt, (*Tree).LeftNode );
	}
	else if( ElementAt > (*Tree).Element ) {
		// inserting an element when the tree exists and the element being
		// inserted is greater than the element at the current tree element.
		(*Tree).RightNode = Insert(StringAt, ElementAt, (*Tree).RightNode );
	}
	else // Else ElementAt is in the tree already and nothing needs to be done.
	{
		//printf(" Element : %d is already in table\n",  ElementAt);
		(*Tree).wordCount= (*Tree).wordCount +1;
	//	printf(" Word count incremented by 1 = %d\n\n", (*Tree).wordCount);
	}
	return Tree;
}

/**
 * Delete
 * If tree is null then the element cannot be found to be deleted.
 * else if element is less than current tree element go to the left node
 * else if element is greater tha nteh current tree element go to the right node
 * else if element is greater than left and right node then find the and
 * replace with smallest in right subtree.
 * Free the temporary cell before returning tree
 * @param ElementType ElementAt , SearchTree Tree
 * @return tree
 */
Position
Delete( ElementType ElementAt, SearchTree Tree )
{
	Position TemporaryCell;

	if( Tree == NULL ) {
		printf( "Element not found" );
	}
	else if( ElementAt < Tree->Element )  /* Go left */
		Tree->LeftNode = Delete( ElementAt, Tree->LeftNode );
	else if( ElementAt > Tree->Element )  /* Go right */
		Tree->RightNode = Delete( ElementAt, Tree->RightNode );
	/* Found element to be deleted */
	else if( Tree->LeftNode && Tree->RightNode )  /* Two children */
	{
		/* Replace with smallest in right subtree */
		TemporaryCell = FindMin( Tree->RightNode );
		Tree->Element = TemporaryCell->Element;
		Tree->RightNode = Delete( Tree->Element, Tree->RightNode );
	}
	else  /* One or zero children */
	{
		TemporaryCell = Tree;
		if( Tree->LeftNode == NULL ) /* Also handles 0 children */
			Tree = Tree->RightNode;
		else if( Tree->RightNode == NULL )
			Tree = Tree->LeftNode;

		free( TemporaryCell );
	}
	return Tree;
 }

/**
 * Retrieve
 * Returns the element at the position parameters
 * @param Position Ptr
 * @return Pointer to element
 */
ElementType
Retrieve( Position Ptr )
{
	return (*Ptr).Element;
}

/**
 * Retrieve
 * Returns the element at the position parameters
 * @param Position Ptr
 * @return Pointer to element
 */
String RetrieveString( String Ptr )
{
	printf(" String = %s",Ptr);
	return Ptr;
}

int RetrieveWordCount( Position Ptr )
{
	return (*Ptr).wordCount;
}

/**
 * Print
 * Returns the element at the position parameters
 * @param SearchTree Tree
 * @rTraverses through the entire tree and prints element at each node
 */
SearchTree
Print( SearchTree TreeNode)
{
	if( TreeNode != NULL) {
		Print(TreeNode->LeftNode);

		if(!(strcmp((*TreeNode).strPtr, ""))==0)
		{
			printf ("\n %d ", Retrieve(TreeNode));
			printf (" %s ", (*TreeNode).strPtr);
			printf ("x %d ", RetrieveWordCount(TreeNode));
		}

		Print(TreeNode->RightNode);
	}
	return 0;
}

int MostNode=0;
int MostOccuring=0;
char* MostWord;


SearchTree
PrintFile( SearchTree TreeNode, FILE *file)
{
	if( TreeNode != NULL) {
		PrintFile(TreeNode->LeftNode,file);

		if(!(strcmp((*TreeNode).strPtr, ""))==0)
		{
			fprintf (file,"(%s,", (*TreeNode).strPtr);
			fprintf (file,"%d) \n", RetrieveWordCount(TreeNode));

			if((*TreeNode).wordCount>MostOccuring)
			{
				MostOccuring = (*TreeNode).wordCount;
				MostNode = (*TreeNode).Element;
				strcpy(MostWord,(*TreeNode).strPtr);
			}
		}

		PrintFile(TreeNode->RightNode,file);
	}
	return 0;
}

Position
writeToFile(SearchTree Tree)
{
	FILE *file;
	file = fopen("output.txt","w");

	//fprintf(file,"%s","This is just an example :)"); /*writes*/
	MostWord = ((char*)malloc(22*sizeof(char)));
	PrintFile(Tree,file);

	//printf("\n Most Occuring = %d",MostOccuring);
	//printf("\n Most Occuring = %d",MostNode);

	printf("\n\n Most Used Word = %s",MostWord);
	fprintf(file,"\n\n Most used word : %s",MostWord);
	fclose(file); /*done!*/
	printf("\n\n File 'output.txt' Created. ");
	//free(MostWord);
	//getchar(); /* pause and wait for key */
	return 0;
}

Position
readFromFile(SearchTree Tree)
{
	 FILE *file_Ptr ;
	 char* fileName = "sherlock.txt";
	 int repeat = 0;
	 int i=0;
	 char charAt;
	// char *word;
	 int stringValue =0;

	 fileName = ((char*)malloc(256*sizeof(char)));
	 temparray = ((char*)malloc(22*sizeof(char)));

	 do
	 {
	 printf("\n Enter FileName : ");
	 scanf(" %s",fileName);

	 file_Ptr= fopen( fileName , "r" ) ;

	while (!feof(file_Ptr))
	{
		char buffer[100];
		char* word = malloc(sizeof(fscanf(file_Ptr, "%s", buffer)));
		stringValue =0;

		fscanf(file_Ptr, "%s", word);

		// creates a node value and makes all chars lower case
		for(i=0;i<strlen(word);i++)
		{
			word[i] = tolower(word[i]);
		}

		//printf(" %s ", word);

		char* tempword = ((char*)malloc(22*sizeof(char)));
		char* tempword2 = ((char*)malloc(22*sizeof(char)));
		int word1count =0;
		int word2count =0;
		int punct =0;

		for(i=0;i<strlen(word);i++)
		{

		charAt = word[i];
		if( !isdigit( charAt ))
		{
				if( isalpha( charAt ) )
				{
					// printf( "\n Letter %c Found" , tolower(charAt )) ;
					 if(punct==0){
						 tempword[word1count] = charAt;
						 word1count++;
					 }
					 else{
						 tempword2[word2count] = charAt;
						 word2count++;
					 }
				}
				else if( ispunct( charAt ) )
				{
					//printf( "\n Punctuation Found %c\n", charAt ) ;
					punct=1;
				}
				else if( isspace( charAt ) )
				{
				//	printf( "\n Space Found\n" ) ;
				}
			 }
		}

	//	printf("\n word1 %s\n",tempword);
	//	printf(" word2 %s\n",tempword2);

		strcpy(word,tempword);
		stringValue =0;
		for(i=0;i<strlen(word);i++)
		{
			stringValue += *word;
		}
		//printf("\n String  : %s\n",word);
		//printf(" At Node : %d\n",stringValue);

		strcpy(temparray,word);
		//printf(" temp array %s", temparray);

		if ((strcmp(word, "endoffile"))==0)
		{
					//	printf("END");
						feof(file_Ptr);
		}
		else
		{

		Tree = Insert( word, stringValue, Tree );

		if(punct==1)
		{
			strcpy(word,tempword2);
			stringValue =0;
					for(i=0;i<strlen(word);i++)
					{
						stringValue += *word;
					}
					//printf("\n String  : %s\n",word);
					//printf(" At Node : %d\n",stringValue);

					strcpy(temparray,word);
					//printf(" temp array %s", temparray);

			Tree = Insert( word, stringValue, Tree );
		}
		}// end of EOF check
	} // while not the end of file

	 if( file_Ptr != NULL ) {

	    fclose( file_Ptr ) ;
	    printf("\n File '%s' closed. \n",fileName);
	    repeat=0;
	  }
	  else  {
	    if( file_Ptr == NULL) printf( "\n Unable to open file.\n" ) ;
	    repeat=1;

	}// end of EOF check
	 }while(repeat==1);

	 return Tree;
}

/**
 * menu
 * Displays Menu and asks for user interger input.
 * @param char menuChoice
 * @return char menuChoice
 */
char menu(char menuChoice)
{
	printf("\n<----------------------------------> \n");
	printf("           Binary Search Tree         \n");
	printf(" <----------------------------------> \n");
	printf(" A)	Insert new integer.\n");
	printf(" B)	Check tree for integer.\n");
	printf(" C)	Print out current tree.\n");
	printf(" D)	Delete and initialise new tree.\n");
	printf(" E)	Quit\n\n");

	printf(" Enter a menu choice : ");
	scanf(" %c",&menuChoice);

	return menuChoice;
}

/**
 * main
 * Initilises an tree with a single node with a null value.
 *
 * @param
 * @return 0
 */
int main()
{
	SearchTree Tree;
	char menuChoice;
	int intElement;
	int i=0;
	char stringElement [22];
	int stringValue=0;

	// Initilise tree with a null element
	Tree = MakeEmpty( NULL );

	Tree = readFromFile(Tree);

	temparray = ((char*)malloc(22*sizeof(char)));
	strcpy(temparray,"null");

	Print(Tree);
	writeToFile(Tree);

	//printf("\n Temp Array : %s\n",temparray);

	/*
	do { 	// Do while the user does not want to exit the program
		menuChoice =  menu(menuChoice);
		stringValue=0;

		switch( menuChoice )  {
			case 'a': {

				printf("\n Inserting String : ");
				scanf(" %s",stringElement);

				for(i=0;i<strlen(stringElement);i++)
				{
					stringValue += *stringElement;
				}
				printf("\n String  : %s\n",stringElement);
				printf(" At Node : %d\n",stringValue);

				strcpy(temparray,stringElement);

				Tree = Insert( stringElement, stringValue, Tree );
				break;
			}
			case 'b': { // Searcing the tree for an integer
				int valueAtTree;
				printf("\n Search for integer : ");
				scanf(" %d",&intElement);
				Tree = Find( intElement, Tree );
				if(Tree!=NULL) {
					valueAtTree = Retrieve( Tree );
					printf("\n Element : %d is present in Tree \n",valueAtTree );
				}
				else {
					printf("\n Element : %d is not present in Tree \n",intElement );
				}
				break;
			}
			case 'c': { // Printing the current tree inorder
				printf("\n Printing Current Tree inorder :\n");
				Print(Tree);
				writeToFile(Tree);
				break;
			}
			case 'd': { // Emptying tree and creating a new tree
				printf("\n Emptying Tree and initialising new tree.");
				Tree = MakeEmpty( NULL );
				printf("\n");
				break;
			}
			case 'e': {
				printf(" \n Exit.");
				break;
			}
			default : {
				printf("\n Invalid Selection %d",menuChoice);
				break;
			}
		}
	}while(menuChoice!='E');
	*/

	printf("\n\n Program Complete.");
return 0;
}

