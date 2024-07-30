#include <iostream>
#include <utility>

using namespace std;

void print(pair<int, int> arr[])
{
	for (auto a : arr)
		cout << a.first << ' ' << a.second << endl;
}

int main()
{
	pair<int, int> arr[] = {{1, 2}, {3, 4}};
	std::cout << sizeof(arr) / sizeof(int) << std::endl;
	print(arr); // 1 2\n3 4\n
	return 0;
}