#include "rbtree.h"
std::string red = "red";
std::string black = "black";
std::string preface = ", color: ";
/*
 * Node Class Functions
*/

// Don't forget to change these constructors!
RBTNode::RBTNode(){
    this->data = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->color = false;
}

RBTNode::RBTNode(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->color = true;
}

RBTNode::~RBTNode(){

}

void RBTNode::swapColor(){
    this->color = (this->color)?false:true;
}

RBTNode* RBTree::insert(int data, RBTNode* root){
    // std::cout << "entering: " << data << " into " << ((root)?std::to_string(root->data):"Null") << std::endl;
    if(!root){
        return new RBTNode(data);
    }
    
    if(data < root->data){
        // std::cout << "Triggering left insert" << std::endl;
        root->left = insert(data, root->left);
    }else{
        // std::cout << "Triggering right insert" << std::endl;
        root->right = insert(data, root->right);
    }

	// Add code here to complete this assignment.
	// HINT: Rules 1-3 sequentially!
    
    
    if(root->right != nullptr){
        if(root->color == false && root->right->color == true){
            // std::cout << "Triggering color based Rotate Left" << std::endl;
            root = this->rotateLeft(root);
            root->swapColor();
            root->left->swapColor();
        }
    }

    if(root->left != nullptr){
        if(root->left->left != nullptr){
            if(root->left->color == true && root->left->left->color == true){
                // std::cout << "Triggering color based Rotate Right" << std::endl;
                // std::cout << "Root:" << root->data << "(Color:" << (root->color?red:black) << "), "<< "Root Left" << ((root->left!=nullptr)?(std::to_string(root->left->data) + "(Color:" + (root->left->color?red:black) + ")"):"Null") << "Root Left Left" << ((root->left->left!=nullptr)?(std::to_string(root->left->left->data) + "(Color:" + (root->left->left->color?red:black) + ")"):"Null") << std::endl;
                root = this->rotateRight(root);
                // std::cout << "Root:" << root->data << "(Color:" << (root->color?red:black) << "), "<< "Root Left" << ((root->left!=nullptr)?(std::to_string(root->left->data) + "(Color:" + (root->left->color?red:black) + ")"):"Null") << "Root Right" << ((root->right!=nullptr)?(std::to_string(root->right->data) + "(Color:" + (root->right->color?red:black) + ")"):"Null") << std::endl;
                
                root->swapColor();
                root->right->swapColor();
                // std::cout << "Root:" << root->data << "(Color:" << (root->color?red:black) << "), "<< "Root Left" << ((root->left!=nullptr)?(std::to_string(root->left->data) + "(Color:" + (root->left->color?red:black) + ")"):"Null") << "Root Right" << ((root->right!=nullptr)?(std::to_string(root->right->data) + "(Color:" + (root->right->color?red:black) + ")"):"Null") << std::endl;
                
            }
        }
    }       
    if(root->left != nullptr && root->right != nullptr){
        if(root->left->color == true && root->right->color == true){
            // std::cout << "Triggering swap color" << std::endl;
            // std::cout << "Root:" << root->data << "(Color:" << (root->color?red:black) << "), "<< "Root Left" << ((root->left!=nullptr)?(std::to_string(root->left->data) + "(Color:" + (root->left->color?red:black) + ")"):"Null") << "Root Right" << ((root->right!=nullptr)?(std::to_string(root->right->data) + "(Color:" + (root->right->color?red:black) + ")"):"Null") << std::endl;
                
            root->left->swapColor();
            root->right->swapColor();
            root->swapColor();
            // std::cout << "Root:" << root->data << "(Color:" << (root->color?red:black) << "), "<< "Root Left" << ((root->left!=nullptr)?(std::to_string(root->left->data) + "(Color:" + (root->left->color?red:black) + ")"):"Null") << "Root Right" << ((root->right!=nullptr)?(std::to_string(root->right->data) + "(Color:" + (root->right->color?red:black) + ")"):"Null") << std::endl;
            
        }
    }

    return root;
}

int RBTree::height(RBTNode* root){
    if(!root){
        return -1;
    }
    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left + 1 : right + 1);
}

void RBTree::preorder(RBTNode* root, std::ostream& os){
    if(!root){
        return;
    }

    os << root->data << ":" << root->color << ", ";
    this->preorder(root->left, os);
    this->preorder(root->right, os);

    return;
}

void RBTree::inorder(RBTNode* root, std::ostream& os){
    if(!root){
        return;
    }

    this->inorder(root->left, os);
    os << root->data << ":" << root->color << ", ";
    this->inorder(root->right, os);

    return;
}

void RBTree::postorder(RBTNode* root, std::ostream& os){
    if(!root){
        return;
    }

    this->postorder(root->left, os);
    this->postorder(root->right, os);
    os << root->data << ":" << root->color << ", ";

    return;
}

void RBTree::destroy(RBTNode* root){
    if(!root){
        return;
    }

    this->destroy(root->left);
    this->destroy(root->right);
    delete root->left;
    delete root->right;
}

bool RBTree::search(int data, RBTNode* root){
    if(!root){
        return false;
    }

    if(data == root->data){
        return true;
    }

    if(data < root->data){
        return this->search(data, root->left);
    }else{
        return this->search(data, root->right);
    }
}

RBTNode* RBTree::rotateLeft(RBTNode* node){
    // std::cout << "before Rotate Left: Root:" << root->data << "Root Left" << ((root->left!=nullptr)?std::to_string(root->left->data):"Null") << "Root Right" << ((root->right!=nullptr)?std::to_string(root->right->data):"Null") << std::endl;
    RBTNode* p = node->right;
    //p->swapColor();
    node->right = node->right->left;
    p->left = node;
    //node->swapColor();
    // std::cout << "After Rotate Left: Root:" << p->data << "Root Left" << ((p->left!=nullptr)?std::to_string(p->left->data):"Null") << "Root Right" << ((p->right!=nullptr)?std::to_string(p->right->data):"Null") << std::endl;
    return p;
}

RBTNode* RBTree::rotateRight(RBTNode* node){
    // std::cout << "Before Rotate right: Root:" << root->data << "Root Left" << ((root->left!=nullptr)?std::to_string(root->left->data):"Null") << "Root Right" << ((root->right!=nullptr)?std::to_string(root->right->data):"Null") << std::endl;
    RBTNode* p = node->left;
    //p->swapColor();
    node->left = node->left->right;
    p->right = node;
    //node->swapColor();
    // std::cout << "After Rotate Right: Root:" << p->data << "Root Left" << ((p->left!=nullptr)?std::to_string(p->left->data):"Null") << "Root Right" << ((p->right!=nullptr)?std::to_string(p->right->data):"Null") << std::endl;
    return p;
}

bool RBTree::isRed(RBTNode* node){
    if(!node){
        return false;
    }

    return node->color;
}

/*
 * Public Functions
*/

RBTree::RBTree(){
    this->root = nullptr;
}

RBTree::~RBTree(){
    this->destroy(this->root);
}

void RBTree::insert(int data){
    this->root = this->insert(data, this->root);
    this->root->color = false;
}

int RBTree::height(){
    return this->height(this->root);
}

void RBTree::preorder(std::ostream& os){
    this->preorder(this->root, os);
    os << "\n";
}

void RBTree::inorder(std::ostream& os){
    this->inorder(this->root, os);
    os << "\n";
}

void RBTree::postorder(std::ostream& os){
    this->postorder(this->root, os);
    os << "\n";
}

bool RBTree::search(int data){
    return this->search(data, this->root);
}

void RBTree::clear(){
    this->destroy(this->root);
    this->root = nullptr;
}