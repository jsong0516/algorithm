class Node:
	def __init__(self, item = None, next = None):
		self.item = item
		self.next = next

def sortList(head, node):

	if head == None: 
		return node

	if node == None:
		return head

	if head.item >= node.item:
		node.next = head
		return node

	currNode = head
	while currNode.next != None and currNode.next.item < node.item:
		currNode = currNode.next

	node.next = currNode.next
	currNode.next = node


	return head

def insertionSort(head):

	sortedHead = None
	while head is not None:

		# take out Node
		currNode = head
		head = head.next
		currNode.next = None
		sortedHead = sortList(sortedHead, currNode)

	return sortedHead



def printAll(head):
	while head is not None:
		print head.item
		head = head.next
	print "\n"

head = Node(29, Node(23, Node(82, Node (11, None))))
#printAll(head)
head = insertionSort(head)
printAll(head)