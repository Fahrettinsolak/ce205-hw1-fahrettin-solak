#include "myqueue.h"
#include <malloc.h>

#pragma region QUEUE FUNCTIONS
/// <summary>
/// Queues are a type of container adaptors that operate in a first in first out (FIFO) type of arrangement.
/// Elements are inserted at the back (end) and are deleted from the front. 
/// Queues use an encapsulated object of deque or list (sequential container class) as its underlying container, 
/// providing a specific set of member functions to access its elements.
/// </summary>
MyQueue* head = NULL;
MyQueue* tail = NULL;

int enqueue(MyQueue* myQueue, Data* data) {
	/// <summary>
	/// We create a method with an int value to create a new linked list node.
	/// </summary>
	/// <param name="myQueue"></param>
	/// <param name="data"></param>
	/// <returns></returns>
	MyQueue* temp = (MyQueue*)malloc(sizeof(MyQueue));
	temp->data = data->key;
	temp->next = NULL;
	/// <summary>
	/// If the row is blank we use it to create new node both in front and back.
	/// </summary>
	/// <param name="myQueue"></param>
	/// <param name="data"></param>
	/// <returns></returns>
	if (head == NULL && tail == NULL) {
		head = tail = temp;
		return 1;
	}
	/// <summary>
	/// We use it to add the new node to the end of the row and replace the back.
	/// </summary>
	/// <param name="myQueue"></param>
	/// <param name="data"></param>
	/// <returns></returns>
	tail->next = temp;
	tail = temp;
	return 1;
}
/// <summary>
/// we use dequeue to remove the next item.
/// </summary>
/// <param name="myQueue"></param>
/// <returns></returns>
Data* dequeue(MyQueue* myQueue) {
	Data* data = (Data*)malloc(sizeof(Data));
	/// <summary>
	/// if queue is empty, return null.
	/// </summary>
	/// <param name="myQueue"></param>
	/// <returns></returns>
	if (head == NULL) {
		return NULL;
	}
	/// <summary>
	/// store previous front and move front one node ahead
	/// </summary>
	/// <param name="myQueue"></param>
	/// <returns></returns>
	if (head == tail) {
		data->key = head->data;
		head = tail = NULL;
		return data;
	}
	data->key = head->data;
	MyQueue* temp = head;
	head = head->next;
	delete(temp);
	return data;
}
/// <summary>
/// We use it to get the front item in the queue.
/// </summary>
/// <param name="myQueue"></param>
/// <returns></returns>
Data* front(MyQueue* myQueue) {
	Data* data = (Data*)malloc(sizeof(Data));
	if (front == NULL) {
		return NULL;
	}
	data->key = head->data;
	return data;
}
/// <summary>
/// We use it to queue the back element.
/// </summary>
/// <param name="myQueue"></param>
/// <returns></returns>
Data* back(MyQueue* myQueue) {
	Data* data = (Data*)malloc(sizeof(Data));
	if (back == NULL) {
		return NULL;
	}
	data->key = tail->data;
	return data;
}
/// <summary>
/// we use lenght to show all the items in the queue.
/// </summary>
/// <param name="myQueue"></param>
/// <returns></returns>
int queueLength(MyQueue* myQueue) {
	int length = 0;
	MyQueue* temp = head;
	while (temp != NULL) {
		length++;
		temp = temp->next;
	}
	return length;
}

#pragma endregion