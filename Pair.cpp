//
// Created by Timur on 03.11.2021.
//

#include "Pair.h"


template<class T, class P>
Pair<T, P>::Pair(T First, P Second) {
    first = First;
    second = Second;
}

template<class T, class P>
T Pair<T, P>::GetFirst() {
    return first;
}

template<class T, class P>
P Pair<T, P>::GetSecond() {
   return second;
}

template<class T, class P>
void Pair<T, P>::SetFirst(T value) {
    first = value;
}

template<class T, class P>
void Pair<T, P>::SetSecond(P value) {
    second = value;
}

template<class T, class P>
bool Pair<T, P>::operator==(const Pair<T, P> &pair) {
    return ((first == pair.first) && (second == pair.second));
}

template<class T, class P>
Pair<T, P> &Pair<T, P>::operator=(const Pair<T, P> &pair) {
    first = pair.first;
    second = pair.second;
    return *this;
}

template<class T, class P>
bool Pair<T, P>::operator!=(const Pair<T, P> &pair) {
    return !((first == pair.first) && (second == pair.second));
}


template <class T, class P>
Pair<T, P> make_pair (T First, P Second) {
    return Pair<T, P>(First, Second);
}

template<class T, class P>
std::ostream& operator<< (std::ostream& out, Pair<T, P> pair) {
    out << "(" << pair.GetFirst() << "; " << pair.GetSecond() << ")";
    return out;
};
