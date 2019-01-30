#include <stdio.h>
#include <stdlib.h>
typedef struct avl_node avl_node;


struct avl_node{
    int item;
    avl_node left;
    avl_node right;
    int height;
}
avl_node* new_node(int data){
    avl_node* new = malloc(sizeof avl_node);
    new->left = NULL;
    new->right = NULL;
    new->height = 1;
    return new;
}
int height(struct avl_node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 
  
// A utility function to get maximum of two integers 
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
  

avl_node* insertion(avl_node* root, int data){

    // normal insertion
    if(root== NULL){
        return new_node(data);
    }
    else if( data < root->item){
        root->left = insertion(root->left,item);
    }
    else if( data > root->item){
        root->right = insertion(root->right,item);
    }
    else 
        return root;

    // balence regained
    root->height = 1 + max(height(root->left), 
                           height(root->right)); 
    int balence = root->left->height - root->right->height;


    if(balence >1 ){// left is heavier
        if( data < root->left->item){
            // left-left
            return right_rotate(root);
        }else{
            // left- right
            root->left= left_rotate(root->left);
            return right_rotate(root);
        }

    }
    if(balence <-1){
        if(data> root->right->item)//rr case
        return left_rotate(root)
        else {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }
    }
    return node;



}
avl_node* right_rotate(avl_node* root){
    if(root == NULL)return;
    if(root->left == NULL)return ;
    avl_node* new_root =root->left;
    root->left = new_root->right;
	new_root->right = root;
    root->height = max(root->right->height,root->left->height)+1;
    new_root->height = max(new_root->right->height,new_root->left->height)+1;
	return new_root;

}

avl_node* left_rotate(avl_node* root){
    if(root == NULL)return;
    if(root->right == NULL)return ;
    avl_node* new_root =root->right;
    root->right = new_root->left;
	new_root->left = root;
    root->height = max(root->right->height,root->left->height)+1;
    new_root->height = max(new_root->right->height,new_root->left->height)+1;
	return new_root;

}








