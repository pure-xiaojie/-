/* Note:Your choice is C IDE */
#include <stdio.h>
int main() {
    int a, b, c,sum;
    scanf("%d %d %d", &a, &b, &c);  
    sum = (a * 70 + b * 21 + c * 15) % (3 * 5 * 7);
    if (sum < a + b + c || sum > 100)
        printf("No answer\n");
    else
        printf("%d\n", sum);
    return 0;
}