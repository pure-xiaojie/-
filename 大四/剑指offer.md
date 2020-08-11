## 剑指offer刷题记录

### 一、贪心题

#### 1、剪绳子

​		给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

**解题：**

此题为贪心题，每次减掉3，最后剩下的有三种情况：

​	**情况1：**为0时,n%3==0，最大乘积为pow(3, n/3)

​	**情况2：**为1时,n%3==1，最大乘积为 pow(3, n/3-1) * 4    // 如n=10,余数为1，3 * 3 * 3 * 1  <  3 * 3 * 4

​	**情况3：**为2时,n%3==2，最大乘积为pow(3, n/3) * 2

```c++
int cutRope(int number) {
        if(number == 2 || number == 3)
            return number-1;
        int res = number/3;
        int m = number % 3;
        
        if(m == 0)
            return pow(3,res);
        else if(m == 1)
            return pow(3,res-1) * 4;
        else if(m == 2)
            return pow(3,res) * 2;
}
```



#### 2、两两配对（腾讯笔试）

​		小Q有M(M为偶数)名员工, 第i名员工完成工作的时候有一个拖延时间值ti。现在小Q手里有M/2份工作需要完成, 每一份工作都需要安排两名员工参与, 对于第i份工作所需完成的时间为两名员工的拖延时间值总和。

​		现在M/2份工作同时开始进行,小Q希望所有工作结束的时间尽量早, 请你帮小Q设计一个优秀的员工分配方案,使得用尽量少的时间完成所有工作,并输出工作所需的最短时间。

**示例1**

**输入**

```
3
1 8
2 5
1 2
```

**输出**

```
10
```

**说明**

​		拖延值为8的和拖延值为2的组队，两名拖延值为5的组队，所以完成工作的时间为10，这是时间最短的方案。

**【解题思路】**

贪心。最大的和最小的组合，次大的和次小的组合。

```c
#include<bits/stdc++.h>

using namespace std;

struct node {
    int cnt;
    int time;
}pe[100005];

bool compare(node a, node b) {
    return a.time < b.time;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> pe[i].cnt >> pe[i].time;
    }

    sort(pe,pe+t,compare);

    int res = 0;
    int left = 0, right = t-1;

    while(left <= right) {
        int number = min(pe[left].cnt,pe[right].cnt);
        
        number /= (left == right) ? 2 : 1;   //若left == right,number折半

        res = max(res,pe[left].time+pe[right].time);

        pe[left].cnt -= number; 
        pe[right].cnt -= number;

        left += (pe[left].cnt == 0) ? 1 : 0;
        right += (pe[right].cnt == 0) ? -1 : 0;
    }
    cout << res << endl;
    return 0;
}

```



### 二、递归题

#### 1、机器人的运动范围

​		地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

**解题：**

​		此题为典型递归题，利用dfs深度搜索，从起点0,0开始，此解妙处在于利用一维数组flag记录访问状态，每次搜索时求得坐标（i , j）在一维数组表示的值。index = i*cols+j;     cols 为列值。还有就是单独写个函数，用来求行列的位数之和并返回。

```c
int flag[10000];

int movingCount(int threshold, int rows, int cols)
{
    memset(flag,0,sizeof(flag));
    int res = dfs(0,0,threshold,rows,cols);
    return res;
}

int dfs(int i,int j,int thre,int rows,int cols) {
    int index = i*cols+j;  //用一维数组简化访问状态
    if(flag[index] || i < 0 || i >= rows || j < 0 || j >= cols ||
    (num(i)+num(j) > thre))
    return 0;
    flag[index] = 1;

    //判断上、下、左、右是否满足移动
    return dfs(i,j-1,thre,rows,cols) + 
    dfs(i,j+1,thre,rows,cols) + 
    dfs(i-1,j,thre,rows,cols) + 
    dfs(i+1,j,thre,rows,cols) + 1;
}

//计算行与列坐标的位数之和
int num(int n) {
    int sum = 0;
    while(n) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}
```



#### 2、矩形覆盖

​		我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

比如n=3时，2*3的矩形块有3种覆盖方法：

![img](https://uploadfiles.nowcoder.com/images/20200218/6384065_1581999858239_64E40A35BE277D7E7C87D4DCF588BE84)

**解题：**递归求解

```c
int rectCover(int number) {
       
    if(number == 0 || number == 1 || number == 2)
        return number;

    return rectCover(number-1) + rectCover(number-2);

}
```

内存标记

```c 
int num[1000] = {0,1,2,3};
     
int rectCover(int number) {
    int n = number;

    if(n == 1 || n == 2 || n == 3)
        return num[n];

    for(int i = 4; i <= n; i++) {
        num[i] = num[i-1] + num[i-2];
    }

    return num[n];
}
```



#### 3、变态跳台阶

​		一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法

**解题：**f(n) = f(n-1)*2 ，且f(1) = 1

```c
int jumpFloorII(int number) {
    if(number == 1)
        return 1;

    return 2*jumpFloorII(number-1);
}
```



#### 4、跳台阶

​		一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

**解题：**f(n) = f(n-1)+f(n-2) ，且f(1) = 1 ，f(2) = 2

```C
int jumpFloor(int number) {
    if(number == 1 || number == 2)
    	return number;

	return jumpFloor(number-1) + jumpFloor(number-2);
}
```



### 三、回溯题

#### 1、矩阵中的路径

​		请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如

a  b  c  e

s  f   c  s

a  d  e  e

矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

**题解：**

​		此题利用递归+回溯即可求解。这里我是选择使用c++解题的，所以hasPath传参为指针，其实也就是一维数组，这里可以根据坐标（i  , j）求得matrix中的位置，因此首先求得matrix的长度，然后初始化一个访问状态flag数组，用来记录是否访问过某个坐标。此题需要寻得str路径，那么此题可以直接遍历rows，cols中的所有坐标。

```c
bool hasPath(char* matrix, int rows, int cols, char* str)
{
    int n = strlen(matrix);
    int flag[n+5];   
    memset(flag,0,sizeof(flag));

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(judgePath(matrix,i,j,rows,cols,str,flag,0)){
                return true;
            }
        }
    }
    return false;
}
    
bool judgePath(char* matrix, int i, int j, int rows, int cols, char* str, 
               int flag[], int k) {
    int index = i * cols + j;     //求得二维坐标在一维中的index
    if(i < 0 || i >= rows || j < 0 || j >= cols || 
       matrix[index] != str[k] || flag[index] == 1)
        return false;

    flag[index] = 1;

    if(k == strlen(str)-1)    //当匹配到str中最后一位时，匹配成功
        return true;

    //判断上、下、左、右是否满足
    if(judgePath(matrix,i-1,j,rows,cols,str,flag,k+1) ||
       judgePath(matrix,i+1,j,rows,cols,str,flag,k+1) ||
       judgePath(matrix,i,j-1,rows,cols,str,flag,k+1) ||
       judgePath(matrix,i,j+1,rows,cols,str,flag,k+1)) {
        return true;
    }
    
    //此处需要更改状态，恰是回溯最重要的一步，因为起点可以为任何一个点
    flag[index] = 0;
    
    return false;
}

```



### 四、栈、队列题

#### 1、滑动窗口的最大值

​		给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

**解题：**

​	方法1：最直接方法，两个循环模拟窗口判断

```c
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> res;
    int len = num.size();
    if(len < size || size == 0)    //若数组长度小于窗口大小，或窗口大小为0，返回空res
        return res;

    for(int i = 0; i <= len-size; i++) {    //滑动窗口个数
        int maxn = num[i];

        for(int j = i+1; j < i+size; j++) {   //滑动窗口值的比较
            if(maxn < num[j])
                maxn = num[j];
        }
        res.push_back(maxn);
    }

    return res;
}
```

​	方法2：双向队列

```c
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> res;
    deque<int> q;

    int len = num.size();
    if(len < size || size == 0)   //若数组长度小于窗口大小，或窗口大小为0，返回空res
        return res;

    for(int i = 0; i < len; i++) {
        //从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
        while(q.size() && num[q.back()] <= num[i])  
            q.pop_back();
        
        //队首元素已不再是新窗口的最大值，需弹出
        while(q.size() && i-q.front()+1 > size)
            q.pop_front();

        q.push_back(i);

        if(i+1 >= size)  //当够窗口大小时，即可添加值了
            res.push_back(num[q.front()]);
    }

    return res;
}
```



#### 2、栈的压入、弹出序列

​		输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

**解题：**利用一个栈，没加入一个数组就与弹出序列比较一次，若有相同的就弹出栈，且弹出数组下标后移，最后只需判断栈是否为空即可

```c
bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    int len = pushV.size();
    
    if(len < 1)
        return false;
    
    stack<int> s;
	
    for(int i = 0, j = 0; i < len;) {
        s.push(pushV[i++]);

        while(j < popV.size() && !s.empty() && s.top() == popV[j]) {
            j++;
            s.pop();
        }
    }

    return s.empty();   //栈为空返回true，反之返回false
}
```



#### 3、包含min函数的栈

​		定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。

**解题：**利用两个栈，一个栈存元素，正常弹栈；一个辅助栈来存放最小值

```c
stack<int> s1,s2;
    
void push(int value) {
    s1.push(value);

    if(s2.empty())
        s2.push(value);
    else {
        if(value < s2.top())
            s2.push(value);
    }
}
void pop() {
    if(s1.top() == s2.top())
        s2.pop();
    s1.pop();
}
int top() {
    return s1.top();
}
int min() {
    return s2.top();
}
```



#### 4、用两个栈实现队列

​		用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

**解题：**

​	

```c
stack<int> stack1;
stack<int> stack2;

void push(int node) {
    stack1.push(node);
}

int pop() {
    if(!stack2.empty()) {
        int node = stack2.top();
        stack2.pop();
        return node;
    }

    while(!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
    }

    int res = stack2.top();
    stack2.pop();
    return res;
}

```



### 五、数组题

#### 1、数据流中的中位数

​		如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。

**解题：**

定义一个数组，没插入一次进行一次排序，获取中位数时利用数组长度判断一下

```c
vector<int> nums;
    
void Insert(int num)
{
    nums.push_back(num);
    sort(nums.begin(), nums.end());
}

double GetMedian()
{ 

    int len = nums.size();
    if(len % 2 == 1)
        return nums[len/2]*1.0;

    return (nums[len/2]+nums[len/2-1])/2.0;
}
```



#### 2、表示数值的字符串

​		请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

**解题：**

​		简单模拟



```c
bool isNumeric(char* string)
{
    // 标记符号、小数点、e是否出现过
    bool sign = false, decimal = false, isE = false;

    for(int i = 0; i < strlen(string); i++) {
        if(string[i] == 'e' || string[i] == 'E') {
            if(i == strlen(string)-1)
                return false;   // e后面一定要接数字
            if(isE)
                return false;    // e不能出现两次
            isE = true;
        } else if(string[i] == '+' || string[i] == '-') {
            // 第二次出现+-符号，则必须紧接在e之后
            if(sign && string[i-1] != 'e' && string[i-1] != 'E')
                return false;
            // 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
            if(!sign && i > 0 && string[i-1] != 'e' && string[i-1] != 'E')
                return false;
            sign = true;
        } else if(string[i] == '.') {
            // e后面不能接小数点，小数点不能出现两次
            if(isE || decimal)
                return false;
            decimal = true;
        } else if (string[i] < '0' || string[i] > '9') // 不合法字符
            return false;
    }

    return true;
}
```



#### 3、字符流中第一个不相等的字符

​		请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

​		如果当前字符流没有存在出现一次的字符，返回#字符。

**解题：**

​		利用一个int型数组表示256个字符，这个数组初值置为0，遍历已给的字符串，计算出每个字符出现的次数，返回结果时直接从前往后遍历，返回第一个统计值为1的字符



```c
string str;
int flag[256];

//插入一个字符
void Insert(char ch)
{
    str += ch;
    flag[ch]++;
}

//返回字符串中第一个出现一次的字符
char FirstAppearingOnce()
{
    for(int i = 0; i < str.size(); i++) {
        if(flag[str[i]] == 1) {
            return str[i];
        }
    }

    return '#';
}

```



#### 4、构建乘积数组

​		给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）

**解题：**

​		题目读了好久才读懂的。题目意思可以简化成一个矩阵，左对角线上的值为除了该元素的其他值的乘积

<img src="https://uploadfiles.nowcoder.com/images/20160829/841505_1472459965615_8640A8F86FB2AB3117629E2456D8C652" alt="img" style="zoom: 25%;" />

那么改题的解可以理解为：先累乘下三角行的乘积，然后累乘上三角行的乘积，最后返回最终求的结果即可

```c
vector<int> multiply(const vector<int>& A) {
    int len = A.size();
    vector<int> res(len);     //累乘结果

    res[0] = 1;

    for(int i = 1; i < len; i++) {     //下三角行的乘积，累乘到res[i]行中
        res[i] = res[i-1]*A[i-1];
    }

    int t = 1;    //累乘变量
    for(int i = len-2; i >= 0; i--) {    //上三角行的乘积，累乘到res[i]行中
        t *= A[i+1];
        res[i] *= t;
    }

    return res;   //返回结果
}
```



#### 5、数组中重复的数字

​		在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

**解题：**

​		遍历数组时，利用map统计数字的次数，若大于1，返回结果

```c
bool duplicate(int numbers[], int length, int* duplication) {
    map<int,int> mp;

    for(int i = 0; i < length; i++) {
        mp[numbers[i]]++;
        if(mp[numbers[i]] > 1) {
            *duplication = numbers[i];
            return true;
        }
    }

    return false;
}
```



#### 6、把字符串转换为整数

​		将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0

**输入描述:**

```
输入一个字符串,包括数字字母符号,可以为空
```

**输出描述:**

```
如果是合法的数值表达则返回该数字，否则返回0
```

示例1

**输入**

```
+2147483647
1a33
```

**输出**

```
2147483647
0
```

**解题：**

​		模拟题，注意边界处理

```c
int StrToInt(string str) {
    int len = str.size();
    if(len == 0)
        return 0;

    int sum = 0,i;

    if(str[0] == '+' || str[0] == '-')
        i = 1;
    else
        i = 0;

    for(; i < len; i++) {
        if(!(str[i] >= '0' && str[i] <= '9'))
            return 0;
        else {
            if(str[0] != '-' && (INT_MAX - (sum*10)) < (str[i] - '0'))
                return 0;
            if((INT_MAX - (sum*10)) < (str[i] - '1'))
                return 0;
            sum = sum*10 + (str[i] - '0');
        }
    }
    if(str[0] == '+' || (str[0] >= '0' && str[0] <= '9'))
        return sum;
    else
        return sum * -1;
}
```



#### 7、孩子们的游戏（圆圈中最后剩下的数）

​		每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)

如果没有小朋友，请返回-1

**解题：**

​		**方法一：暴力**

​		通过构建圆圈数组，进行循环模拟移除，最后移除的数即为返回结果

```c
int LastRemaining_Solution(int n, int m)
{
    if(n < 1 || m < 1)
        return -1;

    int i = -1, count = n, t = 0;
    vector<int> num(n,1);

    while(count) {           //count为0时，num[i]为最后剩下的数
        i++;
        if(i >= n)
            i = 0;

        if(num[i] == 0)
            continue;
        t++;

        if(t == m) {
            num[i] = 0;
            count--;
            t = 0;
        }

    }

    return i;

}
```

**方法二：递推公式法**

​		f[1]=0;

​		f[i]=(f[i-1]+m)%i; (i>1)

```c
int LastRemaining_Solution(int n, int m)
{
    if(n < 1 || m < 1)
        return -1;

    if(n == 1)
        return 0;

    return (LastRemaining_Solution(n-1, m) + m) % n;

}
```





#### 8、扑克牌顺子

​		LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。

**解题：**

​		题意是，给定一个数组，判断数组的值是否在（1-13）直接连续，且数组中的0值可以变换为任意值

​		思路： max 记录 最大值；min 记录 最小值；满足条件 max - min  <5，除0外没有重复的数字(牌)，数组长度 为5

```c
bool IsContinuous( vector<int> numbers ) {
    int n = numbers.size();
    if(n == 0 || n < 5)
        return false;

    int maxn = -1, minn = 14;
    int num[14] = {0};

    for(int i = 0; i < n; i++) {
        if(numbers[i] == 0)
            continue;

        num[numbers[i]]++;
        if(num[numbers[i]] > 1)
            return false;

        if(numbers[i] > maxn)
            maxn = numbers[i];

        if(numbers[i] < minn)
            minn = numbers[i];
    }

    if(maxn - minn < 5)
        return true;
    return false;
}
```



#### 9、和为S的两个数字

​		输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。对应每个测试案例，输出两个数，小的先输出。

**解题：**

  由于数列满足递增，利用二分法可有效解该题 

  若array[left] + array[right] == sum，就是答案（相差越远乘积越小） 

  若array[left] + array[right]  >  sum，需要局部变小查找，right--

  若array[left] + array[right]  <  sum，需要局部变大查找，left++

```c
vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    int len = array.size();

    vector<int> res;
    int left = 0, right = len-1;

    while(left < right) {
        if(array[left] + array[right] == sum) {
            res.push_back(array[left]);
            res.push_back(array[right]);
            return res;
        }
        if(array[left] + array[right] > sum)
            right--;
        else
            left++;
    }

    return res;    //若没有匹配值，返回空res
}
```



#### 10、和为S的连续正数序列

​		小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

​		输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

**解题：**

​	**方法一：** 暴力，最容易想到的方法

```c
vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int> > res;

    if(sum == 0)
        return res;

    for(int i = 1; i <= sum/2; i++) {    //此处遍历范围为sum/2，因为后面的遍历没必要
        vector<int> t;
        t.push_back(i);
        int s = i,j = i+1;

        while(s < sum) {
            s += j;
            t.push_back(j);
            j++;
            if(s == sum)
                res.push_back(t);
            if(s > sum)
                break;
        }
    }

    return res;
}
```



​	**方法二：** 滑动窗口解题，利用两个指针进行滑动判断求解

```c
vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int> > res;

    if(sum < 2)
        return res;

    int slow = 1, fast = 2;

    while(slow < fast) {
        //利用等差数列求和公式求和
        int ant = (fast-slow+1)*(slow+fast)/2;

        if(ant == sum) {
            vector<int> t;
            for(int i = slow; i <= fast; i++) {
                t.push_back(i);
            }
            res.push_back(t);
            slow++;
        } else if(ant > sum)
            slow++;
        else
            fast++;          //需要注意的是，右指针也是右移
    }

    return res;
}
```



#### 11、数组中只出现一次的数字

​		一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

**解题：**

​		**方法一：**利用map进行统计，找到两个出现一次的数分别赋值给返回结果

```c
void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    map<int,int> mp;
    int n = data.size();

    for (int i = 0; i < n; i++) {
        mp[data[i]]++;
    }
    int t = 0;
    for (int i = 0; i < n; i++) {
        if(mp[data[i]] == 1) {
            if(t == 0) {
                *num1 = data[i];
                t = 1;
            }
            else {
                *num2 = data[i];
                break;
            }
        }

    }
}
```

​		**方法二：**利用亦或和按位与求解。两个相同的数^的结果一定为0，任何数与0^都得它本身，因此，所有数亦或后的值为两个不相同的数亦或的值

```c
void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    int n = data.size();

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum ^= data[i];
    }

    int index = 0;
    while((sum & 1) == 0) {       //寻找低位第一个为1 的位置
        index++;
        sum >>= 1;
    }

    *num1 = 0;
    *num2 = 0;

    for(int i = 0; i < n; i++) {
        if(( (data[i] >> index) & 1 ) == 0)
            *num1 ^= data[i];
        else
            *num2 ^= data[i];
    }

}
```



#### 12、丑数

​		把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

**解题：**

​		首先从丑数的定义我们知道，一个丑数的因子只有2,3,5，一个丑数一定由另一个丑数乘以2或者乘以3或者乘以5得到，那么我们从1开始乘以2,3,5，就得到2,3,5三个丑数，在从这三个丑数出发乘以2,3,5就得到4，6,10,6，9,15,10,15,25九个丑数，我们发现这种方式得到的有重复的丑数，而且我们题目要求第N个丑数，这样的方法得到的丑数也是无序的。那么我们可以维护三个队列：

```c
int GetUglyNumber_Solution(int index) {
    if(index < 7)
        return index;

    vector<int> arr(index);

    int p2 = 0, p3 = 0, p5 = 0;
    arr[0] = 1;

    for(int i = 1; i < index; i++) {
        //选出三个队列头最小的数
        int ugly = min(arr[p2]*2,min(arr[p3]*3,arr[p5]*5));

        arr[i] = ugly;

        if(arr[p2]*2 == ugly) p2++;   //更新队列维护的丑数
        if(arr[p3]*3 == ugly) p3++;
        if(arr[p5]*5 == ugly) p5++;
    }

    return arr[index-1];

}
```



#### 13、把数组排成最小的数

​		输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

**解题：**

​		先把数组排个序，只不过排序规则有自己定义，通过两数相加转成字符串比较

```c
string PrintMinNumber(vector<int> numbers) {
    string res = "";
    int len = numbers.size();

    if(len < 1)
        return res;

    sort(numbers.begin(),numbers.end(),cmp);

    for(int i = 0; i < len; i++) {
        res += to_string(numbers[i]);
    }

    return res;
}

static bool cmp(int a, int b) {             //重载排序的比较运算符
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);

    return ab < ba;
}
```



#### 14、连续子数组的最大和

​		HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

**解题：**

**方法一：循环维护最大和**

```c
int FindGreatestSumOfSubArray(vector<int> array) {
    int len = array.size();

    if(len < 1)
        return 0;

    int res = array[0];
    int sum = res;

    for(int i = 1; i < len; i++) {
        if(sum <= 0) {
            sum = array[i];
        } else {
            sum += array[i];
        }

        if(res < sum)
            res = sum;
    }

    return res;
}
```

**方法二：动态规划**

​	F（i）：以array[i]为末尾元素的子数组的和的最大值，子数组的元素的相对位置不变  

​    F（i）=max（F（i-1）+array[i] ， array[i]）  

​    res：所有子数组的和的最大值  

​    res=max（res，F（i））

```c
int FindGreatestSumOfSubArray(vector<int> array) {
    int len = array.size();

    if(len < 1)
        return 0;

    int res = array[0];
    int maxn = res;

    for(int i = 1; i < len; i++) {
        maxn = max(array[i],maxn+array[i]);   //子数组最大和
        res = max(res,maxn);   //更新最大值
    }

    return res;
}
```



#### 15、调整数组顺序使奇数位于偶数前面

​		输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

**解题：**

```c
/**
  i从左向右逐一遍历，为奇数则跳过，为偶数则执行下面语句。
  j从i+1开始向后找，直到找到第一个奇数。
  将[i,...,j-1]的元素整体后移一位，最后将找到的奇数放入i位置，然后i++。
  終止條件：j向后遍历查找失败（即j >= len）。
*/
void reOrderArray(vector<int> &array) {
    int len = array.size();

    for(int i = 0; i < len; i++) {
        if(array[i]%2 == 1)
            continue;
        else {
            int j = i+1;
            while(j < len && array[j] % 2 == 0)
                j++;
            if(j >= len)
                continue;
            int temp = array[j];
            for(; j > i; j--) {
                array[j] = array[j-1];
            }
            array[i] = temp;
        }
    }
}
```



#### 16、二维数组中的查找

​		在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

**解题：**从左下角往上查找，若该数大于查找的数，往上移动，小于要查找的数，则往右移动

```c
bool Find(int target, vector<vector<int> > array) {
    int leni = array.size();
    if(leni == 0)
        return false;

    int lenj = array[0].size();

    int i = leni-1;
    int j = 0;

    while(i >=0 && j < lenj) {
        if(array[i][j] == target)
            return true;
        else if(array[i][j] > target)
            i--;
        else
            j++;
    }

    return false;
}
```



### 六、二叉树

#### 1、二叉搜索树的第k个结点

​		给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）  中，按结点数值大小顺序第三小结点的值为4。

**解题：**

​		此题利用二叉搜索树的性质，使用中序遍历结果是有序的，中序遍历每一个结点存入数组，最后返回第k个结点即可，注意边界的处理

```c
vector<TreeNode*> res;   //存放二叉搜索树的每一个结点

TreeNode* KthNode(TreeNode* pRoot, int k)
{
    if(pRoot == NULL || k <= 0)         //若二叉树为空，或k<=0时返回NULL
        return NULL;

    midVisit(pRoot);     //中序遍历二叉树
    
    int len = res.size();     
    if(k > len)          //若第K个结点不存在，返回NULL
        return NULL;

    return res[k-1];     //下标从0开始，因此返回k-1
}

void midVisit(TreeNode* root){
    if(root == NULL)
        return;

    midVisit(root->left);

    res.push_back(root);

    midVisit(root->right);
}
```



#### 2、把二叉树打印成多行

​		从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

**解题：**

​		层次遍历二叉树，利用队列先进先出性质，按顺序访问每一层的每一个结点



```c
vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int> > res;

    if(pRoot == NULL)
        return res;

    queue<TreeNode*> que;
    que.push(pRoot);

    while(!que.empty()) {
        int n = que.size();
        vector<int> de;
        for(int i = 0; i < n; i++) {
            TreeNode* root = que.front();
            que.pop();
            de.push_back(root->val);

            if(root->left != NULL)
                que.push(root->left);
            if(root->right != NULL)
                que.push(root->right);
        }
        res.push_back(de);
    }
    return res;
}
```



#### 3、按Z字形顺序打印二叉树

​		请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

**解题：**

​		与层次遍历二叉树相似，利用队列先进先出性质，按顺序访问每一层的每一个结点。不同的是每隔一层需要反转后再加入结果集。

```c
vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int> > res;

    if(pRoot == NULL)
        return res;

    queue<TreeNode*> que;
    que.push(pRoot);

    int flag = 1;   // z字形遍历标记

    while(!que.empty()) {
        int n = que.size();
        vector<int> de;
        for(int i = 0; i < n; i++) {
            TreeNode* root = que.front();
            que.pop();
            de.push_back(root->val);

            if(root->left != NULL)
                que.push(root->left);
            if(root->right != NULL)
                que.push(root->right);
        }
        if(flag%2 == 1)        //模2为1时直接添加，为0时需要先反转后再加入res 
            res.push_back(de);
        else
            reverse(de.begin(),de.end()),res.push_back(de);

        flag++;
    }
    return res;

}
```



#### 4、对称的二叉树

​		请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

**解题：**

​		利用递归方法，首先根节点以及其左右子树，左子树的左子树和右子树的右子树比较，左子树的右子树和右子树的左子树比较:

​		情况1：若左右同时为NULL，返回true

​		情况2：若左右有一个为NULL，返回false

​		情况3：若左右值不相等，返回false

```c
bool isSymmetrical(TreeNode* pRoot)
{
    if(pRoot == NULL)
        return true;

    return judge(pRoot->left,pRoot->right);
}

bool judge(TreeNode* left, TreeNode* right) {
    if(left == NULL && right == NULL)  //若左右同时为NULL，返回true
        return true; 

    if(left == NULL || right == NULL)   //若左右有一个为NULL，返回false
        return false;

    if(left->val != right->val)     //若左右值不相等，返回false
        return false;

    //递归：左子树的左子树和右子树的右子树比较，左子树的右子树和右子树的左子树比较
    return judge(left->left,right->right) && judge(left->right,right->left);
}
```



#### 5、二叉树的下一个结点

​		给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

**解题：**

​		当节点为空时，直接返回

​		当右节点存在时，返回右节点的最左结点

​		当右节点不存在时，向上寻找公共父节点

```c
TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    if(pNode == NULL)
        return NULL;

    if(pNode->right != NULL)
    {
        pNode = pNode->right;
        while(pNode->left != NULL) {
            pNode = pNode->left;
        }
        return pNode;
    }

    while(pNode->next != NULL) {
        TreeLinkNode* node = pNode->next;
        if(pNode == node->left)
            return node;
        pNode = pNode->next;
    }

    return NULL;
}
```



#### 6、平衡二叉树

​		输入一棵二叉树，判断该二叉树是否是平衡二叉树。在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树

**解题：**

​		题目意思就是，左右子树的高的绝对值要小于等于1

​		此题通过递归求解

**解法一：**遍历每个结点，借助一个获取树深度的递归函数，根据该结点的左右子树高度差判断是否平衡，然后递归地对左右子树进行判断。

```c
bool IsBalanced_Solution(TreeNode* pRoot) {
    if(pRoot == NULL)
        return true;

    return abs(getDeep(pRoot->left)-getDeep(pRoot->right)) <= 1 
        && IsBalanced_Solution(pRoot->left)   //递归地对左右子树进行判断
        && IsBalanced_Solution(pRoot->right);
}

int getDeep(TreeNode* root) {    //获取树深度的递归函数
    if(root == NULL)
        return 0;

    return max(getDeep(root->left),getDeep(root->right))+1;
}
```

此方法会导致重复遍历大量的结点，效率不是很好

**解法二：**从下往上遍历，如果子树是平衡二叉树，则返回子树的高度；如果发现子树不是平衡二叉树，则直接停止遍历，这样至多只对每个结点访问一次。

```c
bool IsBalanced_Solution(TreeNode* pRoot) {
    if(pRoot == NULL)
        return true;

    return getDeep(pRoot) != -1;
}

int getDeep(TreeNode* root) {
    if(root == NULL)
        return 0;

    int left = getDeep(root->left);
    if(left == -1)
        return -1;

    int right = getDeep(root->right);
    if(right == -1)
        return -1;

    return abs(left-right) > 1 ? -1 : max(left,right)+1;
}
```



#### 7、二叉树的深度

​		输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

**题解：**

​		递归比较求解

```c
int TreeDepth(TreeNode* pRoot)
{
    if(pRoot == NULL)
        return 0;

    return max(TreeDepth(pRoot->left)+1,TreeDepth(pRoot->right)+1);
}
```



#### 8、二叉搜索树与双向链表

​		输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

**解题：**利用中序遍历，同时定义两个中间节点进行调整指向

```c
TreeNode* tail = NULL;   //指向链表末尾
TreeNode* realHead = NULL;  //指向链表开头
TreeNode* Convert(TreeNode* pRootOfTree)
{
    if(pRootOfTree == NULL)
        return NULL;

    Convert(pRootOfTree->left);     //左节点

    if(realHead == NULL) {          //中间节点处理
        realHead = pRootOfTree;
    } else {
        tail->right = pRootOfTree;
        pRootOfTree->left = tail;
    }
    tail = pRootOfTree;
    
    Convert(pRootOfTree->right);     //右节点

    return realHead;   //返回结果
}
```



#### 9、二叉树和为某一值的路径

​		输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

**解题：**利用递归方法，同时定义全局变量，将满足条件的路径加入到结果集

```c
vector<vector<int> > res;    //存放路径的结果集
vector<int> t;   //单个路径
vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    find(root,expectNumber);
    return res;
}

void find(TreeNode* root, int target) {
    if(root == NULL)
        return;

    t.push_back(root->val);

    if(target-root->val == 0 && root->left == NULL && root->right == NULL) {
        res.push_back(t);
    } else {
        if(root->left)
            find(root->left, target-root->val);
        if(root->right)
            find(root->right, target-root->val);
    }
    t.pop_back();
}
```



#### 10、二叉搜索树的后序遍历序列

​		输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

**解题：**利用递归方法；因为二叉搜索树的最后一个值为根节点，我们只需要从后往前找到比根节点大的最后一个节点位置，利用二分递归判断即可

```c
bool VerifySquenceOfBST(vector<int> sequence) {
    int len = sequence.size();

    if(len < 1)
        return false;

    return judge(sequence,0,len-1);
}

bool judge(vector<int> a, int left, int right) {
    if(left >= right)     //左右重合时返回true
        return true;

    int i = right-1;

    while(a[i] > a[right]) i--;   //从后往前找到比根节点大的最后一个节点位置

    for(int j = i; j >= left; j--) {    //若前面有比根节点大的值即返回false
        if(a[j] > a[right])
            return false;
    }

    return judge(a, left, i) && judge(a, i+1, right-1);
}
```



#### 11、二叉树的镜像

​		操作给定的二叉树，将其变换为源二叉树的镜像。

```
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
```

**解题：**递归实现，遍历每个不为空的结点，交换它的两个子节点，把交换后的结点重新调用递归函数，当交换完所有的结点的左右子结点之后，就得到了树的镜像

```c
void Mirror(TreeNode *pRoot) {
    if(pRoot == NULL)
        return;

    TreeNode *temp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = temp;

    Mirror(pRoot->left);
    Mirror(pRoot->right);
}
```



#### 12、二叉树的子结构

​		输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

**解题：**

```
1、首先设置标志位res = false，因为一旦匹配成功res就设为true，剩下的代码不会执行，如果匹配不成功，默认返回false
2、递归思想，如果根节点相同则递归调用judge(TreeNode *root1, TreeNode *root2)，如果根节点不相同，则调用HasSubtree判断pRoot1的左子树和pRoot2是否相同，若不同，则再判断pRoot1右子树和pRoot2是否相同
3、在judge函数中，如果root2为空，则说明第二棵树遍历完了，即匹配成功，root1为空有两种情况
（1）如果root1为空，root2不为空，说明不匹配，
（2）如果root1为空，root2为空，说明匹配。
我们只须将root2放前面判断即可
```

```c
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if(pRoot2 == NULL || pRoot1 == NULL)
        return false;

    bool res = false;

    if(pRoot1->val == pRoot2->val) {   //若根节点等于目标结点，则向下判断
        res = judge(pRoot1,pRoot2);
    }

    if(!res) {     //利用左子树于目标树判断
        res = HasSubtree(pRoot1->left, pRoot2);
    }

    if(!res) {    //利用右子树于目标树判断
        res = HasSubtree(pRoot1->right, pRoot2);
    }

    return res;  //返回最终结果
}

bool judge(TreeNode *root1, TreeNode *root2) {
    if(root2 == NULL)   //若root2遍历完，返回true
        return true; 
    if(root1 == NULL)   //若root1遍历完，root2确还没有遍历完，则返回false
        return false;

    if(root1->val != root2->val)   //若其中有一个结点不相等，返回false
        return false;

    return judge(root1->left, root2->left) && judge(root1->right, root2->right);
}
```



#### 13、重建二叉树

​		输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

**解题：**利用递归，前序首个结点根节点，在中序遍历中的位置左边的元素为左左分支的结点，右边元素为根节点右边分支的结点，然后用递归以同样的方式构建二叉树

```c
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    TreeNode* root = build(pre,0,pre.size()-1,vin,0,vin.size()-1);
    return root;
}

TreeNode* build(vector<int> pre,int ps,int pe,vector<int> vin,int ms,int me) {
    if(ps > pe || ms > me)
        return NULL;

    TreeNode* root = new TreeNode(pre[ps]);

    for(int i = ms; i <= me; i++) {  //找到前序首节点在中序遍历中的位置i
        if(vin[i] == pre[ps]) { 
            root->left = build(pre, ps+1, ps+i-ms, vin, ms, i);
            root->right = build(pre, ps+i-ms+1, pe, vin, i+1, me);
            break;
        }
    }

    return root;
}
```



### 七、链表题

#### 1、删除链表中的重复结点

​		在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

**解题：**

​		建立头结点，以方便碰到第一个与第二个节点就相同的情况；

​		设置 pre ，last 指针， pre指针指向当前确定不重复的那个节点，而last指针用于往后遍历判断；

```c
ListNode* deleteDuplication(ListNode* pHead)
{
    if(pHead == NULL || pHead->next == NULL)
        return pHead;

    ListNode* head = new ListNode(0);     //建立头结点
    head->next = pHead;

    ListNode* pre = head;          //当前确定不重复结点，用于直接指向
    ListNode* last = pHead;		  //用于遍历判断的结点

    while(last != NULL) {
        if(last->next != NULL && last->val == last->next->val) {
            while(last->next != NULL && last->val == last->next->val) {
                last = last->next;
            }
            pre->next = last->next;
            last = last->next;
        } else {
            pre = pre->next;       //改变当前确定不重复结点
            last = last->next;
        }
    }
    return head->next;            //返回结果为头结点的下一个结点
}
```



#### 2、链表中环的入口结点

​		给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

**解题：**

​		利用环的特性，建立快慢指针：fast、slow， fast每次移动两个结点，slow每次移动一个结点，若链表存在环，则fast与last指针一定会相遇，此时任意一个结点回到头结点（如slow=pHead），然后再与fast指针并进，每次移动一个结点，直到指针相遇时，即是环的最终入口。

​		大伙们只需在纸上画一下模拟一遍就能很快的理解了。



```c
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if(pHead == NULL || pHead->next == NULL || pHead->next->next == NULL)
        return NULL;

    ListNode *fast = pHead->next->next, *slow = pHead->next;

    while(fast != slow) {
        if(fast->next == NULL || fast->next->next == NULL)
            return NULL;
        fast = fast->next->next;
        slow = slow->next;
    }

    slow = pHead;
    while(fast != slow) {
        fast = fast->next;
        slow = slow->next;c
    }

    return fast;
}
```



#### 3、链表的第一个公共结点

​		输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）

**解题：**

​	**解法一：**用两个指针扫描”两个链表“，最终两个指针到达 null 或者到达公共结点。

- 长度相同情况：

  有公共结点，第一次就遍历到；

  没有公共结点，走到尾部NULL相遇，返回NULL

- 长度不同情况：

  有公共结点，第一遍差值就出来了，第二遍一起到公共结点；

  没有公共，一起到结尾NULL。

```c
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;

    while (p1 != p2) {
        p1 = (p1 == NULL) ? pHead2 : p1->next;
        p2 = (p2 == NULL) ? pHead1 : p2->next;
    }
    return p1;
}
```



​	**解法二：** 先求出链表的长度，若相等，则直接循环比较；若不相等，则让长的链表先遍历（较长链表的长度减去较短链表长度）个结点，如何循环比较。若没有相等的结点，即返回NULL。此处利用的是若结点相等后，则后面的结点都会相等。

```C
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    int len1 = getLength(pHead1);
    int len2 = getLength(pHead2);

    if(len1 > len2) {
        pHead1 = iterat(pHead1,len1-len2);
    }
    if(len1 < len2) {
        pHead2 = iterat(pHead2,len2-len1);
    }

    while(pHead1) {
        if(pHead1 == pHead2)
            return pHead1;
        pHead1 = pHead1->next;
        pHead2 = pHead2->next;
    }

    return NULL;
}

ListNode* iterat(ListNode* p, int n) {   //遍历链表n个结点
    while(n--) {
        p = p->next;
    }
    return p;
}

int getLength(ListNode* p) {    //求链表的长度
    if(p == NULL)
        return 0;
    int len = 0;
    while(p) {
        len++;
        p = p->next;
    }

    return len;
}
```



#### 4、合并两个排序链表

​		输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

**解题：**简单模拟，两个链表比较

```c
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == NULL)
        return pHead2;
    if(pHead2 == NULL)
        return pHead1;

    ListNode* res = pHead1;

    if(pHead1->val > pHead2->val) {
        res = pHead2;
        pHead2 = pHead2->next;
    } else {
        pHead1 = pHead1->next;
    }
    ListNode* t = res;

    while(pHead1 && pHead2) {
        if(pHead1->val <= pHead2->val) {
            t->next = pHead1;
            t = pHead1;
            pHead1 = pHead1->next;
        } else {
            t->next = pHead2;
            t = pHead2;
            pHead2 = pHead2->next;
        }
    }

    if(pHead1)
        t->next = pHead1;
    else
        t->next = pHead2;

    return res;
}
```



#### 5、反转链表

输入一个链表，反转链表后，输出新链表的表头。

**解题：**简单模拟，使用两个指针

```c
ListNode* ReverseList(ListNode* pHead) {
    if(pHead == NULL)
        return pHead;

    ListNode* pre = NULL;
    ListNode* next = NULL;

    while(pHead) {
        next = pHead->next;
        pHead->next = pre;
        pre = pHead;
        pHead = next;
    }

    return pre;
}
```



#### 6、链表中的倒数第K个结点

输入一个链表，输出该链表中倒数第k个结点。

**解题：**使用两个指针，快指针先走k-1步，然后两个指针同时先后移动，当快指针到达末尾时，慢指针即是倒数第k个结点，需要注意边界的处理

```c
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if(pListHead == NULL || k == 0)
        return NULL;

    ListNode* fast = pListHead;
    ListNode* slow = pListHead;

    while(--k) {
        if(fast->next)
            fast = fast->next;
        else //若K的值大于当前链表的长度，返回NULL
            return NULL;
    }

    while(fast->next && slow->next) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}
```



#### 7、从未到头打印链表

输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

**解题：**使用数组存储，返回翻转后的数组

```c
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> res;

    if(head ==  NULL)
        return res;

    while(head) {
        res.push_back(head->val);
        head = head->next;
    }

    reverse(res.begin(),res.end());

    return res;
}
```



### 八、字符串

#### 1、翻转单词序列

​		牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

**解题：**

​		基础模拟题，从后往前遍历

```c
string ReverseSentence(string str) {
    int len = str.size();
    if(len < 2)
        return str;

    string res = "";

    for(int i = len-1; i >= 0;) {
        if(str[i] != ' ')
            i--;
        else {
            int j = i+1;
            while(str[j] != ' ' && j < len) {
                res += str[j];
                j++;
            }
            while(str[i] == ' ') {
                res += str[i];
                i--;
            }
        }
    }
	//开头单词并还未加入res
    for(int i = 0; str[i] != ' ' && i < len; i++) {  
        res += str[i];
    }

    return res;
}
```



#### 2、左旋转字符串

​		汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

**解题：**

​		给定一个字符串，从位置n处切断进行翻转链接，类似一个环，返回某个点切开后的结果

**解法一：** 连接两个str，返回从位置n开始，长度为原始str长度大小个字符；

```c
string LeftRotateString(string str, int n) {
    int len = str.size();
    if(n == 0 || n == len)
        return str;

    if(n > len)
        return "";

    str += str;

    return str.substr(n,len);
}
```

**解法二：** 找到位置n, 拼接结果n~en  + 0~n

```c
string LeftRotateString(string str, int n) {
    int len = str.size();
    if(n == 0 || n == len)
    return str;
    string res = "";

    if(n > len)
    return res;

    res += str.substr(n,len);
    res += str.substr(0,n);

    return res;
}
```



#### 3、第一个只出现一次的字符串

​		在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）

**解题：**

​	利用map进行统计

```c
int FirstNotRepeatingChar(string str) {
    int len = str.size();

    map<char,int> mp;

    for(int i = 0; i < len; i++) {
        mp[str[i]]++;
    }

    for(int i = 0; i < len; i++) {
        if(mp[str[i]] == 1)
            return i;
    }

    return -1;
}
```



#### 4、替换空格

​		请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

**解题：**定义一个数组，若目标数组为字符，则直接赋值，若为空格，赋值%20

```c
void replaceSpace(char *str,int length) {
    char ch[200];
    int k = 0;
    for (int i = 0; i < length; i++) {
        if(str[i] != ' ')
            ch[k++] = str[i];
        else
        {
            ch[k++] = '%';
            ch[k++] = '2';
            ch[k++] = '0';
        }
    }
    ch[k] = '\0';
    strcpy(str,ch);   //字符串的复制库函数
}
```



### 九、按位题（&，|，^）

#### 1、不用加减乘除做加法

​		写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

**解题：**

​		此题利用按位操作符解题：

​		^亦或符：两者同为0或1为0，不同则为1

​		&按位与： 两者同为1为1，不同则为0

​		| 按位或： 有一者为1则为1，否则为0

**此题利用：**

m = 亦或求得两数不需进位的结果

n = 按位与求得需要进位的结果后再左移一位得到最终进位值

循环以上两步，最终n值一定会变为0

举例：5 + 7 = 12               

一轮：m = 2    n = 10     

二轮：m = 8    n = 4  

 三轮：m = 12   n = 0  

```c
int Add(int num1, int num2)
{
    while(num2 != 0) {
        int m = num1 ^ num2;
        int n = (num1 & num2) << 1;

        num1 = m;
        num2 = n;
    }

    return num1;

}
```



#### 2、整数中二进制为1的个数

​		输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。

**解题：**位运算

方法一：用标记数1，自身左移运算（32次，变为0为止），每次和n进行位与，来判断1的个数

```c
int  NumberOf1(int n) {

	int count = 0,flag = 1;
    while (flag != 0) {
        if ((n & flag) != 0) {
            count++;
        }
        flag = flag << 1;
    }
    return count;
}
```



方法二：利用 n & (n-1) 来统计1 的位数

```c
int  NumberOf1(int n) {
    int count = 0;
    while(n != 0) {
        count++;
        n = n & (n-1);
    }
    return count;
}
```

