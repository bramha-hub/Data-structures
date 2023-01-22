#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char stack[100];
int top=-1;

int stack3[100];
int top3=-1;

// struct stack{
//      char arr[20];
// }stack2[20];

char stack2[10][30];
int top2=-1;

void push2(char ele[]){
     if(top2==19){
          printf("stack full");
     }
     else{
          top2++;
          strcpy(stack2[top2],ele);
     
     }
}
// const char * pop2(){
//      if(top2==-1){
//          printf("stack empty");
//      }
//      else{
//           char * ele;
//           strcpy(ele,"A");
//           // printf("%s",ele);
//           top2--;
//           return ele;
//      }
// }

void push(char ele){
     if(top==99){
          printf("stack full");
     }
     else{
          top++;
          stack[top]=ele;
     
     }
}

 char pop(){
     if(top==-1){
         printf("stack empty");
     }
     else{
          char ele=stack[top];
          top--;
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

 char pop3(){
     if(top3==-1){
         printf("stack empty");
     }
     else{
          int ele=stack3[top3];
          top3--;
          return ele;
     }
}

void intopostfix(char exp[]){
    int len=strlen(exp);
    int i,k,j=-1;
    char arr[40];

    for(i=0;i<len;i++){
        if(exp[i]=='(' || exp[i]=='['){
            push(exp[i]);
          }
        else if(exp[i]=='+' || exp[i]=='-'|| exp[i]=='*'|| exp[i]=='/' ){
               if((stack[top]=='+' &&  exp[i]=='-') || (stack[top]=='-' &&  exp[i]=='+')){
                         char ele=pop();
                         push(exp[i]);
                         arr[++j]=ele;
                         
               }
               else if((stack[top]=='*' &&  exp[i]=='/') || (stack[top]=='/' &&  exp[i]=='*')){
                         char ele=pop();
                         push(exp[i]);
                         arr[++j]=ele;
                         
               }
               else if((stack[top]=='*' &&  exp[i]=='+') || (stack[top]=='*' &&  exp[i]=='-')){
                         char ele=pop();
                         push(exp[i]);
                         arr[++j]=ele;
                         
               }
               else if((stack[top]=='/' &&  exp[i]=='+') || (stack[top]=='/' &&  exp[i]=='-')){
                         char ele=pop();
                         push(exp[i]);
                         arr[++j]=ele;
                         
               }
               else{
                      push(exp[i]);
               }
        }
        else if(exp[i]==')' || exp[i]==']'){
            while(1){
                if(stack[top]=='(' || stack[top]=='['){
                   break;
                }

               char ele=pop();
               arr[++j]=ele;                     
           }  
          pop();
        }
        else{ 
               arr[++j]=exp[i];
               
        }
        
    }

     while(top!=-1){
          arr[++j]=pop();
        } 
     arr[++j]='\0';   
    printf("\nInfix to Postfix : ");
    for(int k=0;k<strlen(arr);k++){
          printf("%c",arr[k]);
    }
    printf("\n");
    
    
    

}

// char  reverse(char arr[]){
//      int len=strlen(arr);
//      int i;
//      char arr[40];
//      for(i=0;i<len;i++){
//           push(arr[i]);
//      }

//      for(i=0;i<len;i++){
//           char ele=pop();
//           arr[i]=ele;
//      }
//      arr[++i]='\0';
//      return arr;

// }

void intoprefix(char arr[]){
     int len=strlen(arr);
     int m,k,j=-1;;
     char exp[20];
     strcpy(exp,strrev(arr));
     int len1=strlen(exp);
     for(m=0;m<len1;m++){
        if(exp[m]==')' || exp[m]==']'){
            push(exp[m]);
          }
        else if(exp[m]=='+' || exp[m]=='-'|| exp[m]=='*'|| exp[m]=='/' ){
               // if((stack[top]=='+' &&  exp[m]=='-') || (stack[top]=='-' &&  exp[m]=='+')){
               //           char ele=pop();
               //           push(exp[m]);
               //           arr2[++j]=ele;
                         
               // }
               // else if((stack[top]=='*' &&  exp[m]=='/') || (stack[top]=='/' &&  exp[m]=='*')){
               //           char ele=pop();
               //           push(exp[m]);
               //           arr2[++j]=ele;
                         
               // }
               if((stack[top]=='*' &&  exp[m]=='+') || (stack[top]=='*' &&  exp[m]=='-')){
                         char ele=pop();
                         push(exp[m]);
                         arr[++j]=ele;
                         
               }
               else if((stack[top]=='/' &&  exp[m]=='+') || (stack[top]=='/' &&  exp[m]=='-')){
                         char ele=pop();
                         push(exp[m]);
                         arr[++j]=ele;
                         
               }
               else{
                      push(exp[m]);
               }
        }
        else if(exp[m]=='(' || exp[m]=='['){
            while(1){
                if(stack[top]==')' || stack[top]==']'){
                   break;
                }

               char ele=pop();
               arr[++j]=ele;                 
           }  
          pop();
        }
        else{ 
               arr[++j]=exp[m];
               
        }
        
    }

     while(top!=-1){
          arr[++j]=pop();
        } 
     arr[++j]='\0';   
     int len3=strlen(arr);
     strcpy(arr,strrev(arr));
     printf("\nInfix to Prefix : ");
      for(int k=0;k<strlen(arr);k++){
          printf("%c",arr[k]);
    }
    printf("\n");


   

}

void posttoinfix(char exp[]){
     int len=strlen(exp);
     int i;
      char arr1[30]={0};
     char ele1[20]={0};
     char ele2[20]={0};
     //  ABC*+D*
     // ABC-D+/EA-*C*

     for(i=0;i<len;i++){
         if(isalpha(exp[i])){
               push2(strncat(arr1,&exp[i],1));
               arr1[0]='\0';
         }
         else if(exp[i]=='-'||exp[i]=='+'||exp[i]=='*'||exp[i]=='/'){
               
                    strcpy(ele2,stack2[top2--]);
                    strcpy(ele1,stack2[top2--]);
                    ele2[strlen(ele2)]='\0';
                    ele1[strlen(ele1)]='\0';
                    strcpy(arr1,"(");
                    strncat(arr1,ele1,strlen(ele1));
                    strncat(arr1,&exp[i],1);
                    strncat(arr1,ele2,strlen(ele2));
                    char ch =')';
                    strncat(arr1,&ch,1);

                    push2(arr1);
                    ele1[0]='\0';
                    ele2[0]='\0';
                    arr1[0]='\0';
                   


            
          }

      }
     
     printf("\nPostfix to Infix : %s\n",stack2[top2]);
     // printf("%d",strlen(stack2[top2]));
     
}

void prettoinfix(char exp[]){
     int len=strlen(exp);
     int i;
     char arr[30]={0};
     char ele1[20]={0};
     char ele2[20]={0};
     //  ABC*+D*
     // ABC-D+/EA-*C*
     strcpy(exp,strrev(exp));
     

     for(i=0;i<len;i++){
         if(isalpha(exp[i])){
               push2(strncat(arr,&exp[i],1));
               arr[0]='\0';
         }
         else if(exp[i]=='-'||exp[i]=='+'||exp[i]=='*'||exp[i]=='/'){
               
                    strcpy(ele2,stack2[top2--]);
                    strcpy(ele1,stack2[top2--]);
                    ele2[strlen(ele2)]='\0';
                    ele1[strlen(ele1)]='\0';
                    strcpy(arr,")");
                    strncat(arr,ele1,strlen(ele1));
                    strncat(arr,&exp[i],1);
                    strncat(arr,ele2,strlen(ele2));
                    char ch ='(';
                    strncat(arr,&ch,1);
                    push2(arr);
                    ele1[0]='\0';
                    ele2[0]='\0';
                    arr[0]='\0';


            
          }

      }
     
     printf("\nPrefix to Infix : %s\n",strrev(stack2[top2]));
     // printf("%d",strlen(stack2[top2]));
     
}

void posttopre(char exp[]){
     int len=strlen(exp);
     int i;
      char arr1[30]={0};
     char ele1[20]={0};
     char ele2[20]={0};
     //  ABC*+D*
     // ABC-D+/EA-*C*

     for(i=0;i<len;i++){
         if(isalpha(exp[i])){
               push2(strncat(arr1,&exp[i],1));
               arr1[0]='\0';
         }
         else if(exp[i]=='-'||exp[i]=='+'||exp[i]=='*'||exp[i]=='/'){
               
                    strcpy(ele2,stack2[top2--]);
                    strcpy(ele1,stack2[top2--]);
                    ele2[strlen(ele2)]='\0';
                    ele1[strlen(ele1)]='\0';
                    strncat(arr1,&exp[i],1);
                    strncat(arr1,ele1,strlen(ele1));
                    strncat(arr1,ele2,strlen(ele2));

                    push2(arr1);
                    ele1[0]='\0';
                    ele2[0]='\0';
                    arr1[0]='\0';
                   


            
          }

      }
     
     printf("\nPostfix to Prefix : %s\n",stack2[top2]);
        

}

void pretopost(char exp[]){
       int len=strlen(exp);
     int i;
     char arr[30]={0};
     char ele1[20]={0};
     char ele2[20]={0};
     //  ABC*+D*
     // ABC-D+/EA-*C*
     strcpy(exp,strrev(exp));
     

     for(i=0;i<len;i++){
         if(isalpha(exp[i])){
               push2(strncat(arr,&exp[i],1));
               arr[0]='\0';
         }
         else if(exp[i]=='-'||exp[i]=='+'||exp[i]=='*'||exp[i]=='/'){
               
                    strcpy(ele1,stack2[top2--]);
                    strcpy(ele2,stack2[top2--]);
                    ele2[strlen(ele2)]='\0';
                    ele1[strlen(ele1)]='\0';
                    strncat(arr,ele1,strlen(ele1));
                    strncat(arr,ele2,strlen(ele2));
                    strncat(arr,&exp[i],1);
                   
                    push2(arr);
                    ele1[0]='\0';
                    ele2[0]='\0';
                    arr[0]='\0';


            
          }

      }
     
     printf("\nPrefix to Postfix : %s\n",stack2[top2]);
        
    

}


void posteval(char exp[]){
     int len=strlen(exp);
     int i;
     
     //  ABC*+D*
     // ABC-D+/EA-*C*

     for(i=0;i<len;i++){
         if(isdigit(exp[i])){
               push3(exp[i]-'0');
              
         }
         else if(exp[i]=='-'||exp[i]=='+'||exp[i]=='*'||exp[i]=='/'){
               
                    int ele2=pop3();
                    int ele1=pop3();
                    int res;
                    if(exp[i]=='+'){
                          res=ele1+ele2;

                     }
                    if(exp[i]=='-'){
                          res=ele1-ele2;

                     }
                    if(exp[i]=='*'){
                          res=ele1*ele2;

                     }
                    if(exp[i]=='/'){
                          res=ele1/ele2;

                     } 
                    push3(res);
                   


            
          }

      }
     
     printf("\nEvaluated  postfix expression : %d\n",pop3());
     // printf("%d",strlen(stack2[top2]));
     
}

void prefixeval(char exp[]){
     int len=strlen(exp);
     int i;
     strcpy(exp,strrev(exp));
     //  ABC*+D*
     // ABC-D+/EA-*C*

     for(i=0;i<len;i++){
         if(isdigit(exp[i])){
               push3(exp[i]-'0');  //'0' = 48 which itts ascii val and subtraction from ascii of given expressions gives us int
              
         }
         else if(exp[i]=='-'||exp[i]=='+'||exp[i]=='*'||exp[i]=='/'){
               
                    int ele2=pop3();
                    int ele1=pop3();
                    int res;
                    if(exp[i]=='+'){
                          res=ele1+ele2;

                     }
                    if(exp[i]=='-'){
                          res=ele2-ele1;

                     }
                    if(exp[i]=='*'){
                          res=ele1*ele2;

                     }
                    if(exp[i]=='/'){
                          res=ele2/ele1;

                     } 
                    push3(res);
                   


            
          }

      }
     
     printf("\nEvaluated prefix expression : %d\n",pop3());
     // printf("%d",strlen(stack2[top2]));
     
}





int main(){
     // char exp1[]="[A+(B*C)]*D";
     // char exp2[]="((A/(B-C+D))*(E-A))*C";
     // char exp[]="(A-B/C)*(A/K-L)";
     // char exp3[]="[(A+B)*(C+D)]";
     // char post[]=" ABC*+D*";
     // char arr[]="ABC-D+/EA-*C*";
     // char arr2[]="(((B*C)+A)*D)";
     // char arr5[]="AB*CD+-E+";
     // char arr4[]="**/A+-BCD-EAC";
     // char arr7[]="-+8/632";
     // char arr6[]="231*+9-";
     int ch;
     char arr[20];
      while(1){
          printf("\nEnter Conversion\n");
          printf("\n1.Infix to Postfix \n");
          printf("\n2.Infix to Prefix  \n");
          printf("\n3.Prefix to Postfix  \n");
          printf("\n4.Postfix to Prefix \n");
          printf("\n5.Postfix to Infix  \n");
          printf("\n6.Prefix to Infix \n");
          printf("\n7.Postfix evaluation \n");
          printf("\n8.Prefix evaluation \n");
          printf("\n9.Exit \n");
          
          printf("\nEnter your choice : ");
          scanf("%d",&ch);
          
         
          switch(ch){
               case 1:
                    printf("\nEnter infix expression : ");
                    scanf("%s",&arr);
                    intopostfix(arr);
                    break;    
               case 2:
                    printf("\nEnter infix expression : ");
                    scanf("%s",&arr);
                    intoprefix(arr);
                    break;
               case 3:
                    printf("\nEnter prefix expression : ");
                    scanf("%s",&arr);
                    pretopost(arr);
                    break;
               case 4:
                    printf("\nEnter postfix expression :");
                    scanf("%s",&arr);
                    posttopre(arr);
                    break;
               case 5:
                    printf("\nEnter postfix expression : ");
                    posttoinfix(arr);                  
                    break;
               case 6:
                    printf("\nEnter prefix expression : ");
                    scanf("%s",&arr);
                    prettoinfix(arr);
                    break;
               case 7:
                    printf("\nEnter postfix to evaluate : ");
                    scanf("%s",&arr);
                    posteval(arr);
                    break;
               case 8:
                    printf("\nEnter prefix to evaluate : ");
                    scanf("%s",&arr);
                    prefixeval(arr);
               case 9:
                    exit(1);          
               default : 
                    printf("Invalid input");     
          }           

                   


           

     }

     
    
     
     
     // posteval(arr6);
     // prefixeval(arr7);
     // intopostfix(arr6);
     // intoprefix(exp2);
     // prettoinfix(arr4);
     // posttoinfix(arr6);
     // pretopost(arr4);
     // posttopre("AB+");
     
     // char m[]="106";
     // int num=0;
     // for(int i=0;i<3;i++){
     //        num = num*10+(m[i]-'0');
     // }
     // printf("%d",num);
     


     
       
  

}
 

