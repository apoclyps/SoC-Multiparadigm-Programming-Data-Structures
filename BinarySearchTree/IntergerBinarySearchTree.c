/**
 * BinarySearchTree.c
 * The binary search tree runs on a continuous basis until the user selects to quit.
 * The following options are available via the menu and call the appropriate function.
 * Integer binary search tree
 * Inserts an integer into the tree
 * Checks if a given integer is in the tree
 * Prints out the current tree inorder
 * Frees the entire tree, cleaning up memory and initialise a new tree
 * Quit the program
 * @ "Kyle Harrison"
 * @ (02/11/2011)
 */

#include <stdio.h>

typedef int ElementType;

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty( SearchTree Tree );
Position Find( ElementType ElementAt, SearchTree Tree );
Position FindMin( SearchTree Tree );
Position FindMax( SearchTree Tree );
SearchTree Insert( ElementType ElementAt, SearchTree Tree );
SearchTree Delete( ElementType ElementAt, SearchTree Tree );
SearchTree Print ( SearchTree Tree );
ElementType Retrieve( Position Ptr );

struct TreeNode{
	ElementType Element;			// Data Item
    SearchTree  LeftNode;		// pointer to left node
    SearchTree  RightNode;		// pointer to right node
};

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
Insert( ElementType ElementAt, SearchTree Tree )
{
	if( Tree == NULL )
	{
		// Create and return a one-node tree
		Tree = malloc( sizeof( struct TreeNode ) );

		if( Tree == NULL ) { // If no space is available tree cannot be  malloced
			printf("\n Out of space!!!");
		}

		else{ // Adding the element into the tree and creating null left and right nodes.
			Tree->Element = ElementAt;
			Tree->LeftNode = Tree->RightNode = NULL;
			printf("\n Element : %d inserted in table",  ElementAt);
		}
	}
	else if( ElementAt < Tree->Element ) {
		// Inserting a element when the tree exists and element being
		//inserted is less than element at the current tree element
		Tree->LeftNode = Insert( ElementAt, Tree->LeftNode );
	}
	else if( ElementAt > Tree->Element ) {
		// inserting an element when the tree exists and the element being
		// inserted is greater than teh element at the current tree element.
		Tree->RightNode = Insert( ElementAt, Tree->RightNode );
	}
	else // Else ElementAt is in the tree already and nothing needs to be done.
	{
		printf("\n Element : %d is already in table",  ElementAt);
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
	return Ptr->Element;
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
		printf ( " %d ", Retrieve(TreeNode) );
		Print(TreeNode->RightNode);
	}
	return 0;
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

	// Initilise tree with a null element
	Tree = MakeEmpty( NULL );

	do { 	// Do while the user does not want to exit the program
		menuChoice =  menu(menuChoice);

		switch( menuChoice )  {
			case 'a': {	// Inserting a integer to tree
				printf("\n Inserting Integer : ");
				scanf(" %d",&intElement);
				Tree = Insert( intElement, Tree );
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
return 0;
}

