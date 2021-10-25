#include <bits/stdc++.h>
using namespace std;
int top=-1,s[100];
int performop(int op1,int op2,char temp)
{
  int ans;
  switch(temp)
  {
    case '+':
        ans=op1+op2;
        break;
    case '-':
        ans=op1-op2;
        break;
    case '*':
        ans=op1*op2;
        break;
    case '/':
        ans=op1/op2;
        break;
  }
  return ans;
}
int convt(char temp)
{
  int  i=temp-'0';
	return i;
}

void push(int x)
{
  top++;
  s[top]=x;
}

int pop()
{
  top--;
  return (s[top+1]);
}

int main()
{
  char temp;
  string str;
  int j=0,n,temp1,op2,op1,value;
  cin >> str;
  reverse(str.begin(), str.end());
  n=str.length();
  for(int i=0;i<n;i++)
  {
    temp=str[j];
    j++;
    if(temp>=48&&temp<=57)
    {
      temp1=convt(temp);
      push(temp1);
    }
    else
    {
      op2=pop();
      op1=pop();
      value=performop(op1,op2,temp);
      push(value);
    }
  }
  cout << "THE ANSWER IS :-"<<s[0];
  return 0;
}