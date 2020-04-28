#include <stdio.h> 
#include <stdlib.h>
int main() 
{ 
	FILE *fptr1,*fptr2; 
	char f1[100],f2[100],c; 
	printf("Enter the filename to open for reading \n"); 
	scanf("%s",f1); 
	fptr1=fopen(f1,"r"); 
	printf("Enter the filename to open for writing \n"); 
	scanf("%s",f2); 
	fptr2=fopen(f2,"w"); 
	c=fgetc(fptr1); 
	while (c!=EOF) 
	{ 
		fputc(c,fptr2); 
		c=fgetc(fptr1); 
	} 
`	fclose(fptr1); 
	fclose(fptr2); 
}

