
public class SortingDriver
{
  private static enum sort_t  {SELECTION, INSERTION, MERGE, QUICK};
  private static enum input_t {INCREASING, DECREASING, CONSTANT, RANDOM};

  static final int DEFAULT_N         = 1000;
  static final sort_t DEFAULT_ALG    = sort_t.MERGE;
  static final input_t DEFAULT_INPUT = input_t.RANDOM;

  static final int N_ARG        = 0;
  static final int ALG_ARG      = 1;
  static final int INPUT_ARG    = 2;
  static final int MIN_ARGS     = 0;
  static final int MAX_ARGS     = 3;
  static final String ARGS  = "Arguments:  [n] [algorithm] [input type]\n\nn (optional):  size of array (default:  %d)\nalgorithm (optional):  one of selectionsort, insertionsort, mergesort, or quicksort (simq, default mergesort)\ninput type (optional):  one of increasing, decreasing, constant, or random (idcr, default random)\n";

  public static void main(String[] args)
  {
    System.out.println("(1) Test main function");

    int n = DEFAULT_N;
    sort_t alg = DEFAULT_ALG;
    input_t intype = DEFAULT_INPUT;
    Integer[] data;
    Integer[] temp;
    long start;
    long[] timing = new long[3];

    //System.out.println("(2) Show args.length: " + args.length);

    //Parse input arguments
    if (args.length < MIN_ARGS || args.length > MAX_ARGS)
    {
      System.out.printf(ARGS, args[0], DEFAULT_N);
      return;
    }

    if (args.length > N_ARG)
      n = Integer.parseInt(args[N_ARG]);

    temp = Helper.zeroArray(n);
    if (args.length > ALG_ARG)
    {
      switch (args[ALG_ARG].charAt(0))
      {
      case 's':
      case 'S':
        alg = sort_t.SELECTION;
        break;
      case 'i':
      case 'I':
        alg = sort_t.INSERTION;
        break;
      case 'm':
      case 'M':
        alg = sort_t.MERGE;
        break;
      case 'q':
      case 'Q':
        alg = sort_t.QUICK;
        break;
      default:
        System.out.printf("Sorting algorithm not recognized\n");
      }
    }

    if (args.length > INPUT_ARG)
    {
      switch (args[INPUT_ARG].charAt(0))
      {
      case 'i': //increasing
      case 'I':
      case 'a': //ascending
      case 'A':
        intype = input_t.INCREASING;
        break;
      case 'd':  //decreasing, descending
      case 'D':
        intype = input_t.DECREASING;
        break;
      case 'c':  //constant
      case 'C':
      case 'z':  //zero
      case 'Z':
        intype = input_t.CONSTANT;
        break;
      case 'r':  //random
      case 'R':
        intype = input_t.RANDOM;
        break;
      default:
        System.out.printf("Input array type not recognized\n");
      }
    }

    //Run sorting algorithm 3 times
    for (int i = 0; i < 3; i++)
    {
      // Initialize data
      switch (intype)
      {
      case INCREASING:
        data = Helper.increasingArray(n);
        break;
      case DECREASING:
        data = Helper.decreasingArray(n);
        break;
      case CONSTANT:
        data = Helper.zeroArray(n);
        break;
      case RANDOM:
      default:
        data = Helper.randomArray(n);
      }

      //Sort data
      //Helper.printArray(data);
      start = System.currentTimeMillis();
      switch (alg)
      {
      case SELECTION:
        Sorting.selectionsort(data);
        break;
      case INSERTION:
        Sorting.insertionsort(data);
        break;
      case MERGE:
        Sorting.mergesort(data, 0, n, temp);
        break;
      case QUICK:
        Sorting.quicksort(data, 0, n);
      }
      timing[i] = System.currentTimeMillis() - start;
      //Helper.printArray(data);

      //Verify data is sorted
      if (Helper.isSorted(data))
        System.out.printf("Array successfully sorted.\n");
      else
      {
        System.out.printf("Array incorrectly sorted.\n");
        //Time to debug...
        return;
      }
    }

    //Output timing results
    for (int i = 0; i < 3; i++)
      System.out.printf("Attempt %d:   %8d ms\n", i+1, timing[i]);
    int med = Helper.medianof3(new Long(timing[0]), new Long(timing[1]), new Long(timing[2]))-1;
    System.out.printf("Median time: %8d ms\n", timing[med]);

    return;
  }

}