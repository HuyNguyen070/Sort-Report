#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void QuickSort(float arr[], int l, int r)
{
	// If the first index less or equal than the last index
	if (l <= r)
	{
		// Create a pivot/Pivot Element
		float pivot = arr[(l + r) / 2];

		// Create temp Variables to loop through array
		int i = l;
		int j = r;

		while (i <= j)
		{
			while (arr[i] < pivot)
				i++;
			while (arr[j] > pivot)
				j--;

			if (i <= j)
			{
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}

		// Recursion to the smaller partition in the array after sorted above

		if (l < j)
			QuickSort(arr, l, j);
		if (r > i)
			QuickSort(arr, i, r);
	}
}

int main()
{
	ifstream fi("10.txt");
	if (fi.fail())
	{
		cout << "Fail to open the file";
		return 0;
	}
	float* p;
	int n;
	fi >> n;
	p = new float[n];
	for (int i = 0; i < n; ++i)
		fi >> *(p + i);
	auto start = high_resolution_clock::now();
	QuickSort(p, 0, n - 1);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start);
	cout << "Time taken by QuickSort function: " << duration.count() << " ms" << endl;
	fi.close();
	return 0;
}