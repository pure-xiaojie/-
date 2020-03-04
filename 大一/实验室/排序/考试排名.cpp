#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

struct Node
{
    string Name;
    int Num;
    int Time;
} A[1100];

int cmp(Node a,Node b)
{
    if(a.Num != b.Num)
        return a.Num > b.Num;
    else
    {
        if(a.Time != b.Time)
            return a.Time < b.Time;
        else
        {
            return a.Name < b.Name;
        }
    }
}
int main()
{
    int N,M,Count = 0;
    string name,temp;
    cin >> N >> M;
    while(cin >> name)
    {
        A[Count].Name = name;
        A[Count].Num = 0;
        A[Count].Time = 0;
        for(int i = 0; i < N; ++i)
        {
            cin >> temp;
            if(temp[0]=='-' || temp[0] == '0')
                continue;
            int d;
            sscanf(temp.c_str(),"%d",&d);
            A[Count].Num++;
            A[Count].Time+= d;
            int pos = temp.find('(');
            if(pos != string::npos)
            {
                sscanf(temp.c_str()+pos+1,"%d",&d);
                A[Count].Time += (d*M);
            }
        }
        Count++;
    }
    sort(A,A+Count,cmp);
    for(int i = 0; i <= Count-1; i++)
    {
        printf("%-10s %2d %4d\n",A[i].Name.c_str(), A[i].Num, A[i].Time);
    }

    return 0;
}
