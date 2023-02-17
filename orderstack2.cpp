#include <iostream>

 #include <stdio.h>             /*数组顺序栈*/
   #include <stdlib.h>
   #define TURE 1
   #define FALSE -1                               /**/
  #define Stack_Size 50
   
   typedef int StackDateType;
   
   struct stack
  {
      StackDateType Date[Stack_Size];
      int top;
  };
  typedef struct stack* SeqStack;
  
  int IsEmpty(SeqStack S);                   /*判断栈是否为空*/
  int IsFull(SeqStack S);                    /*判断栈是否溢出了*/
  int Push(SeqStack S, StackDateType x);     /*进栈*/
  int Pop(SeqStack S, StackDateType *x);      /*出栈*/
  int GetTop(SeqStack S, StackDateType *x);    /*读出栈顶的值*/
  void print(struct stack S);                  /*打印出顺序栈的值*/
  void InitStack(SeqStack S);                  /*初始化*/
  
 int main()
  {
      struct stack S;
      int i, ret;
      StackDateType x;
      InitStack(&S);
  
      for (i = 1; i <= 10; i++)
     {
         Push(&S, i);
      }
      print(S);
  
      Pop(&S, &x);
     printf("Pop value = %d\n", x);
     print(S);
  
      GetTop(&S, &x);
     printf("Top value = %d\n", x);
     print(S);
  
      return 0;
  }
  
  void print(struct stack S)       /*void pint(SeqStack S) lead to S->top changing形参不可以为指针*/
  {
      if (S.top == -1)
     {
          printf("none value\n");
      }
      else
      {
         while (S.top != -1)
          {
             printf("%d ", S.Date[S.top]);
             S.top--;
          }
          printf("\n");
      }
  }
  
  void InitStack(SeqStack S)
 {
      S->top = -1;
  }
  
  int IsEmpty(SeqStack S)
  {
      if (-1 == S->top)
     {
          return TURE;
     }
      else
      {
        return FALSE;
     }
  }
  
  int IsFull(SeqStack S)
  {
      if (S->top == Stack_Size - 1)
      {
        return TURE;
      }
      else
      {
          return FALSE;
      }
  }
  
 int Push(SeqStack S, StackDateType x)
  {
      if (1 == IsFull(S))                   /*if (IsEmpty(S) is error,'-1' 亦是真 或者#define 0 FALSE*/
      {
          printf("Stack Full\n");
     }
    else
    {
         S->top++;
         S->Date[S->top] = x;
         return TURE;
     }
 }
 
 int Pop(SeqStack S, StackDateType *x)
 {
     if (1 == IsEmpty(S))
     {
         printf("stack is empty");
        return FALSE;
     }
     else
   {
 
         *x = S->Date[S->top];
         S->top--;
         return TURE;
     }
}
 
int GetTop(SeqStack S, StackDateType *x)
 {
     if (1 == IsEmpty(S))
    {
         return FALSE;
    }
     else
    {
         *x = S->Date[S->top];
        return TURE;
     }
} 


