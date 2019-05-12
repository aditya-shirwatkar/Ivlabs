#include <iostream>
using namespace std;

#define ma(x,y) ((x>y)?x:y) // macros for maximum of 2 nos

int comp(int p[], int n, int m, int l[], int max[]); // recrusive function to find max profit


int main()
{
	int n, m, s = 0;
	
	cout << "enter number of pieces and total length "<< endl;
	cin >> m >> n;

	int* prices = new int[m]; //dynamically initialised arrays
	int* len = new int[m];
	int* maxp = new int[n];  // maxp will store max profit for length k : from 0 to n
	
	cout << " enter length of cut list  in increasing order" << endl;
	for (size_t i = 0; i < m; i++)
	{
		cin >> len[i];
	}
	cout << " enter corresponding prices " << endl;
	for (size_t i = 0; i < m; i++)
	{
		cin >> prices[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		maxp[i] = 0;
	}

	s = comp(prices, n, m,maxp);
	cout << " max value is " << s <<endl;

	for (size_t i = 0; i < 4; i++)
	{
		cout << endl;
	}
	delete[] prices;
	delete[] len;
	delete[] maxp;
	return 0;
}

int comp(int p[], int n, int m, int max[])
{
	if (n <= 0)
		return 0; // for n = 0 price will be 0	
	else
	{
		for (size_t i = 0; i < m; i++)
		{
			//recursively taking maximum ith cut profit and storing in  max[] i.e maxp[]
			max[n - 1] = ma((comp(p, n - 1 - i, m, max) + p[i]), max[n-1]);

		}
		
	}
	return max[n - 1];
}
