//
// Created by Timur on 22.11.2021.
//

#ifndef LAB2_KNAPSTATE_H
#define LAB2_KNAPSTATE_H

#include "Knap.h"
#include "Set.h"

class KnapState
{
private:
    Knap knap;
    ArrSeq<Object> objects;
public:
    KnapState(Knap, ArrSeq<Object>);
    KnapState(Knap, Object);
    KnapState();
    Knap GetKnap ();
    ArrSeq<Object> GetObjects ();
    Object GetObject (int);
    int GetWeight ();
    int GetSize ();
    int GetCost ();
    Set<Object> UniqueObjects ();
    ArrSeq<KnapState> GetAllPoss ();
    KnapState& operator= (const KnapState&);
    bool HasPermutations ();
};

std::ostream& operator<< (std::ostream&, KnapState);

#endif //LAB2_KNAPSTATE_H
