#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* add_at_beg(struct node *head){
    struct node *temp;
    temp = malloc(sizeof(struct node));
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    
    temp->data = data;
    temp->link = head;
    return temp;
}


struct node* add_at_end(struct node *head, struct node *ptr, int data){
    struct node *temp;

    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = head;

    ptr->link = temp;
    return temp;
}

void main(){
    struct node *head=NULL, *temp;
    //Creating a linked-list
    head = add_at_beg(head);

    temp = add_at_end(head,head, 6);
    temp = add_at_end(head, temp, 7);
    
    //Adding in the beginning
    head = add_at_beg(head);

    temp = add_at_end(head, temp, 8);

    temp=head;
    do{
        printf("%d ", temp->data);
        temp=temp->link;
    }while (temp!=head);
    temp=NULL;
}