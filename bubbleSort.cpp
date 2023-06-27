#include <iostream>
#include <vector>


template<typename T>
std::vector<T> bubbleSort(std::vector<T>& arr) {
	for(int i = 0; i < arr.size() - 1; i++) {
		bool key = false;
		for(int j = i + 1; j < arr.size(); j++) {
			if(arr[i] > arr[j]) {
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				key = true;
			}
		}
		if(key) break;
	}
	return arr;
}

int main() {
	std::vector<int> vec = {5, 6, 4, 2, 8, 9};
	bubbleSort(vec);
	for(int i = 0; i < vec.size(); i++) {
		std::cout << vec[i];
	}
	return 0;
}