#include<stdio.h>
#include<string.h>
int productions[100][100]={{6,-1,6,1,7,-1,7,-2},{7,-1,7,2,8,-1,8,-2},{8,-1,3,6,4,-1,5,-2}};//{1-1234-134,...}
char charmap[100][100]={{'e','\0'},{'+','\0'},{'*','\0'},{'(','\0'},{')','\0'},{'i','d','\0'},{'E','\0'},{'T','\0'},{'F','\0'}};;//id:string
char expr[100];
int expn[100];
int en=0;
int cur=0;
int error_f=0;
int got=-1;

int new_prod[100][100];
int new_p_l=0;
int char_l=9;
int last_i=8;
int pro_l=3;

void T();void E();void F();void E_(); void T_();
void addnew(int productions[100],int pro_l,int new_prod[100][100],int *new_p_l){
    if(productions[0]==productions[2]){
        
        char newv[3];
        strcpy(newv,charmap[productions[0]]);
        int pp=strlen(newv);
        newv[pp]='\'';
        newv[pp+1]='\0';
        strcpy(charmap[char_l++],newv);
        last_i=char_l-1;

        int j=3;
        while(productions[j]!=-1){
            j++;
        }
        j++;
        new_prod[*new_p_l][0]=productions[0];
        new_prod[*new_p_l][1]=-1;
        int npj=2;
        while(productions[j]!=-1&&productions[j]!=-2){
            new_prod[*new_p_l][npj++]=productions[j];
            j++;
        }
        new_prod[*new_p_l][npj++]=last_i;
        new_prod[*new_p_l][npj++]=-2;
        (*new_p_l)++;

        
        new_prod[*new_p_l][0]=last_i;
        new_prod[*new_p_l][1]=-1;
        int newp_j=2;
        j=3;
        while(productions[j]!=-1&&productions[j]!=-2){
            new_prod[*new_p_l][newp_j++]=productions[j];
            j++;
        }
        new_prod[*new_p_l][newp_j++]=last_i;
        new_prod[*new_p_l][newp_j++]=-1;
        new_prod[*new_p_l][newp_j++]=0;
        new_prod[*new_p_l][newp_j++]=-2;


        (*new_p_l)++;
    }
}
void display(int prod[100][100],int l){
    for(int i=0;i<l;i++){
        int j=0;
        while(prod[i][j]!=-2){
            if(prod[i][j]==-1){
                if(j==1)
                    printf(" -> " );
                else
                    printf(" | ");
            }
                
            else{
                
                
                    printf("%s",charmap[prod[i][j]]);
            }
            j++;
        }
        printf("\n");
    }
}


void remove_left_recursion(){
for(int i=0;i<pro_l;i++){
    int j=2;
    int pro_base=productions[i][0];
   
        if(productions[i][2]==pro_base){
            addnew(productions[i],pro_l,new_prod,&new_p_l);
            continue;
        }
         while(productions[i][j]!=-1&&productions[i][j]!=-2){
             j++;
         }
         if(productions[i][j]!=-2){
             if(productions[i][j+1]==pro_base){
                 addnew(productions[i],pro_l,new_prod,&new_p_l);
                 continue;
             }
         }
         int jj=0;
         
         while(productions[i][jj]!=-2){
             
             new_prod[new_p_l][jj]=productions[i][jj];jj++;
             //printf("herer: %d",new_prod[new_p_l][j]);
         }
         new_prod[new_p_l][jj]=-2;
         new_p_l++;
    
}
display(new_prod,new_p_l);
   
}
void E(){
    T();
    E_();

}
void T(){
    F();
    T_();
}
void E_(){
    if(strcmp(charmap[expn[cur]],"+")==0){
        cur++;
        T();
        E_();
        return;
    }
    else return;
        


}
void T_(){
    if(strcmp(charmap[expn[cur]],"*")==0){
        cur++;
        F();
        T_();
        return;
    }
    return ;
}
void F(){
    if(strcmp(charmap[expn[cur]],"(")==0){
        cur++;
        E();
        if(strcmp(charmap[expn[cur]],")")==0){
            cur++;
            return;
        }
        else{
            //printf("error 1");
            got=cur;
            cur++;
            
            error_f=1;
        }
    }
    else if(strcmp(charmap[expn[cur]],"id")==0){
        cur++;
        return;
    }
    else
    {
        //printf("error 2");
        got=cur;
        cur++;
        error_f=2;
    }
    
}
int equals(char c){
    int l;
    if(l==c)
        l=getchar();
    else{
        printf("\n Error");
        return -1;
    }
    return 1;
}
int findi(char charmap[100][100],char e[100]){
    
    for(int i=0;i<char_l;i++){
        //printf("\n%s : %s",charmap[i],e);
        if(strcmp(charmap[i],e)==0){
            return i;
    }
    
}
return -1;
}
void construct_expression(char expr[100]){
 en=0;
    for(int i=0;i<strlen(expr);i++){
        char se[100];
        se[0]=expr[i];
        se[1]='\0';
        int r=findi(charmap,se);
        if(r!=-1){
            expn[en++]=r;

        }
        else{
            i++;
            se[1]=expr[i];
            se[2]='\0';
            r=findi(charmap,se);
        if(r!=-1){
            expn[en++]=r;

        }
        else{
            printf("error");
            i--;
        }
        }
    }
    
}
void main(){
    printf("\nGrammar Evaluated");
    printf("\n-------------------------------------------\n");
    printf("\nE -> E + T | T \nT -> T * F | F \nF -> ( E ) | id ");
    printf("\n\nGrammar after removing left recursion");
    printf("\n-------------------------------------------\n");
    remove_left_recursion();
    
    printf("\nEnter expression to evaluate: ");
    scanf("%s",expr);
    construct_expression(expr);
   
    E();
    printf("\nParser results");
    printf("\n-------------------------------------------\n");
    if(cur<en){
        printf("\n Unexpected EOF");
    }
    else{
        if(error_f==0){
            printf("\n Expression Evaluation success....");

        }
        else if(error_f==1){

            
            if(strcmp(charmap[expn[got]],"e")==0)
                printf("\n Expected ')' but got EOF");
            else
            {
                printf("\n Expected ')' but got %s",charmap[expn[got]]);
            }
            

        }
        else if(error_f==2){
            printf("\n Expected 'id' but got %s",charmap[expn[got]]);
        }
    }
    printf("\n-------------------------------------------\n");
   
}