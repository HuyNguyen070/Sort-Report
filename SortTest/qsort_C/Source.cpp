#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int cmpfunc(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
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
	qsort(p, n, sizeof(float), cmpfunc);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start);
	cout << "Time taken by qsort (C) function: " << duration.count() << " ms" << endl;
	fi.close();
	return 0;
}