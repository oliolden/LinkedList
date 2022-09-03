#pragma once

template <typename T>
struct Node {
	Node(T data);
	~Node();

	T value;
	Node* next = nullptr;
};

template <typename T>
class LinkedList {
public:
	void Add(int index, T value);
	void AddFirst(T value);
	void AddLast(T value);
	//void AddAfter(Node<T> *node, T value);
	//void AddBefore(Node<T> *node, T value);
	int Size();
	bool Contains(T value);
	bool Remove(T value);
	T GetFirst();
	T GetLast();
	void Clear();
	void Print();

private:
	Node<T>* head = nullptr;
};

