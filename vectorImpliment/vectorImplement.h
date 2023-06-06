#ifndef VECTORMY_H
#define VECTORMY_H

#include <iostream>

template <typename T>
class VectorMy {
public:
    VectorMy();
    //VectorMy(int size);
    void delete_m(); 
    ~VectorMy();
    int size() const;
    int capacity() const;
    int* begin() const;
    int front() const;
    int back() const;
    bool empty();
    T& operator[](int pos);
    void resize(int count);
    void reserve();
    void push_back(const T& value);
    void pop_back();
    void insert(int pos, const T& value);
    int find(const T& value) ;
    void erase(int pos);
private:
    int m_size;
    int m_capacity;
    T* header;
};

#include "vectorImplement.tpp"
#endif //VECTORMY_H