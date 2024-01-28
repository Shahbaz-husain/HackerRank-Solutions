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
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    // helping function to fetch the path to the root
    bool getPath(Node* root, vector<Node*>& v, int v1){
        if(!root) return false;
        
        v.push_back(root);
        if(root->data == v1) return true;
        
        if(getPath(root->left, v, v1) or getPath(root->right, v, v1))
            return true;
        v.pop_back();
        return false;
    }
    Node *lca(Node *root, int v1,int v2) {
		if(!root) return root;
        
        vector<Node*> p1;
        vector<Node*> p2;
        
        getPath(root, p1, v1);
        getPath(root, p2, v2);
        
        int i = 0;
        Node* lastMatch = root;
        while(i < p1.size() and i < p2.size() and p1[i] == p2[i]){
            lastMatch = p1[i];
            i++;
        }
        return lastMatch;
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
