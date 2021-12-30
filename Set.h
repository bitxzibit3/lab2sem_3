#ifndef LAB2_SET_H
#define LAB2_SET_H

#include "Array/ArrSeq.h"

template <class T>
class Set
{
private:
    ArrSeq<T> data;
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
    Set ();
    Set (const Set&);
    Set (ArrSeq<T>);
    void Add (T);
    void Remove (T);
    int Size ();
    bool HasItem (T);
    ArrSeq<T> GetData ();
    T& operator[] (int);
    const T& operator[] (int) const;
    Iterator begin() {return (data.GetArray().GetData());};
    Iterator end() {return (data.GetArray().GetData() + (data.GetArray().get_size()));};
};

template<class T>
std::ostream& operator<< (std::ostream&, Set<T>);

#endif //LAB2_SET_H
