#include <iostream>

template <typename T>
class Node {
	public:
		T item;
		Node *next;
		Node(T i = NULL, Node *n = NULL)
		{
			item = i;
			next = n;
		}
};

template <typename T>
class Reverse {
public:
	static Node<T>* reverseEven(Node<T> *head);
};

template <typename T>
Node<T>* Reverse<T>::reverseEven(Node<T> *head)
{
		// if head is null, then return
	if(head == NULL)
		return NULL;

	// if len of head is 1 or 2 then return head;
	if(head->next == NULL || head->next->next == NULL)
		return head;


	// Initial Setup
	Node<T> *head1 = head;
	Node<T> *even_head = head->next;
	head->next = head->next->next;
	head = head->next;
	even_head->next = NULL;

	while(head != NULL && head->next != NULL)
	{

		Node<T> *temp = head->next;
		head->next = head->next->next;
		head = head->next;

		temp->next = even_head;
		even_head = temp;

	}



	head = head1;

	//printAll(head);
	//printAll(even_head);

	// Merge two lists
	while(even_head != NULL)
	{
		Node<T> *temp = even_head->next;
		Node<T> *temp2 = head->next;

		even_head->next = temp2;
		head->next = even_head;

		head = temp2;
		even_head = temp;
	}
	return head1;
}

template <typename T>
void printAll(Node<T> *head)
{
	while(head != NULL) {
		std::cout<<head->item<<std::endl;
		head = head->next;
	}
}
// Merge Two lists in order

int main () {
	Node<int> *head = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5, new Node<int>(6, NULL))))));
	head = Reverse<int>::reverseEven(head);
	printAll(head);
	return 0;
}