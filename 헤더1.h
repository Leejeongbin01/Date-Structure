#include "Çì´õ.h"

class LinkedList
{
	Node org;
public:
	LinkedList() : org(0) {}
	~LinkedList() { clear(); }
	void clear() {
		while (!isEmpty()) {
			delete remove(0);
		}
	}
	Node* getHead() {
		return org.getLink();
	}
	bool isEmpty() {
		return getHead() == NULL;
	}
	Node* getEntry(int pos) {
		Node* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink()) {
			if (n == NULL) {
				break;
			}
		}
		return n;
	}
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			prev->insertNext(n);
		}
	}
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev->removenext();
	}
	Node* find(int pos) {
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			if (p->hasData(pos)) {
				return p;
			}
		}
		return NULL;
	}
	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removenext();
			prev->insertNext(n);
		}
	}
	int size() {
		int cnt = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			cnt++;
		}
		return cnt;
	}
	void display() {
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			p->display();
		}
		cout << endl;
	}
	void reverse() {
		int cnt = 0;
		for (int i = 0; i < size(); i++)
		{
			Node* p = remove(size() - 1);
			insert(cnt++, p);
		}
	}
	void merge(LinkedList* that) {
		while (!that->isEmpty()) {
			Node* p = that->remove(0);
			insert(size(), p);
		}
	}
};