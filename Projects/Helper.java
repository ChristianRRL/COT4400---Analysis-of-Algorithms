import java.util.Random;

public class Helper
{
  /**
  Returns whether an array is in sorted order

  @param data the array to test
  @return whether the array is sorted
  */
 public static <T extends Comparable<T>> boolean isSorted(T[] data)
 {
   for (int i = 0; i < data.length-1; i++)
     if (data[i+1].compareTo(data[i]) < 0)
       return false;
   return true;
 }

 /**
   Prints an array of size n, with spaces in between and a newline at the end

   @param arr the array to print
   */
 public static <T> void printArray(T[] arr)
 {
   for (int i = 0; i < arr.length; i++)
     System.out.printf("%d ", arr[i]);
   System.out.println();
 }

 /**
  Compares 3 values and returns which is the median
  When two values are equal, one of the two will be indicated

  @param a,b,c  3 values
  @return 1, 2, or 3, depending on whether a, b, or c is the median, respectively
  */
 public static <T extends Comparable<T>> int medianof3(T a, T b, T c)
 {
   if (a.compareTo(c) < 0)
   {
     if (b.compareTo(a) < 0)
       return 1;
     else if (c.compareTo(b) < 0)
       return 3;
     else
       return 2;
   }
   else if (b.compareTo(c) < 0)
     return 3;
   else if (a.compareTo(b) < 0)
     return 1;
   else
     return 2;
 }

 /**
  Swaps two objects in an array

  @param arr the array of objects in which to swap
  @param a,b indices of the objects to swap
  */
 public static <T extends Object> void swap(T[] arr, int a, int b)
 {
   T t = arr[a];
   arr[a] = arr[b];
   arr[b] = t;
 }

  /**
    Creates an array of Integers 1 to n
    
    @param n the size of the array
    @return the array
   */
  public static Integer[] increasingArray(int n)
  {
    Integer[] arr = new Integer[n];
    for (int i = 0; i < n; i++)
      arr[i] = i+1;
    return arr;
  }

  /**
    Creates an array of Integers n down to 1
    
    @param n the size of the array
    @return the array
   */
  public static Integer[] decreasingArray(int n)
  {
    Integer[] arr = new Integer[n];
    for (int i = 0; i < n; i++)
      arr[i] = n-i;
    return arr;
  }

  /**
    Creates an array of all zeros
    
    @param n the size of the array
    @return the array
   */
  public static Integer[] zeroArray(int n)
  {
    Integer[] arr = new Integer[n];
    for (int i = 0; i < n; i++)
      arr[i] = 0;
    return arr;
  }

  /**
    Creates a random permutation of the numbers 1 through n
    
    @param n the size of the array
    @return the array
   */
  public static Integer[] randomArray(int n)
  {
    Random rng = new Random();
    Integer[] arr = increasingArray(n);
    for (int i = n; i > 1; i--)
    {
      int swap = rng.nextInt(i);
      swap(arr, swap, i-1);
    }

    return arr;
  }
}