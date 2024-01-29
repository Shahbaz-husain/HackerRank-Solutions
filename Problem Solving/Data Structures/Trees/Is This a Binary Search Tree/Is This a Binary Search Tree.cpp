/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
    
*/
    bool isBSTUtil(Node* node, int min, int max) {
        if (node == nullptr)
            return true;
        
        // node data should not be less than min or greater then max as it will break the rule of having smaller data on the left and bigger data on the right
        if (node->data < min || node->data > max)
            return false;

        return isBSTUtil(node->left, min, node->data - 1) &&
               isBSTUtil(node->right, node->data + 1, max);
    }

    bool checkBST(Node* root) {
        return isBSTUtil(root, 0, 100001);
    }