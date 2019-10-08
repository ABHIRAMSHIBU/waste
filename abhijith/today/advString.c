#include<string.h>
#define true 1
#define false 0
#define True 1
#define False 0
/* String lib for C
 *----   Implemented ---
 *----------------------
 */
 void strrev(char * str){
     char temp;
     int length=strlen(str);
     for(int i=0;i<length/2;i++){
         temp=str[i];
         int index = length-i-1;
         str[i]=str[index];
         str[index]=temp;
     }
 }
 void substr(char * str,char * buff,int start,int stop){
     for(int i=start;i<stop;i++){
         buff[i-start]=str[i];
     }
 }
