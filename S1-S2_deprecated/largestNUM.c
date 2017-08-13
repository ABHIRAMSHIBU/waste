#include<stdio.h>
#include<conio.h>
void main()
{
    int a,buff;
    int b;
    printf("Enter first number :");
    scanf("%d",&a);
    b=1;
    while(b==1)
    {
        printf("Enter another number:");
        scanf("%d",&buff);
        if(buff>a)
            a=buff;
        printf("\nDo you want to enter more , Enter 1 or 0 :");
        scanf("%d",&b);
    }
    printf("\nThe Largest number is : %d",a);
    getch();
}
