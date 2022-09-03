#pragma once
template <typename T>
class LinkedList {
	Node* head = nullptr;

	void Add(int index, T value);
	void AddFirst(T value);
	void AddLast(T value);
	void AddAfter(Node* node, T value);
	void AddBefore(Node<T>* node, T value);
	int Size();
	bool Contains(T value);
	bool Remove(T value);
	T GetFirst();
	T GetLast();
	void Clear();
	void Print();

	struct Node {
		T value;
		Node* next = nullptr;
		Node(T data);
		~Node();
	};
};
