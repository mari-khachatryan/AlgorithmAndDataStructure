#include <iostream> 
#include <vector>

template <typename T>
std::vector<T> insertionSort(std::vector<T>& arr) {
	int index = 0;
	for(int i = 0; i < arr.size() - 1; i++) {
		T min = arr[i];
		for(int j = i + 1; j < arr.size(); j++) {
			if(min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		std::swap(arr[i], arr[index]);
	}
	return arr;
}

int main() {
	std::vector<int> vec = {9, 15, 8, 5, 1, 2 ,7};
	insertionSort(vec);
	//space complexity: O(1), time complexity: O(n^2)
	//best case, regardless of the initial order of the element: O(n)
	//worst case reverse order or in any other order
	for(int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	return 0;
}