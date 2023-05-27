#include <iostream>
#include <vector>
#include <string>
#include <functional>

class Node {
public:
    std::function<int(int)> function;
    std::vector<Node*> children;
public:
    Node(std::function<int(int)> func) : function{func} {}
    void addChild(Node* node) {
            children.push_back(node);
    }
    void removeChild(Node* node) {
        auto it = std::find(children.begin(), children.end(), node);
        if(it != children.end()) {
            children.erase(it);
        }
    }

    int execute(int value) {
        int result = function(value);
        for(Node* child : children) {
            result = child->execute(result);
        }
        return result;
    }

};

class GeneralTree {
public:
    GeneralTree() : root(nullptr) {}
    ~GeneralTree() {
        deleteTree(root);
    }
    Node* getRoot() { return root; }
    void deleteTree(Node* node) {
        if (node == nullptr) {
            return;
        }
        for (Node* child : node->children) {
            deleteTree(child);
        }
        delete node;
    }

    void insertNode(std::function<int(int)> func, Node* parent) {
        Node* newNode = new Node(func);
        if(parent == nullptr) {
            root = newNode;
        } else {
            parent->addChild(newNode);
        }
    }
    void deleteNode(Node* parent, int index) {
        if (parent == nullptr) {
        std::cout << "Invalid parent node." << std::endl;
        return;
    }

    if (index < 0 || index >= parent->children.size()) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    Node* child = parent->children[index];
    parent->children.erase(parent->children.begin() + index);
    delete child;
    }
    int execute(int value) {
        if (root != nullptr) {
            return root->execute(value);
        }
        return value;
    }
private:
    Node* root;
};
int f1(int x) { return x;}
int f2(int x) { return 2 * x; }
int f3(int x) { return x * x ; }

int main() {

    GeneralTree g;
    GeneralTree tree;
    g.insertNode(f1, nullptr);
    g.insertNode(f2, g.getRoot());
    g.insertNode(f3, g.getRoot()->children[0]);

    int result = tree.execute(5);
    std::cout << "Result: " << result << std::endl;  
}
