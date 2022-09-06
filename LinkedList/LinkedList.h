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
	Node* next = &this;
	Node* prev = &this;
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
		newNode->prev = (*current)->prev;
		(*current)->prev = newNode;
		*current = newNode;
	}

	void AddFirst(T value) {
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head;
		newNode->prev = head->prev;
		head = newNode;
	}

	void AddLast(T value) {
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head;
		newNode->prev = head->prev;
	}

	void AddAfter(T node, T value) {
		Node<T>* newNode = new Node<T>(value);
		for (Node<T>* i = head; i != nullptr; i = i->next)
			if (i->value == node) {
				newNode->next = i->next;
				newNode->prev = i;
				i->next = newNode;
				return;
			}
	}

	void AddBefore(T node, T value) {
		Node<T>* newNode = new Node<T>(value);
		for (Node<T>* i = head; i->next != nullptr; i = i->next)
			if (i->next->value == node) {
				newNode->next = i->next;
				newNode->prev = i;
				i->next = newNode;
				return;
			}
	}

	int Size() {
		if (head == nullptr) return 0;
		int count = 1;
		for (Node<T>* i = head->next; i != head; i = i->next) { count++; }
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

	T& operator[](int index) {
		if (index < 0)
			throw std::out_of_range("Index was out of range");
		Node<T>* current = head;
		for (int i = 0; i < index; i++) {
			current = current->next;
			if (current == nullptr)
				throw std::out_of_range("Index was out of range");
		}
		return current->value;
	}

private:
	Node<T>* head = nullptr;
};

