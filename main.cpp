//Author:     Patrick Taliaferro
//Date:       April 29, 2020
//File Name:  main.cpp
//Purpose:    Traverse a Linked List in Reverse

#include <iostream>
#include "LinkedList.hpp"


int main(int argv, char * argc[]) {

	LinkedList llStart(NULL);
	std::cout << "Length: " << llStart.iFindLength() << "\n";
	llStart.push_front(5);
	std::cout << "pushed 5 front\n";
	std::cout << "Length: " << llStart.iFindLength() << "\n";
	llStart.push_front(6);
	std::cout << "pushed 6 front\n";
	std::cout << "Length: " << llStart.iFindLength() << "\n";
	llStart.print_list_forward();

	llStart.pop_front();
	std::cout << "popped front\n";
	llStart.print_list_forward();

	llStart.push_front(4);
	llStart.push_front(5);
	llStart.push_front(6);
	std::cout << "pushed 4,5,6 front \n";
	llStart.print_list_forward();

	std::cout << "Recursive Implementation Backward\n";
	llStart.print_list_backward_recursive();
	return 0;
}
