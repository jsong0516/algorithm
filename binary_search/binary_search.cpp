//Given a sorted array of integers, return the index of the given key. Return -1 if not found.

#include <stdio.h>
#include <iostream>

template <typename T>
class BS 
{
	public:
		static int binary_search(T key, int start, int end, T *array);
		static int binary_search_iter(T key, int start, int end, T *array);
		
};

template <typename T>
int BS<T>::binary_search_iter(T key, int start, int end, T *array) {
	if(array == NULL || start > end)
		return -1;
	int mid;
	do {
		mid = start + (end- start) / 2;
		if(array[mid] == key)
			return mid;
		else if(array[mid] < key)
			start = mid + 1;
		else
			end = mid -1;
	} while(start <= end);
	return -1;
}


template <typename T>
int BS<T>::binary_search(T key, int start, int end, T *array) {
	if(array == NULL || start > end)
		return -1;

	// * Important * my mistake
	//int mid = (start - end) / 2;
	int mid = start + ((end - start) / 2);

	if(array[mid] == key) 
	{
		printf("Found!!\n");
		return mid;
	}
	else if(array[mid] > key) 
	{
		return binary_search(key, start, mid - 1, array);
	}
	else
	{
		return binary_search(key, mid + 1, end, array);
	}
}

int main() {
	BS<int> bs;
	int input_array[] = {1, 10, 20, 47, 59, 63, 75, 88, 99, 107, 120, 133, 155, 162, 176, 188, 199 ,200, 210, 222};
	printf("Val : %d \n", bs.binary_search(20, 0, 19, input_array));
	std::cout <<"Val2 : "<< BS<int>::binary_search_iter(20, 0, 19, input_array) << '\n';
	return 0;
}


