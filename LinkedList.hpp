//Author:    Patrick Taliaferro
//Date:      April 29, 2020
//File Name: LinkedList.hpp
//Purpose:   Define the Linked List class which all the work will occur on

#include <iostream>

struct node {
	int val;
	node * next;
};

class LinkedList {

	public:
		LinkedList(node * head) { nHead = head; }
		
		~LinkedList()
		{
			while(nHead != NULL) pop_front();
		}

		int iFindLength()
		{
			if(nHead == NULL) return 0;
			int iLength = 0;
			node * nBuffer = nHead;
			while(nBuffer != NULL)
			{
				iLength++;
				nBuffer = nBuffer->next;
			}
			return iLength;
		}

		void push_back(int iVal)
		{
			node * newNode = new node();
			newNode->val = iVal;
			newNode->next = NULL;
			if(nHead == NULL) 
			{
				nHead = newNode;
				return;
			}
			node * nBuffer = nHead;
			
			while(nBuffer->next != NULL) nBuffer = nBuffer->next;

			nBuffer->next = newNode;

		}

		void push_front(int iVal)
		{
			node * newNode = new node();
			newNode->val = iVal;
			newNode->next = nHead;
			nHead = newNode;
		}

		void pop_back()
		{
			if(nHead == NULL) return;
			else if(nHead->next == NULL)
			{
				delete nHead;
				nHead = NULL;
				return;
			}
			node * nBuffer = nHead;
			while(nBuffer->next->next != NULL) nBuffer = nBuffer->next;
			delete nBuffer->next;
			nBuffer->next = NULL;
		}

		void pop_front()
		{
			if(nHead == NULL) return;
			node * nTemp = nHead->next;
			delete nHead;
			nHead = nTemp;
		}

		void print_list_forward()
		{
			if(nHead == NULL)
			{
				std::cout << "done\n";
				return;
			}
			node * nBuffer = nHead;
			while(nBuffer != NULL)
			{
			       	std::cout << nBuffer->val << "\n";
				nBuffer = nBuffer->next;
			}
		}

		void print_list_backward_naive()
		{
			if(nHead == NULL) return;
			node * nBack = NULL;
			node * nBuffer = nHead;
		
			while(nBack != nHead)
			{
				while(nBuffer->next != nBack)
				{
					nBuffer = nBuffer->next;
				}
				std::cout << nBuffer->val << "\n";
				nBack = nBuffer;
				nBuffer = nHead;
			}
		}


	private:
		node * nHead;
};
