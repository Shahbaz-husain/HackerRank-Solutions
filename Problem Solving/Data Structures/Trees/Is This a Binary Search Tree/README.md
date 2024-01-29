For the purposes of this challenge, we define a binary tree to be a binary search tree with the following ordering requirements:

The  value of every node in a node's left subtree is less than the data value of that node.
The  value of every node in a node's right subtree is greater than the data value of that node.
Given the root node of a binary tree, can you determine if it's also a binary search tree?

Complete the function in your editor below, which has  parameter: a pointer to the root of a binary tree. It must return a boolean denoting whether or not the binary tree is a binary search tree. You may have to write one or more helper functions to complete this challenge.

Input Format

You are not responsible for reading any input from stdin. Hidden code stubs will assemble a binary tree and pass its root node to your function as an argument.

Constraints

Output Format

You are not responsible for printing any output to stdout. Your function must return true if the tree is a binary search tree; otherwise, it must return false. Hidden code stubs will print this result as a Yes or No answer on a new line.

Sample Input

tree

Sample Output

No
30
/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  
31
​
32
The Node struct is defined as follows:
33
    struct Node {
34
        int data;
35
        Node* left;
36
        Node* right;
37
    }
38
    
39
*/
40
    bool isBSTUtil(Node* node, int min, int max) {
41
        if (node == nullptr)
42
            return true;
43
        
44
        // node data should not be less than min or greater then max as it will break the rule of having smaller data on the left and bigger data on the right
45
        if (node->data < min || node->data > max)
46
            return false;
47
​
48
        return isBSTUtil(node->left, min, node->data - 1) &&
49
               isBSTUtil(node->right, node->data + 1, max);
50
    }
51
​
52
    bool checkBST(Node* root) {
53
        return isBSTUtil(root, 0, 100001);
54
    }
Line: 31 Col: 1
Run Code Submit CodeUpload Code as File Test against custom input
