class Node{
	public int item;
	public Node next;
	Node(int i, Node n)
	{
		item = i;
		next = n;
	}
}

class RotateLinkedList
{
	static int findlen(Node head, int n)
	{
		int len = 0;
		while(head != null) {
			head = head.next;
			len++;
		}
		return len;
	}
	static Node Rotate(Node head, int n) 
	{
		if(head == null || head.next == null || n == 0)
			return head;
		int len = findlen(head, n);
		if(n < 0)
			n = n + len;
		else
			n = n % len;

		if(n == len || n == 0)
			return head;


		// Finding breaking point
		int count = 0;
		Node curr = head;
		while(curr != null &&  count++ < (len - n -1)) 
		{
			curr = curr.next;
		}

		Node newhead = curr.next;
		Node cutPoint = curr;
		while(curr.next != null) {
			curr = curr.next;
		}
		curr.next = head;
		cutPoint.next = null;

		return newhead;

	}
	static void PrintAll(Node head) 
	{
		while(head != null) 
		{
			System.out.println(head.item);
			head = head.next;
		}
	}
	public static void main(String args[]) 
	{
		Node head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, null)))));
		head = RotateLinkedList.Rotate(head, 2);
		PrintAll(head);
	}
}