#include <iostream>
#include "Stack.h"


using namespace std;

void ProcessInput(char input, StackType &StackObj);
void PushCase(StackType &StackObj);

int main()
{
	char input;
	StackType StackObj;

	cout << "This program allows you to perform basic operations on a stack ADT.\n";
	do
	{
		cout << "Enter the operation that you would like to perform: \n\n";
		cout << "1 - Push a new element to the stack.\n";
		cout << "2 - Pop an element from the stack.\n";
		cout << "3 - View the top element of the stack.\n";
		cout << "Q - Quit.\n";
		cout << "Choice: ";
		cin >> input;

		system("cls");

		ProcessInput(input, StackObj);
	} while (toupper(input) != 'Q');

	cout << "Goodbye...\n";
	return 0;
}

void ProcessInput(char input, StackType& StackObj)
{
	switch (toupper(input))
	{
	case '1':
		try
		{
			PushCase(StackObj);
		}
		catch (FullStack overflow)
		{
			cerr << "===============================\n";
			cerr << "Exception: The stack is full.\n";
			cerr << "===============================\n";
		}
		break;

	case '2':
		try
		{
			StackObj.Pop();
			cout << "The top most element has been removed from the stack.\n";
		}
		catch (EmptyStack underflow)
		{
			cerr << "===============================\n";
			cerr << "Exception: The stack is empty.\n";
			cerr << "===============================\n";
		}
		break;

	case '3':
		try
		{
			cout << "The element at the top of the stack is: " << StackObj.Top().Get() << endl;
		}
		catch (EmptyStack underflow)
		{
			cerr << "===============================\n";
			cerr << "Exception: The stack is empty.\n";
			cerr << "===============================\n";
		}
		break;

	case 'Q':
		break;

	default:
		cout << "Unrecognized input - please try again.\n";
	}
}

void PushCase(StackType &StackObj)
{
	int nNewItemData;
	ItemType iNewItem;
	cout << "Enter the item that you would like to add to the list.\n";
	cout << "Item: ";
	cin >> nNewItemData;

	iNewItem.Set(nNewItemData);
	StackObj.Push(iNewItem);

	cout << nNewItemData << " has been added to the stack.\n";
}