#ifndef STACK_H
#define STACK_H

#include "ItemType.h"

class FullStack {};
class EmptyStack {};

class StackType
{
private:
	int nMAX_ITEMS;
	int nTop;
	ItemType *pItems;

public:
	//Constructor:
	StackType();
	//Pre: None
	//Post: A stack object is created with default record values.

	~StackType();
	
	bool IsEmpty() const;
	//Pre: A stack object exists and the call to the method is apart of a try-catch clause
	//Post: A boolean value is returned based on whether or not the stack is empty.

	bool IsFull() const;
	//Pre: A stack object exists and the call to the method is apart of a try-catch clause
	//Post: A boolean value is return based on whether the stack is full.

	void Push(ItemType item);
	//Pre: A stack object exists and the call to the method is apart of a try-catch clause
	//Post: A new item is pushed onto the stack.

	void Pop();
	//Pre: A stack object exists and the call to the method is apart of a try-catch clause.
	//Post: The top most item is removed from the stack. (top element is not returned).

	ItemType Top() const;
	//Pre: A stack object exists and the call to the method is apart of a try-catch clause.
	//Post: The top most element in the stack is returned.
};

#endif STACK_H