#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int minDistance(string word1, string word2) {
    int len1=word1.size(),len2=word2.size();

    int dp[len1+1][len2+1];

    for(int i = 0; i < len1+1; i++)
        dp[i][0] = i;
    for(int j = 0; j < len2+1; j++)
        dp[0][j] = j;

    for(int i = 1; i < len1+1; i++) {
        for(int j = 1; j < len2+1; j++) {
            if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
        }
    }
    return dp[len1][len2];

}


int main()
{
    string str1,str2;
    while(cin >> str1 >> str2) {
        printf("%d\n",minDistance(str1,str2));
    }
    return 0;
}
