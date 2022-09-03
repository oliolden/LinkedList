#include "LinkedList.h"
//#include "LinkedList.cpp"
#include <iostream>

int main() {
	LinkedList<int> list = LinkedList<int>();
	list.AddLast(2);
	list.AddFirst(0);
	//list.Add(1, 1);
	std::cout << list.Size();
}