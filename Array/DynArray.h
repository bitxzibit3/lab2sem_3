//
// Created by Timur on 30.03.2021.
//

#ifndef LAB2_VECTOR_DYNARRAY_H
#define LAB2_VECTOR_DYNARRAY_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

template <class T> class DArray
{
protected:
    T *data = NULL;
    int size;
public:
    DArray ();
    DArray (T*, int);
    DArray (const DArray<T>&);
    DArray<T>& operator= (const DArray<T> &);
    void append(T);
    T* GetData ();
    void prepend (T);
    void insert (T, int);
    void swap (int, int);
    int get_size();
    const int get_size() const;
    void resize(int);
    void printArr ();
    DArray<T> Remove (T);
    DArray<T> RemoveIndex (int);
    DArray<T> GetSubArray (int, int);
    DArray<T> concat (DArray<T> , DArray<T>);
    T& operator[] (int);
    const T& operator[] (int) const;
  //  ~DArray();
};

template<class T>
std::ostream& operator<< (std::ostream&, DArray<T>);

#endif //LAB2_VECTOR_DYNARRAY_H
