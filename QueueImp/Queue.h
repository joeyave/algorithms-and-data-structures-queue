#pragma once

template <class T>
class Queue
{
private:
	struct Node
	{
		T val;
		Node* next;

		Node(T _val, Node* _next)
		{
			val = _val;
			next = _next;
		}
	};

	Node* front;
	Node* rear;

public:
	// Constructors.
	Queue<T>()
	{
		front = nullptr;
		rear = nullptr;
	}

	bool empty()
	{
		return front == nullptr;
	}

	void enqueue(T val)
	{
		Node* temp = new Node(val, nullptr);

		// If queue is empty,
		// new Node is front and rear.
		if (rear == nullptr)
		{
			front = rear = temp;
			std::cout << val << " was enqueued (empty)." << std::endl;
			return;
		}

		rear->next = temp;
		rear = temp;

		std::cout << val << " was enqueued." << std::endl;
	}

	T dequeue()
	{
		Node* temp = front;
		T dequeued = temp->val;
		front = front->next;
		delete temp;

		if (front == nullptr)
			rear = nullptr;

		std::cout << dequeued << " was dequeued." << std::endl;
		return dequeued;
	}

	void swap()
	{
		T temp = front->val;
		front->val = rear->val;
		rear->val = temp;
	}

	void print()
	{
		if (empty()) 
			std::cout << "Queue is empty." << std::endl;

		Node* trav = front;
		while (trav)
		{
			std::cout << trav->val << " ";
			trav = trav->next;
		}
		std::cout << std::endl;
	}

	void reverse()
	{
		if (empty()) return;

		T data = dequeue();
		reverse();
		enqueue(data);
	}

	void destroy()
	{
		if (empty()) return;

		Node* temp = front;
		front = front->next;
		destroy();
		delete temp;
	}

	bool contains(T val)
	{
		if (empty()) return false;

		Node* trav = front;
		while (trav)
		{
			if (trav->val == val) return true;
			trav = trav->next;
		}
		return false;
	}
};

