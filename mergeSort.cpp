#include <iostream>
#include <vector>

void merge(std::vector<int>& v, int start, int mid, int end) {
	std::vector<int> newV(end - start + 1);
	int start1 = start;
	int end1 = mid;
	int start2 = mid + 1;
	int end2 = end;
	int index = 0;
	while(start1 <= end1 && start2 <= end2) {
		if(v[start1]  <= v[start2]) {
			newV[index ++] = v[start1++];
		} else {
			newV[index ++] = v[start2++];
		}
	}  

	while(start1 <= end1) {
		newV[index ++] = v[start1++];
	}

	while(start2 <= end2) {
		newV[index ++] = v[start2++];
	}
	
	for(int p = start; p <= end; ++p) {
		v[p] = newV[p - start];
	}
}

void mergeSort(std::vector<int>& v, int begin, int end) {
	if(begin >= end) return;
	int mid = begin - (begin - end) / 2;
	mergeSort(v, begin, mid);
	mergeSort(v, mid + 1, end);
	merge(v, begin, mid, end);
}

int main() {
	std::vector<int> vec = {9, 15, 8, 5, 1, 2 ,7};
	const int start = 0;
	const int end = vec.size() - 1;
	mergeSort(vec, start, end);
	//space complexity: O(n), time complexity: O(n log n)
	//best case, regardless of the initial order of the element: O(n)
	//Merge Sort follows a divide-and-conquer approach
	for(int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	return 0;
}



