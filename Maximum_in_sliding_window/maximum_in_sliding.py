#Given a large array of integers and a window of size 'w', find the current maximum in the window as the window slides through the entire array.

#O(nw) solution
def maxmum_in_sliding_nw(w, arr):
	print "O(nw)"
	for i in range(len(arr)-2):
		print "i is "+ str(i) + " and the maxmum is " + str(max(arr[i], arr[i+1], arr[i+2]))

#O(n) solution
class sliding_window:
	def __init__(self, w, arr):
		self.arr = arr
		self.w = w
		self.window = []

	# assume array is not none and window is not none
	def find(self):
		if self.w > len(self.arr) :
			print "Maxmum is " + str(max(self.arr))
			return

		for i in range(len(self.arr)):
			print "Maximum is " + str(self.putToWindow(arr[i], i))


	def putToWindow(self, j, jth):
		index = 0

		# First remove all elements that are not greater than j
		for i in range(len(self.window)):
			if j <= self.window[-1][0]:
				break
			else:
				self.window.pop()
			#Note to myself: this pop won't make out of bound exception
		
		# add to the current
		self.window.append((j, jth))


		# if the first number is not within the range then,
		if self.window[0][1] <= jth - self.w:
			self.window.pop(0)
			
		return self.window[0][0]

arr = [-4,2,-5,1,-1,6]
maxmum_in_sliding_nw(3, arr)

maximum_in_sliding_n = sliding_window(3, arr)
maximum_in_sliding_n.find();