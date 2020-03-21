/*Assumptions:
    1) The operands are single digit
    2) The expression is infix   */

#include<iostream.h>
#include<string.h>
#include<conio.h>
char str[100],opr[100];
int opn[100],top1=-1,top2=-1,x,y,z,w;
int preced(char ch)
{
 switch(ch)
 {
  case'(':
   return 1;
  case'+':
  case'-':
   return 2;
  case'*':
  case'/':
   return 3;
  case'^':
   return 4;
  }
}
int calc(char op,int a,int b)
{
 if(op=='+')
  return(a+b);
 else if(op=='-')
  return(a-b);
 else if(op=='*')
  return(a*b);
 else if(op=='/')
  return(a/b);
 else if(op=='^')
  return(a^b);
}
void pushopr(char a)
{
 ++top1;
 opr[top1]=a;
}
void pushopn(int a)
{
 ++top2;
 opn[top2]=a;
}
void main()
{
 clrscr();
 cout<<"Enter the expression : ";
 cin>>str;
 for(int i=0;i<strlen(str);i++)
 {
  if(str[i]=='(')
  {
   pushopr('(');
  }
  else if(str[i]==')')
  {
   while(opr[top1]!='(')
   {
    int x=opn[top2];
      --top2;
    int y=opn[top2];
      --top2;
     int z=calc(opr[top1],x,y);
     pushopn(z);
    --top1;
    }
    --top1;
   }
  else if((str[i]=='+')||(str[i]=='-')||(str[i]=='*')||(str[i]=='/')||(str[i]=='^'))
   {
      w=preced(str[i]);
     while(top1>=0&&preced(opr[top1])>=w)
      {
       x=opn[top2];
       --top2;
       y=opn[top2];
       --top2;
       z=calc(opr[top1],x,y);
	pushopn(z);
       --top1;
      }
     pushopr(str[i]);
    }
   else
    {
      pushopn(int(str[i])-48);
     }
  }
 while(top1>=0)
 {
  x=opn[top2];
   --top2;
  y=opn[top2];
   --top2;
  z=calc(opr[top1],x,y);
   pushopn(z);
   --top1;
  }
 cout<<"\nResult : "<<opn[top2];
 getch();
}











