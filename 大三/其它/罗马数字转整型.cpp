#include<cstdio>
#include<iostream>

using namespace std;

int romanToInt(string s) {
   int i = 0,len = s.size();
   int sum = 0;
   for(;i < len; i++)
   {
       switch(s[i])
       {
           case 'I': sum += 1;break;
           case 'V': sum += 5;break;
           case 'X': sum += 10;break;
           case 'L': sum += 50;break;
           case 'C': sum += 100;break;
           case 'D': sum += 500;break;
           case 'M': sum += 1000;break;
           default :cout << "default" << endl;break;
       }
       if(i > 0)
       {
           if((s[i] == 'V' || s[i] == 'X') && s[i-1] == 'I')
             sum -= 2;
           if((s[i] == 'L' || s[i] == 'C') && s[i-1] == 'X')
             sum -= 20;
           if((s[i] == 'D' || s[i] == 'M') && s[i-1] == 'C')
             sum -= 200;
       }

   }
   return sum;

}

int main()
{
    string s;
    cin >> s;
    cout << romanToInt(s) << endl;
    return 0;
}
