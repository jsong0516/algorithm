class sumTo:
	def __init__(self):
		self.hashTable = set()
		self.solution = set()

	def findSum(self, arr, n):
		self.solution = set()
		# First add elements
		for i in range(len(arr)):
			val = n - arr[i]
			if val in self.hashTable:
				self.solution.add((val, arr[i]))
			else:
				self.hashTable.add(arr[i])

	def findSum2(self, arr, n):
		start = 0
		end = len(arr) - 1
		while(start < end):
			s = arr[start] + arr[end]
			if n == s:
				return True
			if s < n:
				start += 1
			else:
				end +=1



arr = [5, 7, 1, 2, 8, 4, 3]
s = sumTo()
s.findSum(arr, 10)
print s.solution
print s.findSum2(arr, 10)
