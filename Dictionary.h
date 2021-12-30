//
// Created by Timur on 03.11.2021.
//

#ifndef LAB2_DICTIONARY_H
#define LAB2_DICTIONARY_H

#include "Pair.h"

template <class T, class P>
class Dictionary
{
private:
    size_t size;
    Pair<T, P> *array;
public:
    Dictionary();
    void Add (Pair<T, P>);
    void Add (T, P);
    //void Delete ();
    P Get (T);
    bool IsKey (T);
    size_t GetSize ();
};


#endif //LAB2_DICTIONARY_H
