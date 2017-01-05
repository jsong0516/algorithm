class Rotate:
	def __init__(self, arr):
		self.arr = arr

	def rotate(self, n):
		rev = list(reversed(self.arr))
		finalarr = []
		if n < 0:
			finalarr = list(reversed(rev[:len(self.arr)+n])) + list(reversed(rev[len(self.arr)+n:]))
		else:
			finalarr = list(reversed(rev[:n])) + list(reversed(rev[n:]))
		return finalarr

	def toString(self):
		return arr

arr = [1, 10, 20, 0, 59, 86, 32, 11, 9, 40]
n = 2
r = Rotate(arr)
print r.rotate(n);