#include <stdio.h>
 main()
{
    int i, j, rows;

    printf("Enter number of rows: ");
    scanf("%d",&rows);

    for(i=1; i<=rows; ++i)  //for rows
    {
        for(j=1; j<=i; ++j) 
        {
            printf("*");

        }
        printf("\n");
    }
}

