#include "LinkedList.h"

template <typename T>
void LinkedList<T>::Add(int index, T value) {
	Node<T>* newNode = new Node<T>(value);
	Node<T>* current = head;
	for (int i = 0 || current->next == nullptr; i < index; i++) {
		current = current->next;
	}
	newNode->next = current->next;
	current->next = newNode;
}

template<typename T>
void LinkedList<T>::AddFirst(T value) {
	Node<T>* newNode = new Node<T>(value);
	newNode->next = head;
	head = newNode;
}

template<typename T>
void LinkedList<T>::AddLast(T value) {
	Node<T>* newNode = new Node<T>(value);
	Node<T>* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = newNode;
}

template<typename T>
int LinkedList<T>::Size() {
	Node<T>* current = head;
	int count = 0;
	while (current != nullptr) {
		count++;
		current = current->next;
	}
	return count;
}