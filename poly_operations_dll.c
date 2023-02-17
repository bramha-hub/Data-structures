#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct node {
    int pow ;
    int coeff;
    struct node * next,* prev;

};

struct node * poly1=NULL;
struct node * poly2=NULL;
struct node * poly3=NULL;
struct node * poly4=NULL;

void poly_1(int pow ,int coeff){

        struct node * temp=(struct node *)malloc(sizeof(struct node));
        temp->pow=pow;
        temp->coeff=coeff;
        if(poly1==NULL){
            poly1=temp;
            poly1->next=NULL;
            poly1->prev=NULL;

        }
        else{

            struct node * temp3,* temp2=poly1;
            while(temp2!=NULL){
                temp3=temp2;
                temp2=temp2->next;
            }
            temp3->next=temp;
            temp->prev=temp3;
            temp->next=NULL;
        }
}
void poly_2(int pow ,int coeff){

        struct node * temp=(struct node *)malloc(sizeof(struct node));
        temp->pow=pow;
        temp->coeff=coeff;
        if(poly2==NULL){
            poly2=temp;
            poly2->next=NULL;
            poly2->prev=NULL;

        }
        else{

            struct node * temp3,* temp2=poly2;
            while(temp2!=NULL){
                temp3=temp2;
                temp2=temp2->next;
            }
            temp3->next=temp;
            temp->prev=temp3;
            temp->next=NULL;
        }
}

void aresult(int pow ,int coeff){

        struct node * temp=(struct node *)malloc(sizeof(struct node));
        temp->pow=pow;
        temp->coeff=coeff;
        if(poly3==NULL){
            poly3=temp;
            poly3->next=NULL;
            poly3->prev=NULL;

        }
        else{

            struct node * temp3,* temp2=poly3;
            while(temp2!=NULL){
                temp3=temp2;
                temp2=temp2->next;
            }
            temp3->next=temp;
            temp->prev=temp3;
            temp->next=NULL;
        }
}
void mresult(int pow ,int coeff){

        struct node * temp=(struct node *)malloc(sizeof(struct node));
        temp->pow=pow;
        temp->coeff=coeff;
        if(poly4==NULL){
            poly4=temp;
            poly4->next=NULL;
            poly4->prev=NULL;

        }
        else{

            struct node * temp3,* temp2=poly4;
            while(temp2!=NULL){
                temp3=temp2;
                temp2=temp2->next;
            }
            temp3->next=temp;
            temp->prev=temp3;
            temp->next=NULL;
        }
}

void sort_list(struct node * ptr){
    struct node * ptr2;
    int pow,coeff;
    while(ptr!=NULL){
        ptr2=ptr->next;
        while(ptr2!=NULL){
            if(ptr->pow<ptr2->pow){
                  pow=ptr->pow;
                  coeff=ptr->coeff;
                  ptr->pow=ptr2->pow;
                  ptr->coeff=ptr2->coeff;
                  ptr2->pow=pow;
                  ptr2->coeff=coeff;
             }
             ptr2=ptr2->next;
        }
        ptr=ptr->next;
    }
}



void add(struct node * ptr1,struct node * ptr2){
    int res;

    while(ptr1 && ptr2){
        if(ptr1->pow>ptr2->pow){
            aresult(ptr1->pow,ptr1->coeff);
             ptr1=ptr1->next;
        }
        else if(ptr1->pow<ptr2->pow){
            aresult(ptr2->pow,ptr2->coeff);
            ptr2=ptr2->next;
        }
        else{
            res=ptr1->coeff+ptr2->coeff;
            aresult(ptr1->pow,res);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
}
void eval(struct node * ptr){
    struct node * ptr2;
   
    while(ptr!=NULL){
        ptr2=ptr->next;
        while(ptr2!=NULL){
            if(ptr->pow==ptr2->pow){
                 ptr->coeff=ptr->coeff+ptr2->coeff;
                 ptr->next=ptr2->next;
             }
             ptr2=ptr2->next;
        }
        ptr=ptr->next;
    }
}

void multiply(struct node * ptr1){
    int res1,res2;
    struct node * ptr2;
    while(ptr1!=NULL){
        ptr2=poly2;
        while(ptr2!=NULL){
             res1=ptr1->coeff*ptr2->coeff;
             res2=ptr1->pow+ptr2->pow;
             mresult(res2,res1);
             ptr2=ptr2->next;

        }
        ptr1=ptr1->next;
    }
}

void display(struct node * ptr){
    do{
        if(ptr->coeff>=0){
            printf(" + %dx^%d",ptr->coeff,ptr->pow);
            
        }
        else{

            printf(" - %dx^%d",-ptr->coeff,ptr->pow);
            
        }   
        ptr=ptr->next; 
        }while(ptr->next!=NULL);
       
        if(ptr->coeff>=0){
                    printf(" + %dx^%d",ptr->coeff,ptr->pow);
                
        }
        else{

            printf(" - %dx^%d",-ptr->coeff,ptr->pow);
           
        } 
    
}



int main(){
    // poly_1(2,-4);
    // poly_1(4,-3);
    // poly_1(7,5);
    // poly_1(2,3);
    // poly_1(3,6);
    // poly_1(1,-5);
    // poly_2(4,-3);
    // poly_2(2,4);
    // poly_2(2,5);
    // poly_2(3,-9);
   int term;
   int pow,coeff;

   printf("\nEnter number of terms in polynomial 1 : ");
   scanf("%d",&term);
   for(int i=0;i<term;i++){
      printf("\nTerm %d (coefficient power) ",i+1);
      scanf(" %d %d",&coeff,&pow);
      poly_1(pow,coeff);
   }

   printf("\nEnter number of terms in polynomial 2 : ");
   scanf("%d",&term);
   for(int i=0;i<term;i++){
      printf("\nTerm %d (coefficient power) ",i+1);
      scanf(" %d %d",&coeff,&pow);
      poly_2(pow,coeff);
   }
    sort_list(poly1);
    sort_list(poly2);
    // display(poly1);
    printf("\n");
    eval(poly1);
    eval(poly2);
    add(poly1,poly2);
    multiply(poly1);
    sort_list(poly4);
    eval(poly4);

    display(poly1);
    printf("\n");
    display(poly2);
    printf("\n");
    printf("ADDITION : ");
    display(poly3);
    printf("\n");
    printf("MULTIPLICATION : ");
    display(poly4);
    return 0;


    
}