/**
 * 
 * @author christianrodriguez
 *
 */
/*Instructions:
	Implement four sorting functions: selectionsort, insertionsort, mergesort, and quicksort.
*/

public class Sorting
{
	public static <T extends Comparable<T>> void selectionsort(T[] data)
	{
		for (int i = 0; i < data.length; i++)
		{
			for (int j = i + 1; j < data.length; j++)
			{
				// Note: cannot perform if (data[j] < data[i]) comparison because data is of type T 
				// we don't know type is data, and since it may not be int we cannot compare them
				if (data[j].compareTo(data[i]) < 0)
				{
					Helper.swap(data,  i,  j);
					//swap(data, i, j);
				}
			}
		}
	}
	public static <T extends Comparable<T>> void insertionsort(T[] data)
	{
		for (int i = 1; i < data.length; i++)
		{
			int j = i;
			while (j > 0 && (int)data[j-1] > (int)data[j])
			{
				Helper.swap(data, j, j-1);
				j--;
			}
		}
	}
	
	/**
	 * 
	 * @param data
	 * @param left
	 * @param right
	 * @param temp
	 */
	public static <T extends Comparable<T>> void mergesort(T[] data, int left, int right, T[] temp)
	{
		if ((right - left) > 1)
		{
			int mid = (left + right) / 2;
			
			mergesort(data, left, mid, temp);
			mergesort(data, mid, right, temp);
			
			int l = left;
			int r = mid;
			int s = 0;
			
			while (l < mid && r < right)
			{
				if ((int)data[l] < (int)data[r])
				{
					temp[s] = data[l];
					l++;
				}
				else
				{
					temp[s] = data[r];
					r++;
				}
				s++;
			}
			
			// left copy
			System.arraycopy(data, l, temp, s, mid - l);
			
			// increment s
			s += mid - l;
			
			// right copy
			System.arraycopy(data, r, temp, s, right - r);
			
			s = s + mid - l;
			
			// copy temp to data
			System.arraycopy(temp, 0, data, left, (right - left));
			
		}
	}
	public static <T extends Comparable<T>> void quicksort(T[] data, int left, int right)
	{
		// Another problem with this algorithm
		if ((right - left) > 1)
		{
			int mid = (left + right) / 2;
			
			int temp = Helper.medianof3(data[0], data[mid], data[data.length - 1]);
			int pivot = 0;
			
			if (temp == 1)
				pivot = 0;
			if (temp == 2)
				pivot = mid;
			if (temp == 3)
				pivot = data.length - 1;
			
			Helper.swap(data, (int)data[pivot], (int)data[0]);
			
			left = 0;
			right = data.length - 1;
		}
		
		int l = left;
		int r = right;
		do
		{
			while (l < r && (int)data[l] <= (int)data[left])
				l++;
			while (l < r && (int)data[r] > (int)data[left])
				r--;
			Helper.swap(data, (int)data[l], (int)data[r]);
		}
		while(l < r);
		
		if ((int)data[l] > (int)data[left])
			l--;
		
		Helper.swap(data, (int)data[left], (int)data[l]);
		
		quicksort(data, left, l);
		quicksort(data, l + 1, right);
		

		// // base case of recursive function
		// if (size <= 1)
		// {
		// 	return;
		// }

		// int mid = (size + 1) / 2;

		// int temp = medianof3(data[0], data[mid], data[size - 1]);
		// int pivot = 0;

		// // set pivot the the mediam of the numbers
		// if (temp == 1)
		// {
		// 	pivot = 0;
		// }
		// if (temp == 2)
		// {
		// 	pivot = mid;
		// }
		// if (temp == 3)
		// {
		// 	pivot = size - 1;
		// }

		// // perform first swap
		// swap(data[pivot], data[0]);

		// int left = 0;
		// int right = size - 1;

		// // shift left and right elements while performing swaps
		// do
		// {
		// 	while (left < right && data[left] <= data[0])
		// 	{
		// 		left++;
		// 	}
		// 	while (left < right && data[right] > data[0])
		// 	{
		// 		right--;
		// 	}
		// 	swap(data[left], data[right]);
		// }
		// while (!(left >= right));
		
		// if (data[left] > data[0])
		// {
		// 	left--;
		// }

		// // perform third swap
		// swap(data[0], data[left]);

		// // recursively iterate through left side
		// quicksort(data, left);
		// // recursively iterate through right side
		// quicksort(data + left + 1, size - left - 1);

	}
}