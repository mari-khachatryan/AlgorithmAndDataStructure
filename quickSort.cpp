#include <iostream>
#include <vector>

int getPivotIndex(std::vector<int>& vec, int start, int end) {
	int pivot = vec[end];
	int i = start - 1;
	for(int j = start; j <= end - 1; ++j) {
		if(vec[j] < pivot) {
			i++;
			std::swap(vec[i], vec[j]);
		}
	}
	std::swap(vec[i + 1], vec[end]);
	return i + 1;
}

void quickSort(std::vector<int>& vec, int start, int end) {
	if(start < end) {
		int pivotIndex = getPivotIndex(vec, start, end);
		quickSort(vec, start, pivotIndex - 1);
		quickSort(vec, pivotIndex + 1, end);
	}
}

int main() {
	std::vector<int> v = {9, 5, 2, 7, 18, 1, 10};
	int n = v.size();

	quickSort(v, 0, n - 1);

	std::cout << "Sorted array: ";
	for(int i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	return 0;
}