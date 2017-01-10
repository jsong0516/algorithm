#include <iostream>

template <typename T>
class Node {
	public:
		T item;
		Node *next;
		Node(T i = 0, Node *n = NULL) {
			item = i;
			next = n;
		}
};

template <typename T>
Node<T>* findList(Node<T> *l1, Node<T> *l2) {
	int l1_len = findLength(l1);
	int l2_len = findLength(l2);

	// Move forward
	while(l1_len != l2_len) 
	{
		if(l1_len > l2_len)
		{
			if(l1->item == l2->item)
				return l1;
			l1 = l1->next;
			l1_len--;
		}
		else
		{
			if(l1->item == l2->item)
				return l1;
			l2 = l2->next;
			l2_len--;
		}
	}


	// Find an item
	while(l1 != NULL && l2 != NULL)
	{
		if(l1->item == l2->item) 
		{
			return l1;
		}
		else
		{
			l1 = l1->next;
			l2 = l2->next;
		}
	}
	return NULL;
}

template <typename T>
int findLength(Node<T> *l) {
	int n = 0;
	while(l != NULL)
	{
		l = l->next;
		n++;
	}
	return n;
}
int main() {
	Node<int> *l1 = new Node<int>(29, new Node<int>(23, new Node<int>(82, new Node<int>(11, new Node<int>(12, new Node<int>(27, NULL))))));
	Node<int> *l2 = new Node<int>(13, new Node<int>(4, new Node<int>(12, new Node<int>(27, NULL))));
	Node<int> *n = findList(l1, l2);
	if(n == NULL)
	{
		std::cout << "No intersection" << std::endl;
	}
	else 
	{
		std::cout << "item : " << n->item << std::endl;
	}


}