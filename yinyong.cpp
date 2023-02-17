#include<iostream>
using namespace std;
typedef struct stu{
	int x;
	int y;
}coor;
int main(){
	stu c1;
	stu &c=c1;
	c.x=12;
	c.y=45;
	cout<<c1.x<<c1.y<<endl;
	return 0;
}
