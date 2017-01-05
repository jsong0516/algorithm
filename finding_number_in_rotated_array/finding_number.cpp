#include <iostream>

class Finding_Rotated_Array 
{
	public:
		// assume it is accending order
		static int finding_rotated_number(int* arr, int len);
		static int finding_number_in_rotated(int* arr, int len, int num);
};

// Assuming it is ascending order
int Finding_Rotated_Array::finding_rotated_number(int* arr, int len) {
	int start = 0;
	int end = len;
	int mid = start + (end - start) / 2;
	//std::cout<<arr[0];
	while(start < end)
	{
		if(arr[start] > arr[mid])
		{	
			//std::cout<< "a";
			end = mid - 1;
		} 
		else if(arr[end] < arr[mid])
		{
			//std::cout<< "b";
			start = mid + 1;
		}
		else // found where the element is 
		{
			// std::cout<< "c";
			break;
		}
		// std::cout<<"start "<<start<<std::endl;
		// std::cout<<"end "<<end<<std::endl;
		// std::cout<<"mid "<<mid<<std::endl;
		// update
		mid = start + (end - start) / 2;
	}
	return mid;	
}
int Finding_Rotated_Array::finding_number_in_rotated(int *arr, int len, int num) {
	int start = 0;
	int end = len;
	int mid = start + (end - start) / 2;
	while(start <= end) 
	{
		if(arr[mid] == num)
		{
			return mid;
		}
		else if(arr[start] > arr[mid]) // assume it is sorted then if then it is rotated
		{
			// std::cout<<"a";
			// number that is between arr[start] and arr[mid] can't exist
			if(num > arr[start] || num < arr[mid])
			{
				// means it can't exist in start - mid
				
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
		// Means it is not rotated
		else 
		{
			if(num > arr[start] && num < arr[mid])
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
		// std::cout<<"Start "<<start<<std::endl;
		// std::cout<<"End "<<end<<std::endl;
		// std::cout<<"Mid "<<mid<<std::endl;
		mid = start + (end - start) / 2;
	}
	return -1;
}

int main() {
	// int* arr = new int[20]; //ok
	//int arr[] = new int[20]; error
	int arr[] = {176, 188, 199, 200, 210, 222, 1, 10,20,47 ,59, 63, 75 ,88,99,107,120,133,155 };
	std::cout<< "1. Number is " << Finding_Rotated_Array::finding_rotated_number(arr, 20) << std::endl;
	std::cout<< "2. Number is " << Finding_Rotated_Array::finding_number_in_rotated(arr, 20, 200) << std::endl;

	return 0;
}
