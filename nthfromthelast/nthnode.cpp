#include <iostream>

template <typename T>
class Node {
public:
	T item;
	Node<T> *next;
	Node(T i = NULL, Node<T> *n = NULL)
	{
		item = i;
		next = n;
	}
};


template <typename T>
class NthNode
{
public:
	static Node<T>* nthfromthelast(Node<T> *head, int n);
};

template <typename T>
Node<T>* NthNode<T>::nthfromthelast(Node<T> *head, int n) 
{
	Node<T> *curr = head;
	while(head != NULL) 
	{
		if(n <= 0) {
			curr = curr->next;
		}
		else {
			n--;
		}
		head = head->next;

	}
	if(n > 0)
		return NULL;
	return curr;
}

int main() {
	Node<int> *head = new Node<int>(7, new Node<int>(14, new Node<int>(21,new Node<int>(28, new Node<int>(35, new Node<int>(42, NULL))))));
	head = NthNode<int>::nthfromthelast(head, 3);
	std::cout<<head->item<<std::endl;
	return 0;
}