class Smallest {

	public static int finding_smallest(int a[], int b[], int c[]) {
		int a_i = 0;
		int b_i = 0;
		int c_i = 0;
		while(a_i < a.length && b_i < b.length && c_i < c.length) {
			if(a[a_i] == b[b_i] && b[b_i] == c[c_i])
				return a[a_i];
			else if(a[a_i] < b[b_i])
			{
				if(c[c_i] < a[a_i])
				{
					c_i++;
				}
				else 
				{
					a_i++;
				}
			}
			else // b < a
			{
				if(c[c_i] < b[b_i])
				{
					c_i++;
				}
				else
				{
					b_i++;
				}
			}

		}
		return -1;
	}

	public static void main(String[] args) {
		int a[] = {6, 7, 10, 25, 30, 63, 64};
		int b[] = {-1, 4, 5, 6, 7, 8, 50};
		int c[] = {1, 6, 10, 14};
		System.out.println("The number is " + finding_smallest(c,b,a));
	}
}