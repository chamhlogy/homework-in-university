#include<iostream>
#include<iomanip> 
using namespace std;
int main()
{
	double a;
	cout << "Please input number:" << '\n';
	cin >> a;
	cout << fixed << showpoint << setprecision(2) << a << endl;
	return 0;
}