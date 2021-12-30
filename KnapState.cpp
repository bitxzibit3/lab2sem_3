//
// Created by Timur on 22.11.2021.
//

#include "KnapState.h"

Knap KnapState::GetKnap() {
    return knap;
}

ArrSeq<Object> KnapState::GetObjects() {
    return objects;
}

Object KnapState::GetObject(int index) {
    return objects[index];
}

int KnapState::GetWeight() {
    return knap.GetWeight();
}

KnapState::KnapState(Knap knap1, ArrSeq<Object> objs1) {
    this->knap = knap1;
    this->objects = objs1;
}

ArrSeq<KnapState> KnapState::GetAllPoss() {
    if (!objects.GetSize())
        return ArrSeq<KnapState>();
    ArrSeq<KnapState> rez;
    Set<Object> set;
    for (auto it = objects.begin(); it != objects.end(); ++it)
    {
        if (!set.HasItem(*it)) {
            set.Add(*it);
            ArrSeq<Object> variatives = (*it).GetAllObjects();
            for (auto now_item = variatives.begin(); now_item != variatives.end(); ++now_item) {
                ArrSeq<Pair<int, int>> places = knap.PossiblePlaces(*now_item);
                for (auto place = places.begin(); place != places.end(); ++place)
                    rez.Append(KnapState(knap.Add(*now_item, *place), objects.Remove(*it)));
            }
        }
    }
    return rez;
}

KnapState::KnapState(Knap knap, Object obj) {
    this->knap = knap;
    ArrSeq<Object> ans;
    ans.Append(obj);
    this->objects = ans;
}

int KnapState::GetSize() {
    return knap.GetSize();
}

Set<Object> KnapState::UniqueObjects() {
    Set<Object> set;
    for (auto it = objects.begin(); it != objects.end(); ++it)
    {
        ArrSeq<Object> turns = (*it).GetAllObjects();
        bool flag = 1;
        for (auto it_turn = turns.begin(); it_turn != turns.end(); ++it_turn)
        {
            if (set.HasItem(*it_turn)) {
                flag = false;
                break;
            }
        }
        if (flag)
            set.Add (*it);
    }
    return set;
}

KnapState &KnapState::operator=(const KnapState &knap1) {
    this->knap = knap1.knap;
    this->objects = knap1.objects;
    return *this;
}

KnapState::KnapState() {
    this->knap = Knap();
    this->objects = ArrSeq<Object> ();
}

bool KnapState::HasPermutations() {
    Pair<int, int> temp_pair (-1, -1);
    for (auto obj1 = objects.begin(); obj1 != objects.end(); ++obj1) {
        ArrSeq<Object> objects1 = (*obj1).GetAllObjects();
        for (auto obj = objects1.begin(); obj != objects1.end(); ++obj)
            if (knap.IsFit(*obj) != temp_pair)
                return true;
    }
    return false;
}

std::ostream& operator<< (std::ostream& out, KnapState knap)
{
    out << "Now knap: ";
    out << std::endl;
    out << knap.GetKnap() << std::endl;
    out << "Remain objects: ";
    out << std::endl;
    out << knap.GetObjects();
    out << std::endl;
    return out;
}