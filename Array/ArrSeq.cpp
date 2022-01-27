//

#include <iostream>
#include "ArrSeq.h"

// Created by Timur on 28.04.2021.

template<class T>
ArrSeq<T>::ArrSeq(DArray<T> arr)
{
    this->array = DArray<T> (arr);
}

template<class T>
ArrSeq<T>::ArrSeq(ArrSeq<T> const &arr)
{
    array = DArray<T> (arr.array);
}

template<class T>
ArrSeq<T>::ArrSeq() {
    this->array = DArray<T>();
}

template<class T>
T &ArrSeq<T>::operator[](int index) {
    return array[index];
}

template<class T>
ArrSeq<T>::ArrSeq(T *data, int size)
{
    this->array = DArray<T> (data, size);
}

template<class T>
T ArrSeq<T>::GetFirst() {
    if (array.get_size())
        return array.get_i(0);
    else
        throw -1;
}

template<class T>
T ArrSeq<T>::GetLast() {
    if (array.get_size())
        return array[array.get_size() - 1];
    else
        return (T)0.;
}

template<class T>
T ArrSeq<T>::Get(int index, int *checker) {
    *checker = 0;
    if ((index < 0) || (index >= array.get_size()))
    {
        *checker = 1;
        throw -1;
    }
    return array[index];
}

template<class T>
T ArrSeq<T>::Get(int index)
{
    size_t checker = 0;
    return (this->array)[index];
}

template<class T>
int ArrSeq<T>::GetSize() {
    return array.get_size();
}

template<class T>
void ArrSeq<T>::Append(T value) {
    array.resize(array.get_size() + 1);
    array[array.get_size() - 1] = value;
}

template<class T>
void ArrSeq<T>::Prepend(T value) {
    this->array->prepend(value);
}

template<class T>
void ArrSeq<T>::Insert(T value, int index) {
    if ((index < 0) || (index > array.get_size())) {
        throw -1;
    }
    else {
        this->array.insert(value, index);
    }
}

template<class T>
void ArrSeq<T>::Print() {
    this->array.printArr();
}

template<class T>
void ArrSeq<T>::Set(int index, T value)
{
    if ((index < 0) || (index >= GetSize()))
        throw -1;
    if (this->GetSize() == 0)
        this->array = DArray<T> (&value, 1);
    else
        (this->array[index]) = value;
}

template<class T>
void ArrSeq<T>::Resize(int new_size)
{
    if (new_size > 0)
        this->array.resize(new_size);
}

template<class T>
const T &ArrSeq<T>::operator[](int index) const {
    return array[index];
}

template<class T>
ArrSeq<T> &ArrSeq<T>::operator=(const ArrSeq<T> &arr) {
    this->array = arr.array;
    return *this;
}

template<class T>
DArray<T> ArrSeq<T>::GetArray() {
    return array;
}

template<class T>
int ArrSeq<T>::GetSize() const {
    return array.get_size();
}

template<class T>
ArrSeq<T> ArrSeq<T>::Remove(T value) {
    return ArrSeq<T> (array.Remove(value));
}

template<class T>
ArrSeq<T> ArrSeq<T>::Concat(ArrSeq<T> first, ArrSeq<T> second) {
    return ArrSeq<T> (first.array.concat(first.array, second.array));
}

template<class T>
ArrSeq<T> ArrSeq<T>::RemoveIndex(int idx) {
    return ArrSeq<T>(GetArray().RemoveIndex(idx));
}

template<class T>
void ArrSeq<T>::Swap(int f, int s) {
    this->array.swap (f, s);
}

template <class T>
std::ostream& operator<< (std::ostream& out, ArrSeq<T> arr)
{
    int size = arr.GetSize();
    for (int i = 0; i < size; i++)
        out << (arr.GetArray().GetData())[i] << " ";
    return out;
}


template<class T>
T &ArrSeq<T>::Iterator::operator+(int i) {
    return *(ptr + i);
}

template<class T>
T &ArrSeq<T>::Iterator::operator-(int i) {
    return *(ptr - i);
}

template<class T>
T &ArrSeq<T>::Iterator::operator--() {
    return (*(--ptr));
}

template<class T>
T &ArrSeq<T>::Iterator::operator++() {
    return *(++ptr);
}

template<class T>
bool ArrSeq<T>::Iterator::operator==(const ArrSeq::Iterator &it) {
    return (ptr == it.ptr);
}

template<class T>
bool ArrSeq<T>::Iterator::operator!=(const ArrSeq::Iterator &it) {
    return (ptr != it.ptr);
}

template<class T>
T &ArrSeq<T>::Iterator::operator*() {
    return *ptr;
}
