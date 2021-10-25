#include<stdio.h>
int top=0;
char s[100];

void push(char x)
{
	top++;
	s[top]=x;
}

char pop()
{
	top--;
	return s[top+1];
}

int F(char x)
{
    if(x=='+'||x=='-')
    {
        return 1;
    }
    if(x=='*'||x=='/')
    {
        return 3;
    }
    if(x=='^')
    {
        return 6;
    }
    if(x>='a'&&x<='z')
    {
        return 7;
    }
    if(x=='(')
    {
        return 9;
    }
    if(x==')')
    {
        return 0;
    }
}

int G(char x)
{
    if(x=='+'||x=='-')
    {
        return 2;
    }
    if(x=='*'||x=='/')
    {
        return 4;
    }
    if(x=='^')
    {
        return 5;
    }
    if(x>='a'&&x<='z')
    {
        return 8;
    }
    if(x=='(')
    {
        return 0;
    }
}

int R(char x)
{
    if(x=='+'||x=='-')
    {
        return -1;
    }
    if(x=='*'||x=='/')
    {
        return -1;
    }
    if(x=='^')
    {
        return -1;
    }
    if(x>='a'&&x<='z')
    {
        return 1;
    }
}

int main()
{
    s[top]='(';
    top++;
    int j=0;
    int rank=0;
    char str[100],next,temp;
    scanf("%s",&str);
    next=str[j];
    j++;
    while(next!=' ')
    {
        if(top<1)
        {
            printf("      terminated");
            return 0;
        }
        while(G(s[top])>F(next))
        {
            temp=pop();
            printf("%c",temp);
            rank=rank+R(temp);
            if(rank<1)
            {
                printf("invalid");
                return 0;
            }
        }
        if(G(s[top])!=F(next))
        {
            push(next);
        }
        else
        {
            pop();
        }
        next=str[j];
        j++;
    }
return 0;
}