//
// Created by Timur on 20.11.2021.
//

#include "Knap.h"

Knap::Knap() {
    size = 0;
    now_weight = 0;
    now_cost = 0;
    param = ArrSeq<ArrSeq<bool>>();
}

Knap::Knap(int h, int v) {
    now_weight = 0;
    size = 0;
    now_cost = 0;
    param = read_params (h, v);
    for (int i = 0; i < h; i++) {
        ArrSeq<bool> tmp = param[i];
        for (int j = 0; j < v; j++)
            if (!(tmp[j]))
                size++;
    }
}

Pair<int, int> Knap::IsFit(Object obj) {
    if (obj.GetSize() > size)
        return make_pair<int, int>(-1, -1);
    int Hor = obj.GetHor(), Ver = obj.GetVer(), hor = param.GetSize(), ver = (param[0]).GetSize();
    for (int line = 0; line < hor; line++)
        for (int col = 0; col < ver; col++) {
            int flag = 0;
            for (int obj_line = 0; obj_line < Hor; obj_line++) {
                for (int obj_col = 0; obj_col < Ver; obj_col++) {
                    if (obj.GetCell(obj_line, obj_col)) {
                        if ((line + obj_line < hor) && (col + obj_col < ver)) {
                            if (param[line + obj_line][col + obj_col]) {
                                flag = 1;
                                break;
                            }
                        }
                        else {
                            flag = 1;
                            break;
                        }
                    }
                }
                if (flag == 1)
                    break;
            }
            if (flag == 0)
                return make_pair<int, int>(line, col);
        }
    return make_pair<int, int>(-1, -1);
}

Knap Knap::Add(Object obj, Pair <int, int> place) {
    Knap knap (*this);
    if (place.GetFirst() == -1)
        return knap;
    int Hor = obj.GetHor(), Ver = obj.GetVer(), first = place.GetFirst(), second = place.GetSecond();
    for (int i = first; i < first + Hor; i++) {
        for (int j = second; j < second + Ver; j++) {
            if (obj.GetCell(i - first, j - second))
                knap.FillCell(i, j);
        }
    }
    knap.SetSize(size - obj.GetSize());
    knap.SetWeight(now_weight + obj.GetWeight());
    knap.SetCost (now_cost + obj.GetCost());
    return knap;
}

int Knap::GetSize() {
    return size;
}

void Knap::PrintInfo() {
    std::cout << *this << std::endl << "Knap weight = " << now_weight << ", now_cost = " << now_cost;
}

ArrSeq<Pair<int, int>> Knap::PossiblePlaces(Object obj) {
    ArrSeq<Pair<int, int>> rez;
    int flag = 0, hor = GetHor(), ver = GetVer();
    for (int i = 0; i < hor; i++)
        for (int j = 0; j < ver; j++) {
            Pair<int, int> t = make_pair(i, j);
            if (IsFit(obj, t))
                rez.Append(t);
        }
    return rez;
}

bool Knap::IsFit(Object obj, Pair<int, int> pair) {
    if (obj.GetSize() > size)
        return false;
    int Hor = obj.GetHor(), Ver = obj.GetVer(), line = pair.GetFirst(), col = pair.GetSecond(), flag = 0;
    for (int obj_line = 0; obj_line < Hor; obj_line++)
    {
        for (int obj_col = 0; obj_col < Ver; obj_col++)
        {
            if (obj.GetCell(obj_line, obj_col)) {
                if ((line + obj_line < GetHor()) && (col + obj_col < GetVer()))
                {
                    if ((param[line + obj_line])[col + obj_col])
                    {
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1)
            break;
    }
    if (flag == 0)
        return true;
    return false;
}

Knap::Knap(const Knap& knap) {
    size = knap.size;
    now_weight = knap.now_weight;
    now_cost = knap.now_cost;
    int hor = knap.GetHor(), ver = knap.GetVer();
    for (int i = 0; i < hor; i++)
    {
        param.Append (ArrSeq<bool>());
        for (int j = 0; j < ver; j++)
            param[i].Append(knap.param[i][j]);
    }
}

void Knap::FillCell(int i, int j) {
    param[i][j] = true;
}

void Knap::SetSize(int new_size) {
    size = new_size;
}

void Knap::SetWeight(int new_weight) {
    now_weight = new_weight;
}

int Knap::GetHor() {
    return param.GetSize();
}

int Knap::GetHor() const {
    return param.GetSize();
}

int Knap::GetVer() {
    return (param[0]).GetSize();
}

int Knap::GetVer() const {
    return (param[0]).GetSize();
}

ArrSeq<ArrSeq<bool>> Knap::GetParam() {
    return param;
}

int Knap::GetWeight() {
    return now_weight;
}

Knap &Knap::operator=(const Knap &knap1) {
    this->param = knap1.param;
    this->size = knap1.size;
    this->now_weight = knap1.now_weight;
    this->now_cost = knap1.now_cost;
    return *this;
}

int Knap::GetCost() {
    return now_cost;
}

void Knap::SetCost(int value) {
    now_cost = value;
}


std::ostream &operator<<(std::ostream &out, Knap knap) {
    int hor = knap.GetHor();
    for (int i = 0; i < hor; i++) {
        out << knap.GetParam()[i];
        out << std::endl;
    }
    return out;
}
