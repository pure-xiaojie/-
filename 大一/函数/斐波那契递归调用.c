/* Note:Your choice is C IDE */
#include<stdio.h>  

int main() {
	int fun(int n);  
   long int n;
   int i,j;  
    while (scanf("%ld", &n) != EOF) {  
        for (i = 1; i <= n; i++) {  
            for (j = 1; j <= 2 * i - 1; j++) {  
                if (j == 1)  
                    printf("0");  
                else  
                    printf(" %d", fun(j));  
            }  
            printf("\n");  
        }  
    }  
    return 0;  
} 
  
int fun(int n) { 
	int t 
    if (n == 1)  
        return 0;  
    if (n == 2)  
        return 1;  
    if (n > 2) {  
        t = fun(n - 1) + fun(n - 2);  
        return t;  
    }  
}  