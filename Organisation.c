#include<stdio.h>
#define n 20
struct Emp
{
	int empno,sal;
	char empnm[50],depnm[50];
}e[n];
void disp(int i)
{
	printf("%d\t%s\t%s\t%d\n",e[i].empno,e[i].empnm,e[i].depnm,e[i].sal);
};
int main()
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d %s %s %d",&e[i].empno,&e[i].empnm,&e[i].depnm,&e[i].sal);
	for(i=0;i<n;i++)
		disp(i);
}
