public class binary_search { // file name and class name must be aligned
	final static int[] ARR = {1, 10, 20, 47, 59, 63, 75, 88, 99, 107, 120, 133, 155, 162, 176, 188, 199 ,200, 210, 222};
	public static int binary_search(int key, int start, int end, int arr[]) 
	{
		//if(arr == NULL || start > end)
		if(arr == null || start > end)
			return -1;
		int mid = start + (end - start) / 2;

		if(arr[mid] == key)
			return mid;
		else if(arr[mid] < key)
			return binary_search(key, mid+1, end, arr);
		else
			return binary_search(key, start, mid-1, arr);
	}

	public static int binary_search_iter(int key, int start, int end, int arr[])
	{
		if(arr == null || start > end)
			return -1;
		int mid;
		do {
			mid = start + (end - start) / 2;
			if(arr[mid] == key)
				return mid;
			else if(arr[mid] > key)
				end = mid -1;
			else 
				start = mid +1;
		}while(start <= end);
		return -1;
	}
	public static void main(String[] args)
	{
		int key = 20;
		System.out.println("Output is : " + binary_search(key, 0, 19, ARR));
		System.out.println("Output(iter) is " + binary_search_iter(key, 0, 19, ARR));
	}
}