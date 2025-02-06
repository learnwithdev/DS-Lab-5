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
}

struct node* addPoly(struct node *head1, struct node *head2){
    
    int i=0;
    struct node *temp1, *temp2, *head3;

    if (head1->exp>=head2->exp){
        temp1 = head1;
        temp2 = head2;
    }
    else{
        temp1 = head2;
        temp2 = head1;
    }
    
    struct node *ptr = malloc(sizeof(struct node));
    while (temp1!=NULL || temp2!=NULL){
        // struct node *ptr = malloc(sizeof(struct node));
        struct node* ptr1 = malloc(sizeof(struct node));

        if (i==0){
            if (temp1->exp==temp2->exp){
                ptr->coef = temp1->coef + temp2->coef;
                ptr->exp=  temp1->exp;
                ptr->link = NULL;

                temp1 = temp1->link;
                temp2 = temp2->link;
            }
            else if(temp1->exp>temp2->exp){
                ptr->coef = temp1->coef;
                ptr->exp=  temp1->exp;
                ptr->link = NULL;

                temp1 = temp1->link;
            }
            else{
                ptr->coef = temp2->coef;
                ptr->exp=  temp2->exp;
                ptr->link = NULL;

                temp2 = temp2->link;
            }
            head3=ptr;
        }
        else{
            if (temp1->exp==temp2->exp){
                ptr1->coef = temp1->coef + temp2->coef;
                ptr1->exp=  temp1->exp;
                ptr1->link = NULL;

                temp1 = temp1->link;
                temp2 = temp2->link;
            }
            else if(temp1->exp>temp2->exp){
                ptr1->coef = temp1->coef;
                ptr1->exp=  temp1->exp;
                ptr1->link = NULL;

                temp1 = temp1->link;
            }
            else{
                ptr1->coef = temp2->coef;
                ptr1->exp=  temp2->exp;
                ptr1->link = NULL;

                temp2 = temp2->link;
            }
            ptr->link=ptr1;
            ptr=ptr1;
        }
        i++;
    }
    temp1=NULL;
    temp2=NULL;
    return head3;
}

void display(struct node *head){
    // printf("\nNo. of terms: %d\n", size);
    while (head!=NULL){
        printf("%dx^%d ", head->coef, head->exp);
        head = head->link;
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

// 5x^5 4x^3 3x^2 1x^1 1x^1 & 6x^4 3x^3 4x^2 2x^1

// Another way of doing Polynomial sum at the cost of losing data of Polynomial-1:
    // temp=head1;
    // while (temp->link!=NULL){
    //     temp = temp->link;
    // }
    // temp->link = head2;
    // head2=NULL;
    // sortPoly(head1);
    // display(head1);

// Goody-two-shoes way:
    head3 = addPoly(head1, head2);
    display(head3);
}