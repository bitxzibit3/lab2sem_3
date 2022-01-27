//
// Created by Timur on 30.03.2021.
//

#include "DynArray.h"

template<class T>
void DArray<T>::append(T value)
{
    size++;
    data = (T *)realloc (data, size * sizeof(T));
    data[size - 1] = value;
}

template<class T>
int DArray<T>::get_size() {
    return size;
}

template<class T>
DArray<T>::DArray(T *d, int size1) {
    if (this->size  == 0)
        this->data = (T* )calloc (size1, sizeof (T));
    else
        this->data = (T* )realloc (this->data, size1 * sizeof (T));
    for (size_t i = 0; i < size1; i++)
        *(this->data + i) = *(d + i);
    this->size = size1;
}

template<class T>
DArray<T>::DArray(DArray<T> const &Array) {
    size = Array.size;
    data = (T *) calloc (size, sizeof(T));
    for (size_t i = 0; i < size; i++)
        data[i] = Array.data[i];
}

template<class T>
void DArray<T>::resize(int new_size) {
    if (this->size != 0)
        this->data = (T *) realloc (this->data, new_size * sizeof (T));
    else
        this->data = (T *) calloc (new_size, sizeof(T));
    this->size = new_size;
}

//template<class T>
//DArray<T>::~DArray()
//{
//    free(data);
//}

template<class T>
void DArray<T>::prepend(T value)
{
    this->resize (this->size + 1);
    if (this->size == 1)
    {
        *(this->data) = value;
        return;
    }
    for (size_t i = this->size - 1; i > 0; i--)
    {
        *(data + i) = *(data + i - 1);
    }
    *(data) = value;
}

template<class T>
void DArray<T>::insert(T value, int index) {
    resize (this->size + 1);
    for (size_t i = this->size - 1; i > index; i--)
    {
        *(data + i) = *(data + i - 1);
    }
    *(data + index) = value;
}

template<class T>
void DArray<T>::printArr() {
    for (size_t i = 0; i < this->size; i++)
        std::cout << *(data + i) << " ";
    std::cout << std::endl;
}

template<class T>
DArray<T> DArray<T>::concat(DArray<T> first, DArray<T> second) {
    DArray<T> ans;
    ans.resize(first.size + second.size);
    for (size_t i = 0; i < first.size; i++)
        *(ans.data + i) = *(first.data + i);
    for (size_t i = first.size; i < ans.size; i++)
        *(ans.data + i) = *(second.data + i - first.size);
    return ans;
}

template<class T>
DArray<T> DArray<T>::GetSubArray(int begin, int end)
{
    T *new_data = (T* ) calloc (end - begin + 1, sizeof(T));
    for (size_t i = begin; i <= end; i++)
        *(new_data + i - begin) = this->data[i];
    DArray<T> ans (new_data, end - begin + 1);
    free (new_data);
    return ans;
}

template<class T>
DArray<T>::DArray()
{
    this->data = nullptr;
    this->size = 0;
}

template<class T>
T &DArray<T>::operator[](int index) {
    return data[index];
}

template<class T>
const T &DArray<T>::operator[](int index) const {
    return data[index];
}

template<class T>
DArray<T> &DArray<T>::operator=(const DArray<T> &arr) {
    size = arr.size;
    data = (T*) calloc (size, sizeof(T));
    for (int i = 0; i < size; i++)
        data[i] = arr[i];
    return *this;
}

template<class T>
std::ostream &operator<< (std::ostream &out, DArray<T> arr)
{
    int size = arr.get_size();
    out << "[";
    for (int i = 0; i < size; i++)
        out << arr[i] << "; ";
    out << "]" << std::endl;
    return out;
}

template<class T>
T *DArray<T>::GetData() {
    return data;
}

template<class T>
const int DArray<T>::get_size() const {
    return size;
}

template<class T>
DArray<T> DArray<T>::Remove(T value) {
    DArray<T> rez(*this);
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            for (int j = i; j < size - 1; j++)
                rez[j] = rez[j + 1];
        }
    }
    rez.resize(rez.size - 1);
    return rez;
}

template<class T>
DArray<T> DArray<T>::RemoveIndex(int idx) {
    if (idx >= size)
        return DArray<T>();
    T* new_data = (T *) calloc (size - 1, sizeof(T));
    for (int i = 0; i < size - 1; i++) {
        if (i < idx)
            *(new_data + i) = *(data + i);
        else
            *(new_data + i) = *(data + i + 1);
    }
    return DArray(new_data, size - 1);
}

template<class T>
void DArray<T>::swap(int f, int s) {
    if (((f >= 0) && (f < size)) && ((s >= 0) && (s < size)))
    {
        T tmp = data[f];
        data[f] = data[s];
        data[s] = tmp;
    }
}
