#include<bits/stdc++.h>

using namespace std;

//链表节点
struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x),next(NULL) {

    }
};

//链表遍历
ListNode* iterat(ListNode* p, int n) {
    while(n--) {
        p = p->next;
    }
    return p;
}

//获取链表的长度
int getLength(ListNode* p) {
    if(p == NULL)
        return 0;
    int len = 0;
    while(p) {
        len++;
        p = p->next;
    }

    return len;
}

//链表的比较，获取公共结点
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


int main()
{
    ListNode *p1, *p2, *q1, *q2;

    int n = 5,t;
    cin >> t;
    q1 = new ListNode(t);
    p1 = q1;
    q2 = q1;

    while(n--) {
        cin >> t;
        q1 = new ListNode(t);
        q2->next = q1;
        q2 = q1;

        if(n == 2)
            p2 = q1;
    }

    ListNode *head = FindFirstCommonNode(p1,p2);
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
