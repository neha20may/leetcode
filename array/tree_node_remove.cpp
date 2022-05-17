//
// Created by neha2 on 09-05-2022.
//


bool traverse(TreeNode *node, int k){
    if(node== nullptr)
        return true;

    if(node->left== nullptr && node->right== nullptr){
        if(node->val ==k){
            return true;
        }
        return false;
    }else{
        //non leaf node
        //traverse the tree
        /**
         *         a
         *     /       \
         *     c(!k)   b(k) (true)
         */
        bool leftresult= traverse(node->left, k);
        bool rightresult= traverse(node->right, k);

        if(node->val==k && leftresult && rightresult){
            node->left= nullptr;
            node->right= nullptr;
            return true;
        }else if(leftresult){
            node->left= nullptr;
        }else if(rightresult){
            node->right= nullptr;
        }
        return false;

    }

}