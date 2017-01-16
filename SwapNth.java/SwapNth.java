class SwapNth 
{
	static Node swapnth(Node head, int i) {
		if(i == 0 ) // also the length of head < 2
			return head;

		if(i == 1)
		{
			Node curr = head.next;
			head.next = curr.next;
			curr.next = head;
			return curr;
		}


		Node prev = null;
		Node curr = head;

		while(curr != null && --i > 0) {
			prev = curr;
			curr = curr.next;
		}

		prev.next = head;

		// swap
		Node temp = curr.next;
		curr.next = head.next;
		head.next = temp;

		return curr;

	}
	static void printAll(Node head) {
		while(head != null)
		{
			System.out.println(head.item);
			head = head.next;
		}
	}

	public static void main(String[] args)
	{
		Node head = new Node(7, new Node(14, new Node(21, new Node(28, new Node(35, new Node(42, null))))));
		head = SwapNth.swapnth(head, 1);
		printAll(head);
	}
}

class Node {
	int item;
	Node next;

	Node(int i) {
		item = i;
	}
	Node(int i, Node n) {
		item = i;
		next = n;
	}
}