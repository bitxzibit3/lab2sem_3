//
// Created by Timur on 03.11.2021.
//

#include "Dictionary.h"


template<class T, class P>
Dictionary<T, P>::Dictionary() {
    array = (Pair <T, P> *) calloc (1, sizeof(Pair<T, P>));
    size = 0;
}

template<class T, class P>
void Dictionary<T, P>::Add(Pair<T, P> pair)
{
    size++;
    array = (Pair<T, P> *) realloc (array, sizeof(Pair<T, P>) * size);
    array[size - 1] = pair;
}

template<class T, class P>
size_t Dictionary<T, P>::GetSize() {
    return size;
}

template<class T, class P>
P Dictionary<T, P>::Get(T key) {
    for (size_t i = 0; i < size; i++)
        if (array[i].GetFirst() == key)
            return array[i].GetSecond();
}

template<class T, class P>
bool Dictionary<T, P>::IsKey(T key) {
    for (size_t i = 0; i < size; i++)
        if (array[i].GetFirst() == key) {
            return true;
        }
    return false;
}

template<class T, class P>
void Dictionary<T, P>::Add(T key, P value) {
    Add (make_pair(key, value));
}

