#include<iostream>  
using namespace std;
#include<assert.h>  

void Permutation(char* sourceStr, char* changeStr)
{
	assert(sourceStr && changeStr);//���ԣ���ֹԽ��  

	if (*changeStr == '\0')
		cout<<sourceStr<<endl;//���û�пɽ�����ĸ���Ѿ���ĩβ����Դ�ַ������ 
	else
	{
		//����Դ�ַ�����ǰ��sourceStr="abc",�����ַ���ҲΪchangeStr="abc",
		//��Ҫע����ǣ�����void Permutation(str,str)������ָ��ͬһ���ַ�����ָ��
		for (char* pCh = changeStr; *pCh != '\0'; pCh++)
		{
			swap(*changeStr, *pCh);//������һ���ͺ���һ��  
			Permutation(sourceStr, changeStr + 1);//�̶�ǰ��ģ�����������  
			swap(*changeStr, *pCh);//�ٻ���ԭ����  
		}
	}
	//һ�������Ĵ�ӡ�������ģ�����sourceStr��changeStr��ָ��"abc"������swap��һ�����������"abc"��
	//���ʱ��ͻ����'abc'�����Ż��˻صĹ̶�'a','b'��'c'���н��������ʱ��//sourceStr="acb"����������ȫ���к��ֻỻ����������"acb"Ҳ�ʹ�ӡ���� 
}

int main(void)
{
	char str[] = "abc";
	Permutation(str, str);
	return 0;
}
