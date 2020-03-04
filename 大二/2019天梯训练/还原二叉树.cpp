#include<cstdio>
#include<iostream>
using namespace std;

int dfs(char a[],char b[],int n){
    int i;
    if(n==0)return 0;
    for(i=0;i<n;i++){
        if(b[i]==a[0]){
            break;
        }
    }
    int x=dfs(a+1,b,i)+1;
    int y=dfs(a+i+1,b+i+1,n-i-1)+1;
    return x>y?x:y;
}
int main()
{
    char a[101],b[101];
    int n;
    cin>>n;
    cin>>a>>b;
    cout<<dfs(a,b,n);
}

