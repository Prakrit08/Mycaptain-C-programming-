#include <stdio.h>
#include <string.h> 
int main()
{
    FILE *fp1;
    int cnt=0,i=0;
    char fn[100];
    printf("Enter filename with .txt extension: ");
    scanf("%s",fn);
    fp1 = fopen(fn,"r");
    if(fp1==NULL )
        printf("File can not be opened !! \n");
    fseek(fp1,0,SEEK_END);
    cnt = ftell(fp1);
    while( i < cnt )
    {
        i++;
        fseek(fp1,-i,SEEK_END);
        printf("%c",fgetc(fp1));
    }
    printf("\n");
    fclose(fp1);
}
