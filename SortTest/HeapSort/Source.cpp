#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void heapify(float arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

void HeapSort(float arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
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
	HeapSort(p, n);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start);
	cout << "Time taken by HeapSort function: " << duration.count() << " ms" << endl;
	fi.close();
	return 0;
}