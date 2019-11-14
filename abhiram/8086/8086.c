#include<stdio.h>
#include<string.h>
#include "color.h"
char expressions[100][100];
int n=1;


void gen_asm(){
    for(int i=0;i<n;i++){
        if(strlen(expressions[i]) == 3){
            printf("%sMOV CX,[address_%c]%s\n",RED,expressions[i][2],RESET);
            printf("%sMOV [address_%c],CX%s\n",GRN,expressions[i][0],RESET);
            break;
        }
        
        printf("%sMOV CX,[address_%c]%s\n",RED,expressions[i][2],RESET);

        if( expressions[i][3] == '+'){
                printf("%sADD CX,[address_%c]%s\n",RED,expressions[i][4],RESET);
                }
        else if( expressions[i][3] == '-'){
                printf("%sSUB CX,[address_%c]%s\n",RED,expressions[i][4],RESET);
        }
        else if( expressions[i][3] == '*' ){
                printf("%sMOV BX,[address_%c]%s\n",GRN,expressions[i][4],RESET);
                printf("%sMUL BX%s\n",RED,RESET);
        }

        else if( expressions[i][3] == '/' ){
                printf("%sMOV BX,[address_%c]%s\n",RED,expressions[i][4],RESET);
                printf("%sDIV BX%s\n",GRN,RESET);
        }

        printf("%sMOV [address_%c],CX%s\n",GRN,expressions[i][0],RESET);

    }
}
void main(){
    printf("Enter n:");
    int num;
    scanf("%d",&num);

    printf("Enter exp,\n");
    for(int i=0;i<num;i++){
		printf("%s",YEL);
        scanf("%s",expressions[0]);
        gen_asm();
    }
    printf("%s",RESET);
    printf("%sDone..%s\n",BLU,RESET);

}
