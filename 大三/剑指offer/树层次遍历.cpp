#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> res;
    queue<TreeNode* > q;

    if(root != NULL) {
        res.push_back(root->val);
        if(root->left != NULL)
            q.push(root->left);
        if(root->right != NULL)
            q.push(root->right);
    }

    while(!q.empty()){
        TreeNode* p = q.front();
        q.pop();
        res.push_back(p->val);
        if(p->left != NULL)
            q.push(p->left);
        if(p->right != NULL)
            q.push(p->right);
    }
    return res;
}

int main()
{
    int n,m,t;
    cin >> n;
    while (n--) {

    }
    return 0;
}

