#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
char a[1000], s[1000], b[1000], b1[1000];
stack<char> ss;

int is_op(char c){
	if(  c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']')
		return 1;
	return 0;
}

int if_com(char s, char t){
	if(s == '(' && t == ')')
		return 1;
	else if(s == '{' && t == '}')
		return 1;
	else if(s == '[' && t == ']')
		return 1;
	else if(s == '<' && t == '>')
		return 1;
	return 0;
}

int main(){
	int k = 0, n, count, i, j;
	while(1){
		if(a[0] == '.' && strlen(a) == 1)
			break;

		scanf("%s", &a);
		getchar();
		int len = strlen(a);
		for( i = 0; i < len; ++i){
			if(is_op(a[i]))
				s[k++] = a[i];
			else if((a[i] == '/' && a[i + 1] == '*')){
				s[k++] = '<';
				++i;
			}
			else if((a[i] == '*' && a[i + 1] == '/')){
				s[k++] = '>';
				++i;
			}
		}

	}
	n = k;
	count = 0;
/*	for( i = 0; i < n; ++i)
		printf("%c", s[i]);
	printf("\n\n");*/
	for(i = 0; i < n; ++i){
	 	if(s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<')
	 		ss.push(s[i]);
	 	else if(!ss.empty()){
	 		if(if_com(ss.top(), s[i]) == 1){
	 			ss.pop();
			}
			else
				ss.push(s[i]);
		}
		else
			ss.push(s[i]);
    }
    if(ss.empty()){
    	printf("YES\n");
	}
    else {
  	  k = 0;
		while(!ss.empty()){
		b[k++] = ss.top();
		ss.pop();
	}
	n = k;
	for(i = 0; i < n; ++i)
		b1[n - i - 1] = b[i];

	int tt = n - 1;
	for(i = 0; i < tt; ++i){
		for(j = tt; j > i; j--){
			if(if_com(b1[i], b1[j]) || if_com(b1[j], b1[i])){
				b1[i] = '@';
				b1[j] = '@';
				tt = j - 1;
			}
		}
	}
	char aa;
	for(i = 0; i < n; ++i) {
		if(b1[i] != '@'){
			aa = b1[i];
			break;
		}
	}
	if(aa == '(') printf("NO\n(-?\n");
	if(aa == '[') printf("NO\n[-?\n");
	if(aa == '{') printf("NO\n{-?\n");
	if(aa == '<') printf("NO\n/*-?\n");
	if(aa == ')') printf("NO\n?-)\n");
	if(aa == ']') printf("NO\n?-]\n");
	if(aa == '}') printf("NO\n?-}\n");
	if(aa == '>') printf("NO\n?-*/\n");
	}
	return 0;
}
