#pragma once
#ifndef X
#define FC1016
#endif // !X
#include <iostream>
#include <cstdlib>


using namespace std;

#define max 100



class Circular
{
public:
	int front;
	int rear;
	int data[max];

	Circular() {
		front = 0;
		rear = 0;
	}
	bool isEmpty() {
		return front == rear;
	}
	bool isFull() {
		return (rear + 1 ) % max == front;
	}
	void enqueue(int x) {
		rear = (rear + 1) % max;
		data[rear] = x;
	}
	int dequeue() {
		front = (front + 1) % max;
		return data[front];
	}
	int peek() {
		return data[(front + 1) % max];
	}
	void display() {
		int tmp = 0;
		if (front < rear) {
			tmp = rear;
		}
		else {
			tmp = (rear + max);
		}
		for (int i = front + 1; i <= tmp; i++)
		{
			cout << "큐의 내용 " << endl;
			cout << data[i] << " ";
		}
	}
};