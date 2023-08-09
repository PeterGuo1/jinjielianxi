#include<stdio.h>
 int main()
 {
	 int i,j,n,min,sz;
	 float s;
	 int sum =0;
	 int arr[50]={0};
	 int sx[50]={0};
	 scanf("%d\n",&n);
	 for(i=1;i<=n;i++)
	 {
		 scanf("%d ",&arr[i]);
	 }
	 for(i=1;i<=10;i++)
	 {
		 min = arr[i];sz=i;
		 for(j=1;j<=10;j++)
		 {
			 
			 if(min>arr[j])
			 {
				 min=arr[j];
				 sz=j;

			 }
		 }
		 sum=sum+(10-i)*arr[sz];
		 sx[i]=sz;
		 arr[sz]=100000;
	 }
	 for(i=1;i<=10;i++)
	 {
		 printf("%d ",sx[i]);
	 }
	 printf("\n");
	 s=sum;
	 printf("%.2f",s/10);
	 return 0;
 }
