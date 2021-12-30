#ifndef LAB2_PAIR_H
#define LAB2_PAIR_H

#include <cstdlib>
#include <iostream>

template <class T, class P>
class Pair
{
private:
    T first;
    P second;
public:
    Pair (T, P);
    T GetFirst ();
    P GetSecond ();
    void SetFirst (T);
    void SetSecond (P);
    bool operator== (const Pair<T, P> &);
    bool operator!= (const Pair<T, P> &);
    Pair<T, P> &operator= (const Pair<T, P> &);
};

template <class T, class P>
Pair<T, P> make_pair (T, P);

template <class T, class P>
std::ostream& operator<< (std::ostream&, Pair<T, P> pair);

#endif //LAB2_PAIR_H
