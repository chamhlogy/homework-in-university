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
	cout << "������Ա������" << endl;
	int N;
	cin >> N;
	vector<example> array(N);
	for (int i = 0; i < N; i++)
	{
		cout << "�������"<<i+1<<"��Ա��ID{����):" << endl;
		cin >> array[i].elem1;
		cout << "�������"<<i+1<<"��Ա������:" << endl;
		cin >> array[i].elem2;
	}
	sort(array.begin(), array.end(), comparison);
	cout << "Ա��������������Ϊ:" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << array[i].elem1 << " " << array[i].elem2 << endl;
	}
	system("pause");
	return 0;
}