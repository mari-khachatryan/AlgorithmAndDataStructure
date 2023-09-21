#include "bst.h"
#include <iostream>

int main() {
	BST bst;
	bst.insert(5);
	bst.insert(10);
	bst.insert(18);
	bst.insert(4);
	bst.insert(2);
	bst.insert(40);
	Node* n = bst.searchNode(4);
	if(n) {
		std::cout << "the node with 4 val exists." << std::endl;
	} else {
		std::cout << "the node with 4 val don't find." << std::endl;
	}
	bst.deleteNode(4);
	Node* n1 = bst.searchNode(4);
	if(n1) {
		std::cout << "the node with 4 val exists." << std::endl;
	} else {
		std::cout << "the node with 4 val don't find." << std::endl;
	}
	bst.inorderTraversal();
	bst.preoderTraversal();
	bst.levelOrderTraversal();
	return 0;
}
