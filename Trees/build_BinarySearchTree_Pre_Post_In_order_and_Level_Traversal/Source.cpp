#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include<queue>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};

Node* buildTree(Node *root) {
    int data;
    fin >> data;

    root = new Node(data);

    if (data == -1) {
        return NULL;
    }

        // creating the left subtree 
        root->left = buildTree(root->left);

        // creating the right substree
        root->right = buildTree(root->right);
        return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        fout << temp-> data << " ";
        q.pop();

        if (temp->left) {
            q.push(temp->left);
        }
        
        if (temp->right) {
            q.push(temp->right);
        }
    }
}

// LNR
void inOrderTraversal(Node* root) {
    
   
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    fout << root->data << " ";
    inOrderTraversal(root->right);

}

// NLR
void preTraversal(Node* root) {


    if (root == NULL)
        return;

    fout << root->data << " ";
    preTraversal(root->left);
    preTraversal(root->right);

}

// LRN
void postTraversal(Node* root) {


    if (root == NULL)
        return;

    postTraversal(root->left);
    postTraversal(root->right);
    fout << root->data << " ";

}



// height of a tree
int height(Node* node) {
    if (node == NULL) return 0;

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right) + 1;
    return ans;

}

int helper(Node* root){
    if(root == NULL) return 0;
    
    int left =  1 + helper(root->left);
    int right = 1 + helper(root->right);
    return max(left, right);
}

int maxDepth(Node* root){
    if(root == NULL) return 0;

    int left =  1 + helper(root->left);
    int right = 1 + helper(root->right);
    return max(left, right);
}

int main()
{        
    Node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    levelOrderTraversal(root);
    fout << endl;
    inOrderTraversal(root);
    fout << endl;
    preTraversal(root);
    fout << endl;
    postTraversal(root);
    
    fout<<"--------"<<endl;
    Node *root2 = NULL;
    root = buildTree(root2);
    // 2 1 -1 -1 3 4 -1 -1 -1
    int h = height(root);
    fout << "height: "<< h<<endl;
    int d = maxDepth(root);
    fout << "max depth: "<< d<<endl;


    fin.close();
    fout.close();
    return 0;

}
