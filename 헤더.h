#include <cstdio>
#include <iostream>
using namespace std;

class Node
{
	int data;
	Node* link;
public:
	Node(int val = 0) : data(val), link ( NULL) {}
	Node* getLink() {
		return link;
	}
	void setLink(Node* next) {
		link = next;
	}
	void display() {
		cout << data;
	}
	bool hasData(int val) {
		return data == val;
	}

	void insertNext(Node* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}
	Node* removenext() {
		Node* removed = link;
		if (removed != NULL) {
			link = removed->link;
		}
		return removed;
	}

};