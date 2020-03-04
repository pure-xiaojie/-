#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

typedef struct pcb {
    char name[20];    //进程名字
    int prio;         //进程优先级
    int round;        //CPU的时间片
    int cputime;      //CPU执行时间
    int needtime;     //进程的到达时间
    char state;       //进程的状态，W--就绪态，R--执行态，F--完成态
    int count;        //记录执行的次数
    struct pcb *next;   //链表指针
} PCB;

PCB *ready = NULL;      //就绪队列
PCB *run = NULL;        //运行队列
PCB *finish = NULL;     //阻塞队列

int num;   //PCB数

//输出队列信息
void Output() {
    PCB *p;
    printf("进程名\t优先级\t时间片\tcpu时间\t需要时间\t进程状态\t计数器\n");
    p = ready;
    while(p!=NULL) {
        printf("%s\t%d\t%d\t%d\t%d\t\t%c\t\t%d\n",p->name,p->prio,p->round,p->cputime,p->needtime,p->state,p->count);
        p = p->next;
    }
    p = finish;
    while(p!=NULL) {
        printf("%s\t%d\t%d\t%d\t%d\t\t%c\t\t%d\n",p->name,p->prio,p->round,p->cputime,p->needtime,p->state,p->count);
        p = p->next;
    }
    p = run;
    while(p!=NULL) {
        printf("%s\t%d\t%d\t%d\t%d\t\t%c\t\t%d\n",p->name,p->prio,p->round,p->cputime,p->needtime,p->state,p->count);
        p = p->next;
    }
    Sleep(1000);
}

//创建优先级队列，规定优先数越小，优先级越高
void InsertPrio(PCB *in) {
    PCB *fst,*nxt;
    fst = nxt = ready;

    if(ready == NULL) { //如果队列为空，则为第一个元素
        in->next = ready;
        ready = in;
    } else { //查到合适的位置进行插入
        if(in ->prio > fst ->prio) { //比第一个还要大(大于等于)，则插入到队头
            in->next = ready;
            ready = in;
        } else {
            while(fst->next != NULL) { //移动指针查找第一个别它小的元素的位置进行插入
                nxt = fst;
                fst = fst->next;
            }

            if(fst ->next == NULL) { //已经搜索到队尾，则其优先级数最小，将其插入到队尾即可
                in ->next = fst ->next;
                fst ->next = in;
            } else { //插入到队列中
                nxt = in;
                in ->next = fst;
            }
        }
    }
}

//将进程插入到就绪队列尾部
void InsertTime(PCB *in) {
    PCB *fst;
    fst = ready;

    if(ready == NULL) {
        in->next = ready;
        ready = in;
    } else {
        while(fst->next != NULL) {
            fst = fst->next;
        }
        in ->next = fst ->next;
        fst ->next = in;
    }
}

//将进程插入到完成队列尾部
void InsertFinish(PCB *in) {
    PCB *fst;
    fst = finish;

    if(finish == NULL) {
        in->next = finish;
        finish = in;
    } else {
        while(fst->next != NULL) {
            fst = fst->next;
        }
        in ->next = fst ->next;
        fst ->next = in;
    }
}

//优先级调度输入函数
void PrioCreate() {
    PCB *tmp;
    int i;

    printf("输入进程名字和进程到达时间,优先级：\n");
    for(i = 0; i < num; i++) {
        tmp = (PCB *)malloc(sizeof(PCB));
        cin >> tmp->name;
        cin >> tmp->needtime;
        cin >> tmp ->prio;

        tmp ->cputime = 0;
        tmp ->state ='W';
        tmp ->round = 0;
        tmp ->count = 0;
        InsertPrio(tmp);      /*按照优先级从高到低，插入到就绪队列*/
    }
}


//从就绪队列取得第一个节点
void GetFirst() {
    run = ready;

    if(ready!=NULL) {
        run ->state = 'R';
        ready = ready ->next;
        run ->next = NULL;
    }
}

//按照优先级调度，每次执行一个时间片
void Priority() {
    int flag = 1;

    GetFirst();
    while(run != NULL) { //当就绪队列不为空时，则调度进程
        Output();  //输出每次调度过程中各个节点的状态
        while(flag) {
            run->prio -= 3;     //优先级减去三,若设为0则优先级不变
            run->cputime++;     //CPU时间片加一
            run->needtime--;    //进程执行完成的剩余时间减一

            if(run->needtime == 0) {     //如果进程执行完毕，将进程状态置为F，将其插入到完成队列
                run ->state = 'F';
                run->count++;   //进程执行的次数加一
                InsertFinish(run);
                flag = 0;
            } else {    //将进程状态置为W，入就绪队列
                run->state = 'W';
                run->count++;   //进程执行的次数加一
                InsertTime(run);
                flag = 0;
            }
        }
        flag = 1;
        GetFirst();    //继续取就绪队列队头进程进入执行队列
    }
}


int main(void) {

    printf("请输入要创建的进程数目:\n");
    cin >> num;

    //优先权调度算法
    PrioCreate();
    Priority();

    //打印
    Output();
    return 0;
}

