#include <iostream>
#include "hashMap.h"

int main() {
	HashMap<std::string, int> hashMap(10, 2, 0.8);

	hashMap.insert("apple", 1);
	hashMap.insert("banana", 2);
	hashMap.insert("cherry", 3);

	int value;
	if (hashMap.get("banana", value)) {
        std::cout << "Value of 'banana': " << value << std::endl;
    } else {
        std::cout << "Key 'banana' not found." << std::endl;
    }

    if (hashMap.get("grape", value)) {
        std::cout << "Value of 'grape': " << value << std::endl;
    } else {
        std::cout << "Key 'grape' not found." << std::endl;
    } 
	return 0;
}