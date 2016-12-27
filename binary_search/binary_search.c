//Given a sorted array of integers, return the index of the given key. Return -1 if not found.

#include <stdio.h>

int binary_search(int key, int start, int end, int array[]);

int main() {
	int input_array[] = {1, 10, 20, 47, 59, 63, 75, 88, 99, 107, 120, 133, 155, 162, 176, 188, 199 ,200, 210, 222};
	printf("Val : %d \n ", binary_search(20, 0, 19, input_array));
	return 0;
}

int binary_search(int key, int start, int end, int array[]) {
	if(array == NULL || start > end)
		return -1;

	// * Important * my mistake
	//int mid = (start - end) / 2;
	//int mid = start + ((start - end) / 2); <- mistake again. Do you see?
	int mid = start + ((end - start) / 2);

	if(array[mid] == key) 
	{
		printf("Found!!\n");
		return mid;
	}
	else if(array[mid] > key) 
	{
		printf("Going left\n");
		return binary_search(key, start, mid - 1, array);
	}
	else
	{
		printf("Going right\n");
		return binary_search(key, mid + 1, end, array);
	}






}
