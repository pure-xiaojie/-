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
        printf("超过范围，最大万亿！整数部分最多13位！\n");

    }

    printf("￥%s 的大写金额： ", a);

    /*转换整数部分*/
    for(i=0;i<len_integer;i++)
    {
        a=*(p+i)-'0';
        if(a==0)
        {
            if(i==0)
            {
                printf("零元");
                break;
            }
            else
                if(*(p+i+1)!='0'&&i!=len_integer-5&&i!=len_integer-1&&i!=len_integer-9)
                {
                    printf("零元");
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

    /*求出小数部分的长度*/
    len_decimal=len-len_integer-1;
    if(len_decimal<0)
    {
        len_decimal=0;
        printf("整");

    }

    if(len_decimal>2)
        len_decimal=2;
    p=c;
     /*转换小数部分*/
     for(j=0;j<len_decimal;j++)
     {
         a=*(p+len_integer+1+j)-'0';
         if(a<0 || a>9)
         {
             printf("\n小数部分有误！\n");
             system("pause");
         }
         if(a==0)
         {
             if(j+1<len_decimal)
             {
                 if(*(p+len_integer+2+j)!='0')
                    printf("零");
                 else
                 {
                     printf("整");
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
        case 3:case 7:case 11:printf("拾");break;
        case 4:case 8:case 12:printf("佰");break;
        case 5:case 9:case 13:printf("仟");break;
        case 6:case 14:       printf("万");break;
        case 10:              printf("万");break;
        case 2:       printf("万");break;
        case 1:       printf("万");break;
        case 0:       printf("万");break;
        default:break;
    }
}

void big_write_num(int n)
{
    switch(n)
    {
        case 0:printf("零");break;
        case 1:printf("壹");break;
        case 2:printf("贰");break;
        case 3:printf("叁");break;
        case 4:printf("肆");break;
        case 5:printf("伍");break;
        case 6:printf("陆");break;
        case 7:printf("柒");break;
        case 8:printf("捌");break;
        case 9:printf("玖");break;
        default:break;
    }
}
