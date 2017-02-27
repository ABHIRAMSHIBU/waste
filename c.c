#include<stdio.h>
void main()
{
    char a;
    printf("Enter a charector:");
    scanf("%c",&a);
    if( a=='a' || a=='e' || a=='i' || a=='o' || a=='u' )
    {
        printf("Entered charector %c is a vovel!",a);
    }
    else
    {
        if(a=='1' || a=='2' || a=='3' || a=='4'|| a=='5' || a=='6' || a=='7' || a=='8' || a=='9' || a=='0')
        {
            printf("Numbers are taken as consonant!\n");
        }
        printf("Enterd charector %c is a consonant!",a);
    }
}
