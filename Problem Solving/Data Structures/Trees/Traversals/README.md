Complete the  function in the editor below, which has  parameter: a pointer to the root of a binary tree. It must print the values in the tree's preorder traversal as a single line of space-separated values.

Input Format

Our test code passes the root node of a binary tree to the preOrder function.

Constraints

 Nodes in the tree 

Output Format

Print the tree's preorder traversal as a single line of space-separated values.

Sample Input

     1
      \
       2
        \
         5
        /  \
       3    6
        \
         4  
Sample Output

1 2 5 3 4 6 
Explanation

The preorder traversal of the binary tree is printed.

Language
C++11
More
135363738394041424344454647484950515253545556575859606162
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = inse…             cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
…        if (root == nullptr)
            return;
        
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

}; //End of Solution










Line: 82 Col: 1

Test against custom input
Congratulations!

You have passed the sample test cases. Click the submit button to run your code against all the test cases.


Sample Test case 0

Sample Test case 1
Input (stdin)
6
1 2 5 3 6 4
Your Output (stdout)
1 2 5 3 4 6 
Expected Output
1 2 5 3 4 6 
