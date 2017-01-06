# Kadane's algorithm
# Maximum difference in the list
class single_sell:
	def __init__(self, arr):
		self.arr = arr

	def maximum_profit(self):
		current_buy = self.arr[0] # smallest number seens so far
		current_sell = self.arr[1]
		global_profit = current_sell - current_buy
		for ele in self.arr:
			current_profit = ele - current_buy
			if current_profit > global_profit:
				global_profit = current_profit
				current_sell = ele
			if ele < current_buy: # smallest number seens so far
				current_buy = ele

		return  current_sell - global_profit, current_sell



stock_price = [8, 5, 12, 9, 19, 1]
a = single_sell(stock_price)
print a.maximum_profit()