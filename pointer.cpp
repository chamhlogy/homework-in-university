#include<iostream>
using namespace std;
int main(){
	int x=12;
	int*p =new int[5];
	//	p=&x;
	p[0]=45;
	p[1]=45;
	
	cout<<p[1]<<endl;
	delete p;
	return 0;
} 
