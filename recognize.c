#include<stdio.h>
int s[100],top=-1;

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

void main()
{
	int j=0,counter_b=0;
	char str[100],next;
	printf("ENTER THE STRING: ");
	scanf("%s",&str);

	next=str[j];
	j++;

	while (next!='\0')
	{
		if (next=='a')
		{
			push(next);
		}
		else
		{
			counter_b=counter_b+1;
		}
		next=str[j];
		j++;
	}
	while(top!=-1)
	{
		pop();
		counter_b=counter_b-1;
	}
	if(counter_b!=0)
	{
		printf("invalid string");
	}
	else
	{
		printf("valid string");
	}
}