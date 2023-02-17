#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct example
{
	int elem1;
	double elem2;
}example;
 bool comparison(example a, example b) {
	return a.elem2 < b.elem2;
}

int main()
{
	cout << "请输入员工个数" << endl;
	int N;
	cin >> N;
	vector<example> array(N);
	for (int i = 0; i < N; i++)
	{
		cout << "请输入第"<<i+1<<"个员工ID{数字):" << endl;
		cin >> array[i].elem1;
		cout << "请输入第"<<i+1<<"个员工工资:" << endl;
		cin >> array[i].elem2;
	}
	sort(array.begin(), array.end(), comparison);
	cout << "员工工资升序排列为:" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << array[i].elem1 << " " << array[i].elem2 << endl;
	}
	system("pause");
	return 0;
}