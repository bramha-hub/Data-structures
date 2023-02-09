#include<stdio.h>
#include<stdlib.h>
#include<math.h>


struct node{
    int pow;
    int coeff;
    char sign;
    struct node* next;
};

struct node * poly1=NULL;
struct node * poly2=NULL;
struct node * poly3=NULL;
struct node * poly4=NULL;


void poly_1(int pow ,int coeff,char sign){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->pow=pow;
    temp->coeff=coeff;
    temp->sign=sign;
    if(poly1==NULL){
       poly1=temp;
       poly1->next=NULL;
    }
    else{
        struct node * temp1,* temp2=poly1;
        while(temp2!=NULL){
            temp1=temp2;
            temp2=temp2->next;
        }
        temp1->next=temp;
        temp->next=NULL;
    }

}

void poly_2(int pow ,int coeff,char sign){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->pow=pow;
    temp->coeff=coeff;
    temp->sign=sign;
    if(poly2==NULL){
       poly2=temp;
       poly2->next=NULL;
    }
    else{
        struct node * temp1,* temp2=poly2;
        while(temp2!=NULL){
            temp1=temp2;
            temp2=temp2->next;
        }
        temp1->next=temp;
        temp->next=NULL;
    }

}

void sort_list(struct node * ptr){
    int temp1,temp2;
    char temp3;
    struct node * index =NULL;
    while(ptr!=NULL){
        index=ptr->next;
        while(index!=NULL){
            if(index->pow>ptr->pow){
                temp1=index->pow;
                temp2=index->coeff;
                temp3=index->sign;
                index->pow=ptr->pow;
                index->coeff=ptr->coeff;
                index->sign=ptr->sign;
                ptr->pow=temp1;
                ptr->coeff=temp2;
                ptr->sign=temp3;
            }
            index=index->next;
        }
        ptr=ptr->next;
    }

}

void eval_list(struct node * ptr){
    int temp1;
    struct node * index =NULL;
    while(ptr!=NULL){
        index=ptr->next;
        while(index!=NULL){
            if(index->pow==ptr->pow){
                if(ptr->sign=='+' && index->sign=='+'){
                    ptr->coeff=ptr->coeff + index->coeff;
                    ptr->next=index->next;

                }
                else if(ptr->sign=='-' && index->sign=='-'){
                    ptr->coeff=ptr->coeff + index->coeff;
                    ptr->next=index->next;
                }
                else if((ptr->sign=='+' && index->sign=='-')||(ptr->sign=='-' && index->sign=='+')){
                    temp1=ptr->coeff - index->coeff;
                    temp1=abs(temp1);
                    ptr->coeff=temp1;
                    if(ptr->coeff<index->coeff){
                            ptr->sign=index->sign;
                    }
                    ptr->next=index->next;


                }

                
            }
            index=index->next;
        }
        ptr=ptr->next;
    }

}


void a_result(int pow ,int coeff,char sign){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->pow=pow;
    temp->coeff=coeff;
    temp->sign=sign;
    if(poly3==NULL){
       poly3=temp;
       poly3->next=NULL;
    }
    else{
        struct node * temp1,*temp2=poly3;
        while(temp2!=NULL){
            temp1=temp2;
            temp2=temp2->next;
        }
        temp1->next=temp;
        temp->next=NULL;
    }

}



void m_result(int pow ,int coeff,char sign){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->pow=pow;
    temp->coeff=coeff;
    temp->sign=sign;
    if(poly4==NULL){
       poly4=temp;
       poly4->next=NULL;
    }
    else{
        struct node * temp1,*temp2=poly4;
        while(temp2!=NULL){
            temp1=temp2;
            temp2=temp2->next;
        }
        temp1->next=temp;
        temp->next=NULL;
    }

}

void multiply(struct node * ptr1,struct node * ptr2){
    int res1,res2;
    sort_list(ptr1);
    sort_list(ptr2);
    eval_list(ptr1);
    eval_list(ptr2);
    while(ptr1!=NULL){
        ptr2=poly2;
        while(ptr2!=NULL){
             if(ptr1->sign=='+' && ptr2->sign=='+'){
                res1=ptr1->coeff*ptr2->coeff;
                res2=ptr1->pow+ptr2->pow;
                m_result(res2,res1,ptr1->sign);
                ptr2=ptr2->next;
              }
              else if((ptr1->sign=='+' && ptr2->sign=='-')||(ptr1->sign=='-' && ptr2->sign=='+')){
                res1=ptr1->coeff*ptr2->coeff;
                res2=ptr1->pow+ptr2->pow;
                m_result(res2,res1,'-');
                ptr2=ptr2->next;
              }
              else if(ptr1->sign=='-' && ptr2->sign=='-'){
                res1=ptr1->coeff*ptr2->coeff;
                res2=ptr1->pow+ptr2->pow;
                m_result(res2,res1,'+');
                ptr2=ptr2->next;
              }
        }
        ptr1=ptr1->next;

    }
    eval_list(poly4);
    
}

void add(struct node * ptr1,struct node * ptr2){
    int res;
    sort_list(ptr1);
    sort_list(ptr2);
    eval_list(ptr1);
    eval_list(ptr2);
    while(ptr1 && ptr2){
         if(ptr1->pow>ptr2->pow){
            a_result(ptr1->pow,ptr1->coeff,ptr1->sign);
            ptr1=ptr1->next;
         }
         else if(ptr1->pow<ptr2->pow){
            a_result(ptr2->pow,ptr2->coeff,ptr2->sign);
            ptr2=ptr2->next;
         }
         else{
            if(ptr1->sign=='+' && ptr2->sign=='+'){
                res=ptr1->coeff+ptr2->coeff;
                a_result(ptr1->pow,res,ptr1->sign);
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            else if(ptr1->sign=='-' && ptr2->sign=='-'){
                res=ptr1->coeff+ptr2->coeff;
                a_result(ptr1->pow,res,ptr1->sign);
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }  
            else if((ptr1->sign=='+' && ptr2->sign=='-')||(ptr1->sign=='-' && ptr2->sign=='+') ) {
                res=ptr1->coeff-ptr2->coeff;
                res=abs(res);
                if(ptr1->coeff>ptr2->coeff){
                    a_result(ptr1->pow,res,ptr1->sign);
                }
                else{
                    a_result(ptr1->pow,res,ptr2->sign);
                }
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }

         }
    }
    eval_list(poly3);
}



    void display_polynomial(struct node* head) {
    struct node* ptr = head;
    while (ptr != NULL) {
        if (ptr->pow == 0) {
            printf("%d", ptr->coeff);
        } else {
            printf("%dx^%d", ptr->coeff, ptr->pow);
        }
        ptr = ptr->next;
        if (ptr != NULL) {
            printf(" + ");
        }
    }
}



void display(struct node * ptr){
   
    while(ptr->next!=NULL){
        if(ptr->pow==0){
            printf(" %c %d",ptr->sign,ptr->coeff);
        }
        else if(ptr->pow==1){
             printf(" %c %dX",ptr->sign,ptr->coeff);
        }
        else{
             printf(" %c %dX^%d",ptr->sign,ptr->coeff,ptr->pow);
        }
       
        ptr=ptr->next;
    }
    if(ptr->pow==0){
        printf(" %c %d",ptr->sign,ptr->coeff);
    }
    else if(ptr->pow==1){
            printf(" %c %dX",ptr->sign,ptr->coeff);
    }
    else{
            printf(" %c %dX^%d",ptr->sign,ptr->coeff,ptr->pow);
    }
    
}
int main(){
   int term;
   int pow,coeff;
   char sign;
   printf("\nEnter number of terms in polynomial 1 : ");
   scanf("%d",&term);
   for(int i=0;i<term;i++){
      printf("\nTerm %d (sign coefficient power) ",i+1);
      scanf(" %C %d %d",&sign,&coeff,&pow);
      poly_1(pow,coeff,sign);
   }

   printf("\nEnter number of terms in polynomial 2 : ");
   scanf("%d",&term);
   for(int i=0;i<term;i++){
      printf("\nTerm %d (sign coefficient power) ",i+1);
      scanf(" %C %d %d",&sign,&coeff,&pow);
      poly_2(pow,coeff,sign);
   }

//    poly_1(6,9,'-');
//    poly_1(2,4,'+');
//    poly_1(3,5,'-');
//    poly_1(1,6,'-');
//    poly_2(2,2,'+');
//    poly_2(3,5,'-');
//    poly_2(1,1,'+');
//    poly_2(3,8,'-');
//    poly_2(4,10,'+');
//    poly_2(4,5,'-');
//    poly_2(4,3,'+');
   

    add(poly1,poly2);
    multiply(poly1,poly2);
   
   
    printf("\n");
    display(poly1);
    printf("\n");
    display(poly2);
    printf("\n");
    printf("\n ADDITION :");
    display(poly3);
    printf("\n");
    printf("\n MULTIPLICATION :");
    display(poly4);
    printf("\n");
    // printf("\n");
    
}