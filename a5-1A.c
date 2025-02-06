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

void add_at_pos(struct node **head, int pos, int data, int size){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = NULL;
    struct node *temp=*head;

    if (pos==1){
        do{
            temp=temp->link;
            size++;
        }while (temp->link!=*head);
        ptr->link = *head;
        *head = ptr;
        temp->link=*head;
    }
    else if(pos==size+1){
        do{
            temp=temp->link;
            size++;
        }while (temp->link!=*head);

        temp->link = ptr;
        ptr->link = *head;
    }

    else{
        int i=2;
        while (i<pos){
            temp=temp->link;
            i++;
        }
        ptr->link = temp->link;
        temp->link = ptr;
    }
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
    temp=head;
    do{
        printf("%d ", temp->data);
        temp=temp->link;
        size++;
    }while (temp!=head);
    temp=NULL;

    printf("\nEnter the data & position you wanna insert at: ");
    scanf("%d %d", &data, &pos);

    add_at_pos(&head, pos, data, size);
    
    temp=head;
    do{
        printf("%d ", temp->data);
        temp=temp->link;
        size++;
    }while (temp!=head);
    
}