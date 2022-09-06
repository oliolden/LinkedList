#include "LinkedList.h"
#include <iostream>

int main() {
	LinkedList<int> list = LinkedList<int>();
	for (int i = 0; i < 10; i++) {
		list.AddLast(i);
	}
	list[2] = 5;
	std::cout << list[2] << std::endl;
	list.Print();
}