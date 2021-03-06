#include <bits/stdc++.h>
using namespace std;

// Class defination for queue
template <class X>
class Queue {

private:
	// Stores the frontIndex
	int frontIndex;

	// Stores the back Index
	int backIndex;

	// Stores the array
	X* arr;

	// Stores the sizeof queue
	int sizeVar;

	// Stores the size of array
	int capacityVar = 4;

public:
	// Queue class constructor
	Queue()
	{
		arr = new X[capacityVar];
		frontIndex = backIndex = -1;
		sizeVar = 0;
	}

	// Function Methods
	bool empty();
	bool full();
	void push(X x);
	void pop();
	X front();
	X back();
	int capacity();
	int size();
};

// Find the capacity of queue
template <class X>
int Queue<X>::capacity()
{
	return capacityVar;
}

// Find the number of elements
// present in Queue
template <class X>
int Queue<X>::size()
{
	return sizeVar;
}

// Function to check if
// Queue is empty or not
template <class X>
bool Queue<X>::empty()
{
	if (frontIndex == -1
		&& backIndex == -1)
		return true;
	else
		return false;
}

// Function to check if the queue
// is full or not
template <class X>
bool Queue<X>::full()
{
	if (sizeVar == capacityVar)
		return true;
	else
		return false;
}

// Function to find the front element
// of the queue
template <class X>
X Queue<X>::front()
{
	// If queue is empty
	if (empty()) {
		cout << "Queue underflow"
			<< endl;
		abort();
	}

	return arr[frontIndex];
}

// Function to find the last element
// of the Queue
template <class X>
X Queue<X>::back()
{
	if (empty()) {
		cout << "Queue underflow"
			<< endl;
		abort();
	}
	return arr[backIndex];
}

// Function to insert the element
// to the rear end of the queue
template <class X>
void Queue<X>::push(X x)
{
	if (full()) {

		// If the queue is full, then
		// double the capacity
		capacityVar = capacityVar * 2;

		// Initialize new array of
		// double size
		X* temp = new X[capacityVar];

		// Copy the elements of the
		// previous array
		for (int i = 0; i < sizeVar; i++)
			temp[i] = arr[i];

		// Deallocate the memory
		// of previous array
		delete[] arr;
		arr = temp;
	}

	// If size is zero
	if (empty()) {

		frontIndex = backIndex = 0;
		arr[backIndex] = x;
		sizeVar++;
		return;
	}

	// Increment the backIndex
	backIndex = (backIndex + 1) % capacityVar;
	arr[backIndex] = x;
	sizeVar++;

	return;
}

// Function to pop an element from
// front end of the queue
template <class X>
void Queue<X>::pop()
{
	// If queue is empty
	if (empty()) {
		cout << "Queue underflow"
			<< endl;
		abort();
	}

	// If there is only one character
	if (frontIndex == backIndex) {

		// Mark Queue as empty
		// and decrement sizeVar
		frontIndex = backIndex = -1;
		sizeVar--;
		return;
	}

	// Increment frontIndex cyclically
	// using modulo arithmetic
	frontIndex = (frontIndex + 1) % capacityVar;
	sizeVar--;

	return;
}

// Driver Code
int main()
{
	// Queue initialization
	Queue<int> q;

	// Iterate the range [1, 100]
	for (int i = 1; i < 100; i++)
		q.push(i);

	// Print the current capacity
	cout << "Current capacity "
		<< q.capacity() << endl;

	// Print current size
	cout << "Current size "
		<< q.size() << endl;

	// Print front elements of queue
	cout << "Front element "
		<< q.front() << endl;

	// Print last element of the queue
	cout << "Rear element "
		<< q.back() << endl;

	cout << endl;

	cout << "Pop an element" << endl;

	// Pop an element from the queue
	q.pop();

	cout << "Pop an element" << endl;

	// Pop an element from the queue
	q.pop();

	cout << endl;

	// Print the current capacity
	cout << "Current capacity "
		<< q.capacity() << endl;

	// Print current size
	cout << "Current size "
		<< q.size() << endl;

	// Print front elements of queue
	cout << "Front element "
		<< q.front() << endl;

	// Print last element of the queue
	cout << "Rear element "
		<< q.back() << endl;

	return 0;
}
/*
Output:

Current capacity 128
Current size 99
Front element 1
Rear element 99

Pop an element
Pop an element

Current capacity 128
Current size 97
Front element 3
Rear element 99
*/