#include "mystack.h"
#include <stdlib.h>

#pragma region STACK FUNCTIONS

/// <summary>
/// Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, 
/// where a new element is added at one end (top) and an element is removed from that end only.  
/// Stack uses an encapsulated object of either vector or deque (by default) or list (sequential container class) as its underlying container, providing a specific set of member functions to access its elements.
/// </summary>
/// <param name="myStack"></param>
/// <param name="data"></param>
/// <returns></returns>
int push(MyStack* myStack, Data* data) {
	/// <summary>
	/// We use the push operation to create the LL to add the items.
	/// </summary>
	/// <param name="myStack"></param>
	/// <param name="data"></param>
	/// <returns></returns>
	MyStack* temp = new MyStack;
	/// <summary>
	/// To add data to the LL we add it to mystack.
	/// </summary>
	/// <param name="myStack"></param>
	/// <param name="data"></param>
	/// <returns></returns>
	temp->data = data->key;
	temp->link = myStack->link;
	myStack->link = temp;

	return 0;
}

/// <summary>
/// We do the pop operation to remove the item from the stack.
/// </summary>
/// <param name="myStack"></param>
/// <returns></returns>
Data* pop(MyStack* myStack) {
	if (myStack->link == NULL) {
		return NULL;
	}
	MyStack* temp = myStack->link;
	myStack->link = temp->link;
	Data* data = new Data();
	data->key = temp->data;
	delete(temp);
	return 0;
}
/// <summary>
/// We do the ball operation to look at the item from the stack.
/// </summary>
/// <param name="myStack"></param>
/// <returns></returns>
Data* top(MyStack* myStack)
{
	if (myStack->link == NULL) {
		return NULL;
	}
	else {
		Data* data = new Data();
		data->key = myStack->link->data;
	}
	return 0;
}
/// <summary>
/// We use bottom to move from the stack to the bottom item.
/// </summary>
/// <param name="myStack"></param>
/// <returns></returns>
Data* bottom(MyStack* myStack)
{
	if (myStack->link == NULL) {
		return NULL;
	}
	else {
		MyStack* temp = myStack->link;
		while (temp->link != NULL) {
			temp = temp->link;
		}
		Data* data = new Data();
		data->key = temp->data;
	}
	return 0;
}
/// <summary>
/// To display the item on the stack we use
/// </summary>
/// <param name="myStack"></param>
/// <returns></returns>
int stackLength(MyStack* myStack) {
	int count = 0;
	MyStack* temp = myStack->link;
	/// <summary>
	/// is the loop we use to count the items in the stack.
	/// </summary>
	/// <param name="myStack"></param>
	/// <returns></returns>
	while (temp != NULL) {
		count++;
		temp = temp->link;
	}
	return count;
}

#pragma endregion