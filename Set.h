#ifndef LAB2_SET_H
#define LAB2_SET_H

#include "Array/ArrSeq.h"

template <class T>
class Set
{
private:
    ArrSeq<T> data;
public:

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
};

template<class T>
std::ostream& operator<< (std::ostream&, Set<T>);

#endif //LAB2_SET_H
