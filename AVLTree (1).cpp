//AVL tree
//Self balance binary tree
//Self balance by using left and right rotation to maintain, time complexity of log n in worst
//Time complexity: Searching, insert, remove take O(Log n) in worst
//Rotation time complexity: O(1)
//Space complexity: O(n)

//AVL tree is more balance compare to Red Black Tree, but require more rotation during insert and remove
//If insert and remove is more frequent, choose Red Black Tree
//If search is more frequent, choose AVL Tree

#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    int height; //Height of the node, the number of edge to furthest child node
    int bf; //Balance Factor the height difference of left right node
    Node* left;
    Node* right;
    Node(int d): data{d}, left{nullptr}, right{nullptr}, height{0}, bf{0} {}
};

void update(Node *root){
    int lh = -1, rh = -1; //Initialize height of left and right
    if(root->left != nullptr) 
        lh = root->left->height; //get height of left child
    if(root->right != nullptr) 
        rh = root->right->height; //get height of right child
    root->height = 1+max(lh, rh); //Current height is the furthest child (highest) +1
    root->bf = rh-lh; //Update current balance factor
}


Node *rightRotation(Node *root){
    Node *temp = root->left; //Reference to left node
    root->left = temp->right; //Left is left->right (closest smaller number of root)
    temp->right = root; //Set root to child of temp
    
    update(root); //Update height and balance factor
    update(temp);
    return temp;
}

Node *leftRotation(Node *root){
    Node *temp = root->right; //Reference to right node
    root->right = temp->left; //Right is right->left (closest bigger number of root)
    temp->left = root; //Set root to child of temp

    update(root); //Update height and balance factor
    update(temp);
    update(temp);
    return temp;
}


Node *lLC(Node *root){ //Left left case
    return rightRotation(root);
}

Node *rRC(Node *root){ //Right right case
    return leftRotation(root);
}

Node *lRC(Node *root){ //Left right case
    root->left = leftRotation(root->left);
    return lLC(root);
}

Node *rLC(Node *root){ //Right left case
    root->right = rightRotation(root->right);
    return rRC(root);
}

Node* balance(Node* root){
    //Left heavy subtree
    if(root->bf == -2){ //If balance factor is -2 (not balance)
        if(root->left->bf <= 0) return lLC(root); //Check child balance factor
        else return lRC(root); //If bf is smaller or equal than 0, it is left left, or it is left right (left-1, right+1)
    }else if(root->bf == 2){ //Right heavy subtree
        if(root->right->bf >= 0) return rRC(root);
        else return rLC(root); //If bf is bigger or equal than 0, it is right right, or it is right left (left-1, right+1)
    }
    return root;
}

Node *insertNode(Node* root, int d){
    if(root == nullptr) return new Node(d); //Base condition

    if(d < root->data) 
        root->left = insertNode(root->left, d); //Smaller go left
    else 
        root->right = insertNode(root->right, d); //Larger go left

    update(root); //Update root node

    return balance(root); //Balance root and return root
}

bool insert(Node *root, int d){
    if(root == nullptr) return false;
    //Assume no repeated value in tree
    root = insertNode(root, d);
    return true;
}

int findMax(Node *root){
    while(root->right != nullptr) root = root->right; //Traverse to right most node (largest)
    return root->data;
}

int findMin(Node *root){
    while(root->left != nullptr) root = root->left; //Traverse to left most node (smallest)
    return root->data;
}

Node *removeNode(Node *root, int d){
    if(root == nullptr) return nullptr; //Return if value not found

    if(d < root->data) root->left = removeNode(root->left, d); //Smaller go left
    else if(d > root->data) root->right = removeNode(root->right, d); //Larger go left
    else{ //Found value
        if(root->left == nullptr) return root->right; //When only have right subtree
        else if(root->right == nullptr) return root->left; //When only have left subtree
        else{ //When have both subtree
            if(root->left->height > root->right->height){ //If left subtree is deeper
                int susData = findMax(root->left); //Choose the largest node in this subtree
                root->data = susData; //Copy data from successor
                root->left = removeNode(root->left, susData); //Remove repeated successor node
            }else{ //If right subtree is deeper
                int susData = findMin(root->right); //Choose the smallest node in this subtree
                root->data = susData; //Copy data from successor
                root->right = removeNode(root->right, susData); //Remove repeated successor node
            }
        }
    }

    update(root); //Update and balance tree
    return balance(root);
}

bool remove(Node *root, int d){
    if(root == nullptr) return 0;
    //Assume no repeated value in tree
    root = removeNode(root, d);
    return true;
}

void printNode(Node *root){ //In-order print
    if(root == nullptr) return;
    printNode(root->left);
    cout << root->data << " ";
    printNode(root->right);
}

int main(){
    Node *root = new Node(4);
    Node *left = new Node(2);
    Node *right = new Node(5);
    Node *leftLeft = new Node(1);
    Node *leftRight = new Node(3);

    root->left = left;
    root->right = right;

    left->left = leftLeft;
    left->right = leftRight;

    printNode(root);
    cout << endl;

    cout << insert(root, 8) << endl;
    printNode(root);
    cout << endl;
    
    cout << insert(root, 6) << endl;
    printNode(root);
    cout << endl;
    return 0;
}