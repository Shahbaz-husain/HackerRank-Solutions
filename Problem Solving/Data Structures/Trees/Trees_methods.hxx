#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include "Binary_tree.hxx"

using namespace std;

void preOrder_traversal_recursion(Node<int>* root){
    if( root == nullptr)
        return;
    cout << root->data << endl;
    preOrder_traversal_recursion(root->left);
    preOrder_traversal_recursion(root->right);  
}

void preOrder_traversal_iteration(Node<int> *root) {
    if (root == nullptr) return;
    stack<Node<int>*> s;
    s.push(root);
    while(!s.empty()){
        Node<int>* curr = s.top();
        cout << curr->data << " ";
        s.pop();
        if(curr->right != nullptr) s.push(curr->right);
        if(curr->left != nullptr) s.push(curr->left);
    }
}


void inOrder_traversal_recursion(Node<int>* root){
    if( root == nullptr)
        return;
    inOrder_traversal_recursion(root->left);
    cout << root->data << endl;
    inOrder_traversal_recursion(root->right);  
}

void inOrder_traversal_iteration(Node<int> *root) {
    if (root == nullptr) return;
    stack<Node<int>*> s;
    Node<int>* curr = root;
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

void postOrder_traversal_recursion(Node<int>* root){
    if( root == nullptr)
        return;
    postOrder_traversal_recursion(root->left);
    postOrder_traversal_recursion(root->right);  
    cout << root->data << endl;
}

void postOrder_traversal_iteration(Node<int> *root) {
    if ( root == nullptr) return;
    stack<Node<int>*> s;
    Node<int>* curr = root;
    while(curr != nullptr or !s.empty()){
        if( curr != nullptr){
            s.push(curr);
            curr = curr->left;
        }
        else{
            Node<int>* temp = s.top() -> right;
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

void levelOrder_traverse(Node<int>* root) {
    if (root == nullptr)
        return;
    queue<Node<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; ++i){
            Node<int>* curr = q.front();
            cout << curr->data << " ";
            q.pop();
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right); 
        }
    }

}

void zig_zag_traversal(Node<int>* root){
    if( root == nullptr) return;

    queue<Node<int>*> q;
    q.push(root);

    bool leftToRight = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);
        for(int i = 0 ; i < size; ++i){
            Node<int>* curr = q.front();
            q.pop();
            int index = leftToRight ? i : size-i-1;
            level[index] = curr->data;
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);
        }
        leftToRight = !leftToRight;
        for(int i = 0 ; i < size; i++)
        {
            cout << level[i] << endl;
        }
    }
    cout << endl;
}

void traverse_2d_array(vector<vector<int>> v){
    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < v[i].size(); ++j){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> levelOrder_traversal(Node<int>* root){
    vector<vector<int>> ans;
    if(root == nullptr) return ans; 
    queue<Node<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; ++i){
            Node<int>* curr = q.front();
            q.pop();
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);
            level.push_back(curr->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int height_of_tree(Node<int>* root){
    if(root == nullptr)
        return 0;
    
    int lh = height_of_tree(root->left);
    int rh = height_of_tree(root->right);

    return max(lh, rh) + 1;
}


int max_edges_in_height_of_tree(Node<int>* root){
    if(root == nullptr)
        return -1;
    
    int lh = max_edges_in_height_of_tree(root->left);
    int rh = max_edges_in_height_of_tree(root->right);

    return 1 + max(lh, rh);
}

int dfsHeight(Node<int>* root){
    if(root == nullptr)
        return 0;
    
    int lh = dfsHeight(root->left);
    if (lh == -1)  return -1;

    int rh = dfsHeight(root->right);
    if (rh == -1)  return -1;

    if(abs(lh - rh) > 1) return -1;
    return max(lh, rh) + 1;
}

bool check_balance(Node<int>* root){
    return dfsHeight(root) != -1;
}


int diameter(Node<int>* root, int& dia){
    if (root == nullptr) return 0;

    int lh = diameter(root->left, dia);
    int rh = diameter(root->right, dia);

    dia = max(dia, lh+rh);

    return 1 + max(lh,rh);
}

int width(Node<int>* root){
    if (root == nullptr) return 0;

    queue<Node<int>*>  q;
    q.push(root);
    int maxW = 0;
    while(!q.empty()){
        int size = q.size();
        maxW = max(maxW, size);
        for(int i = 0; i < size; ++i){
            Node<int>* curr = q.front();
            q.pop();
            if(curr -> left != nullptr) q.push(curr->left);
            if(curr -> right != nullptr) q.push(curr->right);
        }
    }
    return maxW;
}

int maxPathSum(Node<int>* node, int& maxSum)
{
    if(node == nullptr) return 0;

    int leftSum = maxPathSum(node->left, maxSum);
    int rightSum = maxPathSum(node->right, maxSum);

    maxSum = max(maxSum, node->data + leftSum + rightSum);

    return node->data + max(leftSum, rightSum);
}


bool identical(Node<int>* root1, Node<int>* root2){
    if(root1 == nullptr or root2==nullptr)
        return root1 == root2;
    
    return (root1->data == root2->data) and identical(root1->left , root2->left) and identical(root1->right , root2->right);
}


bool isLeaf(Node<int>* node)
{
    return node->left == nullptr and node->right == nullptr;
}

void addLeftBoundary(Node<int>* root , vector<int>& v){
    Node<int>* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) v.push_back(curr->data);
        if(curr->left != nullptr) curr = curr->left;
        else curr = curr->right;
    }
}

void addRightBoundary(Node<int>* root , vector<int>& v){
    Node<int>* curr = root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right != nullptr) curr = curr->right;
        else curr = curr->left;
    }
    for(int i = temp.size()-1; i >= 0 ; --i){
        v.push_back(temp[i]);
    }
}

void addLeaves(Node<int>* root, vector<int>& v){
    if(isLeaf(root)){
        v.push_back(root->data);
        return;
    }
    if(root -> left)  addLeaves(root->left, v);
    if(root -> right)  addLeaves(root->right, v);
}


void boundary_traversal(Node<int>* root){
    vector<int> v;
    if(!root) return ;
    if(!isLeaf(root)) v.push_back(root->data);
    addLeftBoundary(root, v);
    addLeaves(root, v);
    addRightBoundary(root, v);

    for(int i = 0 ; i < v.size(); ++i)
    {
        cout << v[i] << endl;
    }
    cout << endl;
}

void topView(Node<int>* root){
    if (!root) return ;
    map<int,int> mp;
    // first member will the node and second will be the vertical
    queue<pair<Node<int>*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node<int>* curr = it.first;
        int line = it.second;

        if(mp.find(line) == mp.end()) mp[line] = curr ->data;

        if(curr->left) q.push({curr->left,line-1}); 
        if(curr->right) q.push({curr->right,line+1}); 
    }

    for(auto it : mp){
        cout << it.second << endl;
    }
}

bool showPathRecursion(Node<int>* root, vector<int>& v, int data){
    if(!root) return false;
    v.push_back(root->data);
    if(root->data == data)
        return true;
    
    if(showPathRecursion(root->left, v, data) or showPathRecursion(root->right, v, data))
        return true;
    
    v.pop_back();
    return false;
}

void showPath(Node<int>* root, int data){
    if(!root) return;

    vector<int> v;
    showPathRecursion(root, v, data);
    
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
}

bool getPathRecursion(Node<int>* root, vector<Node<int>*>& v, int data){
    if(!root) return false;
    v.push_back(root);
    if(root->data == data)
        return true;
    
    if(getPathRecursion(root->left, v, data) or getPathRecursion(root->right, v, data))
        return true;
    
    v.pop_back();
    return false;
}

Node<int>* getCommonAncestor(Node<int>* root, int a, int b){
    if(!root) return root;
    vector<Node<int>*> v1;
    vector<Node<int>*> v2;
    getPathRecursion(root, v1, a);
    getPathRecursion(root, v2, b);

    Node<int>* lastMatch = root;
    int i = 0;

    while(i < v1.size() and i < v2.size() and v1[i] == v2[i]){
        lastMatch = v1[i];
        i++;
    }

    return lastMatch;
}

// space complexity = O(h)
// time complexity : worst = O(n) , average = O(logn)
Node<int>* insertion_recursion(Node<int>* root, int data){
    if(!root) return new Node<int>(data);

    if(data<root->data)
        root->left = insertion_recursion(root->left, data);
    else if(data>root->data)
        root->right = insertion_recursion(root->right, data);

    return root;
}

// space complexity = O(1)
// time complexity : worst = O(n) , average = O(logn)
Node<int>* insertion_iteration(Node<int>* root, int data){
    Node<int>* new_node = new Node<int>(data);
    if(!root) 
        root = new_node;
    else{
        Node<int>* curr = root;
        Node<int>* parent = nullptr;
        while(curr){
            parent = curr;
            if(curr->data > data)
                curr = curr->left;
            else
                curr = curr->right;
        }

        if (parent->data < data)
            parent->right = new_node;
        else
            parent->left = new_node;
    }

    return root;
}