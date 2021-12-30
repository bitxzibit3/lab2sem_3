#include "Set.h"

template<class T>
Set<T>::Set() {
    data = ArrSeq<T>();
}

template<class T>
void Set<T>::Add(T item) {
    int size = data.GetSize();
    for (int i = 0; i < size; i++) {
        if (data[i] == item)
            return;
    }
    data.Append(item);
}

template<class T>
Set<T>::Set(const Set &set) {
    int size = set.data.GetSize();
    for (int i = 0; i < size; i++)
        data.Append ((set.data)[i]);
}

template<class T>
Set<T>::Set(ArrSeq<T> arr) {
    data = arr;
}

template<class T>
void Set<T>::Remove(T item) {
    int size = data.GetSize();
    for (int i = 0; i < size; i++)
        if ((*this)[i] == item)
        {
            for (int j = i; j < size - 1; j++)
                (*this)[j] = (*this)[j + 1];
            data.Resize(size - 1);
            return;
        }
}

template<class T>
T &Set<T>::operator[](int index) {
    return data[index];
}

template<class T>
const T &Set<T>::operator[](int index) const {
    return data[index];
}

template<class T>
ArrSeq<T> Set<T>::GetData() {
    return data;
}

template<class T>
int Set<T>::Size() {
    return data.GetSize();
}

template<class T>
bool Set<T>::HasItem(T item) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (*it == item)
            return true;
    }
    return false;
}

template<class T>
std::ostream &operator<<(std::ostream &out, Set<T> set) {
    ArrSeq<T> arr = set.GetData();
    for (auto it = arr.begin(); it != arr.end(); ++it)
        out << *it << " ";
    return out;
}

template<class T>
T &Set<T>::Iterator::operator--() {
    return *(--ptr);
}

template<class T>
T &Set<T>::Iterator::operator-(int n) {
    return *(ptr - n);
}

template<class T>
bool Set<T>::Iterator::operator==(const Set::Iterator &it) {
    return (ptr == it.ptr);
}

template<class T>
T &Set<T>::Iterator::operator+(int n) {
    return *(ptr + n);
}

template<class T>
T &Set<T>::Iterator::operator++() {
    return *(++ptr);
}

template<class T>
bool Set<T>::Iterator::operator!=(const Set::Iterator &it) {
    return (ptr != it.ptr);
}

template<class T>
T &Set<T>::Iterator::operator*() {
    return *ptr;
}
