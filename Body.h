//
// Created by Timur on 20.11.2021.
//

#ifndef LAB2_BODY_H
#define LAB2_BODY_H


#include <iostream>
#include "./Array/ArrSeq.h"


class Object
{
private:
    int weight, size, shapes, cost;
    ArrSeq<ArrSeq<bool>> params;
public:
    Object(int, int, int, int);
    Object(int, int, int, int, ArrSeq<ArrSeq<bool>>);
    Object();
    Object (const Object&);
    int GetSize ();
    int GetSize () const;
    int GetWeight ();
    int GetWeight () const;
    int GetCost ();
    int GetCost () const;
    int GetHor ();
    int GetVer ();
    int GetShapes ();
    bool GetCell (int, int);
    bool operator== (const Object&);
    bool operator!= (const Object&);
    void Fit ();
    Object Reverse ();
    Object Turn90 ();
    Object Turn180 ();
    Object Turn270 ();
    ArrSeq<Object> GetAllObjects ();
    int GetHor () const;
    int GetVer () const;
    Object& operator= (const Object&);
};

ArrSeq<ArrSeq<bool>> read_params (int, int);

std::ostream& operator<< (std::ostream&, Object);

#endif //LAB2_BODY_H
