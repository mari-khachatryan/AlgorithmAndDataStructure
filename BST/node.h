#include <iostream>


class Node {
public:
	Node* left;
	Node* right;
	int val;
	Node(int v) : val{v}, left{nullptr}, right{nullptr} {}
};