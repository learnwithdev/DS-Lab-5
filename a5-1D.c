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

struct node*  del_at_pos(struct node *head, int pos){
    struct node *temp=head;
    struct node *temp2=head;
        do{
            temp2=temp2->link;
        }while (temp2->link!=head);

    if (pos==1){
        temp=head;
        head = head->link;
        free(temp);
        temp=NULL;
        temp2->link = head;
    }
    else{
        int i=2;
        while (i<pos){
            temp=temp->link;
            i++;
        }
        temp2 = temp->link;
        temp->link = temp->link->link;
        free(temp2);
        temp2=NULL;
    }
    return head;
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

    printf("\nEnter the position you wanna delete: ");
    scanf("%d", &pos);

    head = del_at_pos(head, pos);
    
    printf("\nAfter:\n");
    temp=head;
    do{
        printf("%d ", temp->data);
        temp=temp->link;
    }while (temp!=head);
}