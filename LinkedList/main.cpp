#include "LinkedList.h"
#include "LinkedList.cpp"
#include <iostream>

int main() {
	LinkedList<int> list = LinkedList<int>();
	list.AddLast(1);
	std::cout << list.Size();
	while (true) {

	}
}