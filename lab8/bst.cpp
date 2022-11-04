#include "bst.h"

/*
 * Node Class Functions
*/

BSTNode::BSTNode(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

BSTNode::~BSTNode(){
}

/*
 * Tree Class Functions
*/

/*
 * Private Functions
*/

BSTNode* BSTree::insert(int data, BSTNode* root){

    BSTNode* response; 
    BSTNode* temp = new BSTNode(data);
    //std::cout << "if decision" << data << "the root object check" << (root == nullptr) << std::endl;
    
    if(root == nullptr){
        root = temp;
        return root;    
    }
    //std::cout << "if decision" << data << "the root object" << root << "the bool:" << (data > root->data) << std::endl;
    
    if(data > root->data){
        response = insert(data, root->right);
        //std::cout << "Right Tree" << data << "The right pointer" << root->right << std::endl;
        root->right = response;
        //std::cout << "Right Tree" << data << "The right pointer now is" << root->right << std::endl;
    } else {
        response = insert(data, root->left);
        //std::cout << "Left Tree" << data << "The left pointer" << root->right << std::endl;
        root->left = response;
        //std::cout << "Left Tree" << data << "The left pointer now is" << root->right << std::endl;
    }
    // BSTNode* currentNode = root;
    // bool running = true;
    // while(running == true){
    //     if(data > currentNode->data){
    //         if(currentNode->right){
    //             currentNode = currentNode->right;    
    //         } else {
    //             currentNode->right = temp;
    //             running = false;
    //         }
    //     } else {
    //         if(currentNode->left){
    //             currentNode = currentNode->left;
    //         } else {
    //             currentNode->left = temp;
    //             running = false;
    //         }
    //     }
    // }
    return root;
}

int BSTree::height(BSTNode* root){
    int level = 0;
    if(root != nullptr){
        level++;
        int leftHeight = level;
        int rightHeight = level;
        if(root->left != nullptr)leftHeight += this->height(root->left);
        if(root->right != nullptr)rightHeight += this->height(root->right);
        //std::cout << "This is the left height:" << leftHeight << "And the right hand height is:" << rightHeight << std::endl;
        level = MAX(leftHeight, rightHeight);
    } 
    return level;
}

void BSTree::preorder(BSTNode* root, std::ostream& os){
    if(root != nullptr){
        os << root->data << ", ";
        this->preorder(root->left, os);
        this->preorder(root->right, os);
    }
    return;
}

void BSTree::inorder(BSTNode* root, std::ostream& os){
    if(root != nullptr){
        this->inorder(root->left, os);
        os << root->data << ", ";
        this->inorder(root->right, os);
    }
    return;
}

void BSTree::postorder(BSTNode* root, std::ostream& os){
    if(root != nullptr){
        this->postorder(root->left, os);
        this->postorder(root->right, os);
        os << root->data << ", ";
    }
    return;
}

void BSTree::destroy(BSTNode* root){
    if(root == nullptr){
        return;
    }
    destroy(root->left);
    destroy(root->right);
    delete root;
    this->root = nullptr;
    return;
}

bool BSTree::search(int data, BSTNode* root){
   bool answer = false;
    if(root == nullptr){
        return false;
    }

    if(root != nullptr && data == root->data){
        return true;
    } 

    if(root->left != nullptr){
        if(data < root->data){
            answer = search(data, root->left);
        }
    }
    if(root->right != nullptr){
        if(root->data < data){
            if(root->right != nullptr) search(data, root->right);
        }
    }
   return answer;
}

/*
 * Public Functions
*/

BSTree::BSTree(){
    this->root = nullptr;
    return;
}

BSTree::~BSTree(){
    this->destroy(this->root);
    return;
}

void BSTree::insert(int data){
    this->root = this->insert(data, root);
    return;
}

int BSTree::height(){
    int value = this->height(root);
    return --value;
}

void BSTree::preorder(std::ostream& os){
    this->preorder(this->root, os);
    os << "\n";
    return;
}

void BSTree::inorder(std::ostream& os){
    this->inorder(this->root, os);
    os << "\n";
    return;
}

void BSTree::postorder(std::ostream& os){
    this->postorder(this->root, os);
    os << "\n";
    return;
}

bool BSTree::search(int data){
     bool answer = this->search(data, this->root);
    return answer;
}