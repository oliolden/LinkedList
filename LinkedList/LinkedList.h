#pragma once
#include <iostream>

template <typename T>
struct Node {
	Node(T data) {
		value = data;
	}
	~Node() {
		//std::cout << "Node with value: " << value << " deleted\n"; 
	}

	T value;
	Node<T>* next = this;
	Node<T>* prev = this;
};

template <typename T>
class LinkedList {
public:
	void Add(int index, T value) {

		Node<T>* current = head;
		int i = 0;
		while (i < index - 1) {
			current = current->next;
			i++;
		}
		if (current == head) {
			AddFirst(value);
			return;
		}
		AddAfter(current, value);
	}

	void AddFirst(T value) {
		Node<T>* newNode = new Node<T>(value);
		if (head == nullptr) { head = newNode; return; }
		head->prev->next = newNode;
		newNode->next = head;
		newNode->prev = head->prev;
		head->prev = newNode;
		head = newNode;
	}

	void AddLast(T value) {
		if (head == nullptr) {
			head = new Node<T>(value);
			return;
		}
		AddAfter(head->prev, value);
	}

	void AddAfter(T node, T value) {
		Node<T>* current = head;
		do {
			if (current->value == node) {
				AddAfter(current, value);
				return;
			}
		} while (current != head);
	}

	void AddBefore(T node, T value) {
		if (head->value == node) { AddFirst(value); return; }
		Node<T>* current = head;
		do {
			if (current->next->value == node) {
				AddAfter(current, value);
				return;
			}
		} while (current != head);
	}

	int Size() {
		if (head == nullptr) return 0;
		int count = 1;
		for (Node<T>* i = head->next; i != head; i = i->next) { count++; }
		return count;
	}

	bool Contains(T value) {
		if (head == value) return true;
		for (Node<T>* i = head->next; i != head; i = i->next)
			if (i->value == value) return true;
		return false;
	}

	bool Remove(T value) {
		Node<T>* current = head;
		do {
			if (current->value == value) {
				return DeleteNode(current);
			}
		} while (current != head);
		return false;
	}

	T GetFirst() {
		return head->value;
	}

	T GetLast() {
		return head->prev;
	}

	void Clear() {
		Node<T>* current = head->next;
		while (current != head) {
			current = current->next;
			delete current->prev;
		}
		delete head;
		head = nullptr;
	}

	void Print() {
		if (head == nullptr) return;
		Node<T>* current = head;
		do {
			std::cout << current->value << std::endl;
			current = current->next;
		} while (current != head);
	}

	T& operator[](int index) {
		Node<T>* current = head;
		int i = 0;
		while (i < index) {
			current = current->next;
			i++;
		}
		return current->value;
	}

private:
	Node<T>* head = nullptr;

	bool DeleteNode(Node<T>* node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete node;
		return true;
	}

	void AddAfter(Node<T>* node, T value) {
		Node<T>* newNode = new Node<T>(value);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		node->next->prev = newNode;
		newNode->next = node->next;
		node->next = newNode;
		newNode->prev = node;
	}
};

