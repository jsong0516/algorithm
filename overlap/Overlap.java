import java.util.*;
class Tuple
{
	int left;
	int right;
	Tuple(int left, int right)
	{
		this.left= left;
		this.right = right;
	}
	String toMyString()
	{
		return "(" + left + ", " + right + ")";
	}
}

class Overlap 
{

	public static ArrayList<Tuple> overlap(Tuple[] tlist)
	{
		ArrayList<Tuple> result = new ArrayList<Tuple>();

		Tuple currT = tlist[0]; 
		result.add(currT);
		for(int i = 1; i < tlist.length; i++) 
		{	
			// Check left
			if(tlist[i].left < currT.right)
				currT.right = tlist[i].right > currT.right ? tlist[i].right : currT.right;
			else // if it is not merged then add to the new result
			{
				Tuple newT = new Tuple(tlist[i].left, tlist[i].right);
				currT = newT;
				result.add(currT);
			}
		}
		return result;
	}

	public static void main(String args[])
	{
		Tuple tlist[] = {new Tuple(1,5), new Tuple(3,7), new Tuple(4,6), new Tuple(6,8),
		 new Tuple(10,12), new Tuple(11,15)};
		 ArrayList<Tuple> result = Overlap.overlap(tlist);
		 for(Tuple t : result) {
		 	System.out.println(t.toMyString());
		 }
	}
}