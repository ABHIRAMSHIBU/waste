
void PUSH(int *s,int *top,int key){
	
	*top=*top+1;
        s[*top]=key;

}
	
void display_stack(int *s,int top){
	for(int i=top;i>=0;i--){
		printf("%d\n",s[i]);
	}
}

int POP(int *s,int *top){
	int val=-1;
	if(*top==-1){
		printf("Stack Overflow");
	}
	else{
                val=s[*top];
		*top=*top-1;
	}
	
	return val;	

}
	

        
