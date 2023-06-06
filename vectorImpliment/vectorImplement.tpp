#include "vectorImplement.h"

template <typename T>
VectorMy<T>::VectorMy()
{ 
    m_size = 0;
    m_capacity = 0;
    header = new T[m_capacity];
}

// template <typename T>
// VectorMy<T>::VectorMy(int size) : m_size{size} , m_capacity{size}
// { 
//     header = new T[size];
// }

template <typename T>
void VectorMy<T>::delete_m() 
{
    if(header) {
        delete[] header;
        m_size = 0;
        m_capacity = 0;
        header = nullptr;
    }
}

template <typename T>
VectorMy<T>::~VectorMy() { delete_m(); }

template <typename T>
int VectorMy<T>::size() const { return m_size; }

template <typename T>
int VectorMy<T>::capacity() const { return m_capacity; }

template <typename T>
int* VectorMy<T>::begin() const{ return header; }

template <typename T>
int VectorMy<T>::front() const {
    return header[0];
}

template <typename T>
int VectorMy<T>::back() const {
    return header[m_size - 1];
}

template <typename T>
bool VectorMy<T>::empty() {
    return m_size == 0;
}

template <typename T>
T& VectorMy<T>::operator[](int pos) {
    if(pos < 0 && pos > m_size) {
        std::cout << "incorect pos";
        exit(-1);
    }
    return header[pos];
}

template <typename T>
void VectorMy<T>::resize(int count) {
T* newData = new T[count];
for(int i{0}; i < size(); ++i) {
    newData[i] = header[i];
}
delete_m();
m_capacity = count * 2;
m_size = count;
header = newData;
}

template <typename T>
void VectorMy<T>::reserve() {
    int newCapcity = (m_capacity == 0) ? 1 : m_capacity * 2;
    T* newData = new T[newCapcity];
    for(int i = 0; i < size(); ++i) {
        newData[i] = header[i];
    }
    delete_m();
    m_capacity = newCapcity;
    //m_size++;
    header = newData;
}

template <typename T>
void VectorMy<T>::push_back(const T& value) {
    if(size() + 1 > m_capacity) {
        reserve();
    } 
    header[m_size] = value;
    m_size++;
    std::cout << m_size << std::endl;
}

template <typename T>
void VectorMy<T>::pop_back(){
	if(empty()){
		std::cout << "Vector is empty";
        exit(-1);
	}
	--m_size;
}

template <typename T>
void VectorMy<T>::insert(int pos, const T& value) {
    int val = value;
    if(size() + 1 <= m_capacity) {
        reserve();
    } 
    while(pos++ <= size() - 1) {
        T tmp = header[pos];
        header[pos] = val;
        val = tmp;
    }
}

template <typename T>
int VectorMy<T>::find(const T& value) {
    int pos{0};
    for(int i{0}; i < m_size; ++i) {
        if(header[i] == value) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void VectorMy<T>::erase(int pos) {
    if(pos > m_size) { 
        std:: cout << "incorect pos"; 
        exit(-1);
    }
    for(int i{pos}; i < size(); ++i) {
        header[pos] = header[pos + 1];
    }
    m_size = m_size - 1;
}













