#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int coeff;
    int pow1;
    int pow2;
    struct node * next;
};

struct node * poly1=NULL;
struct node * poly2=NULL;
struct node * poly3=NULL;
struct node * poly4=NULL;

void poly_1(int coeff, int pow1,int pow2){

    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->coeff=coeff;
    temp->pow1=pow1;
    temp->pow2=pow2;
    temp->next=NULL;
    if(poly1==NULL){
        poly1=temp;
    }
    else{
        struct node * ptr=poly1;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

void poly_2(int coeff, int pow1,int pow2){

    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->coeff=coeff;
    temp->pow1=pow1;
    temp->pow2=pow2;
    temp->next=NULL;
    if(poly2==NULL){
        poly2=temp;
    }
    else{
        struct node * ptr=poly2;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

void apoly(int coeff, int pow1,int pow2){

    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->coeff=coeff;
    temp->pow1=pow1;
    temp->pow2=pow2;
    temp->next=NULL;
    if(poly3==NULL){
        poly3=temp;
    }
    else{
        struct node * ptr=poly3;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

void mpoly(int coeff, int pow1,int pow2){

    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->coeff=coeff;
    temp->pow1=pow1;
    temp->pow2=pow2;
    temp->next=NULL;
    if(poly4==NULL){
        poly4=temp;
    }
    else{
        struct node * ptr=poly4;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}



void sort(struct node * ptr){
    struct node * ptr2;
    int temp1,temp2,temp3;
    while(ptr!=NULL){
        ptr2=ptr->next;
        while(ptr2!=NULL){
            if((ptr->pow1<ptr2->pow2) && (ptr->pow2<ptr2->pow2)){
                temp1=ptr->coeff;
                temp2=ptr->pow1;
                temp3=ptr->pow2;
                ptr->coeff=ptr2->coeff;
                ptr->pow1=ptr2->pow1;
                ptr->pow2=ptr2->pow2;
                ptr2->coeff=temp1;
                ptr2->pow1=temp2;
                ptr2->pow2=temp3;

            }
            ptr2=ptr2->next;
        }
        ptr=ptr->next;
    }
}

void eval(struct node * ptr){
    struct node * ptr2;
    while(ptr!=NULL){
        ptr2=ptr->next;
        while(ptr2!=NULL){
            if(ptr->pow1==ptr2->pow1 && ptr->pow2==ptr2->pow2){
                  ptr->coeff=ptr->coeff+ptr2->coeff;
                  ptr->next=ptr2->next;
                  
            }
            ptr2=ptr2->next;
        }
        ptr=ptr->next;
    }
}

void add(struct node * term1,struct node * term2){
    int sum;
   
   while (term1 != NULL && term2 != NULL) {
        if (term1->pow1 > term2->pow1 || (term1->pow1 == term2->pow1 && term1->pow2 > term2->pow2)) {
            apoly( term1->coeff, term1->pow1, term1->pow2);
            term1 = term1->next;
        } else if (term1->pow1 < term2->pow1 || (term1->pow1 == term2->pow1 && term1->pow2 < term2->pow2)) {
            apoly( term2->coeff, term2->pow1, term2->pow2);
            term2 = term2->next;
        } else {
            int sum = term1->coeff + term2->coeff;
            if (sum != 0) {
                apoly(sum, term1->pow1, term1->pow2);
            }
            term1 = term1->next;
            term2 = term2->next;
        }
    }
  
    while (term1 != NULL) {
        apoly(term1->coeff, term1->pow1, term1->pow2);
        term1 = term1->next;
    }
     while (term2 != NULL) {
        apoly(term2->coeff, term2->pow1, term2->pow2);
        term2 = term2->next;
    }
    }



void multiply(struct node * ptr1 ,struct node * ptr2){
    int res1,res2,res3;
    while(ptr1!=NULL){
        ptr2=poly2;
        while(ptr2!=NULL){
            res1=ptr1->coeff*ptr2->coeff;
            res2=ptr1->pow1+ptr2->pow1;
            res3=ptr1->pow2+ptr2->pow2;
            mpoly(res1,res2,res3);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }


}

void display(struct node * ptr){
    while(ptr->next!=NULL){
         if(ptr->coeff<0){
            if(ptr->pow1==0 && ptr->pow2==0){
                 printf(" - %d",-ptr->coeff);
            }
            else if(ptr->pow1==1 && ptr->pow2==1){
                  printf(" - %dxy",-ptr->coeff);   
            }
            else if(ptr->pow1==0){
                printf(" - %dy^%d",-ptr->coeff,ptr->pow2);
            }
            else if(ptr->pow2==0){
                printf(" - %dx^%d",-ptr->coeff,ptr->pow1);
            }
            else if(ptr->pow1==1){
                printf(" - %dxy^%d",-ptr->coeff,ptr->pow2);
            }
            else if(ptr->pow2==1){
                printf(" - %dx^%dy",-ptr->coeff,ptr->pow1);
            } 
            else{
                printf(" - %dx^%dy^%d",-ptr->coeff,ptr->pow1,ptr->pow2);
            }
        
          
        }
        else{
            if(ptr->pow1==0 && ptr->pow2==0){
                 printf(" + %d",ptr->coeff);
            }
            else if(ptr->pow1==1 && ptr->pow2==1){
                 printf(" + %dxy",ptr->coeff);
            }
            else if(ptr->pow1==0){
                printf(" + %dy^%d",ptr->coeff,ptr->pow2);
            }
            else if(ptr->pow2==0){
                printf(" + %dx^%d",ptr->coeff,ptr->pow1);
            }
            else if(ptr->pow1==1){
                printf(" + %dxy^%d",ptr->coeff,ptr->pow2);
            }
            else if(ptr->pow2==1){
                printf(" + %dx^%dy",ptr->coeff,ptr->pow1);
            }
            else{
                printf(" + %dx^%dy^%d",ptr->coeff,ptr->pow1,ptr->pow2);
            } 
        
          
            
        }
        ptr=ptr->next;
    }
     if(ptr->coeff<0){
            if(ptr->pow1==0 && ptr->pow2==0){
                 printf(" - %d",-ptr->coeff);
            }
            else if(ptr->pow1==1 && ptr->pow2==1){
                  printf(" - %dxy",-ptr->coeff);   
            }
            else if(ptr->pow1==0){
                printf(" - %dy^%d",-ptr->coeff,ptr->pow2);
            }
            else if(ptr->pow2==0){
                printf(" - %dx^%d",-ptr->coeff,ptr->pow1);
            }
            else if(ptr->pow1==1){
                printf(" - %dxy^%d",-ptr->coeff,ptr->pow2);
            }
            else if(ptr->pow2==1){
                printf(" - %dx^%dy",-ptr->coeff,ptr->pow1);
            } 
            else{
                printf(" - %dx^%dy^%d",-ptr->coeff,ptr->pow1,ptr->pow2);
            }
        
          
        }
        else{
            if(ptr->pow1==0 && ptr->pow2==0){
                 printf(" + %d",ptr->coeff);
            }
            else if(ptr->pow1==1 && ptr->pow2==1){
                 printf(" + %dxy",ptr->coeff);
            }
            else if(ptr->pow1==0){
                printf(" + %dy^%d",ptr->coeff,ptr->pow2);
            }
            else if(ptr->pow2==0){
                printf(" + %dx^%d",ptr->coeff,ptr->pow1);
            }
            else if(ptr->pow1==1){
                printf(" + %dxy^%d",ptr->coeff,ptr->pow2);
            }
            else if(ptr->pow2==1){
                printf(" + %dx^%dy",ptr->coeff,ptr->pow1);
            }
            else{
                printf(" + %dX^%dy^%d",ptr->coeff,ptr->pow1,ptr->pow2);
            } 
        
          
            
        }
   
}

void main(){
    //  2x2 +4xy+7y2 +3x+2y-8
    poly_1(3,1,0);
    poly_1(5,0,2);
    poly_1(4,0,2);
    poly_1(5,1,0);
    poly_1(-7,0,1);
    poly_1(3,3,1);
    // poly_1(4,2,1);
    poly_1(8,0,0);
    // poly_1(2,2,0);
    poly_2(4,1,1);
    poly_2(2,0,2);
    poly_2(7,1,0);
    poly_2(-3,4,0);
    poly_2(-5,0,1);
    poly_2(-10,0,0);
    sort(poly1);
    sort(poly2);
    // display(poly1);
    // printf("\n");
    eval(poly1);
    eval(poly2);

    add(poly1,poly2);
    multiply(poly1,poly2);
    eval(poly3);
    eval(poly4);

     
    display(poly1);
    printf("\n");
    display(poly2);
    printf("\n");
    display(poly3);
    printf("\n");
    display(poly4);
    

}


