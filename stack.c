#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void Push(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    
    if(t==NULL)
	printf("Stack is full\n");
    else
    {
	t->data = x;
	t->next = top;
	top = t;
    }
}

int Pop()
{
    struct Node *t;
    int x = -1;

    if (top==NULL)
	printf("Stack is empty\n");
    else
    {
	t=top;
	top = top->next;
	x = t->data;
	free(t);
    }
    return x;
}


void Display()
{
    struct Node *p;
    p = top;
    while(p!=NULL)
    {
	printf("%d ", p->data);
	p = p->next;
    }
    printf("\n");
}



int main()
{
    Push(10);
    Push(20);
    Push(30);
    Display();
    printf("%d \n", Pop());
    Display();

    return 0;
}
