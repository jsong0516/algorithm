class Node:
	def __init__(self, item, next):
		self.item = item
		self.next = next

def mergeSort(head):
	if head == None:
		return None

	if head.next == None:
		return head
	head1, head2 = split_in_half(head)
	# print "MergeSort called. Printing first half"
	#printAllElem(head1)

	# print "Printing Second half"
	#printAllElem(head2)

	h1 = mergeSort(head1)
	h2 = mergeSort(head2)
	
	# print "H1"
	# printAllElem(h1)
	# print "H2"
	# printAllElem(h2)
	result = mergeSortHelper(h1, h2)
	# print "Result"
	# printAllElem(result)
	return result

def printAllElem(head):
	while head != None:
		print head.item
		head = head.next


# this is important. Move two pointers. 1 move one step, 2 move two steps
def split_in_half(head):
	if head == None:
		return None

	cut = None
	slow = head
	fast = head.next

	# if len is 1
	if fast is None:
		return head, None

	# if len is 2
	if fast.next is None:
		head.next = None
		return head, fast

	while fast != None:
		fast = fast.next
		if fast != None:
			fast = fast.next
		else:
			break
		cut = slow
		slow = slow.next


	cut.next = None
	return head, slow

def mergeSortHelper(l1, l2):
	if l1 == None:
		return l2

	if l2 == None:
		return l1

	result = None
	if l1.item <= l2.item:
		result = l1
		l1 = l1.next
	else:
		result = l2
		l2 = l2.next
	head = result
	while l1 != None and l2 != None:
		if l1.item <= l2.item:
			result.next = l1
			l1 = l1.next
		else:
			result.next = l2
			l2 = l2.next
		result = result.next

	# add the rests
	while l1 != None:
		result.next = l1
		l1 = l1.next
		result = result.next
	while l2 != None:
		result.next = l2
		l2 = l2.next
		result = result.next

	return head

head = Node(29, Node(23, Node(82, Node(11, Node(4, Node(3, Node(21, None)))))))
head = mergeSort(head)
printAllElem(head)