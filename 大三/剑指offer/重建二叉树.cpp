#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
    int inlen=in.size();
    if(inlen==0)
        return NULL;

    vector<int> left_pre,right_pre,left_in,right_in;

    //�������ڵ㣬���ڵ�϶���ǰ������ĵ�һ����
    TreeNode* head=new TreeNode(pre[0]);

    //�ҵ�����������ڵ�����λ��,����ڱ���gen��
    int gen=0;
    for(int i=0;i<inlen;i++)
    {
        if (in[i]==pre[0])
        {
            gen=i;
            break;
        }
    }

    //����������������ڵ���ߵĽڵ�λ�ڶ���������ߣ����ڵ��ұߵĽڵ�λ�ڶ��������ұ�
    //����������㣬�Զ������ڵ���й鲢
    for(int i=0;i<gen;i++)
    {
        left_in.push_back(in[i]);
        left_pre.push_back(pre[i+1]);//ǰ���һ��Ϊ���ڵ�
    }

    for(int i=gen+1;i<inlen;i++)
    {
        right_in.push_back(in[i]);
        right_pre.push_back(pre[i]);
    }

    //��shell�����˼�����ƣ�ȡ��ǰ�������������ڵ���ߺ��ұߵ�����
    //�ݹ飬�ٶ�������������в��裬��������������������������ֱ��Ҷ�ڵ�
    head->left=reConstructBinaryTree(left_pre,left_in);
    head->right=reConstructBinaryTree(right_pre,right_in);

   return head;
}

void prin(TreeNode *tree)
{
    if(tree == NULL)
        return;
    cout << tree->val << "  ";
    prin(tree->left);
    prin(tree->right);

}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int m,s;
        cin >> m;
        vector<int> pre;
        vector<int> vin;
        for(int i = 0; i < m; i++) {
            cin >> s;
            pre.push_back(s);
        }
        for(int i = 0; i < m; i++) {
            cin >> s;
            vin.push_back(s);
        }
        TreeNode *tree = reConstructBinaryTree(pre,vin);
        prin(tree);
    }
    return 0;
}
