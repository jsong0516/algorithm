class Zero 
{
	public static void main(String args[])
	{
		//int arr[] = new int[8];
		int arr[] = {1, 10, 20, 0, 59, 63, 0, 88, 0};
		int read = arr.length-1, write = arr.length-1;

		// Fill in numbers
		while(read >= 0) 
		{
			if(arr[read] == 0) 
			{
				read--;
			}
			else 
			{
				arr[write--] = arr[read--];
			}
		}

		// Fill in zeros
		while(write >= 0)
		{
			arr[write--] = 0;
		}

		for(int i = 0; i < arr.length; i++)
			System.out.print(arr[i] +" ");
		System.out.println("");
	}
}