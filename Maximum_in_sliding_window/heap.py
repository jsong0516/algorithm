# Documentation https://interactivepython.org/runestone/static/pythonds/Trees/BinaryHeapImplementation.html 
# Heap solution
class Heap:
	def __init__(self, size):
		self.arr = [0]
		self.size = 0

	#max-heap, min-heap O(log n)
	def insert(self, elem):
		# add element at the end of the list
		self.arr.append(elem)
		# incrase size
		self.size += 1
		self.percUp(self.size)

	def percUp(self, i):
		while i // 2 > 0: # can't be located into 0th index
			if self.arr[i] > self.arr[i // 2]:
				temp = self.arr[i//2]
				self.arr[i // 2] = self.arr[i]
				self.arr[i] = temp
			i = i // 2

	def percDown(self, i):
		while (i * 2 + 1) <= self.size:
			minElem = min(self.arr[i], self.arr[i * 2], self[i*2 + 1])
			if minElem == self.arr[i * 2]:
				temp = self.arr[i * 2]
				self.arr[i*2] = self.arr[i]
				self.arr[i] = temp
				i = i * 2
			elif minElem == self.arr[i * 2 + 1]:
				temp = self.arr[i * 2 + 1]
				self.arr[i*2 + 1] = self.arr[i]
				self.arr[i] = temp	
				i = i * 2 + 1			
			else:
				break
		# last check
		if i * 2 <= self.size and self.arr[i] < self.arr[i * 2]:
			temp = self.arr[i * 2]
			self.arr[i * 2] = self.arr[i]
			self.arr[i] = temp
		elif (i * 2 + 1) <= self.size and self.arr[i] < self.arr[i * 2 + 1]:
			temp = self.arr[i * 2 + 1]
			self.arr[i * 2 + 1] = self.arr[i]
			self.arr[i] = temp


	def pop(self): # deleting max or min
		if(self.arr.length == 0):
			return -1
		firstElem = self.arr[1] # get the first elem
		lastElem = self.arr.pop() # get the last elem
		self.arr[1] = lastElem
		self.size -= 1
		self.percDown(1)
		return firstElem
