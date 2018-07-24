/*******************
* 7/24
*******************/

// 根据前序和中序重建二叉树

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* _Re(vector<int>& pre,int start_pre,int end_pre,
                 vector<int>& vin,int start_in,int end_in) {
        if (start_pre > end_pre)    
            return NULL;
        TreeNode* cur = new TreeNode(pre[start_pre]);
        int count = 0;  
        for (int i=start_in; i<end_in; i++) {
            if(vin[i] == pre[start_pre])
                break;
            count++;
        }
        cur->left = _Re(pre,start_pre+1,start_pre+count,vin,start_in,start_in+count-1);
        cur->right = _Re(pre,start_pre+count+1,end_pre,vin,start_in+count+1,end_in);
        
        return cur;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() != vin.size())
            return NULL;
        TreeNode* root = _Re(pre,0,pre.size()-1,vin,0,vin.size()-1);
        return root;
    }
};