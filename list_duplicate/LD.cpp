#include <iostream>
#include <unordered_set>

template <typename T>
class Node
{
	public:
		T item;
		Node *next;
		Node(T elem = NULL, Node *n = NULL) {
			item = elem;
			next = n;
		}
};

template <typename T>
class LD 
{
	public:
		static void removeduplicate(Node<T> *head);
		static void printALL(Node<T> *head);
};

template <typename T>
void LD<T>::printALL(Node<T> *head) {
	while(head != NULL) 
	{
		std::cout << head->item << " ";
		head = head->next;
	}
	std::cout<< std::endl;
}


template <typename T>
void LD<T>::removeduplicate(Node<T> *head) 
{
	//std::set<T> hashSet;
	std::unordered_set<T> currSet;
	Node<T> *prev = NULL;
	while(head != NULL)
	{
		if(currSet.count(head->item) > 0) // found; remove
		{
			prev->next = head->next;
			head = head->next;
		}
		else // not found. Insert 
		{
			currSet.insert(head->item);
			prev = head;
			head = head->next;
		}	
	}
}

int main()
{
	// 7, 14, 28, 28, 14, 21 Null
	Node<int> *head = new Node<int>(7, new Node<int>(14, new Node<int>(28, new Node<int>(28, 
		new Node<int>(14, new Node<int>(21, NULL))))));
	//LD.removeduplicate(head); illegal
	LD<int>::printALL(head);
	LD<int>::removeduplicate(head);
	LD<int>::printALL(head);

	return 0;
}
 

