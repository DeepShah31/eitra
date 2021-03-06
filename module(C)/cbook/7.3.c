#include<stdio.h>
#include<stdarg.h>
void minprintf(char *fmt,...);

int main(void)
{
    char *a="Hii hello";
    minprintf("%d",a);

    
    return 0;
}

void minprintf(char *fmt,...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p,*sval;
    int ival;
    double dval;
  unsigned uval;
  char masfmt[20]; 
    va_start(ap,fmt);   /* make ap point to 1st unnamed arg */
    
    for(p=fmt;*p;p++)
    {
        if(*p != '%')
        {
            putchar(*p);
            continue;
        }

        switch(*++p)
        {
            case 'd':
                ival = va_arg(ap,int);
                printf("%d",ival);
                break;
            case 'f':
                dval = va_arg(ap,double);
                printf("%f",dval);
                break;
            case 's':
                for(sval = va_arg(ap,char *);*sval;sval++)
                    putchar(*sval);
                break;
        case 'o':
            case 'x':
            case 'X':
            case 'u':
            case 'e':
                uval = va_arg(ap, unsigned);
                printf(masfmt, uval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); /* clean up when done */
}
