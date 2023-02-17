#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct Stack
{
	int top;
	char array[1000];
}Stack;

Stack S;

int Init_Stack()
{
	S.top = 0;
	return 1;
}

int IsEmpty()
{
	if (S.top == 0)
		return 1;
	else return 0;
}

int Push(char x)
{
	S.top++;
	S.array[S.top] = x;
	return S.top;
}

char Pop(Stack *S)
{
	S->top--;
	return S->array[S->top];

}

int main()
{
	Init_Stack();
	int i;
	scanf("%s", S.array);
	S.top = sizeof(S.array);
	for (i = S.top - 1; i >= 0; i--)
	{
		if (S.array[i] == '\0')
			continue;
		else
		{
			S.top = i + 1;
			break;
		}
	}

	if (!IsEmpty())
	{
		for (i = S.top - 1; i >= 0; i--)
		{
			if (S.array[i] == '\0')
				printf("");
			else
				cout << Pop(&S);
		}

	}
	cout << endl;
	if (IsEmpty())
	{
		std::cout << "ÏÖÔÚÎª¿Õ£¡£¡" << std::endl;
	}
	printf("\n");
	system("pause");
	return 0;
}
