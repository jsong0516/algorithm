class Node 
{
	public int item;
	public Node next;

	Node(int item)
	{
		this.item = item;
		this.next = null;
	}

	Node(int item, Node next)
	{
		this.item = item;
		this.next = next;
	}
	static void printAll(Node head)
	{
		while(head != null)
		{
			System.out.print("" + head.item + " ");
			head = head.next;
		}
		System.out.println();
	}
	static void removeKey(Node head, int key)
	{
		Node prev = null;
		while(head != null) 
		{
			if(head.item == key) 
			{
				if(prev == null)
				{
					Node temp = head;
					head = head.next;
					temp.next = null;
				}
				else
				{
					Node temp = head;
					prev.next = head.next;
					head = head.next;
					temp.next =null;
				}
			}
			else 
			{
				prev = head;
				head = head.next;
			}

		}
	}

	public static void main(String args[])
	{
		Node head = new Node(7, new Node(14, new Node(21, new Node(28, new Node(35, new Node(42))))));
		printAll(head);
		removeKey(head, 28);
		printAll(head);
	}
}

