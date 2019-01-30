


Btree partition(Btree node, size_t k){

    if(node== NULL)return NULL;
    if(node->size == k)return node;
    size_t lsize= node->left== NULL?0: node->left->size;
    if( lsize <k){
        node->left = partition(node->left,k);
        node = right_rotate(node);


    }
    else if (lsize >k){
        node->right = partition(node->rightk,k-lsize-1);
        node= left_rotate(node);

    }
    return tree;




}




Btree balence (Btree node){
    if(node == NULL)return NULL;
    node = partition(node,(node->size)/2);
    node->right = balence(node->right);
    node->left = balence(node->left);
}