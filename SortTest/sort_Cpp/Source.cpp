#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

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
	sort(p, p + n);
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - start);
	cout << "Time taken by sort (C++) function: " << duration.count() << " ms" << endl;
	fi.close();
	return 0;
}