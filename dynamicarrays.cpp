#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


/* takes input and returns dynamic array with the added entry*/
string* addEntry(string* dynamicArray, int &size, string newEntry);
/* takes the entry that needs to be deleted and returns a new array without it*/
string* deleteEntry(string *dynamicArray, int &size, string entryToDelete);
/* loops through the array and prints out the values*/
void print(string *dynamicArray, int size);


int main()
{
	//initializing an array with 5 strings
	int size = 5;
	string *names = new string[size];
	names[0] = "neil";
	names[1] = "chris";
	names[2] = "heather";
	names[3] = "walt";
	names[4] = "apu";

	cout << "Initial list:" << endl;
	print(names, size);

	//names to be added with the add entry function and print out
	names = addEntry(names, size, "ned");
	names = addEntry(names, size, "seymour");
	cout << "After adding names:" << endl;
	print(names, size);

	//delete names and print list with removed names
	names = deleteEntry(names, size, "chris");
	names = deleteEntry(names, size, "joe");
	names = deleteEntry(names, size, "ned");
	cout << "After deleting names:" << endl;
	print(names, size);

	//delete the array
	delete[] names;
	return 0;
}

//create new dynamic array  size +1 for new entry in the array, then copy all the elements in the old array onto the new array and copy the new entry to the end of the array, increment size and delete the array before returning the new array */
string *addEntry(string *dynamicArray, int &size, string newEntry)
{
	string *newArray = new string[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = dynamicArray[i];
	}
	newArray[size] = newEntry;
	size++;
	delete[] dynamicArray;
	return newArray;
}
// create dynamic array for the result, then search for item to delete (-1) indicates item to delete was not found if it is found it will be greater than or equal to 0, for loop to loop through the array if element is found to delete store i to idex to delete and break to end loop. if not found (-1) return the original array, if found new array with a size of -1, loop through original array and copy all elements into new array except for element that whose indexed was save if found by index of entry to delete. delete original array and return the new resulting array if an item is removed then the array is decremented accordingly.
string *deleteEntry(string *dynamicArray, int &size, string entryToDelete)
{
	string *result = dynamicArray;
	int index_of_entry_to_delete = -1;
	for (int i = 0; i < size; i++)
	{
		if (dynamicArray[i] == entryToDelete)
		{
			index_of_entry_to_delete = i;
			break;
		}
	}
	if (index_of_entry_to_delete == -1)
	{
		return result;

	}
	else {
		result = new string[size - 1];
		int index_new_array = 0;
			for (int i = 0; i < size; i++)
			{
				if (i!= index_of_entry_to_delete)
				{
					result[index_new_array] = dynamicArray[i];
					index_new_array++;
				}
				else
				{

				}
			}
			size--;
		delete[] dynamicArray;
	}
	return result;
	
}

//prints each element in array
void print(string *dynamicArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i << ":" << dynamicArray[i] << endl;
	}
	cout << endl;
}