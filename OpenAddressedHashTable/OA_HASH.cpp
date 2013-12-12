/**
 * OA_HASH
 * Open Addressed Hash tables
 * Initilises a new instance of the hash class for an initial table of type in and displays a menu
 * Menu allows for user input to execute a block of code from switch statement
 *  I allows for element to be inserted into hash table
 *  D deles an element in the hash table
 *  L looks up an element in the hash table
 *  S obtains the size of the table
 *  P prints the current table
 *  C creates a new table of user choice of type
 *  E exits the systems
 * Input for menu can accept either upper or lower case charachters
 * Input for elements in table are type specific to user selection of table
 * @ "Kyle Harrison"
 * @ (07/11/2011)
 */

// including c++ libaries
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <stdio.h>
#include <math.h>

// Using the standard name space
using namespace std;

// OA_Hash Class
//######################################################################################
template <class T>
class OA_HASH
{
	// private class variables
	int tableSize;
	int currentSize;

	vector <T> table;
	vector <int> markers;

	public:
			// public variables
			T value;
			string stringValue;
			char type;
			string tableName;


		// OA_HASH Constructors
		OA_HASH();
		OA_HASH(int);

		//hash functions
		int calculateHashValue(int value);
		int calculateHashValue(double value);
		int calculateHashValue(char value);
		int calculateHashValue(float value);
		int calculateHashValue(bool value);
		int calculateHashValue(string value);

		void initilise(int tableSize);
		void print();
		void insertion(int key);
		void deletion(int key);
		bool lookUp(int key, T element);
		int ProbeEmpty(int key);
		int sizeOfTable();
		int probeLast(int key);

		int getTableSize();
		void setTableSize(int tableSize);
		int size() { return currentSize; }

		char inputChar();
		float inputFloat();
		double inputDouble();
		bool inputBool();

		~OA_HASH();
};

/**
 * OA_HASH
 * default Constructor for objects
 */
template <class T>
OA_HASH<T>::OA_HASH()
{
	currentSize = 0;
	tableSize = 0;
	table.resize(tableSize);
	markers.resize(tableSize);
}

/**
 * OA_HASH
 * Constructor for objects accepting size parameter
 */
template <class T>
OA_HASH<T>::OA_HASH(int size)
{
	currentSize = 0;
	tableSize = size;
	table.resize(tableSize);
	markers.resize(tableSize);

	for(int i = 0; i<tableSize; i++)
	{
		markers.at(i)=0;
	}
}

/**
 * OA_HASH
 * default deconstructor for objects
 */
template <class T>
OA_HASH<T>::~OA_HASH()
{
	cout << tableName << " Object destroyed" << endl;
}

//######################################################################################

int inputValue();
template <class T>
char menu(OA_HASH <T> &table);
char createTable(char initialMenuChoice);

// Global tables
OA_HASH<int> initialTable;
OA_HASH<int> intTable;
OA_HASH<double> doubleTable;
OA_HASH<char> charTable;
OA_HASH<float> floatTable;
OA_HASH<bool> boolTable;
OA_HASH<string> stringTable;

/**
 * main
 * creates an initial table that allows the user to access the menu and create new tables
 * continues in a loop until the user chooses to exit the system
 * all tables are initilised from here before the menu function is called
 * @param  none
 * @return 0
 */
int main ()
{
	cout << "<---------------------------------------------->" << endl;
	cout << ""<<" 	Open Addressed Hash Tables" << endl;
	cout << "<---------------------------------------------->" << endl;
	cout << ""<<"  Author   : Kyle Harrison" << endl;
	cout << ""<<"  ID#      : 110009870" << endl;
	cout << ""<<"  Module   : AC21008 - Multi-Paradigm Programming " << endl;
	cout << ""<<"             and Data Structures" << endl;
	cout << ""<<"  Project  : Assignment 3" << endl;
	cout << ""<<"  Date     : 09/11/2011" << endl;
	cout << "<---------------------------------------------->" << endl;

	initialTable.type	='i';
	intTable.type		='i';
	doubleTable.type	='d';
	charTable.type		='c';
	floatTable.type		='f';
	boolTable.type		='b';
	stringTable.type	='s';

	initialTable.tableName	= "Initial Table";
	intTable.tableName 		= "Integer Table";
	doubleTable.tableName 	= "Double Table";
	charTable.tableName 	= "Char Table";
	floatTable.tableName 	= "Float Table";
	boolTable.tableName 	= "Bool Table";
	stringTable.tableName 	= "String Table";

	initialTable.initilise(10);

	char initialMenuChoice;
	char menuChoice;


			// Call initial menu
			do
			{
				initialMenuChoice = menu(initialTable);

				if(initialMenuChoice=='c')
				{
					menuChoice = createTable(initialMenuChoice);
					initialMenuChoice='e';
				}
			} while(initialMenuChoice!='e');

			// Call Menu that allows for new tables to be created and used
			char repeatMenu;
			do
			{
				if(menuChoice=='i')
				{
					do
					{
						repeatMenu = menu(intTable);

						if(repeatMenu=='c')
						{
							menuChoice = createTable(initialMenuChoice);
							repeatMenu='e';
						}
						else if(repeatMenu=='e')
						{
							menuChoice='e';
						}
					}while(repeatMenu!='e');
				}
				else if(menuChoice=='d')
				{
					do
					{
						repeatMenu = menu(doubleTable);

						if(repeatMenu=='c')
						{
							menuChoice = createTable(initialMenuChoice);
							repeatMenu='e';
						}
						else if(repeatMenu=='e')
						{
							menuChoice='e';
						}
					}while(repeatMenu!='e');
				}
				else if(menuChoice=='c')
				{
					do
					{
						repeatMenu = menu(charTable);

						if(repeatMenu=='c')
						{
							menuChoice = createTable(initialMenuChoice);
							repeatMenu='e';
						}
						else if(repeatMenu=='e')
						{
							menuChoice='e';
						}
					}while(repeatMenu!='e');
				}
				else if(menuChoice=='f')
				{
						do {
							repeatMenu = menu(floatTable);

							if(repeatMenu=='c')
							{
								menuChoice = createTable(initialMenuChoice);
								repeatMenu='e';
							}
							else if(repeatMenu=='e')
							{
								menuChoice='e';
							}
						}while(repeatMenu!='e');
				}
				else if(menuChoice=='s')
				{
					do
					{
						repeatMenu = menu(stringTable);

						if(repeatMenu=='c')
						{
								menuChoice = createTable(initialMenuChoice);
								repeatMenu='e';
						}
						else if(repeatMenu=='e')
						{
								menuChoice='e';
						}
					}while(repeatMenu!='e');
				}
				else if(menuChoice=='b')
				{
						do
						{
							repeatMenu = menu(boolTable);

							if(repeatMenu=='c')
							{
									menuChoice = createTable(initialMenuChoice);
									repeatMenu='e';
							}
							else if(repeatMenu=='e')
							{
									menuChoice='e';
							}
						}while(repeatMenu!='e');
				}
				// Exits the first loop
			} while(menuChoice!='e');
			return 0;
}

/**
 * initilise
 * Initilises the table to the size input by the user for each new table
 * if no value is passed as a parameter then user must enter size
 * @param  int tablesize
 * @return void
 */
template <class T>
void OA_HASH<T>::initilise(int tableSize)
	{
		if(tableSize<=0)
		{
			do
			{
				cout << "\n Table Size cannot be " << tableSize << endl;
				cout << " (Table size must be greater than zero." << endl;
				tableSize = inputValue();
			}
			while(tableSize<=0);
		}

		table.resize(tableSize);
		markers.resize(tableSize);

		for(int i=0; i<tableSize; i++)
		{
			markers.at(i)=0;
		}
		currentSize = tableSize;

		cout << "\n "<<tableName << " created of size " << tableSize << endl;
	}

/**
 * calculateHashValue
 * takes in a value and converts the value to a key for the hash table
 * @param  int value
 * @return int key
 */
template <class T>
int OA_HASH<T>::calculateHashValue(int value)
{
	int key = value % table.size();
	return key;
}

/**
 * calculateHashValue
 * takes in a value and converts the value to a key for the hash table
 * @param  double value
 * @return int key
 */
template <class T>
int OA_HASH<T>::calculateHashValue(double value)
{
	double key;
	int tableSize = table.size();
	key = fmod (value,tableSize);
	return key;
}

/**
 * calculateHashValue
 * takes in a value and converts the value to a key for the hash table
 * @param  char value
 * @return int key
 */
template <class T>
int OA_HASH<T>::calculateHashValue(char value)
{
	int key = static_cast<int>(value);
	key = key % table.size();
	return key;
}

/**
 * calculateHashValue
 * takes in a value and converts the value to a key for the hash table
 * @param  float value
 * @return int key
 */
template <class T>
int OA_HASH<T>::calculateHashValue(float value)
{
	float key = fmod (value,table.size());
	return key;
}

/**
 * calculateHashValue
 * takes in a value and converts the value to a key for the hash table
 * @param  bool value
 * @return int key
 */
template <class T>
int OA_HASH<T>::calculateHashValue(bool value)
{
	bool key = value % table.size();
	return key;
}

/**
 * calculateHashValue
 * takes in a value and converts the value to a key for the hash table
 * @param  string value
 * @return int key
 */
template <class T>
int OA_HASH<T>::calculateHashValue(string value)
{
	int key=0;

	int length = value.size();

	for(int index =0; index < length; index++)
	{
		int valueAtI = static_cast<int>(value[index]);
		key = key + valueAtI;
	}

	key = key % length;
	value=key;
	return key;
}

/**
 * inputValue
 * asks the user to enter a integer value and reads in a value from command line before returning it
 * @param  none
 * @return input
 */
int inputValue()
	{
		int input;
		bool inputValid = false;

		// do while input is not value
		do
		{	// try to read input
			try/**
    	 * inputElement
    	 * asks the user to enter a value and reads in a value from command line before returning it
    	 * @param  none
    	 * @return input
    	 */
			{
				// read input
				cout << "\n Enter Integer Number : ";
				cin >> input;

				if( cin.fail() )
				{
					throw 1;
				}
				inputValid=true;
			}
			// catch failed input and get new input
			catch ( int cinFail )
			{
				cout << "\n Value must be numeric integers, Please re-enter." << endl;
				inputValid=false;
				input=0;
				cin.clear();
			    	cin.get();
			}
			// catch invalid input and gets new input
		// ends loop when input is valid
		}while(inputValid==false);

		//cout << "input = " << input << endl;
		return input;
	}

/**
 * inputFloat
 * asks the user to enter a float value and reads in a value from command line before returning it
 * @param  none
 * @return input
 */
float inputFloat()
	{
		float input;
		bool inputValid = false;

		// do while input is not value
		do
		{	// try to read input
			try
			{
				// read input
				cout << "\n Enter Float Number : ";
				cin >> input;

				if( cin.fail() )
				{
					throw 1;
				}
				inputValid=true;
			}
			// catch failed input and get new input
			catch ( int cinFail )
			{
				cout << "\n Value must be numeric floats, Please re-enter." << endl;
				inputValid=false;
				input=0;
				cin.clear();
			    	cin.get();
			}
			// catch invalid input and gets new input
		// ends loop when input is valid
		}while(inputValid==false);

		//cout << "input = " << input << endl;
		return input;
	}

/**
 * inputDouble
 * asks the user to enter a integer value and reads in a value from command line before returning it
 * @param  none
 * @return input
 */
double inputDouble()
	{
		double input;
		bool inputValid = false;

		// do while input is not value
		do
		{	// try to read input
			try
			{
				// read input
				cout << "\n Enter Double Number : ";
				cin >> input;

				if( cin.fail() )
				{
					throw 1;
				}
				inputValid=true;
			}
			// catch failed input and get new input
			catch ( int cinFail )
			{
				cout << "\n Value must be numeric double, Please re-enter." << endl;
				inputValid=false;
				input=0;
				cin.clear();
			    cin.get();
			}
			// catch invalid input and gets new input
		// ends loop when input is valid
		}while(inputValid==false);

		//cout << "input = " << input << endl;
		return input;
	}

/**
 * inputBool
 * asks the user to enter a integer value and reads in a value from command line before returning it
 * @param  none
 * @return input
 */
bool inputBool()
	{
		bool input;
		bool inputValid = false;

		// do while input is not value
		do
		{	// try to read input
			try
			{
				// read input
				cout << "\n Enter Boolean Number : ";
				cin >> input;

				if( cin.fail() )
				{
					throw 1;
				}
				if(input<0 || input >1)
				{
					throw 1;
				}
				inputValid=true;
			}
			// catch failed input and get new input
			catch ( int cinFail )
			{
				cout << "\n Value must be booleans with a value of 0 or 1, Please re-enter." << endl;
				inputValid=false;
				input=0;
				cin.clear();
			    cin.get();
			}
			// catch invalid input and gets new input
		// ends loop when input is valid
		}while(inputValid==false);

		//cout << "input = " << input << endl;
		return input;
	}

/**
 * inputChar
 * asks the user to enter a integer value and reads in a value from command line before returning it
 * @param  none
 * @return input
 */
char inputChar()
	{
		char input;
		bool inputValid = false;

		// do while input is not value
		do
		{	// try to read input
			try
			{
				// read input
				cout << "\n Enter Single Character : ";
				cin >> input;

				input = tolower(input);
				if( cin.fail() )
				{
					throw 1;
				}
				else if(input<97||input>122)
				{
					throw 1;
				}
				inputValid=true;
			}
			// catch failed input and get new input
			catch ( int cinFail )
			{
				cout << "\n Value must be single char between a-z, Please re-enter." << endl;
				inputValid=false;
				input=0;
				cin.clear();
			    	cin.get();
			}
			// catch invalid input and gets new input
		// ends loop when input is valid
		}while(inputValid==false);

		//cout << "input = " << input << endl;
		return input;
	}

/**
 * deletion
 * deletes the given element from the hash table
 * @param  int key,T element
 * @return none
 */
template <class T>
void OA_HASH<T>::deletion(int key)
{
	int lastProbe=-1;

	// call last probe to find the last element of that value inserted
	lastProbe=probeLast(key);
	//	cout << lastProbe << endl;

	// if last probe returns -1 then there is no element to delete
	if(lastProbe==-1)
	{
		cout << "\n No element to delete in table. " << endl;
	}
	// delete value from location returnd from lastprobe.
	else if (lastProbe>=0)
	{
		// Remove element from table
		markers.at(lastProbe)=0;
		table.at(lastProbe)=' ';

		cout << "\n Value : " << value << " from location : " << lastProbe << " Deleted" << endl;
	}
}

/**
 * print
 * prints out the current state of the hash table
 * @param  none
 * @return none
 */
template<class T>
void OA_HASH<T>::print()
{
		int tableSize= table.size();
		cout << endl;

		// For each element in the table
		for(int i=0; i<tableSize; i++)
		{
			if(type!='s')
			{
				cout << " " << i << " : ";
			}
			else if (type=='s')
			{
				cout << " " << i << " :";
			}

			// if not default value then display value else 0
			if(markers.at(i)>0)
			{
				cout << table.at(i) << " ";
			}
			else
			{
				if(type=='s')
				{
					cout << " -";
				}
				else
				{
					cout << '-';
				}
			}

			// if element has no size then output zero
			if(tableSize==0)
			{
				cout << 0 << endl;
			}
			else
			{
				// new line at the end of each iteration of the loop
				cout << endl;
			}
		}
}

/**
 * Insertion
 * checks to see if element can be inserted into table
 * if element does not exist and table is not full then it is inserted at its key
 * if key is taken then element is placed at next available location by linear probing.
 * @param  int key
 * @return void
 */
template <class T>
void OA_HASH<T>::insertion(int key)
{
		bool validInput=false;
		if(type !='s')
		{
			validInput = lookUp(key,value);
			if(validInput==true)
			{
				cout << "\n Value "<< value << " already exists in table " << endl;
			}
		}
		else if (type=='s')
		{
			value =' ';
			int size = stringValue.size();
			for(int i =0; i < size; i++)
			{
				value=value+stringValue.at(i);
			}

			validInput = lookUp(key,value);
			if(validInput==true)
			{
				cout << "\n Value "<< value << " already exists in table " << endl;
			}
		}

		if(validInput==false)
		{
		T tableValue;

		if(type != 's')
		{
			tableValue= value;

			// if value at element is default (-1) then insert
			if(markers.at(key)==0)
			{
					table.at(key)=value;
					markers.at(key)=1;
					cout << "\n Value "<< value << " inserted at Position " << key <<  endl;
			}
			else
			{
				int probeAt=ProbeEmpty(key);

				// if probe location does not return locatin of key then
				if(key!=probeAt)
				{
					// insert value at probed location
					table.at(probeAt)=value;
					markers.at(probeAt)=1;
					cout << "\n Value "<< value << " inserted at Position " << probeAt <<  endl;
				}
			}
		}
		else
		{
				int size = stringValue.size();

				// if value at element is default (-1) then insert
					if(markers.at(key)==0)
					{
						table.at(key)=' ';
						for(int i =0; i < size; i++)
						{
							table.at(key)=table.at(key)+stringValue.at(i);
						}

						markers.at(key)=1;
						cout << "\n Value"<< table.at(key) << " inserted at Position " << key <<  endl;
						}
						else
						{
							// probe for empty space.
							int probeAt=ProbeEmpty(key);

							// if probe location does not return locatin of key then
							if(key!=probeAt)
							{
								table.at(probeAt)=' ';
								for(int i =0; i < size; i++)
								{
										table.at(probeAt)=table.at(probeAt)+stringValue.at(i);
								}
								markers.at(probeAt)=1;
								cout << "\n Value"<< table.at(key) << " inserted at Position " << probeAt <<  endl;
							}
						}
		}
		}// end input validation
	}

/**
 * sizeOfTable
 * returns the number of elements stored in the hash table
 * @param  none
 * @return int sizeOfTable
 */
template <class T>
int OA_HASH<T>::sizeOfTable()
{
	int sizeOfTable =0;
	int size = table.size();

	// getting size of table by checking if table element store a value or default
	for(int i =0; i < size; i++)
	{
		// if element stores a value then increment by 1
		if(markers.at(i)==1)
		{
			sizeOfTable = sizeOfTable + 1;
		}
	}

	// Table is full when 100 elements are in the table
	if(sizeOfTable==size)
	{
		cout << "\n<---------------------------------------------->" << endl;
		cout << ""<<"		   Table is Full" << endl;
		cout << "<---------------------------------------------->" << endl;
	}
	return sizeOfTable;
}

/**
 * probeLast
 * find the last instance of an element and returns position
 * if no element then returns -1 which cannot exist inside table
 * @param  int key
 * @return int lastProbe
 */
template <class T>
int OA_HASH<T>::probeLast(int key)
{
		bool probingComplete=false;
		int probeStarting=key;
		int probeAt=key;
		int lastProbe=-1;

		if( type=='s')
		{
				int size = stringValue.size();
				value=' ';

				for(int i =0; i < size; i++)
				{
					value=value+stringValue.at(i);
				}
		}

		int i =0;
		// Do while probe is not equal to starting probe or probe does not find empty space
		do
		{
			i++;
			if(i>currentSize)
			{
				probingComplete=true;
			}
			if(table.at(probeAt)==value && markers.at(probeAt)==1)
			{
				lastProbe=probeAt;
			}

			probeAt=probeAt+1;

			// if probe reaches end of table before searching all then move to element 1 of table
			if(probeAt==(currentSize-1))
			{
				if(table.at(probeAt)==value && markers.at(probeAt)==1)
				{
					lastProbe=probeAt;
				}
				probeAt=0;
			}
			if(probeAt>=currentSize)
			{

				probeAt=0;
			}

			// end probing if returns to startion element
			if(probeAt==probeStarting)
			{
				if(lastProbe==-1 && table.at(probeAt)==value && markers.at(probeAt)==1)
				{
					lastProbe=probeAt;
				}
				probingComplete=true;
			}
		}while(probingComplete!=true);

	return lastProbe;
}

/**
 * ProbeEmpty
 * find the the next available empty cell in the table and returns position
 * if no element then returns key which cannot be inserted at.
 * @param  int key
 * @return int lastProbe
 */
template<class T>
int OA_HASH<T>::ProbeEmpty(int key)
	{
		bool probingComplete=false;
		int probeStarting=key;
		int probeAt=key;

		// Do while probe is not equal to starting probe
		do
		{
			// move probe by 1 incrementation
			probeAt=probeAt+1;

			// if probe reaches end of table before searching all then move to element 1 of table
			int tableSize = table.size();
			if(probeAt==tableSize)
			{
				probeAt=0;
			}

			// end probing if the probe has turned to start location
			if(probeAt==probeStarting)
			{
				cout << "\n Value : "<< value << " cannot be inserted." << endl;

				cout << "\n<---------------------------------------------->" << endl;
				cout << ""<<"		   Table is Full" << endl;
				cout << "<---------------------------------------------->" << endl;

				probingComplete=true;
			}

			// end proving if a free location is found
			if(markers.at(probeAt)==0)
			{
				probingComplete=true;
			}
		}while(probingComplete!=true);
	return probeAt;
	}

/**
 * createTable
 * initilises table of chosen type to size selected by user
 * @param  char initialMenuChoice
 * @return char menuChoice
 */
char createTable(char initialMenuChoice)
{
	int sizeOfTable=0;
	char menuChoice;

	cout << "\n<---------------------------------------------->" << endl;
	cout << ""<<"		   NEW TABLE" << endl;
	cout << "<---------------------------------------------->" << endl;

	cout << "\n Size of new Table " << endl;
	//cout << "\n Enter Size : ";
	sizeOfTable = inputValue();

	bool menuChoiceValid=false;
	do
	{
	cout << "\n Select Type :" << endl;
	cout << " I	- Integer" << endl;
	cout << " C	- Char" << endl;
	cout << " D	- Double" << endl;
	cout << " F	- Float" << endl;
	cout << " B	- Boolean" << endl;
	cout << " S	- String " << endl;
	//cout << "\n Enter Type : ";

	menuChoice=inputChar();
	menuChoice = tolower(menuChoice);

	switch(menuChoice)
	{
		case 'i':
		{
			intTable.initilise(sizeOfTable);
			menuChoiceValid=true;
			break;
		}
		case 'd':
		{
			doubleTable.initilise(sizeOfTable);
			menuChoiceValid=true;
			break;
		}
		case 'c':
		{
			charTable.initilise(sizeOfTable);
			menuChoiceValid=true;
			break;
		}
		case 'f':
		{
			floatTable.initilise(sizeOfTable);
			menuChoiceValid=true;
			break;
		}
		case 'b':
		{
			boolTable.initilise(sizeOfTable);
			menuChoiceValid=true;
			break;
		}
		case 's':
		{
			stringTable.initilise(sizeOfTable);
			menuChoiceValid=true;
			break;
		}
		default:
		 {
		// If no case is selected, input did not match a case and was invalid
			cout << "\n Invalid Choice, Please try again" << endl;
			break;
		 }
	}
	}while(menuChoiceValid!=true);

	return menuChoice;
}

/**
 * menu
 * runs until the uses selects e to exit the system
 * can be used to access any of the functions the user requires by passing table object
 * @param  T element
 * @return boolean
 */
template <class T>
char menu(OA_HASH<T> &table)
{
		char tableType = table.type;

		// creating a variable for user choice
		char userChoice;

		// Displaying menu
		cout << "\n<---------------------------------------------->" << endl;
		cout << ""<<"		   MAIN MENU" << endl;
		cout << "<---------------------------------------------->" << endl;
		cout << "\n " << table.tableName << endl;
		cout << "\n Press :" << endl;
		cout << "  I - Insert an element into the hash table" << endl;
		cout << "  D - Delete an element into the hash table" << endl;
		cout << "  L - Look Up an element into the hash table" << endl;
		cout << "  S - Obtain the Size of the the table" << endl;
		cout << "  P - Print the current table" << endl;
		cout << "  C - Create new table" << endl;
		cout << "  E - Exit the System" << endl;

		// asking for input from command line
		cout << "" << "\n   Enter character : " ;
		cin >> userChoice;

		cout << "\n<---------------------------------------------->" << endl;

		// Converts upper case characters to lower
		userChoice = tolower(userChoice);

		int key 		= 0;

		// Executes case depending on user input
		switch (userChoice)
		{
			//Insert element into hash table
		 	 case 'i':
			{
				cout << "\n<---------------------------------------------->" << endl;
				cout << ""<<"		   INSERTION" << endl;
				cout << "<---------------------------------------------->" << endl;

				if(tableType=='i')
				{
						int value;
						//cout << " Enter Integer" << endl;
						value = inputValue();
						table.value=value;
						key = table.calculateHashValue(value);
						table.insertion(key);
				}
				else if(tableType=='d')
				{
						double value;
						//cout << " Enter double" << endl;
						//cin >> value;
						value = inputDouble();
						table.value=value;
						key = table.calculateHashValue(value);
						table.insertion(key);
				}
				else if(tableType=='c')
				{
						char value;
						//cout << " Enter char" << endl;
						//cin >> value;
						value = inputChar();
						table.value=value;
						key = table.calculateHashValue(value);
						table.insertion(key);
				}
				else if(tableType=='f')
				{
						float value;
						//cout << " Enter float" << endl;
						//cin >> value;
						value = inputFloat();
						table.value=value;
						key = table.calculateHashValue(value);
						table.insertion(key);
				}
				else if(tableType=='b')
				{
					bool value;
					//cout << " Enter bool" << endl;
					//cin >> value;
					value = inputBool();
					table.value=value;
					key = table.calculateHashValue(value);
					table.insertion(key);
				}
				else if(tableType=='s')
				{
					string value;
					cout << " Enter String" << endl;
					cin >> value;

					table.stringValue = value;
					key=table.calculateHashValue(table.stringValue);
					table.insertion(key);
				}

				break;
			}
			// Delete element from hash table
			 case 'd':
			{
				cout << "\n<---------------------------------------------->" << endl;
				cout << ""<<"		   DELETION" << endl;
				cout << "<---------------------------------------------->" << endl;

				if(tableType=='i')
				{
						int value;
						cout << "Enter Integer" << endl;
						value = inputValue();
						key = table.calculateHashValue(value);
						table.value=value;
						table.deletion(key);
				}
				else if(tableType=='d')
				{
						double value;
						value = inputDouble();
						table.value=value;
						key = table.calculateHashValue(value);
						table.deletion(key);
				}
				else if(tableType=='c')
				{
						char value;
						value = inputChar();
						table.value=value;
						key = table.calculateHashValue(value);
						table.deletion(key);
				}
				else if(tableType=='f')
				{
						float value;
						value = inputFloat();
						table.value=value;
						key = table.calculateHashValue(value);
						table.deletion(key);
				}
				else if(tableType=='b')
				{
						bool value;
						value = inputBool();
						table.value=value;
						key = table.calculateHashValue(value);
						table.deletion(key);
				}
				else if(tableType=='s')
				{
						string value;
						cout << "Enter String" << endl;
						cin >> value;
						table.stringValue = value;
						key = table.calculateHashValue(value);
						table.deletion(key);
				}

				break;
			}

			// look up element from hash table
			 case 'l':
			{
				cout << "\n<---------------------------------------------->" << endl;
				cout << ""<<"		   LOOK UP" << endl;
				cout << "<---------------------------------------------->" << endl;

				// asks for keyboard input to look up element in table
				cout << " Which value would you like to look up ? " << endl;

				T element;

				if(table.type=='i')
				{
					element = inputValue();
				}
				else
				{
					cout << "\n Enter value : ";
					cin >> element;
				}

				int key = table.calculateHashValue(element);

				// checks if element is in table and returns true or false
				table.value = element;
				bool present = table.lookUp(key,element);

				string elementPresent = "NULL";

				// changes 0 and 1 to true or false text
				if(present==1)
				{
					elementPresent = "True";
				}
				else
				{
					elementPresent = "False";
				}

				cout << "\n Value "<< element<< " in table = " << elementPresent << endl;
				break;
			}
			// look up element from hash table
			 case 's':
			{
				cout << "\n Elements in table = " << table.sizeOfTable()  << endl;
				cout << " Size of Table = " << table.size() << endl;
				break;
			}
			// look up element from hash table
			 case 'p':
			{
				table.print();
				break;
			}
			 case 'c':
			 {
				 return userChoice;
				 break;
			 }
			case 'e':
			{
				cout << "\n<---------------------------------------------->" << endl;
				cout << ""<<"		   EXIT" << endl;
				cout << "<---------------------------------------------->\n" << endl;

				// Returns true to exit the menu ending the program
				return userChoice;
				break;
			}
			default:
			   {
				// If no case is selected, input did not match a case and was invalid
				cout << "\n Invalid Choice, Please try again" << endl;
				break;
			    }
		} // end switch

	// returns false to run menu again
	return userChoice;
}

/**
 * lookUp
 * returns true if element is in the hash table, false otherwise
 * @param  T element
 * @return boolean
 */
template <class T>
bool OA_HASH<T>::lookUp(int key, T element)
	{
		int lastProbe=(-1);

		// call last probe to find last instance of value
		lastProbe=probeLast(key);

		// if returned -1 then value is not in table
		if(lastProbe==(-1))
		{
			// check location of element at the key location
			if(table.at(key)==element)
			{
				// element in table
				if(markers.at(key)==1)
				{
					return true;
				}
			}
			else
			{
				// element not in table
				return false;
			}
		}
		else if (lastProbe>=0)
		{
			// element in table at last probe
			return true;
		}
		return false;
	}
