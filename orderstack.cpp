#include <iostream>


using namespace std;

typedef struct

{

   int d[100];//����һ������Ϊ100��һά�����������������ó���

   int top;//ջ��ָ��

} Stack;

void chushihua(Stack * s);//��ʼ��һ��ջ

bool em(Stack * s);//�ж��Ƿ�Ϊ��

bool full(Stack * s);//�ж��Ƿ�Ϊ��

bool push(Stack * s,int a);//��ջ

bool pop(Stack * s,int *a);//��ջ

bool ding(Stack * s,int *a);//ȡջ��Ԫ��

int len(Stack * s);//ȡ��ЧԪ�ظ���

void bianli(Stack * s);//����


//�������֣�

 

//��ʼ��һ��ջ

void chushihua(Stack * s)

{

   s->top=-1;  //���ʾ��ͼ��topΪ-1  ���ǳ�ʼ�����ջ

}

 

//�ж��Ƿ�Ϊ�� 

bool em(Stack * s)

{

    if(-1==s->top)

       return true;

   else

       return  false;

}

 

//�ж��Ƿ�Ϊ�� 

bool full(Stack * s)

{

   if(99==s->top)//��������Ϊ������±�Ϊ�� ���Զ���һ����˵ 99�������һ�������ӡ�

       return true;

   else

       return false;

}

 
//��ջ

bool push(Stack * s,int a)

{

   if(full(s))  //���˾Ͳ�����ջ

       return false;

   else

    {

       s->top++;  //���ͼ  ָ���ȼ�

       s->d[s->top]=a;//  �ٰ����ݴ����Ӧ�ġ����ӡ�

       return true;

    }

}



 

 

 

//��ջ

bool pop(Stack * s,int *a)

{

   if(em(s))//  �յĵ�Ȼ���ܳ�ջ

       return false;

   else

    {

       *a=s->d[s->top]; //��ջ��Ԫ�� ���� ����

       s->top--; //ָ���һ

       return true;

    }

}

 

 //ȡջ��Ԫ��

//����ֻ��ȡջ��Ԫ�� ����ջ���κβ���

bool ding(Stack * s,int *a)

{

   if(em(s)) //ͬ�� ��ջû��Ԫ�� �Ͳ���

       return false;

   else

    {

       *a=s->d[s->top]; // ��ջ����Ԫ�ظ�ֵ����

       return true;

    }

}

 

//ȡ��ЧԪ�س���//


int len(Stack * s)

{

   return s->top+1;

}

 
//����

void bianli(Stack * s)

{

   int i;

   while(!em(s))//����Ϊ��ջ

    {

       pop(s,&i);  //���Ǿͳ�ջ����ֵ

       cout<<i<<" "; // ��ӡ

    }

   cout<<endl;//�����൱��C�����еĻ���

}



//���������֣����ԣ�

 

int main(void)

{

Stack s;
    int a,c;
    chushihua(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    ding(&s,&a);
  cout<<"��Ч����Ϊ��"<<len(&s)<<" ջ��Ԫ��Ϊ "<<a<<endl;
    bianli(&s);
    return 0;

}
