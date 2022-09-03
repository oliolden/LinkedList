#include "LinkedList.h"
//#include "LinkedList.cpp"
#include <iostream>

int main() {
	LinkedList<int> list = LinkedList<int>();
	for (int i = 0; i < 10; i++) {
		list.AddLast(i);
	}
	list.AddBefore(4, 52);
	list.Print();
}