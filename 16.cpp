#include<iostream>  
using namespace std;
#include<assert.h>  

void Permutation(char* sourceStr, char* changeStr)
{
	assert(sourceStr && changeStr);//断言，防止越界  

	if (*changeStr == '\0')
		cout<<sourceStr<<endl;//如果没有可交换字母，已经到末尾，将源字符串输出 
	else
	{
		//比如源字符串当前是sourceStr="abc",交换字符串也为changeStr="abc",
		//需要注意的是，函数void Permutation(str,str)传的是指向同一个字符串的指针
		for (char* pCh = changeStr; *pCh != '\0'; pCh++)
		{
			swap(*changeStr, *pCh);//交换第一个和后面一个  
			Permutation(sourceStr, changeStr + 1);//固定前面的，后面再排列  
			swap(*changeStr, *pCh);//再换回原来的  
		}
	}
	//一次完整的打印是这样的，首先sourceStr、changeStr都指向"abc"，接着swap第一个，结果还是"abc"，
	//这个时候就会输出'abc'。接着会退回的固定'a','b'和'c'进行交换，这个时候//sourceStr="acb"，经过后面全排列后，又会换回来，这样"acb"也就打印出来 
}

int main(void)
{
	char str[] = "abc";
	Permutation(str, str);
	return 0;
}
