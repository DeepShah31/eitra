#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
FILE *fp1,*fp2;
fp1=fopen("read_write.txt","r");
printf("%p \n",fp1);
fclose(fp1);
fp2=fopen("read_write.txt","r");
printf("%p \n",fp2);
fclose(fp2);
return 0;
}