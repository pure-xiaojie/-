#include"stdio.h"
#include"string.h"
#include"stdlib.h"
void rmb_units(int m);
void big_write_num(int n);

main()
{
    char c[30],*p;
    int a,i,j,len,len_integer=0,len_decimal=0;
    scanf("%s",c);
    p=c;
    len=strlen(p);

    for(i=0;i<=len-1&&*(p+i)<='9'&&*(p+i)>='0';i++)
        if(*(p+i)=='.'||*(p+i)=='\0')
          len_integer=i;

    if(len_integer>13)
    {
        printf("������Χ��������ڣ������������13λ��\n");

    }

    printf("��%s �Ĵ�д�� ", a);

    /*ת����������*/
    for(i=0;i<len_integer;i++)
    {
        a=*(p+i)-'0';
        if(a==0)
        {
            if(i==0)
            {
                printf("��Ԫ");
                break;
            }
            else
                if(*(p+i+1)!='0'&&i!=len_integer-5&&i!=len_integer-1&&i!=len_integer-9)
                {
                    printf("��Ԫ");
                    continue;
                }
                else
                   if(i==len_integer-5||i==len_integer-1||i!=len_integer-9)
                   {
                      rmb_units(len_integer+1-i);
                      continue;
                   }
                   else
                       continue;

        }
        big_write_num(a);
        rmb_units(len_integer+1-i);

    }

    /*���С�����ֵĳ���*/
    len_decimal=len-len_integer-1;
    if(len_decimal<0)
    {
        len_decimal=0;
        printf("��");

    }

    if(len_decimal>2)
        len_decimal=2;
    p=c;
     /*ת��С������*/
     for(j=0;j<len_decimal;j++)
     {
         a=*(p+len_integer+1+j)-'0';
         if(a<0 || a>9)
         {
             printf("\nС����������\n");
             system("pause");
         }
         if(a==0)
         {
             if(j+1<len_decimal)
             {
                 if(*(p+len_integer+2+j)!='0')
                    printf("��");
                 else
                 {
                     printf("��");
                     break;
                 }

             }
             continue;
         }
         big_write_num(a);
        rmb_units(1-j);
     }
 printf("\n");
 return 0;
}

void rmb_units(int m)
{
    switch(m)
    {
        case 3:case 7:case 11:printf("ʰ");break;
        case 4:case 8:case 12:printf("��");break;
        case 5:case 9:case 13:printf("Ǫ");break;
        case 6:case 14:       printf("��");break;
        case 10:              printf("��");break;
        case 2:       printf("��");break;
        case 1:       printf("��");break;
        case 0:       printf("��");break;
        default:break;
    }
}

void big_write_num(int n)
{
    switch(n)
    {
        case 0:printf("��");break;
        case 1:printf("Ҽ");break;
        case 2:printf("��");break;
        case 3:printf("��");break;
        case 4:printf("��");break;
        case 5:printf("��");break;
        case 6:printf("½");break;
        case 7:printf("��");break;
        case 8:printf("��");break;
        case 9:printf("��");break;
        default:break;
    }
}
