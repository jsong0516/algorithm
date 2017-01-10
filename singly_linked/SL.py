class Node:
	def __init__(self):
		self.item = None
		self.next = None

	def __init__(self, item):
		self.item = item
		self.next = None

	def setnext(self, node):
		self.next = node


class singly_linked_list:
	def __init__(self):
		self.head = None
		self.tail = None
		self.length = 0

	def add(self, node):
		self.length += 1
		if self.head is None:
			self.head = node
			self.tail = node
			return

		self.tail.setnext(node)
		self.tail = node

	def reverse(self):
		if self.length <= 1:
			return

		# First make tail to be None
		prev = None
		curr = self.head
		next = curr.next

		while next is not None:
			curr.next = prev
			prev = curr
			curr = next
			next = curr.next

		curr.next = prev
		self.head = curr
		
	# Also,
	# Another version is using Stack
	# O(n), Memory O(n)

	def printAll(self):
		oldHead = self.head
		while self.head is not None:
			print self.head.item
			self.head = self.head.next

		self.head = oldHead




sl = singly_linked_list()
sl.add(Node(1))
sl.add(Node(2))
sl.printAll()
print "Revesred"

sl.reverse()
sl.printAll()

