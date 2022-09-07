#include "LinkedList.h"
#include <iostream>

int main() {
	LinkedList<int> list = LinkedList<int>();
	while (true) {
		list.AddFirst(256);
		list.Remove(256);
	}
}