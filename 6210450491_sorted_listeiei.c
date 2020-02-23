//6210450491 Akarawat Meksangaroonrung 
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}Node;
void bubble_sort(Node *head)
{
    Node *x, *y;
    int swap;
    for(x = head; x ;x = x -> next)
    {
        for(y = x -> next; y ;y = y -> next)
        {
            if(x -> data > y -> data)
            {
                swap = x -> data;
                x -> data = y -> data;
                y -> data = swap;
            }
        }
    }
}
void create_list(Node **head, int input)
{
    Node *create = (Node *)malloc(sizeof(Node));
    Node *tmp = *head;
    create -> data = input;
    create -> next = NULL;
    if(*head == NULL)
    {
        *head = create;
    } 
    else
    {
        while(tmp -> next != NULL)
        {
            tmp = tmp -> next;
        }
        tmp -> next = create;
        bubble_sort(*head);
    }
}
void print_list(Node **head)
{
    Node *tmp;
    for(tmp = *head; tmp;tmp = tmp -> next)
    {
        printf("%d\n",tmp -> data);
    }
}
int main()
{
    Node *head = NULL;
    int input;
    while(2)
    {
        scanf("%d",&input); 
        if(input == -1)
        {
            break;
        }
        else
        {
            create_list(&head,input);
        }
    }
    print_list(&head);
}