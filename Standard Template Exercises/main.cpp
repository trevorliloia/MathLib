#include <vector>
#include <iostream>
#include <ctime>
#include <map>
#include <algorithm>
#include <functional>
#include <array>
using namespace std;



int main()
{
	srand(time(0));

	vector<int> data;

	for (int i = 0; i < 20; ++i)
	{
		data.push_back(rand() % 10);
	}

	for each (auto var in data)
	{
		cout << var << " ";
	}
	cout << endl;
	sort(data.begin(), data.end());

	for each (auto var in data)
	{
		cout << var << " ";
		//cout << endl;
	}

	for (int i = 0; i < 20; i += 2)
	{
		data[i] = 0;
	}

	for each (auto var in data)
	{
		cout << var << " ";
	}
	cout << endl;
	sort(data.rbegin(), data.rend());

	for each (auto var in data)
	{
		cout << var << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}