//
// Created by Timur on 20.11.2021.
//

#include "Body.h"

Object::Object(int weight, int hor, int ver, int cost) {
    this->weight = weight;
    this->cost = cost;
    size = 0;
    this->params = read_params(hor, ver);
    for (int i = 0; i < hor; i++) {
        for (int j = 0; j < ver; j++) {
            if (params[i][j])
                size++;
        }
    }
    Fit();
    shapes = 1;

}

Object::Object() {
    weight = 0;
    params = ArrSeq<ArrSeq<bool>>();
    shapes = 0;
    cost = 0;
}

int Object::GetSize() {
    return size;
}

int Object::GetWeight() {
    return weight;
}

int Object::GetHor() {
    return params.GetSize();
}

int Object::GetVer() {
    return (params[0]).GetSize();
}

bool Object::GetCell(int i, int j) {
    return params[i][j];
}

bool Object::operator==(const Object &obj) {
    int ver = GetVer(), hor = GetHor();
    if ((size != obj.GetSize()) || (ver != obj.GetVer()) || (hor != obj.GetHor()) || (weight != obj.weight) || (cost != obj.cost))
        return false;
    for (int i = 0; i < hor; i++)
        for (int j = 0; j < ver; j++)
            if ((params[i])[j] != ((obj.params)[i])[j])
                return false;
    return true;
}

void Object::Fit() {
    bool flag = false;
    int hor = GetHor(), ver = GetVer();
    while (!flag) {
        for (int i = 0; i < ver; i++) //Last line fit
        {
            if (params[hor - 1][i]) {
                flag = true;
                break;
            }
        }
        if (!flag)
            params.Resize(--hor);
    }
    hor = GetHor(), ver = GetVer();
    flag = false; //Last column fit
    while (!flag) {
        for (int i = 0; i < hor; i++)
        {
            if (params[i].GetLast()) {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            for (int line = 0; line < hor; line++)
                (params[line]).Resize((params[line]).GetSize() - 1);
        }
    }
    hor = GetHor(), ver = GetVer();
    flag = false;
    while (!flag) {
        for (int i = 0; i < ver; i++) //First line fit
        {
            if (params[0][i]) {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            for (int i = 0; i < hor - 1; i++)
                params.Set(i, params[i + 1]);
            params.Resize(params.GetSize() - 1);
        }
    }
    hor = GetHor(), ver = GetVer();
    flag = false; //First column fit
    while (!flag) {
        for (int i = 0; i < hor; i++)
        {
            if (params[i][0]) {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            for (int line = 0; line < hor; line++) {
                for (int column = 0; column < ver - 1; column++)
                    params[line][column] = params[line][column + 1];
                params[line].Resize(params[line].GetSize() - 1);
            }
        }
    }
}

Object Object::Reverse() {
    int hor = GetHor(), ver = GetVer();
    ArrSeq<ArrSeq<bool>> obj_data;
    for (int i = 0; i < hor; i++)
    {
        obj_data.Append (ArrSeq<bool>());
        for (int j = 0; j < ver; j++)
            obj_data[i].Append(params[i][ver - 1 - j]);
    }
    return Object (weight, hor, ver, cost, obj_data);
}


Object::Object(int weight, int hor, int ver, int cost, ArrSeq<ArrSeq<bool>> mas) {
    this->weight = weight;
    size = 0;
    this->cost = cost;
    params = mas;
    for (int i = 0; i < hor; i++) {
        ArrSeq<bool> tmp = params[i];
        for (int j = 0; j < ver; j++) {
            if (tmp[j])
                size++;
        }
    }
    shapes = 1;
}

Object Object::Turn90() {
    int hor = GetHor(), ver = GetVer();
    ArrSeq<ArrSeq<bool>> obj_data;
    for (int i = 0; i < ver; i++)
    {
        obj_data.Append(ArrSeq<bool>());
        for (int j = 0; j < hor; j++)
            obj_data[i].Append(params[hor - 1 - j][i]);
    }
    return Object (weight, ver, hor, cost, obj_data);
}

Object Object::Turn180() {
    int hor = GetHor(), ver = GetVer();
    ArrSeq<ArrSeq<bool>> obj_data;
    for (int i = 0; i < hor; i++)
    {
        obj_data.Append(ArrSeq<bool>());
        for (int j = 0; j < ver; j++)
            obj_data[i].Append(params[hor - 1 - i][ver - 1 - j]);
    }
    return Object(weight, hor, ver, cost, obj_data);
}

Object Object::Turn270() {
    ArrSeq<ArrSeq<bool>> obj_data;
    int hor = GetHor(), ver = GetVer();
    for (int i = 0; i < ver; i++)
    {
        obj_data.Append(ArrSeq<bool>());
        for (int j = 0; j < hor; j++)
            obj_data[i].Append(params[j][ver - 1 - i]);
    }
    return Object (weight, ver, hor, cost, obj_data);
}

ArrSeq<Object> Object::GetAllObjects() {
    ArrSeq<Object> rez;
    rez.Append(Object(*this));
    Object tmp = Turn90();
    for (int i = 0; i < 3; i++) {
        bool flag = true;
        for (auto it = rez.begin(); it != rez.end(); ++it) {
            if (tmp == *it) {
                flag = false;
                break;
            }
        }
        if (flag)
            rez.Append(tmp);
        tmp = tmp.Turn90();
    }
    tmp = this->Reverse();
    for (int i = 0; i < 3; i++) {
        bool flag = true;
        for (int j = 0; j < rez.GetSize(); j++) {
            if (tmp == rez[j]) {
                flag = false;
                break;
            }
        }
        if (flag)
            rez.Append(tmp);
        tmp = tmp.Turn90();
    }
    shapes = rez.GetSize() - 1;
    return rez;
}

bool Object::operator!=(const Object& obj) {
    return !(*this == obj);
}

Object::Object(Object const &obj) {
    weight = obj.weight;
    shapes = obj.shapes;
    cost = obj.cost;
    size = obj.size;
    for (int i = 0; i < obj.GetHor(); i++)
    {
        params.Append(ArrSeq<bool>());
        for (int j = 0; j < obj.GetVer(); j++)
            params[i].Append(obj.params[i][j]);
    }
}

int Object::GetShapes() {
    return shapes;
}

int Object::GetHor() const {
    return params.GetSize();
}

int Object::GetVer() const {
    return params[0].GetSize();
}

Object &Object::operator=(const Object &obj) {
    this->shapes = obj.shapes;
    this->weight = obj.weight;
    this->size = obj.size;
    this->params = obj.params;
    this->cost = obj.cost;
    return *this;
}

int Object::GetSize() const {
    return size;
}

int Object::GetWeight() const {
    return weight;
}

int Object::GetCost() {
    return cost;
}

int Object::GetCost() const {
    return cost;
}

ArrSeq<ArrSeq<bool>> read_params (int hor, int ver) {
//    std::cout << "Input matrix " << hor << "x" << ver << std::endl;
    ArrSeq<ArrSeq<bool>> params;
    for (int i = 0; i < hor; i++) {
        params.Append (ArrSeq<bool>());
        for (int j = 0; j < ver; j++) {
            int t;
            std::cin >> t;
            (params[i]).Append(t == 1);
        }
    }
    return params;
}

std::ostream &operator<<(std::ostream &out, Object obj) {
    for (int i = 0; i < obj.GetHor(); i++) {
        for (int j = 0; j < obj.GetVer(); j++)
            out << obj.GetCell(i, j) << " ";
        out << std::endl;
    }
    return out;
}
