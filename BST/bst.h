#ifndef BST_H
#define BST_H

#include "node.h"
#include <iostream>
#include <vector>
#include <queue>

class BST {
public:
	BST() : root{nullptr} {};
	BST(Node*);
	Node* searchNode(int);
	void insert(int);
	void deleteNode(int);
	void inorderTraversal();
	void preoderTraversal();
	void postorderTraversal();
	void levelOrderTraversal();
private:
	Node* searchNode(Node*, int);
	Node* minimum(Node*);
	Node* maximum(Node*);
	void insert(Node*&, int);
	void deleteNode(Node*&, int val);
	void inorderTraversal(Node*);   //O(n)time
	void preoderTraversal(Node*);
	void postorderTraversal(Node*);
	void levelOrderTraversal(Node*);
	Node* predecessor(Node*);
	Node* successor(Node*);
private:
	Node* root;
	std::vector<Node*> v;
};

BST::BST(Node* r) : root{r} {}

Node* BST::searchNode(int key) {
	return searchNode(root, key);
}

void BST::insert(int val) {
	return insert(root, val);
}
void BST::deleteNode(int val) {
	return deleteNode(root, val);
}

// void BST::deleteNode(int val) {
// 	return deleteNode(root, val)
// }

void BST::inorderTraversal() {
	return inorderTraversal(root);
}

void BST::preoderTraversal() {
	return preoderTraversal(root);
}

void BST::postorderTraversal() {
	return postorderTraversal(root);
}

void BST::levelOrderTraversal() {
	return levelOrderTraversal(root);
}

Node* BST::searchNode(Node* root, int key) {
	if(!root || root->val == key) return root;
	if(key < root->val ) {
		return searchNode(root->left, key);
	} else {
		return searchNode(root->right, key);
	}
}

// Node* BST::searchNode(Node* root, int key) {   //iterative
// 	while(root && root->val != key) {
// 		if(key < root->val) {
// 			root = root->left;
// 		} else {
// 			root = root->right;
// 		}
// 	}
// 	return root
// }

Node* BST::minimum(Node* root) {
	if(!root) return root;
	while(root->left) {
		root = root->left;
	}
	return root;
}

Node* BST::maximum(Node* root) {
	if(!root) return root;
	while(root->right) {
		root = root->right;
	}
	return root;
}

// void BST::insert(Node*& root, int val) {
//     if (!root) {
//         root = new Node(val);
//     } else if (val < root->val) {
//         insert(root->left, val);
//     } else {
//         insert(root->right, val);
//     }
// }

void BST::insert(Node*& root, int key) {
	Node* newNode = new Node(key);
	Node* tmp = root;
	Node* parent = nullptr;  //parent of x
	while(tmp) {
		parent = tmp;
		if(newNode->val < tmp->val) {
			tmp = tmp->left;
		} else {
			tmp = tmp->right;
		}
	}
	if(!parent) {
		root = newNode;
	} else if (newNode->val > parent->val) {
		parent->right = newNode;
	} else {
		parent->left = newNode;
	}
}

void BST::deleteNode(Node*& root, int val) {
    Node* curr = root;
    Node* parent = nullptr;

    // Search for the node to delete
    while (curr && curr->val != val) {
        parent = curr;
        if (val < curr->val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    // If the node was not found, return
    if (!curr) {
        return;
    }

    // Case 1: Node has no children (leaf node)
    if (!curr->left && !curr->right) {
        if (curr == root) {
            delete root;
            root = nullptr;
        } else if (parent->left == curr) {
            delete curr;
            parent->left = nullptr;
        } else {
            delete curr;
            parent->right = nullptr;
        }
    }
    // Case 2: Node has one child
    else if (!curr->left || !curr->right) {
        Node* child = (curr->left) ? curr->left : curr->right;
        if (curr == root) {
            root = child;
        } else if (parent->left == curr) {
            delete curr;
            parent->left = child;
        } else {
            delete curr;
            parent->right = child;
        }
    }
    // Case 3: Node has two children
    else {
        Node* successor = minimum(curr->right);
        int successorVal = successor->val;
        deleteNode(root, successorVal); // Recursively delete the successor
        curr->val = successorVal;
    }
}


void BST::inorderTraversal(Node* root) {
	if(!root) return;
	inorderTraversal(root->left);
	std::cout << root->val << std::endl;
	inorderTraversal(root->right);
}

void BST::preoderTraversal(Node* node) {
	if(!node) return;
	std::cout << node->val << std::endl;
	preoderTraversal(node->left);
	preoderTraversal(node->right);
}

void BST::postorderTraversal(Node* node) {
	if(!node) return;
	postorderTraversal(node->left);
	postorderTraversal(node->right);
	std::cout << node->val << std::endl;
}

void BST::levelOrderTraversal(Node* node) {
	if(!root) return;
	std::queue<Node*> q;
	Node* curr = root;
	q.push(curr);
	std::vector<Node*> v;
	while(!q.empty()) {
		int s = q.size();
		
		while(s--) {
			Node* tmp = q.front();
			q.pop();
			v.push_back(tmp);
			if(tmp->left) q.push(tmp->left);
			if(tmp->right) q.push(tmp->right);
		}
	}
	std::cout << "levelOrderTraversal : " << std::endl;
	for(size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i]->val << std::endl;
	}
}

Node* BST::predecessor(Node* node) {
	if(!node->left && !node->right) return node;
	if(!node->left) return node;
	Node* tmp = node->left;
	while(tmp) {
		tmp = tmp->right;
	}
	return tmp;
}

Node* BST::successor(Node* node) {
	if(!node->left && !node->right) return node;
	if(!node->right) return node;
	Node* tmp = node->right;
	while(tmp) {
		tmp = tmp->left;
	}
	return tmp;
}

#endif   //BST_H