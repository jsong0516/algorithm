#include <iostream>
class HiLo {
	
	public:
		int high;
		int low;
		HiLo() 
		{
			high = -1;
			low = 2147483647;
		}
		void findHigh(int *arr, int len, int key);
		void findLow(int *arr, int len, int key);
		void findHighLow(int *arr, int len, int key);
};

void HiLo::findHigh(int *arr, int len, int key) {
	int start = 0;
	int end = len;
	int mid = start + (end - start) / 2;
	while(start <= end)
	{
		if(arr[mid] == key) 
		{
			if(mid > high)
				high = mid;
			// need to go left side
			start = mid + 1;
		}
		// go to right side
		else if(arr[mid] < key) 
		{
			start = mid + 1;
		}
		else // need to go to left side
		{
			end = mid - 1;
		}
		mid = start + (end - start) / 2;
	}
}

void HiLo::findLow(int *arr, int len, int key) {
	low = len;
	int start = 0;
	int end = len;
	int mid = start + (end - start) / 2;
	while(start <= end)
	{
		if(arr[mid] == key) 
		{
			if(mid < low)
				low = mid;
			// need to go left side
			end = mid - 1;
		}
		else if(arr[mid] < key) // go to right side
		{
			start = mid + 1;
		}
		else // need to go to left side
		{
			end = mid - 1;
		}
		mid = start + (end - start) / 2;
	}
}

void HiLo::findHighLow(int *arr, int len, int key) {
	if(arr == NULL || len <= 0)
		return;
	findLow(arr, len, key);
	findHigh(arr, len, key);
}


int main() 
{
	HiLo *hl = new HiLo();
	int arr[] = {1,2,5,5,5,5,5,20};
	hl->findHighLow(arr, 8, 5);
	std::cout << "Hi " << hl->high << std::endl;
	std::cout << "Low " << hl->low << std::endl;
	return 0;
}
