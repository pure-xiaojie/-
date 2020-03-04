#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

bool isToeplitzMatrix(char matrix[4][4]) {
    for(int i = 1; i < 3; i++)
      for(int j = 1; j < 4; j++) {
        if(matrix[i][j] != matrix[i-1][j-1])
            return false;
    }
    return true;
}

int main()
{
     char a[4][4]= {
  {1,2,3,4},
  {5,1,2,3},
  {9,5,1,2}};

    cout << isToeplitzMatrix(a) << endl;
    return 0;
}
