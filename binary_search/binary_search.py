class binary_search:
	# static variable
	ARR = [1, 10, 20, 47, 59, 63, 75, 88, 99, 107, 120, 133, 155, 162, 176, 188, 199 ,200, 210, 222]

	# # this defins the local variable
	def __init__(self):
		print "Binary Search is called"

	def search(self, key, start, end, arr):
		if arr is None or start > end:
			return -1

		mid = start + (end - start) / 2

		if arr[mid] == key:
			return mid
		elif arr[mid] > key:
			return self.search(key, start, mid - 1, arr)
		else:
			return self.search(key, mid +1, end, arr)

	def search_iter(self, key, arr):
		start = 0
		end = len(arr)

		while start <= end:
			mid = start + (end - start) / 2
			if arr[mid] == key:
				return mid
			elif arr[mid] < key:
				start = mid + 1
			else:
				end = mid - 1
		return -1

x = binary_search()

print x.search(20, 0, 19, binary_search.ARR)

print x.search_iter(20, binary_search.ARR)
