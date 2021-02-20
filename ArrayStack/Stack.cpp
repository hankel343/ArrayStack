#include "Stack.h"

StackType::StackType()
{
	nMAX_ITEMS = 5;
	nTop = -1;
	pItems = new ItemType[nMAX_ITEMS];
}

bool StackType::IsEmpty() const
{
	return nTop == -1;
}

bool StackType::IsFull() const
{
	return (nTop == nMAX_ITEMS - 1);
}

void StackType::Push(ItemType item)
{
	if (IsFull() == true)	
		throw FullStack();
	else					
		pItems[++nTop] = item;
}

void StackType::Pop()
{
	if (IsEmpty() == true)
		throw EmptyStack();
	else
		nTop--;
}

ItemType StackType::Top() const
{
	if (IsEmpty() == true)
		throw EmptyStack();
	else
		return pItems[nTop];
}

StackType::~StackType()
{
	//Deallocates memory for the stack.
	delete[] pItems;
}

