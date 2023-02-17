#include <iostream>

 #include <stdio.h>             /*����˳��ջ*/
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
  
  int IsEmpty(SeqStack S);                   /*�ж�ջ�Ƿ�Ϊ��*/
  int IsFull(SeqStack S);                    /*�ж�ջ�Ƿ������*/
  int Push(SeqStack S, StackDateType x);     /*��ջ*/
  int Pop(SeqStack S, StackDateType *x);      /*��ջ*/
  int GetTop(SeqStack S, StackDateType *x);    /*����ջ����ֵ*/
  void print(struct stack S);                  /*��ӡ��˳��ջ��ֵ*/
  void InitStack(SeqStack S);                  /*��ʼ��*/
  
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
  
  void print(struct stack S)       /*void pint(SeqStack S) lead to S->top changing�ββ�����Ϊָ��*/
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
      if (1 == IsFull(S))                   /*if (IsEmpty(S) is error,'-1' ������ ����#define 0 FALSE*/
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


