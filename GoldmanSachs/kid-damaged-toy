public class goldmanprblm_7 {
	static int lastPosition(int n, int m, int k)
	{
        if (m <= n - k + 1)
		    return m + k - 1;

		m = m - (n - k + 1);

		return (m % n == 0) ? n : (m % n);
	}

	public static void main(String arg[])
	{
		int n = 5;
		int m = 8;
		int k = 2;
		System.out.print(lastPosition(n, m, k));
	}
}
