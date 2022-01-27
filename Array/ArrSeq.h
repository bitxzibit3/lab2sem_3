//
// Created by Timur on 28.04.2021.
//

#ifndef LAB2_VECTOR_ARRSEQ_H
#define LAB2_VECTOR_ARRSEQ_H
//#include "DynArray.h"
#include "DynArray.cpp"

template <class T>
class ArrSeq
{
protected:
    DArray<T> array;
public:
    class Iterator
    {
    private:
        T* ptr;
    public:
        Iterator (T* first) : ptr (first){}
        T& operator+ (int);
        T& operator- (int);
        T& operator++();
        T& operator--();
        bool operator== (const Iterator&);
        bool operator!= (const Iterator&);
        T& operator* ();
    };
    ArrSeq ();
    ArrSeq (DArray<T>);
    ArrSeq (ArrSeq<T> const &);
    ArrSeq (T *, int);
    T GetFirst ();
    T GetLast ();
    T Get (int, int *);
    T Get (int);
    void Set (int, T);
    void Resize (int);
    ArrSeq<T> Remove (T);
    ArrSeq<T> Concat (ArrSeq<T>, ArrSeq<T>);
    ArrSeq<T> RemoveIndex (int);
    int GetSize ();
    int GetSize () const;
    DArray<T> GetArray ();
    void Append (T);
    void Prepend (T);
    void Insert (T, int);
    void Print ();
    void Swap (int, int);
    T& operator[] (int);
    const T& operator[] (int) const;
    ArrSeq<T>& operator= (const ArrSeq<T> &);
    Iterator begin() {return array.GetData();};
    Iterator end() {return (array.GetData() + array.get_size());};
};

template <class T>
std::ostream& operator<< (std::ostream&, ArrSeq<T>);

#endif //LAB2_VECTOR_ARRSEQ_H
