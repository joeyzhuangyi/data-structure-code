#include <stdio.h>
typedef struct btree btree;
typedef btree* Btree;

struct btree{
    Btree left;
    Btree right;
    int item;
};


btree* right_rotate(btree* root){
    if(root == NULL)return;
    if(root->left == NULL)return ;
    btree* new_root =root->left;
    root->left = new_root->right;
	new_root->right = root;
	return new_root;

}

btree* left_rotate(btree* root){
    if(root == NULL)return;
    if(root->right == NULL)return ;
    btree* new_root =root->right;
    root->right = new_root->left;
	new_root->left = root;
	return new_root;

}
Btree splay(Btree node, int item){
    if(node == NULL)return NULL;
    if(node->item == item) return node;

    if(node->item > item){
    // left of the current root
        if( node->left == NULL)return root;
        if( root->left->item > item){
            // LL case
            root->left->left = splay(root->left->left,item);
            root = right_rotate(root);
        }else if (root->left->item < item){
            // LR case
            root->left->right= splay(root->left->right,item);
            root->left= left_rotate(root->left);
        }
        // now that the element is left next to the node
        return right_rotate(root);
    }else ( node->item < item){
        if( node->right == NULL)return root;
        if( root->right->item < item){
            // RR case
            root->right->right = splay(root->right->right,item);
            root = left_rotate(root);
        }else if (root->right->item > item){
            // RL case
            root->right->left= splay(root->right->left,item);
            root->right= right_rotate(root->right);
        }
        // now that the element is right next to the node
        return left_rotate(root);
    }



}