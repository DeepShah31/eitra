#include<stdio.h>
int main()
{
	int a[100],x,low,mid,high,n;
	printf("how many elements you want");
	scanf("%d",&n);
	printf("enter elements in array");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
		
	}
	printf("which element you want to find");
	scanf("%d",&x);
	low=0;
	high=n-1;
	mid=(low+high)/2;

	while(low<=high)
	{
			mid=low+high;
		if(x>a[mid]||x<a[mid])
		{
			(x<a[mid])?(high=mid-1):(low=mid+1);
		}
			
		else
		return mid;
		
	}
}