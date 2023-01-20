#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100 

// char stack[100];
int top1=-1;
int top2=-1;
int top3=-1;
char stack1[100];
char stack2[100];
int stack3[100];


void push1(char ele){
     if(top1==99){
          printf("stack full");
     }
     else{
          top1++;
          stack1[top1]=ele;
     
     }
}

 char pop1(){
     if(top1==-1){
         printf("stack empty");
     }
     else{
          char ele=stack1[top1];
          top1--;
          return ele;
     }
}

void push2(char ele){
     if(top2==99){
          printf("stack full");
     }
     else{
          top2++;
          stack2[top2]=ele;
     
     }
}

 char pop2(){
     if(top2==-1){
         printf("stack empty");
     }
     else{
          char ele=stack2[top2];
          top2--;
          return ele;
     }
}
void push3(int ele){
     if(top3==99){
          printf("stack full");
     }
     else{
          top3++;
          stack3[top3]=ele;
     
     }
}

 int pop3(){
     if(top3==-1){
         printf("stack empty");
     }
     else{
          int ele=stack3[top3];
          top3--;
          return ele;
     }
}

int palindrome(char arr[]){
     int len=strlen(arr);
     int l=len/2;
     int i;
     for(i=0;i<l;i++){
          push1(arr[i]);
     }

     if(len%2!=0){
          i++;
     }

     while(arr[i]!='\0'){
          char ele=pop1();
          if(ele!=arr[i]){
              return 0;
               }
          i++;
     }
     return 1;
}

void reverse(char arr[]){
     int len=strlen(arr);
     int i;
     for(i=0;i<len;i++){
          push1(arr[i]);
     }

     for(i=0;i<len;i++){
          char ele=pop1();
          printf("%c",ele);
     }

}

void parenthesischeck(char str[]){
     int len=strlen(str);
     int i;
     while(str[i]){
          if(str[i]=='[' || str[i]=='{' || str[i]=='('){
               push1(str[i]);
          }
          if(str[i]==']' || str[i]=='}' || str[i]==')'){
               if(stack1[top1]=='[' && str[i]==']')
                         pop1();
               else if(stack1[top1]=='{' && str[i]=='}')
                         pop1();
               else if(stack1[top1]=='(' && str[i]==')')
                         pop1();
                                         
               }
           i++;    
        } if(top1==-1)
               printf("valid parenthesis");
           
          else 
               printf("invalid parenthesis");  
     }


void dectobin(int data){
    
          while(data!=0){

               push3(data%2);
               data/=2;
          } 

          while(top3!=-1){
               int ele = pop3();
               printf("%d",ele);
          }   

     
     
} 

int factorial(int data){
      int fact=1;
      for(int i=1;i<=data;i++){
          push3(i);
      }    

      while(top3!=-1){
          fact=fact*pop3();
      }
      printf("%d",fact);
}

void name(char arr[]){
     int len=strlen(arr);
     int i,flag=0;
     for(i=0;i<len;i++){
          if(isspace(arr[i]))
               flag++;
          if(flag==2)
              break;   
          push1(arr[i]);      
     }
     
     while(top1!=-1){
          push2(pop1());
       }
     push2(arr[i]);
     while(top2!=-1){
          if(i==len){
               printf("%c",pop2());
          }
          else{
               printf("%c",arr[i]);
               i++;
          }
     }
   
}    

void fibonacci(int data){
     for(int i=0;i<data;i++){
          if(i==0){
               push3(i);
            }
          else if(i==1){
               push3(i);
          } 
          else{
               int ele1 = pop3();
               int ele2 = pop3();
               int ele3=ele1+ele2;
               push3(ele2);
               push3(ele1);  
               push3(ele3);

          } 
          
     }
     for(int i=0;i<data;i++){
          printf(" %d ",pop3());
     }

}

void fib(int n){
     int t1,t2;
     while(n!=0){
          t1=(n-1)+(n-2);
          push3(t1);
     }
     for(int i=0;i<n;i++){
          printf(" %d ",pop3());
     }
}




int main(){
     char arr[100];
     char str1[20];
     char str2[20];
     char str3[20];


     int ch,data,st;
    
     
     while(1){
          printf("\nEnter function to perform using stacks\n");
          printf("\n1.Palindrome string check \n");
          printf("\n2.String reverse \n");
          printf("\n3.Parenthesis check \n");
          printf("\n4.Decimal to binary conversion \n");
          printf("\n5.Name : Last First Middle \n");
          printf("\n6.Factorial Number \n");
          printf("\n7.Fibonacci series \n");
          printf("\n8.Exit \n");
          
          printf("Enter your choice : ");
          scanf("%d",&ch);
          
         
          switch(ch){
               case 1:
                    printf("\nEnter string without spaces : \n");
                    scanf("%s",&arr);
                    if(palindrome(arr)){
                         printf("Palindrome");

                      }
                    else{
                         printf("Not a palindorme");
                       }
                    break;    
               case 2:
                    printf("\nEnter string without spaces : \n");
                    scanf("%s",&arr);
                    reverse(arr);
                    break;
               case 3:
                    printf("\nEnter string without spaces : \n");
                    scanf("%s",&arr);
                    parenthesischeck(arr);
                    break;
               case 4:
                    printf("\nEnter decimal number\n");
                    scanf("%d",&data);
                    dectobin(data);
                    break;
               case 5:
                    printf("\nEnter string : \n");
                    scanf("%s%s%s",str1,str2,str3);
                    strcpy(arr,str1);
                    strcat(strcat(arr," "),str2);
                    strcat(strcat(arr," "),str3);
                    printf("\nChanged string format : \n");
                    name(arr);
                    break;
               case 6:
                    printf("\nEnter number\n");
                    scanf("%d",&data);
                    factorial(data);
                    break;
               case 7:
                    printf("\nEnter number for fibonacci series\n");
                    scanf("%d",&data);
                    fibonacci(data);
                    break;
               case 8:
                    exit(1);     
               default : 
                    printf("Invalid input");     
          }           

                   


           

     }
      
    
     // if(palindrome(arr)){
     //      printf("Palindrome");

     // }
     // else{
     //      printf("Not a palindorme");
     // }
     // reverse(arr);
     // parenthesischeck(arr);
     // dectobin(100);
     // factorial(5);
     // name(arr);
     // fibonacci(10); 
     // printf("\nEnter string : \n");
     // scanf("%s%s%s",str1,str2,str3);
     // strcpy(arr,str1);
     // strcat(strcat(arr," "),str2);
     // strcat(strcat(arr," "),str3);

     // int l =strlen(str1)+ strlen(str2)+  strlen(str3)+2;
     
     // for(int i=0;i<l;i++){
     //      printf("%c",arr[i]);
     // } 
      
     
     
     
}
