#include <chrono>
#include <cstdlib>
#include "vectorImplement.h"
//#include "list.h"

int main() {
    std::cout << "hello" << std::endl;
    VectorMy<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(15);
    std::cout << v.size() << std::endl; 
    // int size = 5;
    // for(int i = 0; i < size; ++i) {
    //     v.push_back(i);
    // }
    
    // for(int i = 0; i < v.size(); ++i) {
    //     std::cout << v[i] << " ";
    // }
    // std::cout << "back" << v.back() << std::endl;
    // std::cout << "begin" << v.begin() << std::endl;
    // std::cout << "capac" << v.capacity() << std::endl;
    // std::cout << "find 2" <<  v.find(2) << std::endl;
    // v.pop_back();
    // v.push_back(9);
    // v.insert(3, 8);
    // v.erase(0);
    // for(int i{0}; i < v.size(); ++i) {
    //     std::cout << v[i];
    // }

}

