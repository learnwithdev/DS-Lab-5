#include <stdio.h>
#include <stdlib.h>

struct node{
    int coef;
    int exp;
    struct node* link;
};

struct node* add_at_beg(struct node *head){
    struct node *temp;
    int coef, exp;

    temp = malloc(sizeof(struct node));
    printf("\nEnter coef & exp: ");
    scanf("%d %d", &coef, &exp);
    
    temp->coef = coef;
    temp->exp = exp;
    temp->link = head;

    return temp;
}

struct node* add_at_end(struct node *ptr){
    struct node *temp;
    int coef, exp;

    printf("\nEnter coef & exp: ");
    scanf("%d %d", &coef, &exp);

    temp = malloc(sizeof(struct node));
    temp->coef = coef;
    temp->exp = exp;
    temp->link = NULL;

    ptr->link = temp;
    return temp;
}

void del_at_pos(struct node **head, int pos){
    struct node *temp=*head;
    struct node *temp2;

    if (pos==1){
        temp2=temp;
        temp = temp->link;
        free(temp2);
        temp2=NULL;
        *head = temp;
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
}

struct node* getPoly(struct node *head, int *size){
    struct node *ptr;
    char user;
    int i=0;

    while (1){
        printf("Enter 'q' to exit otherwise any other letter: ");
        scanf(" %c", &user);
        if (user!='q'){
            if (i==0){
                head = add_at_beg(head);
                ptr = head;
            }
            else{
                ptr = add_at_end(ptr);
            }
            i++;
        }
        else{
            break;
        }
    }
    *size=i;
    return head;
}

void sortPoly(struct node *head){
    int max,x;
    struct node *temp1, *temp2;
    temp1=head;
    while (temp1!=NULL){
        temp2=temp1->link;
        while (temp2!=NULL){
            max=temp1->exp;
            x = temp1->coef;
            if (temp1->exp<temp2->exp){
                temp1->exp = temp2->exp;
                temp1->coef = temp2->coef;
                temp2->exp = max;
                temp2->coef = x;
            }
            temp2 = temp2->link;
        }
        temp1=temp1->link;
    }
    temp1=NULL;
    temp2=NULL;

    int i=1,j;
    temp1=head;
    while (temp1!=NULL){
        temp2=temp1->link;
        j=i+1;
        while (temp2!=NULL){
            if (temp1->exp==temp2->exp){
                temp1->coef += temp2->coef;
                temp2 = temp2->link;
                del_at_pos(&head, j);
            }
            else{
            temp2 = temp2->link;
            }
            j++;
        }
        temp1=temp1->link;
        i++;
    }
    temp1=NULL;
    temp2=NULL;

    // temp1 = head;
    // int k=1;
    // while (temp1!=NULL){
    //     if (temp1->coef==0 && k==1){
    //         temp1=temp1->link;
    //         del_at_pos(&head, 1);
    //         k++;
    //     }
    //     if (temp1->coef==0 && k!=1){
    //         temp1=temp1->link;

    //         del_at_pos(&head, k);
    //         k++;
    //     }
    //     else{
    //         temp1=temp1->link;
    //         k++;
    //     }
    // }
}

// struct node* polyProduct(){
    
// }

struct node* polyProduct(struct node *head1, struct node *head2){
    
    int i=0;
    struct node *temp1, *temp2, *temp3, *head3;

    if (head1->exp>=head2->exp){
        temp1 = head1;
        temp2 = head2;
    }
    else{
        temp1 = head2;
        temp2 = head1;
    }
    temp3 = temp2;

    struct node *ptr = malloc(sizeof(struct node));
    while (temp1!=NULL){
        temp2=temp3;
        while(temp2!=NULL){
            if (i==0){
                ptr->coef = temp1->coef*temp2->coef;
                ptr->exp = temp1->exp+temp2->exp;

                head3=ptr;
            }
            else{
                struct node* ptr1 = malloc(sizeof(struct node));
                ptr1->coef = temp1->coef*temp2->coef;
                ptr1->exp = temp1->exp+temp2->exp;

                ptr->link=ptr1;
                ptr=ptr1;
                ptr1=NULL;
            }
            temp2=temp2->link;
            i++;
        }
        temp1=temp1->link;
    }
    temp1=NULL;
    temp2=NULL;
    return head3;
}

void display(struct node *head){
    // printf("\nNo. of terms: %d\n", size);
    while (head!=NULL){\
        if (head->exp==0){
            printf("%d ", head->coef);
            head = head->link;
        }
        else{
            printf("%dx^%d ", head->coef, head->exp);
            head = head->link;
        }
    }
    printf("\n");
}

void main(){
    int size1=0, size2=0;
    struct node *head1=NULL, *head2=NULL, *head3=NULL, *temp;

    printf("Enter Polynomial 1: \n");
    head1 = getPoly(head1, &size1);
    sortPoly(head1);
    // display(head1);

    printf("\nEnter Polynomial 2: \n");
    head2 = getPoly(head2, &size2);
    sortPoly(head2);
    // display(head2);

    //5x^2 4x^1 2x^0 & 5x^1 5x^0

    printf("Result: \n");
    head3 = polyProduct(head1, head2);
    sortPoly(head3);
    display(head3);


    

}