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
	Node* next = nullptr;
};

template <typename T>
class LinkedList {
public:
	void Add(int index, T value) {
		Node<T>* newNode = new Node<T>(value);
		// Get address of head
		Node<T>** current = &head;

		// Iterate through nodes
		for (int i = 0; i < index && *current != nullptr; i++) {
			current = &((*current)->next);
		}

		// Set newNode's next node pointer to the current node pointer and replace current pointer with newNode's pointer
		newNode->next = *current;
		*current = newNode;
	}

	void AddFirst(T value) {
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head;
		head = newNode;
	}

	void AddLast(T value) {
		Node<T>* newNode = new Node<T>(value);
		Node<T>** current = &head;
		while (*current != nullptr) {
			current = &((*current)->next);
		}
		*current = newNode;
	}

	void AddAfter(T node, T value) {
		Node<T>* newNode = new Node<T>(value);
		for (Node<T>* i = head; i != nullptr; i = i->next)
			if (i->value == node) {
				newNode->next = i->next;
				i->next = newNode;
				return;
			}
	}

	void AddBefore(T node, T value) {
		Node<T>* newNode = new Node<T>(value);
		for (Node<T>* i = head; i->next != nullptr; i = i->next)
			if (i->next->value == node) {
				newNode->next = i->next;
				i->next = newNode;
				return;
			}
	}

	int Size() {
		int count = 0;
		for (Node<T>* i = head; i != nullptr; i = i->next) { count++; }
		return count;
	}

	bool Contains(T value) {
		for (Node<T>* i = head; i != nullptr; i = i->next)
			if (i->value == value) return true;
		return false;
	}

	bool Remove(T value) {
		Node<T>** prev = nullptr;
		for (Node<T>* i = head; i != nullptr; i = i->next) {
			if (i->value == value) {
				if (prev != nullptr)
					(*prev)->next = i->next;
				else
					head = i->next;
				delete i;
				return true;
			}
			prev = &i;
		}
		return false;
	}

	T GetFirst() {
		return head->value;
	}

	T GetLast() {
		Node<T>* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		if (current == nullptr) return NULL;
		else return current->value;
	}

	void Clear() {
		Node<T>* current = head;
		Node<T>* next = nullptr;
		while (current != nullptr) {
			next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
	}

	void Print() {
		for (Node<T>* i = head; i != nullptr; i = i->next)
			std::cout << i->value << std::endl;
	}

private:
	Node<T>* head = nullptr;
};

