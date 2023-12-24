#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int c;
char a[]={'0','1','2','3','4','5','6','7','8'},X,O,put;
 void display(){
    printf("\n**************\n");
    printf("    |     |   \n");
    printf("  %c |  %c  | %c \n",a[0],a[1],a[2]);
    printf("---------------\n");
    printf("    |     |   \n");
    printf("  %c |  %c  | %c \n",a[3],a[4],a[5]);
    printf("---------------\n");
    printf("    |     |   \n");
    printf("  %c |  %c  | %c \n",a[6],a[7],a[8]);
    printf("\n***************\n");  
}
int check(int n){
    if(a[n]=='O' || a[n]=='X'){
        return 1;
    }else {
        return 0;
    }
}
int checkresult(){
    if(a[0]==a[1] && a[1]==a[2]){
        return 1;
    }else if(a[3]==a[4] && a[4]==a[5]){
        return 1;
    }else if(a[6]==a[7] && a[7]==a[8]){
        return 1;
    }else if(a[0]==a[3] && a[3]==a[6]){
        return 1;
    }else if(a[1]==a[4] && a[4]==a[7]){
        return 1;
    }else if(a[2]==a[5] && a[5]==a[8]){
        return 1;
    }else if(a[0]==a[4] && a[4]==a[8]){
        return 1;
    }else if(a[2]==a[4] && a[4]==a[6]){
        return 1;
    }else{
        return 0;
    }
}
int draw(){
    c=0;
 for(int i=0;i<=8;i++){
    if(a[i]=='O' || a[i]=='X'){
      c++;
    }
 }if(c>=9){
    return 1;
 }return 0;
}
void main(){
    display();
    int n,pl=1;
    label:
pl=(pl%2==0)?2:1;    
put=(pl==1)?'O':'X';
printf("enter your choice number for %c : \n",put);
    printf("your choice is = ");
    scanf("%d",&n);
    if(n<0 || n>8){
        printf("invalid input\n");
        goto label;
     }else{
         if(check(n)){
        printf(" number is already choosen,chose another location\n");
        goto label;
         }
      else{
        a[n]=put;
        pl++;
        display();
        if(checkresult()){
            printf("\n\nplayer %c won the game!!",put);
            goto end;
        }if(draw()){
            printf("\n\ngame draw");
            goto end;
        }
        goto label;
     }
    }end:
}
