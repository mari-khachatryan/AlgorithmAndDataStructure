#include <iostream>
#include <vector>

template <typename T>
std::vector<T> insertionSort(std::vector<T>& v) {
	for(int i = 1; i < v.size(); i++) {
		T key = v[i];
		int j = i - 1;
		while(j >= 0 && key < v[j]) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = key;
 	}
	return v;
}

int main() {
	std::vector<int> vec = {9, 5, 3, 45, 89, 1, 100};
	insertionSort(vec);
	//space complexity: O(1), time complexity: O(n^2)
	//best case, that input is already sorted: O(n)
	for(int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	return 0;
}