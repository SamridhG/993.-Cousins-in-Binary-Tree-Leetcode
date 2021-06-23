/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode* root,int x)
    {
        if(root!=NULL)
        {
            queue<TreeNode *>A;
            A.push(root);
            A.push(NULL);
            int k=-1;
            while(!A.empty())
            {
                TreeNode *p=A.front();
                A.pop();
                if(p!=NULL && p->val==x)
                {
                    return k+1;
                }
                if(p==NULL)
                {
                    A.push(NULL);
                    k++;
                }
                if(p!=NULL && p->left!=NULL)
                {
                    A.push(p->left);
                }
                if(p!=NULL && p->right!=NULL)
                {
                    A.push(p->right);
                }
            }
        }
                    return -1;
    }
    TreeNode* parent(TreeNode *root,int x)
    {
         if(root!=NULL)
        {
            queue<TreeNode *>A;
            A.push(root);
            while(!A.empty())
            {
                TreeNode *p=A.front();
                A.pop();
                if(p->left!=NULL && p->left->val==x)
                {
                    return p;
                }
                if(p->right!=NULL && p->right->val==x)
                {
                    return p;
                }
                 if(p->left!=NULL)
                {
                    A.push(p->left);
                }
                if(p->right!=NULL)
                {
                    A.push(p->right);
                }
              
            }
             
        }
        return root;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int depthx=depth(root,x);
        int depthy=depth(root,y);
        if(depthy==depthx)
         {
             if(parent(root,x)!=parent(root,y))
             {
                 return true;
             }
         }
        else
        {
            return false;
        }
        return false;
    }
};
