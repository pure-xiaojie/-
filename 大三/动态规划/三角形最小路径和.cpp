#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int minimumTotal(vector<vector<int> >& triangle) {
    vector<int> mini = triangle[triangle.size()-1];
    for(int i = triangle.size()-2; i >= 0; i--) {
        for(int j = 0; j < triangle[i].size(); j++) {
            mini[j] = triangle[i][j] + min(mini[j],mini[j+1]);
        }
    }
    return mini[0];
}

int main()
{
    vector<vector<int> > triangle;
    vector<int> b;
    b.push_back(2);
    triangle.push_back(b);
    b.clear();

    b.push_back(3);
    b.push_back(4);
    triangle.push_back(b);
    b.clear();

    b.push_back(6);
    b.push_back(5);
    b.push_back(7);
    triangle.push_back(b);
    b.clear();

    b.push_back(4);
    b.push_back(1);
    b.push_back(8);
    b.push_back(3);
    triangle.push_back(b);

    cout << minimumTotal(triangle) << endl;
    return 0;
}
