#include "LinkedList.h"

template <typename T>
void LinkedList<T>::Add(int index, T value) {

}

template<typename T>
void LinkedList<T>::AddFirst(T value) {

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