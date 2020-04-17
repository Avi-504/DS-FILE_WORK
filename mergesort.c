#include <stdio.h>
#include <stdlib.h>
void merge(int arr[],int s,int m,int e)
 {	
	int n1=m-s+2;
	int n2=e-m+1;
	int l[n1];
	int r[n2];
	for(int i=0;i<=n1-2;i++)
	{
		l[i]=arr[s+i];
	}
	l[n1-1]=1000000;
	for(int q=0;q<=n2-2;q++)
	{
		r[q]=arr[m+1+q];
	}
	r[n2-1]=1000000;
	int w=0,y=0;
	for(int k=s;k<=e;k++)
	{
		if(l[w]<=r[y])
		{
			arr[k]=l[w];
			w++;
		}
		else
		{
			arr[k]=r[y];
			y++;
		}
	}
}	
void mergesort(int arr[],int s, int e)
{
	if(s<e)
	{
		int m=(s+e-1)/2;
		mergesort(arr,s,m);
		mergesort(arr,m+1,e);
		merge(arr,s,m,e);
	}
}
int main()
{
	int arr[]={10,5,1,4};
	
		int s=0,e=3;
		mergesort(arr,s,e);
		//printf("from main\n");
		for(int i=0;i<=3;i++)
		{
			printf("%d ",arr[i]);
		}
return 0;
}