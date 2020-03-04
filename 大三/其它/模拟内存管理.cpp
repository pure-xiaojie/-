#include<bits/stdc++.h>

using namespace std;

typedef struct page
{
    int id;     //记录页面号
    int time;   //记录调入内存时间
} Page;

int num=0,Num=0,out_num,In_num; //In_out命中数

void create(Page page[]) {
    int i;
    cout << "请输入要输入页面的个数：" << endl;
    cin >> num;

    printf("请输入%d个页面序号:",num);
    for(i=0; i<num; i++) {
        scanf("%d",&page[i].id);
        page[i].time=0;
    }
    printf("请输入驻留集:");
    cin >> Num;
    printf("输入完成\n");
}

//显示
void display(Page page[],int N) {
    for(int i=0; i<N; i++) {
        printf("%d,[%d]  ",page[i].id,page[i].time);
    }
}

//先进先出算法
void  FIFO(Page page[]) {
    out_num=0;

    Page fiofo_page[Num],out_page[20];//淘汰页;
    int i,j=0;
    for(i=0; i<num; i++) {
        if(i<Num) {
            fiofo_page[j]=page[i];
            j++;
            printf("\n驻留集中页面的编号id,[time]:");
            display(fiofo_page,j);
        } else {
            out_page[out_num++]=fiofo_page[0];
            In_num++;
            for(j=1; j<Num; j++) {

                fiofo_page[j-1]=fiofo_page[j];

            }
            fiofo_page[j-1]=page[i];
            printf("\n驻留集中页面的编号id,[time]:");
            display(fiofo_page,Num);
        }
    }
    printf("\n淘汰的页面编号：");
    display(out_page,out_num);


}
//lru计数
void lru(Page page[]) {
    Page out_page[20];//淘汰页
    out_num=0;
    In_num=0;
    int i,j,flag=0,max=0;
    for(i=Num-1,j=0; j<Num; j++,i--) {
        page[j].time=i;
    }
    for(i=Num; i<num; i++) {
        printf("\n驻留集中页面的编号id,[time]:");
        display(page,Num);
        for(j=0; j<Num; j++) {
            page[j].time++;
        }
        flag=0;
        max=0;
        for(j=0; j<Num; j++) {
            if(page[i].id==page[j].id) {
                page[j].time=0;
                In_num++;
                flag=1;
                break;
            }
        }
        if(flag==0) {
            for(j=1; j<Num; j++) {
                if(page[max].time < page[j].time)
                    max=j;
            }
            out_page[out_num]=page[max];
            out_num++;
            page[max]=page[i];

        }
    }
    printf("\n淘汰的页面编号：");
    display(out_page,out_num);
    printf("\n缺页率：%d/%d",(num-In_num),num);
}


//将更新的页面放置顶部
void list_hour(Page page[],int n) {
    int i;
    Page temp;
    temp=page[n];
    for(i=n+1; i<Num; i++) {
        page[i-1]=page[i];
    }
    page[i-1]=temp;
}

//LRU替换策略
void lru_replace(Page page[]) {
    Page out_page[20],lru_replace_page[Num];//淘汰页
    out_num=0;
    In_num=0;

    int i,j,flag=0;
    for(i=0; i<num; i++) {
        flag=0;
        if(i<Num) {
            lru_replace_page[i]=page[i];
            printf("\n驻留集中页面的编号id,[time]:");
            display(lru_replace_page,i+1);
        } else {
            for(j=0; j<Num; j++) {
                if(lru_replace_page[j].id==page[i].id) {
                    list_hour(lru_replace_page,j);/*命中则放置顶部  */
                    flag=1;
                    In_num++;
                    break;
                }
            }
            if(flag==0) {
                out_page[out_num++]=lru_replace_page[0];
                list_hour(lru_replace_page,0);
                lru_replace_page[Num-1]=page[i];

            }
            printf("\n驻留集中页面的编号id,[time]:");
            display(lru_replace_page,Num);
        }
    }
    printf("\n淘汰的页面编号：");
    display(out_page,out_num);
    printf("\n缺页率：%d/%d",(num-In_num),num);
}

void menu()
{
    printf("\n1.计数器方式的 LRU 算法\n");
    printf("2.先进先出算法\n");
    printf("3.替换方式的LRU 算法\n");
    printf("0.退出\n");
}

int main()
{
    Page page[20];              //初始化页
    Page count_lru_page[20];    //计数lru
    Page fifo_page[20];         //先进先出
    Page replace_lru_page[20];  //替换方式lru

    int key=0;   //菜单选择编号
    create(page);

    while(1)
    {
        menu();
        cin >> key;
        switch(key)
        {
        case 1:
            for(int i=0; i<num; i++) {
                count_lru_page[i]=page[i];
            }
            lru(count_lru_page);
            break;
        case 2:
            for(int i=0; i<num; i++) {
                fifo_page[i]=page[i];
            }
            FIFO(fifo_page);
            break;
        case 3:
            for(int i=0; i<num; i++) {
                replace_lru_page[i]=page[i];
            }
            lru_replace(replace_lru_page);
            break;
        case 0:
            return 0;
        }
    }
    return 0;
}

