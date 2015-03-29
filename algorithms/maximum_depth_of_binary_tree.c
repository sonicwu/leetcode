#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	 int val;
	 struct TreeNode *left;
	 struct TreeNode *right;
};

int maxDepth(struct TreeNode *root) {
    if (!root)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
  
    if (leftDepth > rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}

struct TreeNode* newTree(int val) {
    // init struct's pointer (to avoid segmentation fault)
    struct TreeNode* tree = (struct TreeNode*) malloc(sizeof(struct TreeNode));;
    
    tree->val = val;
    tree->left = NULL;
    tree->right = NULL;
  
    return(tree);
}

int main() {
    struct TreeNode* root = newTree(1);
    root->left = newTree(2);
    root->right = newTree(3);
    root->left->left = newTree(4);

    printf("%d\n", maxDepth(root));
}