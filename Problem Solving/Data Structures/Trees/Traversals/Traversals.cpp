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

/* you only have to complete the function given below.  
Node is defined as  

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
    // preOder through recursion
    void preOrder(Node *root) {
        if (root == nullptr)
            return;
        
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    // preOrder through iteration
    void preOrder(Node *root) {
        if (root == nullptr) return;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node* curr = s.top();
            cout << curr->data << " ";
            s.pop();
            if(curr->right != nullptr) s.push(curr->right);
            if(curr->left != nullptr) s.push(curr->left);
        }
    }

    // postOrder through recursion
    void postOrder(Node *root) {
        if (root == nullptr)
            return;
        
        preOrder(root->left);
        preOrder(root->right);
        cout << root->data << " ";
    }

    // postOrder through iteration
    void postOrder(Node *root) {
        if ( root == nullptr) return;
        stack<Node*> s;
        Node* curr = root;
        while(curr != nullptr or !s.empty()){
            if( curr != nullptr){
                s.push(curr);
                curr = curr->left;
            }
            else{
                Node* temp = s.top() -> right;
                if (temp == nullptr){
                    temp = s.top();
                    cout << temp->data << " ";
                    s.pop();
                    while(!s.empty() and temp == s.top()->right){
                        temp = s.top();
                        s.pop();
                        cout << temp->data << " ";
                    }
                }
                else 
                    curr = temp;
            }
        }
    }

    // inorder through recursion
    void inOrder(Node *root) {
        if (root == nullptr)
            return;
        
        preOrder(root->left);
        cout << root->data << " ";
        preOrder(root->right);
    }

    // inorder through iteration
    void inOrder(Node *root) {
        if (root == nullptr) return;
        stack<Node*> s;
        Node* curr = root;
        while(true){
            if(curr != nullptr){
                s.push(curr);
                curr= curr->left;
            }
            else{
                if(s.empty()) break;
                curr = s.top();
                s.pop();
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }


    void levelOrder_traverse(Node * root) {
        if (root == nullptr)
            return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; ++i){
                Node* curr = q.front();
                cout << curr->data << " ";
                q.pop();
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right); 
            }
        }
    }


    void traverse_2d_array(vector<vector<int>> v){
        for(int i = 0; i < v.size(); ++i){
            for(int j = 0; j < v[i].size(); ++j){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }


    vector<vector<int>> levelOrder_traversal(Node* root){
        vector<vector<int>> ans;
        if(root == nullptr) return ans; 
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; ++i){
                Node* curr = q.front();
                q.pop();
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
                level.push_back(curr->data);
            }
            ans.push_back(level);
        }
        return ans;
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
  
	myTree.preOrder(root);
    return 0;
}
