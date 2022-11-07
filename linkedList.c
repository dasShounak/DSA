#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Node Structure
struct Node
{
  int data;
  struct Node *next;
} *head = NULL;

// Create Linked List
void Create(int A[], int n)
{
  int i;
  struct Node *t, *current;
  head = (struct Node *)malloc(sizeof(struct Node));
  head->data = A[0];
  head->next = NULL;
  current = head;

  for (i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = NULL;
    current->next = t;
    current = t;
  }
}

// Display list
void Display(struct Node *p)
{
  printf("\n");
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
}

// Count number of nodes
void Count(struct Node *p)
{
  int l = 0;
  while (p != NULL)
  {
    l++;
    p = p->next;
  }
  printf("\n%d", l);
}

// Calculate sum of data in all nodes
void Sum(struct Node *p)
{
  int s = 0;
  while (p != NULL)
  {
    s += p->data;
    p = p->next;
  }
  printf("\n%d", s);
}

// Find highest value in list
void Max(struct Node *p)
{
  int max = INT32_MIN;
  while (p != NULL)
  {
    if (p->data > max)
      max = p->data;
    p = p->next;
  }

  printf("\n%d", max);
}

// Search node
void Search(struct Node *p, int key)
{
  if (p == NULL)
  {
    printf("Not found!");
  }
  else if (p->data == key)
  {
    printf("\n%d", p);
  }
  else
  {
    Search(p->next, key);
  }
}

// Insert new node
void Insert(struct Node *p, int index, int x)
{
  struct Node *t;
  int i = 0;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;

  while (i != index - 1)
  {
    i++;
    p = p->next;
  }
  t->next = p->next;
  p->next = t;
}

int main()
{
  int A[] = {3, 5, 7, 9, 11, 13};
  Create(A, 6);
  Insert(head, 3, 30);
  Display(head);
  Count(head);
  Sum(head);
  Max(head);
  Search(head, 9);

  return 0;
}