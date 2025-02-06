#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* add_at_end(struct node *head, struct node *ptr, int data){
    struct node *temp;

    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = head;

    ptr->link = temp;
    return temp;
}

void add_last(struct node **head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = NULL;
    struct node *temp=*head;
        do{
            temp=temp->link;
        }while (temp->link!=*head);

        temp->link = ptr;
        ptr->link = *head;
}

void main(){
    int size=0;
    int pos, data;

    struct node *head, *temp;
    struct node* ptr1 = malloc(sizeof(struct node));
    ptr1->data = 5;
    ptr1->link = NULL;
    head=ptr1;
    temp = add_at_end(head,head, 6);
    temp = add_at_end(head, temp, 7);
    temp = add_at_end(head, temp, 8);

    //Display
    printf("Before:\n");
    temp=head;
    do{
        printf("%d ", temp->data);
        temp=temp->link;
        size++;
    }while (temp!=head);
    temp=NULL;

    printf("\nEnter the data: ");
    scanf("%d", &data);

    add_last(&head, data);
    
    printf("\nAfter:\n");
    temp=head;
    do{
        printf("%d ", temp->data);
        temp=temp->link;
        size++;
    }while (temp!=head);
    
}