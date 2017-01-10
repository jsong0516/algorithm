#include <stdlib.h>
#include <iostream>

class Quicksort {
public:
	static void quicksort(int *arr, int low, int high);
};
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
};
// in-place
void Quicksort::quicksort(int *arr, int low, int high)
{
	if(arr == NULL || low >= high) 
		return;
	//int pivot = low + rand() % (high - low);
	int elem_pivot = arr[high];
	int start = low;
	int end = high;
	high--;
	//swap(arr[pivot], arr[high]);
	while(low <= high)
	{
		// find the candidate to move low
		while(low < end && arr[low] < elem_pivot) low++;
		while(high >= start && arr[high] >= elem_pivot) high--;

		if(low <= high)
		{
			std::swap(arr[low], arr[high]);
		}

	}

	// last swap
	arr[end] = arr[low];
	arr[low] = elem_pivot;

	//swap(arr[low], arr[pivot]);
	quicksort(arr, start, low -1);
	quicksort(arr, low + 1, end);

}

void printArray(int *arr, int len) 
{
	for(int i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout<<std::endl;
}

int main() {
	int arr[] = {55, 23, 26, 2, 18, 78, 23, 8, 2, 3};
	Quicksort::quicksort(arr, 0, 9);
	printArray(arr, 10);
	return 0;
}