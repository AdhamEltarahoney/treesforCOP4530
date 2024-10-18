// Trees
#include <iostream>
#include <queue>
#include <stack>

using namespace std;


class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    //declare a constructor
    TreeNode(int value) : data(value), left(nullptr), right(nullptr){}
};
// [left ptr   data    rightptr]

class Tree{
private:
    TreeNode *root;
    void dfsHelper(TreeNode *node) const;
    int countLeafNodesHelper(TreeNode *node) const;

public:
    Tree();
    void setRoot(int value);
    TreeNode* getRoot() const;

    void addLeftChild(TreeNode* parent, int value);
    void addRightChild(TreeNode* parent, int value);

    void preOrderTraversalHelper(TreeNode *node) const;
    void preOrderTraversal() const;

    void postOrderTraversalHelper(TreeNode *node) const;
    void postOrderTraversal() const;

    void inOrderTraversalHelper(TreeNode *node) const;
    void inOrderTraversal() const;

    void bfs() const;// level order traversal
    int countLeafNodes() const;

    ~Tree();
};
//constructor
Tree :: Tree() : root(nullptr){}

//setting the root
void Tree::setRoot(int value){
    root = new TreeNode(value);
}

//getting the pointer to the root
TreeNode* Tree :: getRoot() const{
    return root;
}

void Tree :: addLeftChild(TreeNode* parent, int value){    
     if (parent->left){
        cout<<"left child already exists";
        return;
    } 
    if (parent){
        parent->left = new TreeNode(value);
    }
}
 
void Tree :: addRightChild(TreeNode* parent, int value){  
    if (parent->right){
        cout<<"right child already exists";
        return;
    } 
    if (parent){
        parent->right = new TreeNode(value);
    }

}
 void Tree :: preOrderTraversalHelper(TreeNode *node) const{
    if (node == nullptr){
        return;
    }
    cout<<node->data<<" ";
    preOrderTraversalHelper(node->left);
    preOrderTraversalHelper(node->right);


 }

void Tree :: preOrderTraversal() const{
    cout<<"This is preorder: ";
    preOrderTraversalHelper(root);
    cout<<endl;
}


void Tree :: postOrderTraversalHelper(TreeNode *node) const{
    if (node == nullptr){
        return;
    }
    postOrderTraversalHelper(node->left);
    postOrderTraversalHelper(node->right);
    cout<<node->data<<" ";
}


void Tree :: postOrderTraversal() const{
    cout<<"This is post order: ";
    postOrderTraversalHelper(root);
    cout<<endl;
}

void Tree :: inOrderTraversalHelper(TreeNode *node) const{
    if (node == nullptr){
        return;
    }
    inOrderTraversalHelper(node->left);
    cout<<node->data<< " ";
    inOrderTraversalHelper(node->right);
}

void Tree :: inOrderTraversal() const{
    cout<<"This is in order: ";
    inOrderTraversalHelper(root);
    cout<<endl;
}

void Tree :: bfs() const{
    if (root == nullptr){
        return;
    }
    queue<TreeNode*> q;

    q.push(root);
    cout<<"BFS Traversal: ";

    while (!q.empty()){
        TreeNode *current = q.front();
        q.pop();

        cout<<current->data<<" ";
        if (current->left){
            q.push(current->left);
        }
         if (current->right){
            q.push(current->right);
        }
    }
    cout<<endl;
}

int Tree :: countLeafNodesHelper(TreeNode *node) const{
    if (node == nullptr){
        return 0;
    }

    if (node->left == nullptr && node->right == nullptr){
        return 1;
    }

    return countLeafNodesHelper(node->left) + countLeafNodesHelper(node->right);
}

int Tree :: countLeafNodes() const{
    return countLeafNodesHelper(root);
}

Tree :: ~Tree(){
    delete root;
} 



int main() {
    // Create the tree
    Tree tree;
    tree.setRoot(1);  // Root node

    // Adding left and right children to build a binary tree
    TreeNode* root = tree.getRoot();
    tree.addLeftChild(root, 2);
    tree.addRightChild(root, 3);

    tree.addLeftChild(root->left, 4);  // Adding children to node 2
    tree.addRightChild(root->left, 5);

    tree.addLeftChild(root->right, 6);  // Adding children to node 3
    tree.addRightChild(root->right, 7);

    // Perform preorder traversal
    tree.preOrderTraversal();// 1,2,4,5,3,6,7
    tree.postOrderTraversal();//4,5,2,6,7,3,1
    tree.inOrderTraversal();//4,2,5,1,6,3,7
    tree.bfs();//1,2,3,4,5,6,7s

    //          1
    //     2          3
    //  4    5      6   
    int x = tree.countLeafNodes();
    cout<<"The number of leaf nodes are "<<x<<endl;

    return 0;
}













