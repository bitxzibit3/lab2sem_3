//
// Created by Timur on 20.11.2021.
//

#ifndef LAB2_KNAP_H
#define LAB2_KNAP_H

#include "Body.h"

class Knap
{
private:
    int size, now_weight, now_cost;
    ArrSeq<ArrSeq<bool>> param;
public:
    Knap ();
    Knap (const Knap&);
    Knap (int, int);
    int GetSize ();
    int GetWeight ();
    int GetCost ();
    void SetCost (int);
    void SetSize (int);
    void SetWeight (int);
    int GetHor ();
    int GetHor () const;
    int GetVer ();
    int GetVer () const;
    Pair<int, int> IsFit (Object);
    bool IsFit (Object, Pair<int, int>);
    Knap Add (Object, Pair <int, int>);
    void FillCell (int, int);
    ArrSeq<Pair<int, int>> PossiblePlaces (Object);
    void PrintInfo ();
    ArrSeq<ArrSeq<bool>> GetParam ();
    Knap& operator= (const Knap&);
};

std::ostream& operator<< (std::ostream&, Knap);

#endif //LAB2_KNAP_H
