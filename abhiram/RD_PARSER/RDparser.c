#include<stdio.h>
#include<string.h>


// Prototypes
void FunctonT();
void FunctionE();
void FunctionF();
void FunctionSuperE();
void FunctionSuperT();
int charL=9;
int lastI=8;
char charMap[100][100]={{'e','\0'},{'+','\0'},{'*','\0'},{'(','\0'},{')','\0'},{'i','d','\0'},{'E','\0'},{'T','\0'},{'F','\0'}};;//id:string
void addNewProduction(int productions[100],int pro_l,int new_prod[100][100],int *new_p_l){
    if(productions[0]==productions[2]){

        char newv[3];
        strcpy(newv,charMap[productions[0]]);
        int pp=strlen(newv);
        newv[pp]='\'';
        newv[pp+1]='\0';
        strcpy(charMap[charL++],newv);
        lastI=charL-1;

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
        new_prod[*new_p_l][npj++]=lastI;
        new_prod[*new_p_l][npj++]=-2;
        (*new_p_l)++;


        new_prod[*new_p_l][0]=lastI;
        new_prod[*new_p_l][1]=-1;
        int newp_j=2;
        j=3;
        while(productions[j]!=-1&&productions[j]!=-2){
            new_prod[*new_p_l][newp_j++]=productions[j];
            j++;
        }
        new_prod[*new_p_l][newp_j++]=lastI;
        new_prod[*new_p_l][newp_j++]=-1;
        new_prod[*new_p_l][newp_j++]=0;
        new_prod[*new_p_l][newp_j++]=-2;


        (*new_p_l)++;
    }
}
int geti(char charmap[100][100],char e[100]){

		for(int i=0;i<charL;i++){
			//printf("\n%s : %s",charMap[i],e);
			if(strcmp(charmap[i],e)==0){
				return i;
		}

	}
	return -1;
}
int prod[100][100]={{6,-1,6,1,7,-1,7,-2},{7,-1,7,2,8,-1,8,-2},{8,-1,3,6,4,-1,5,-2}};//{1-1234-134,...}
char expressionArray[100];
int expressionArrayNumbers[100];
int en=0;
int cur=0;
int errorFlag=0;
int got=-1;

int newProd[100][100];
int newPL=0;

int proL=3;
void displayAll(int prod[100][100],int l){
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
                    printf("%s",charMap[prod[i][j]]);
            }
            j++;
        }
        printf("\n");
    }
}


void removeLeftRecurssionFromGrammar(){
	for(int i=0;i<proL;i++){
		int j=2;
		int pro_base=prod[i][0];

			if(prod[i][2]==pro_base){
				addNewProduction(prod[i],proL,newProd,&newPL);
				continue;
			}
			 while(prod[i][j]!=-1&&prod[i][j]!=-2){
				 j++;
			 }
			 if(prod[i][j]!=-2){
				 if(prod[i][j+1]==pro_base){
					 addNewProduction(prod[i],proL,newProd,&newPL);
					 continue;
				 }
			 }
			 int jj=0;

			 while(prod[i][jj]!=-2){

				 newProd[newPL][jj]=prod[i][jj];jj++;
				 //printf("herer: %d",new_prod[new_p_l][j]);
			 }
			 newProd[newPL][jj]=-2;
			 newPL++;

	}
	displayAll(newProd,newPL);
}
void FunctionE(){
    FunctonT();
    FunctionSuperE();

}
void FunctonT(){
    FunctionF();
    FunctionSuperT();
}
void FunctionSuperE(){
    if(strcmp(charMap[expressionArrayNumbers[cur]],"+")==0){
        cur++;
        FunctonT();
        FunctionSuperE();
        return;
    }
    else return;
        


}
void FunctionSuperT(){
    if(strcmp(charMap[expressionArrayNumbers[cur]],"*")==0){
        cur++;
        FunctionF();
        FunctionSuperT();
        return;
    }
    return ;
}
void FunctionF(){
    if(strcmp(charMap[expressionArrayNumbers[cur]],"(")==0){
        cur++;
        FunctionE();
        if(strcmp(charMap[expressionArrayNumbers[cur]],")")==0){
            cur++;
            return;
        }
        else{
            //printf("error 1");
            got=cur;
            cur++;
            
            errorFlag=1;
        }
    }
    else if(strcmp(charMap[expressionArrayNumbers[cur]],"id")==0){
        cur++;
        return;
    }
    else
    {
        //printf("error 2");
        got=cur;
        cur++;
        errorFlag=2;
    }
    
}
int checkEquals(char c){
    int l=0;
    if(l==c)
        l=getchar();
    else{
        printf("\n Error");
        return -1;
    }
    return 1;
}
void construct(char expr[100]){
 en=0;
    for(int i=0;i<strlen(expr);i++){
        char se[100];
        se[0]=expr[i];
        se[1]='\0';
        int r=geti(charMap,se);
        if(r!=-1){
            expressionArrayNumbers[en++]=r;

        }
        else{
            i++;
            se[1]=expr[i];
            se[2]='\0';
            r=geti(charMap,se);
        if(r!=-1){
            expressionArrayNumbers[en++]=r;

        }
        else{
            printf("error");
            i--;
        }
        }
    }
    
}
int main(){
    printf("\nHardwired Grammar");
    printf("\nE -> E + T \nE -> T \nT -> T * F \nT -> F \nF -> ( E ) \nF -> id \n\n\n");
    removeLeftRecurssionFromGrammar();
    printf("\n\nAbove grammar after eliminating left recursion");
    printf("\nExpression ?[(id+id)]:");
    scanf("%s",expressionArray);
    construct(expressionArray);
   
    FunctionE();
    if(cur<en){
        printf("\nParsing Failure!");
    }
    else{
        if(errorFlag==0){
            printf("\nThat expression is OK!");
        }
        else if(errorFlag==1){

            
            if(strcmp(charMap[expressionArrayNumbers[got]],"e")==0)
                printf("\nParsing ERROR Need )");
            else
            {
                printf("\nParsing ERROR Need ) but %c in string",charMap[expressionArrayNumbers[got]]);
            }
            

        }
        else if(errorFlag==2){
            printf("\nParsing ERROR Needed terminal id but %c in string",charMap[expressionArrayNumbers[got]]);
        }
    }
   return errorFlag;
}

