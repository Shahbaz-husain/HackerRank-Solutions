#include<bits/stdc++.h>

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

/*
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

*/

    void topView(Node * root) {
        if (!root)  return;
        
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* curr = it.first;
            int line = it.second;
            
            if(mp.find(line) == mp.end()) mp[line] = curr->data;
            
            if(curr->left) q.push({curr->left, line-1});
            if(curr->right) q.push({curr->right, line+1});
        }
        
        for (auto it : mp){
            cout << it.second << " ";
        }

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
  
	myTree.topView(root);
    return 0;
}
