#include<stdio.h>
#include<malloc.h>
/* Copyright (c) 2017 Author Abhiram Shibu */
/* Create a programme that displays the longest Increasing or decreasing sequence Numbers stored in a 2D array */
int array[25][100];
int r=0,c=0;
void input_array(){
	printf("Enter rows, colums:");
	scanf("%d %d",&r,&c);
	printf("Values is:r=%d c=%d\n",r,c);  //debug	
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			printf("Enter row:%d, column:%d value:",i,j);;
			scanf("%d",&array[i][j]);
		}
}

void print_array(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			printf("%d ",array[i][j]);
		printf("\n");
	}
}
int inc[100];
int array_count_inc;  //max count of values in inc
void find_incriment(){
	int temp=array[0][0];
	int count=0;
	int reset_flag=0;
	int array_count=0;
	for(int i=0;i<r;i++){
		for(int j=1;j<c;j++){
			if(reset_flag==1){
				j=0;
				reset_flag=0;
			}
			if(temp<array[i][j]){
				printf("Found\n"); //debug
				count++;
			}
			else{
				inc[array_count]=count;
				count=0;
				array_count++;
			}
			temp=array[i][j];
			inc[array_count]=count;
			printf("RAN\n");
		}
		reset_flag=1;
	}

	array_count_inc=array_count;
}
int dec[100];
int array_count_dec; //max count of values in dec
void find_decriment(){
	int temp=array[0][0];
	int count=0;
	int reset_flag=0;
	int array_count=0;
	for(int i=0;i<r;i++){
		for(int j=1;j<c;j++){
			if(reset_flag==1){
				j=0;
				reset_flag=0;
			}
			if(temp>array[i][j]){
				printf("Found\n"); //debug
				count++;
			}
			else{
				dec[array_count]=count;
				count=0;
				array_count++;
				}
			temp=array[i][j];
			dec[array_count]=count;
			printf("RAN\n");
		}
		reset_flag=1;
	}

	array_count_dec=array_count;
}
int biggest_dec=0;
int biggest=0;
void biggestFunction(){
	for(int i=0;i<=array_count_inc;i++){
		printf("Processing %d , biggest %d\n",inc[i],biggest); //debug
		if(biggest<inc[i]){
			printf("RAN?\n"); //debug
			biggest=inc[i];
		}
	}
	for(int i=0;i<=array_count_dec;i++)
		if(biggest<dec[i]){
			printf("True overriding biggest:%d,dec[i]:%d \n",biggest,dec[i]); //debug
			biggest=dec[i];
			biggest_dec=1;
		}
}

void print_incriment_match(int match){
	int temp=array[0][0];
	int count=0;
	int reset_flag=0;
	int array_count=0;
	int array_temp[100];
	array_temp[0]=temp;
	int array_temp_count=1;
	for(int i=0;i<r;i++){
		for(int j=1;j<c;j++){
			if(reset_flag==1){
				j=0;
				reset_flag=0;
			}
			if(temp<array[i][j]){
				printf("Found\n"); //debug
				array_temp[array_temp_count]=array[i][j];
				count++;
				array_temp_count++;
			}
			else{
				inc[array_count]=count;
				count=0;
				array_temp_count=0;
				array_count++;
			}
			if(count==match)
			{
				printf("Array is :");
				for(int k=0;k<count+1;k++){
					if(!(k==count&&array_temp[k]==0))
					printf("%d ",array_temp[k]);
				}
			}
			temp=array[i][j];
			inc[array_count]=count;
			printf("RAN\n");
		}
		reset_flag=1;
	}

	array_count_inc=array_count;
}
void print_decriment_match(int match){
	int temp=array[0][0];
	int count=0;
	int reset_flag=0;
	int array_count=0;
	int array_temp[100];
	array_temp[0]=temp;
	int array_temp_count=1;
	for(int i=0;i<r;i++){
		for(int j=1;j<c;j++){
			if(reset_flag==1){
				j=0;
				reset_flag=0;
			}
			if(temp>array[i][j]){
				printf("Found\n"); //debug
				array_temp[array_temp_count]=array[i][j];
				count++;
				array_temp_count++;
			}
			else{
				dec[array_count]=count;
				count=0;
				array_temp_count=0;
				array_count++;
			}
			if(count==match)
			{
				printf("Array is :");
				for(int k=0;k<count+1;k++){
					printf("%d ",array_temp[k]);
				}
			}	
			temp=array[i][j];
			dec[array_count]=count;
			printf("RAN\n");
		}
		reset_flag=1;
	}

	array_count_dec=array_count;
}
int main(){
	input_array();
	printf("----Values in array----\n");
	print_array();
	find_incriment();
	printf("Value of array_count is:%d and value is:%d \n",array_count_inc,inc[array_count_inc]); //debug
	for(int i=0;i<array_count_inc+1;i++){
		printf("%d ",inc[i]);
	}
	printf("\n");
	find_decriment();
	printf("Value of array_count is:%d and value is:%d\n",array_count_dec,dec[array_count_inc]); //debug
	for(int i=0;i<array_count_dec+1;i++){
		printf("%d ",dec[i]);
	}
	printf("\n");
	biggestFunction();
	printf("Biggest is :%d, dec flag:%d\n",biggest,biggest_dec);
	if(biggest_dec==0)
		print_incriment_match(biggest);
	else
		print_decriment_match(biggest);
}
