#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int n,a[n],temp,temp1;
   	time_t t;
	printf("enter the size of an array:");
	scanf("%d",&n);
   srand((unsigned) time(&t));
 for(int i = 0 ; i < n ; i++ ) 
   {
     a[i]=rand()%50;
     printf("%d\n",a[i]);
   }

	printf("this is logic for selection sort\n");
	for (int i = 0; i <n-1; ++i)
	{
		int min=i;
		for (int j = i+1; j <n; ++j)//no of elements scanned
		{
			if (a[j]<a[min])
				min=j;
		}
				int temp=a[i];
				a[i]=a[min];
				a[min]=temp;

	}
	printf("AFTER SORTING:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n",a[i]);
	}
	
	return 0;
	/*
time complexity of this algorithm is (n-1)*(n-1)*c=o(n^2)
*/
}
