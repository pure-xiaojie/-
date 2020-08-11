## LeetCode题目分类

#### **Hash相关**

##### [q1_两数之和](https://leetcode-cn.com/problems/two-sum/)

```c
vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;

        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            if(m.find(target-nums[i]) != m.end()) {
                res.push_back(m[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            m[nums[i]] = i;
        }
        return res;
    }
```



#### **链表操作**

##### [q2_两数相加](https://leetcode-cn.com/problems/add-two-numbers/)

```c
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //因为数已经为翻转的，直接相加
        ListNode* res = NULL;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        int x = l1->val + l2->val;
        l1 = l1->next;
        l2 = l2->next;

        ListNode* q = new ListNode(x%10);
        res = q;
        x /= 10;
		
    	//两个链表都不为空
        while(l1 && l2) {
            x += l1->val + l2->val;
            ListNode* p = new ListNode(x%10);
            x /= 10;
            q->next = p;
            q = p;
            l1 = l1->next;
            l2 = l2->next;
        }
   		//当l2为空，则结果指向l1，注意前期进位x  例如：l1:1->9  l2:9
        if(l1) {
            q->next = l1;
            while(x && l1) {
                q = l1;
                x += l1->val;
                l1->val = x%10;
                l1 = l1->next;
                x /= 10;
            }
        }
    	//当l1为空，则结果指向l2，注意前期进位x   例如：l1:1  l2:9->9
        if(l2) {
            q->next = l2;
            while(x && l2) {
                q = l2;
                x += l2->val;
                l2->val = x%10;
                l2 = l2->next;
                x /= 10;
            }
        }
    	//最后检查进位x情况，若x不为0，新建一个节点并指向它
        if(x) {
            ListNode* p = new ListNode(x%10);
            q->next = p;
        }
        return res;
    }
```

```c
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* p = res;

        int k = 0;

        while(l1 || l2 || k) {
            if(l1 != NULL) {
                k += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                k += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(k%10);
            k /= 10;
            p = p->next;
        }
        return res->next;
    }
```



##### [q19_删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

利用快慢指针，快指针想走N步，然后和慢指针同时往后移动

当快指针的next为空时，删除慢指针的下一个结点即可

```c
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        if(n == 0)
            return head;
            
        while(n--) {
            fast = fast->next;
        }

        if(fast == NULL)
            return head->next;

        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return head;
    }
```



##### [q61_旋转链表]()

```c
ListNode* rotateRight(ListNode* head, int k) {
    if(k == 0 || head == NULL || head->next == NULL)
        return head;
    //计算链表的长度
    ListNode* p = head;
    int len = 0;
    while(p) {
        len++;
        p = p->next;
    }

    k %= len;   //确定截取的位置

    if(k == 0)  //表示不用旋转
        return head;

    p = head;    //遍历到第K个结点
    while(k < len) {
        k++;
        p = p->next;
    } 
    ListNode* node = p;
    ListNode* res = p;   //结果集

    while(p->next) {
        p = p->next;
    }
    p->next = head;

    while(head->next != node) {
        head = head->next;
    }
    head->next = NULL;

    return res;
}
```



##### [q138_复制带随机指针的链表]()

原地复制，然后抽取复制的结点

```c
Node* copyRandomList(Node* head) {
    if(head == NULL)
        return head;

    //原链表中复制每个结点在原节点后
    Node* p = head;
    while(p) {
        Node* temp = new Node(p->val);
        temp->next = p->next;
        p->next = temp;
        p = temp->next;
    }

    //复制随机指针
    p = head;
    while(p) {
        if(p->random != NULL) {
            p->next->random = p->random->next;  //p->random->next 为复制后的结点
        }
        p = p->next->next;
    }

    //抽取结果
    Node* s = head;
    Node* res = new Node(0);
    p = res;
    while(s) {
        p->next = s->next;
        p = p->next;
        s->next = s->next->next;
        s = s->next;
    }

    return res->next;
}
```

利用map

```c
Node* copyRandomList(Node* head) {
    if(head == NULL)
        return head;

    map<Node*,Node*> hash;   //存储每一个结点
    Node* p = head;          
    while(p) {
        Node* temp = new Node(p->val);
        hash[p] = temp;
        p = p->next;
    }

    p = head;     //根据原链表的指向，改变复制后结点的指向
    while(p) {
        hash[p]->next = hash[p->next];
        hash[p]->random = hash[p->random];
        p = p->next;
    }

    return hash[head];   //返回结果
}
```



##### [q206_反转链表](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)

迭代法

```c
ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;

    ListNode* pre = NULL;
    ListNode* p = head;
    ListNode* next = NULL;

    while(p) {
        next = p->next;
        p->next = pre;
        pre = p;
        p = next;
    }

    return pre;
}
```



#### **双指针遍历/滑动窗口**

##### [q3_无重复字符的最长子串]()

滑动窗口，通过两个指针移动判断

```c
int lengthOfLongestSubstring(string s) {
    int len = s.size();

    if(len == 0 || len == 1)
        return len;

    unordered_map<char,int> window;
    int left = 0, right = 0;
    int res = 0;

    while(right < len) {
        char ch = s[right];
        window[ch]++;
        right++;

        while(window[ch] > 1) {
            char d = s[left];
            left++;
            window[d]--;
        }

        res = max(res,right-left);
    }
    return res;
}
```



##### [q11_盛最多水的容器]()

```c
int maxArea(vector<int>& height) {
    int left = 0, right = height.size()-1;
    int res = 0;

    while(left < right) {
        int h = min(height[left],height[right]);  //两边整体高度，去较小值
        int w = right - left;   //长度

        res = max(res,h*w);     //保存面积较大者

        if(height[left] < height[right])  
            left++;
        else
            right--;
    }

    return res;
}
```



##### [q15_三数之和]()

```c
vector<vector<int>> threeSum(vector<int>& nums) {
    int sum;
    vector<vector<int>> res;

    sort(nums.begin(),nums.end());

    for(int i = 0; i < nums.size(); i++) {
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        sum = nums[i];
        if(sum > 0)
            break;

        int l = i+1, r = nums.size()-1;

        while(l < r) {
            if(nums[l] + nums[r] + sum > 0)
                r--;
            else if(nums[l] + nums[r] + sum < 0)
                l++;
            else {
                res.push_back({sum, nums[l], nums[r]});
                l++;
                r--;
                while(l < r && nums[l] == nums[l-1]) l++;
                while(r > l && nums[r] == nums[r+1]) r--;
            }
        }

    }
    return res;
}
```



##### [q16_最接近的三数之和]()

##### [q26_删除排序数组中的重复项]()

##### [q42_接雨水]()

##### [q121_买卖股票的最佳时机]()

##### [q209_长度最小的子数组]()





#### **快慢指针遍历**

##### [q141_环形链表]()

##### [q202_快乐数]()

##### [q876_链表的中间结点]()

#### **区间合并**

##### [q56_合并区间]()

#### **字符串操作**

##### [q6_Z字形变换]()

##### [q14_最长公共前缀]()

##### [q763_划分字母区间]()





#### **数字操作**

##### [q7_整数反转]()

```c
int reverse(int x) {
    if(x == 0)
        return x;

    long long res = 0;

    while(x) {
        res = res * 10  + x % 10;        //正负都可以处理

        if(res > INT_MAX || res < INT_MIN)  //如果溢出，直接返回0
            return 0;

        x /= 10;
    }

    return res;
}
```



##### [q8_字符串转换整数]()

```c
int myAtoi(string str) {
    int len = str.size();
    if(len < 1)
        return 0;

    int i = 0;  //过滤开头空格
    while(i < len && str[i] == ' ')
        i++;

    int flag = 0;    //记录负号
    if(str[i] == '-') {
        flag = 1;
        i++;
    }
    else if(str[i] == '+')
        i++;

    if(!(str[i] >= '0' && str[i] <= '9'))  //判断开头是否为其它字符
        return 0;


    long long res = 0;

    for(int j = i; j < len; j++) {
        if(!(str[j] >= '0' && str[j] <= '9'))
            break;

        int num = str[j] - '0';

        res = res * 10  + num;        //累计结果

        if(flag && (-1*res) < INT_MIN)  //当数值为负，如果溢出，直接返回INT_MIN
            return INT_MIN;

        if(!flag && res > INT_MAX)    //当数值为正，如果溢出，直接返回INT_MIN
            return INT_MAX;

    }

    return flag ? -1*res : res;
}
```



##### [q9_回文数]()



##### [q43_字符串相乘]()



##### [q172_阶乘后的零]()



##### [q258_各位相加]()





#### **数组操作**

- [q54_螺旋矩阵](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E6%95%B0%E7%BB%84%E6%93%8D%E4%BD%9C/q54_%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5)
- [q73_矩阵置零](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E6%95%B0%E7%BB%84%E6%93%8D%E4%BD%9C/q73_%E7%9F%A9%E9%98%B5%E7%BD%AE%E9%9B%B6)
- [q945_使数组唯一的最小增量](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E6%95%B0%E7%BB%84%E6%93%8D%E4%BD%9C/q945_%E4%BD%BF%E6%95%B0%E7%BB%84%E5%94%AF%E4%B8%80%E7%9A%84%E6%9C%80%E5%B0%8F%E5%A2%9E%E9%87%8F)

#### **栈相关**

- [q20_有效的括号](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E6%A0%88%E7%9B%B8%E5%85%B3/q20_%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7)
- [q32_最长有效括号](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E6%A0%88%E7%9B%B8%E5%85%B3/q32_%E6%9C%80%E9%95%BF%E6%9C%89%E6%95%88%E6%8B%AC%E5%8F%B7)
- [q155_最小栈](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E6%A0%88%E7%9B%B8%E5%85%B3/q155_%E6%9C%80%E5%B0%8F%E6%A0%88)
- [q224_基本计算器](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E6%A0%88%E7%9B%B8%E5%85%B3/q224_%E5%9F%BA%E6%9C%AC%E8%AE%A1%E7%AE%97%E5%99%A8)
- [q316_去除重复字母](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E6%A0%88%E7%9B%B8%E5%85%B3/q316_%E5%8E%BB%E9%99%A4%E9%87%8D%E5%A4%8D%E5%AD%97%E6%AF%8D)

#### **堆相关**

- [q215_数组中的第K个最大元素](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%A0%86%E7%9B%B8%E5%85%B3/q215_%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E7%AC%ACK%E4%B8%AA%E6%9C%80%E5%A4%A7%E5%85%83%E7%B4%A0)
- [q347_前K个高频元素](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%A0%86%E7%9B%B8%E5%85%B3/q347_%E5%89%8DK%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0)

#### **递归**

- [q21_合并两个有序链表](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E9%80%92%E5%BD%92/q21_%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%9C%89%E5%BA%8F%E9%93%BE%E8%A1%A8)
- [q101_对称二叉树](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E9%80%92%E5%BD%92/q101_%E5%AF%B9%E7%A7%B0%E4%BA%8C%E5%8F%89%E6%A0%91)
- [q104_二叉树的最大深度](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E9%80%92%E5%BD%92/q104_%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%A4%A7%E6%B7%B1%E5%BA%A6)
- [q226_翻转二叉树](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E9%80%92%E5%BD%92/q226_%E7%BF%BB%E8%BD%AC%E4%BA%8C%E5%8F%89%E6%A0%91)
- [q236_二叉树的最近公共祖先](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E9%80%92%E5%BD%92/q236_%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88)

#### **分治法/二分法**

- [q23_合并K个排序链表](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%88%86%E6%B2%BB%E6%B3%95/q23_%E5%90%88%E5%B9%B6K%E4%B8%AA%E6%8E%92%E5%BA%8F%E9%93%BE%E8%A1%A8)
- [q33_搜索旋转排序数组](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%88%86%E6%B2%BB%E6%B3%95/q33_%E6%90%9C%E7%B4%A2%E6%97%8B%E8%BD%AC%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84)
- [q34_在排序数组中查找元素的第一个和最后一个位置](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%88%86%E6%B2%BB%E6%B3%95/q34_%E5%9C%A8%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E6%9F%A5%E6%89%BE%E5%85%83%E7%B4%A0%E7%9A%84%E7%AC%AC%E4%B8%80%E4%B8%AA%E5%92%8C%E6%9C%80%E5%90%8E%E4%B8%80%E4%B8%AA%E4%BD%8D%E7%BD%AE)

#### **动态规划**

- [q5_最长回文子串](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/q5_%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2)
- [q53_最大子序和](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/q53_%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C)
- [q62_不同路径](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/q62_%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84)
- [q64_最小路径和](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/q64_%E6%9C%80%E5%B0%8F%E8%B7%AF%E5%BE%84%E5%92%8C)
- [q70_爬楼梯](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/q70_%E7%88%AC%E6%A5%BC%E6%A2%AF)
- [q118_杨辉三角](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/q118_%E6%9D%A8%E8%BE%89%E4%B8%89%E8%A7%92)
- [q300_最长上升子序列](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/q300_%E6%9C%80%E9%95%BF%E4%B8%8A%E5%8D%87%E5%AD%90%E5%BA%8F%E5%88%97)
- [q746_使用最小花费爬楼梯](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/q746_%E4%BD%BF%E7%94%A8%E6%9C%80%E5%B0%8F%E8%8A%B1%E8%B4%B9%E7%88%AC%E6%A5%BC%E6%A2%AF)
- [q1277_统计全为1的正方形子矩阵](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/q1277_%E7%BB%9F%E8%AE%A1%E5%85%A8%E4%B8%BA1%E7%9A%84%E6%AD%A3%E6%96%B9%E5%BD%A2%E5%AD%90%E7%9F%A9%E9%98%B5)

#### **回溯法**

- [q10_正则表达式匹配](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%9B%9E%E6%BA%AF%E6%B3%95/q10_%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F%E5%8C%B9%E9%85%8D)
- [q22_括号生成](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%9B%9E%E6%BA%AF%E6%B3%95/q22_%E6%8B%AC%E5%8F%B7%E7%94%9F%E6%88%90)
- [q46_全排列](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E5%9B%9E%E6%BA%AF%E6%B3%95/q46_%E5%85%A8%E6%8E%92%E5%88%97)

#### **树的遍历**

- [q94_二叉树的中序遍历](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E6%A0%91%E7%9A%84%E9%81%8D%E5%8E%86/q94_%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86)
- [q102_二叉树的层次遍历](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E6%A0%91%E7%9A%84%E9%81%8D%E5%8E%86/q102_%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E6%AC%A1%E9%81%8D%E5%8E%86)
- [q110_平衡二叉树](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E6%A0%91%E7%9A%84%E9%81%8D%E5%8E%86/q110_%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91)
- [q144_二叉树的前序遍历](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E6%A0%91%E7%9A%84%E9%81%8D%E5%8E%86/q144_%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86)
- [q145_二叉树的后序遍历](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E6%A0%91%E7%9A%84%E9%81%8D%E5%8E%86/q145_%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86)

#### **二叉搜索树相关**

- [q98_验证二叉搜索树](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9B%B8%E5%85%B3/q98_%E9%AA%8C%E8%AF%81%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91)
- [q450_删除二叉搜索树中的节点](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9B%B8%E5%85%B3/q450_%E5%88%A0%E9%99%A4%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9)
- [q701_二叉搜索树中的插入操作](https://link.zhihu.com/?target=https%3A//github.com/yuanguangxin/LeetCode/tree/master/src/%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9B%B8%E5%85%B3/q701_%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E6%8F%92%E5%85%A5%E6%93%8D%E4%BD%9C)



#### **深搜遍历**

##### [q130_被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)

```c
void solve(vector<vector<char>>& board) {
    int leni = board.size();
    if(leni <= 1)
        return;

    int lenj = board[0].size();

    for(int i = 0; i < leni; i++) {
        if(board[i][0] == 'O')
            dfs(board,i,0);
        if(board[i][lenj-1] == 'O')
            dfs(board,i,lenj-1);
    }

    for(int i = 1; i < lenj-1; i++) {
        if(board[0][i] == 'O')
            dfs(board,0,i);
        if(board[leni-1][i] == 'O')
            dfs(board,leni-1,i);
    }

    for(int i = 0; i < leni; i++) {
        for(int j = 0; j < lenj; j++) {
            if(board[i][j] == '*')
                board[i][j] = 'O';
            else if(board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}

void dfs(vector<vector<char>>& board, int i, int j) {
    int leni = board.size();
    int lenj = board[0].size();
    if(i < 0 || i >=leni || j < 0 || j >= lenj || board[i][j] == 'X' || board[i][j] == '*')
        return;

    if(board[i][j] == 'O')
        board[i][j] = '*';

    dfs(board,i,j+1);
    dfs(board,i,j-1);
    dfs(board,i+1,j);
    dfs(board,i-1,j);
} 
```



#### **广搜遍历**