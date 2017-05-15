#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"MSM_Header.h"

struct Medicine data;
struct customer cust;

void add_customer(struct customer cust)  {

       FILE *fp;
       fp=fopen("customer.dat","a");
       fwrite(&cust, sizeof(cust),1,fp);
       fclose(fp);
}


int search_medicine(char medi_name[], FILE *fp)
{
  int flag=0; //0 for Not found
  rewind(fp);
   while (fread (&data, sizeof(data),1,fp))   {
      if(strcmp(data.medi_name,medi_name)==0)   {
       flag=1;
       break;
      }

  }

if(flag == 0)
     return 0;
else
        return 1;
}


int check_quantity(char medi_name[], int medi_quantity, FILE *fp)
{
  int flag=-1;
  rewind(fp);

  while (fread(&data, sizeof(data),1,fp))    {
    if(strcmp(data.medi_name,medi_name)==0)   {

      if(data.medi_quantity-medi_quantity<0)   {
       flag=1;
       return 0;
     }
     else
      flag=0;
   }
 }

  if(!flag)
    return 1;
}


void update_inc(char medi_name[], int medi_quantity, FILE *fp)
{
  int a=search_medicine(medi_name,fp);

    if(a==1)
     {
       data.medi_quantity=data.medi_quantity+medi_quantity;
       fseek(fp,-(sizeof(data)),SEEK_CUR);
       fwrite(&data,(sizeof( data)),1,fp);
       printf("There is  %d %s in your shop\n",data.medi_quantity,data.medi_name);
    }
}


void update_dec(char medi_name[], int medi_quantity, FILE *fp)
{
   int a=search_medicine(medi_name,fp);

    if(a==1)
     {
       data.medi_quantity=data.medi_quantity-medi_quantity;
       fseek(fp,-(sizeof(data)),SEEK_CUR);
       fwrite(&data,(sizeof( data)),1,fp);
       printf("There is  %d %s in your shop\n",data.medi_quantity,data.medi_name);
    }
}


void add_medicine()
{
  char medi_name[20],c[2];
  int medi_quantity;

  FILE *fp;
  fp=fopen("medicine.dat","a");
  printf("Medicine Name: ");
  scanf("%s",medi_name);
  int a=search_medicine(medi_name,fp);

  if(!a)   {
   strcpy(data.medi_name,medi_name);
   printf("Medicine Quantity: ");
   scanf ("%d", &data.medi_quantity);
   printf("Price: ");
   scanf ("%f", &data.medi_price);
   printf("Supplier Name: ");
   scanf ("%s",data.supp_name);
   printf("Supplier Contact Number: ");
   scanf ("%lu", &data.supp_cont);
   printf("Medicine id: ");
   scanf ("%s", data.id);
    fclose(fp);

   FILE *fp;
   fp=fopen("medicine.dat","a");
   fwrite(&data, sizeof(data),1,fp);
   fclose(fp);
   printf("%s sucessfully added in your database\n",data.medi_name);
  }

  else
   {
     printf("%s already present in your database\n",data.medi_name);
     printf("Do you want to add Medicine??\n");
     printf("Press Y to add N to exit : ");
     scanf("%s",c);
     if(c[0]=='y'||c[0]=='Y')    {
       printf("Medicine Quantity: ");
       scanf ("%d", &medi_quantity);

       update_inc(medi_name,medi_quantity,fp);
     }
     else
      printf("%s not added in your database\n",medi_name);

    fclose(fp);
  }
}

void generate_bill(struct customer cust);
void sell_medicine()
{
   int e,h,i=0;
   int flag=-1;
   char  c[1],d[1],f[1];

   FILE *fp1=fopen("medicine.dat","r+");
   FILE *fp2=fopen("customer.dat","a");
   cust.medi_count=1;
 x:printf("Medicine Name: ");
   scanf ("%s", cust.medicine[i]);
   printf("Medicine Quantity: ");
   scanf ("%d", &cust.quantity[i]);
   //cust.medi_count=1;
      int a=search_medicine(cust.medicine[i],fp1);
       if(a==1)   {

        int b=check_quantity(cust.medicine[i], cust.quantity[i],fp1);
           if(b==1)  
            {

              update_dec(cust.medicine[i], cust.quantity[i],fp1);

            printf("Press Y for another entry N to exit : ");
              scanf("%s",c);

              if(c[0]=='y'||c[0]=='Y')   {
                 i++;
                 cust.medi_count=cust.medi_count + 1;
                 printf("count = %d\n",cust.medi_count);
                goto x;
               }
              else {
             z:printf("Customer Name: ");
               scanf ("%s",cust.name);
               printf("Enter contact: ");
               scanf("%lu",&cust.contact_no);
               add_customer(cust);
             }
           }
         else  {
            printf("%d available in your shop\n",data.medi_quantity);
            printf("It is less than the quantity you required\n");
            cust.medi_count=cust.medi_count-1;
            printf("Enter Y to continue N to exit : ");
            scanf("%s",d);

              if(d[0]=='y'||d[0]=='Y')   {

                 printf("Enter 1 to enter new medicine and 2 to generate bill\n");
                 scanf("%d",&e);
                  switch(e) {
                       case 1:
                          goto x;
                          break;
                       case 2:
                           if(cust.medi_count==0)
                            printf("No medicine purchased\n");
                           else
                             goto z;
                          break;
                   }                 //goto m;
               }
          }
      }
     else  {
       printf("Not available in shop\n");
       cust.medi_count=cust.medi_count-1;
       printf("Enter Y to continue N to exit : ");
            scanf("%s",f);

              if(f[0]=='y'||f[0]=='Y')   {

                  printf("Enter 1 to enter new medicine and 2 to generate bill\n");
                 scanf("%d",&h);
                  switch(h) {
                       case 1:
                          goto x;
                          break;
                       case 2:
                          if(cust.medi_count==0)
                            printf("No medicine purchased\n");
                           else
                            goto z;
                          break;
                   }


                 //goto z;
               }
       }
        generate_bill(cust);            // Generate bill
   fclose(fp1);
}


void buy_medicine(char medi_name[], int medi_quantity)
{
  int flag=-1;
  FILE *fp;
  fp=fopen("medicine.dat","r+");
   int a=search_medicine(medi_name,fp);

    if(a==1)  {
       update_inc(medi_name,medi_quantity,fp);
       flag=1;
       fclose(fp);
     }
   else
      flag=0;

   if(!flag){
     char c[1];
     printf("%s is not in your database\n",medi_name);
     printf("Do you want to add Medicine??\n");
     printf("Press Y to add N to exit : ");
     scanf("%s",c);
     if(c[0]=='y'||c[0]=='Y')
       add_medicine();
     else
      printf("%s not added in your database\n",medi_name);
    }
}

void delete_medicine()
{
  char c[1];
  int flag=-1;
  char medi_name[20];
  FILE *fp;
  fp=fopen("medicine.dat","r");

  printf("Enter the medicine you want to delete: ");
  scanf("%s",medi_name);

  while (fread(&data, sizeof(data),1,fp))   {
    if(strcmp(data.medi_name,medi_name)==0)   {
      printf("Are you sure you want to delete?? %s\n",medi_name);
      printf("Press Y to confirm : ");
      scanf("%s",c);
      flag=1;

      if(c[0]=='y'||c[0]=='Y')   {
         data.medi_name[0]='\0';
         data.medi_quantity=0;
         data.medi_price=0;
         data.supp_name[0]='\0';
         data.supp_cont=0;
         data.id[0]='\0';

         fseek(fp,-(sizeof(data)),SEEK_CUR);
         fwrite(&data,sizeof(data),1,fp);
         printf("%s sucessfully deleted from your database\n",medi_name);
      }
      else  {
        printf("%s is not deleted from your database\n",medi_name);
        break;
      }
   }
    else
      flag=0;
  }

 if(!flag)
    printf("%s not found in database\n",medi_name);

 fclose(fp);
}


void stock()
{
  char medi_name[1];
  medi_name[0]='\0';
  FILE *fp=fopen("medicine.dat","r");
  while (fread(&data, sizeof(data),1,fp))
    {
     if(strcmp(data.medi_name,medi_name)==0)
     {}
     else
    printf ("\nMedicine Name= %s\t\tQuantity of Medicine= %d\n",data.medi_name, data.medi_quantity);
 }
 fclose(fp);
}




int search_cust(char name[],long int contact) {
    FILE *fp_bill = fopen("bill.dat","r");
        struct Bill bill;
        int i;
    int flag=0; // 0 for Not found
	while (fread(&bill,sizeof(bill),1,fp_bill)) {
        if (strcmp(bill.cstmr.name,name) == 0 && bill.cstmr.contact_no == contact)
        {
                printf("\n");
                printf("Date: %d-%d-%d Time : %d:%d:%d\n", bill.year, bill.month, bill.day, bill.hour, bill.minute, bill.second);
                printf("Customer Name : %s\n",bill.cstmr.name);
                for ( i = 0; i < bill.cstmr.medi_count; ++i)
                {
                        printf("%s",bill.cstmr.medicine[i]);
                        printf("\t\t\t%d\n",bill.cstmr.quantity[i]);
                }
                printf("Total : %f\n",bill.cstmr.total);
                flag = 1;
        }
    }
    if(flag == 0)
      return 0; //Not found
    else
        return 1;
}



void generate_bill(struct customer cust)
{
        FILE *fp1=fopen("medicine.dat","r");
        FILE *fp=fopen("customer.dat","a");
        FILE *fp_bill=fopen("bill.dat","a")	;
        fseek(fp,-(sizeof(data)),SEEK_CUR);

        struct Bill bill;

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        float total[2];
        float sum;
        long int contact;
        printf("\n\n-------------------------------Medical Store Management Project-------------------------------\n\n");
        printf("Date: %d-%d-%d Time : %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        printf("\n\n");

        bill.day = tm.tm_mday;
        bill.month = tm.tm_mon + 1 ;
        bill.year = tm.tm_year + 1900;
        bill.hour = tm.tm_hour ;
        bill.minute = tm.tm_min;
        bill.second = tm.tm_sec ;


        printf("Customer Name : %s\n",cust.name);
        printf("Customer No.  : %lu\n\n",cust.contact_no);

        printf("Medicine\t\tQuantity\t\tPrice per Unit\t\tTotal\n\n");

        fread(&cust,sizeof(cust),1,fp);

        printf("Count of Medicines : %d\n",cust.medi_count);
        int i;
              for ( i = 0; i <cust.medi_count; ++i)
               {
           int a=search_medicine(cust.medicine[i],fp1);

                 printf("%s",cust.medicine[i]);
                 printf("\t\t\t%d",cust.quantity[i]);
                 printf("\t\t\t%f",data.medi_price);
                 total[i]=(cust.quantity[i]*data.medi_price);
                 printf("\t\t%f\n",total[i]);
                sum=sum+total[i];
               }
        cust.total = sum ;
        bill.sum = sum ;
        printf("\n\n");
        printf("Total Amount : %f\n\n",sum );
        bill.cstmr = cust ;

        fwrite(&bill,sizeof(bill),1,fp_bill); //Writing into Bill File
fclose(fp_bill);
fclose(fp);
fclose(fp1);
}






