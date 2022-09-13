#include "LinkedList.h"
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	LinkedList<int> list = LinkedList<int>();
	list.AddLast(2);
	list.Remove(2);
	for (int i = 0; i < 20; i++) {
		list.AddLast(i);
	}
	list.Remove(5);
	list.Remove(6);
	list.Remove(8);
	list.Clear();
}