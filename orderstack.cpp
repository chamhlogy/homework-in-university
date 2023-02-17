#include <iostream>


using namespace std;

typedef struct

{

   int d[100];//定义一个长度为100的一维数组这里可以随便设置长度

   int top;//栈顶指针

} Stack;

void chushihua(Stack * s);//初始化一个栈

bool em(Stack * s);//判断是否为空

bool full(Stack * s);//判断是否为满

bool push(Stack * s,int a);//入栈

bool pop(Stack * s,int *a);//出栈

bool ding(Stack * s,int *a);//取栈顶元素

int len(Stack * s);//取有效元素个数

void bianli(Stack * s);//遍历


//函数部分：

 

//初始化一个栈

void chushihua(Stack * s)

{

   s->top=-1;  //结合示意图让top为-1  就是初始化这个栈

}

 

//判断是否为空 

bool em(Stack * s)

{

    if(-1==s->top)

       return true;

   else

       return  false;

}

 

//判断是否为满 

bool full(Stack * s)

{

   if(99==s->top)//这里是因为数组的下标为零 所以对于一百来说 99就是最后一个“格子”

       return true;

   else

       return false;

}

 
//入栈

bool push(Stack * s,int a)

{

   if(full(s))  //满了就不能入栈

       return false;

   else

    {

       s->top++;  //结合图  指针先加

       s->d[s->top]=a;//  再把数据存进对应的“格子”

       return true;

    }

}



 

 

 

//出栈

bool pop(Stack * s,int *a)

{

   if(em(s))//  空的当然不能出栈

       return false;

   else

    {

       *a=s->d[s->top]; //把栈顶元素 付给 变量

       s->top--; //指针减一

       return true;

    }

}

 

 //取栈顶元素

//这里只是取栈顶元素 不对栈有任何操作

bool ding(Stack * s,int *a)

{

   if(em(s)) //同理 空栈没有元素 就不行

       return false;

   else

    {

       *a=s->d[s->top]; // 把栈顶的元素赋值即可

       return true;

    }

}

 

//取有效元素长度//


int len(Stack * s)

{

   return s->top+1;

}

 
//遍历

void bianli(Stack * s)

{

   int i;

   while(!em(s))//当不为空栈

    {

       pop(s,&i);  //我们就出栈并赋值

       cout<<i<<" "; // 打印

    }

   cout<<endl;//这是相当于C语言中的换行

}



//主函数部分（测试）

 

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
  cout<<"有效长度为："<<len(&s)<<" 栈顶元素为 "<<a<<endl;
    bianli(&s);
    return 0;

}
