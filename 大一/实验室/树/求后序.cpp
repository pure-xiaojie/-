#include<iostream>
using namespace std;

struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    char elem;
};


TreeNode* PostOrderFromOrderings(char* inorder, char* preorder, int length)
{
    if(length == 0)
    {
        return NULL;
    }
    TreeNode* node = new TreeNode;
    node->elem = *preorder;
    int rootIndex = 0;
    for(; rootIndex < length; rootIndex++)  // 求左子树的长度
    {
        if(inorder[rootIndex] == *preorder)
            break;
    }
    node->left = PostOrderFromOrderings(inorder, preorder + 1, rootIndex);
    node->right = PostOrderFromOrderings(inorder + rootIndex + 1, preorder + rootIndex + 1, length - (rootIndex + 1));
    cout << node->elem << " ";   // 求后序序列，所以最后输出根结点
    return node;
}


int main()
{
    char* pre = "ABDECFG";
    char* in = "DBEAFCG";
    PostOrderFromOrderings(in, pre, 7);
    cout << endl;
    return 0;
}

