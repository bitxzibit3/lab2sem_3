//
// Created by Timur on 20.11.2021.
//

#include "NTree.h"

template<class T>
ArrSeq<Node<T> *> Node<T>::GetChilds() {
    return childs;
}

template<class T>
void Node<T>::SetChild(T value, int index) {
    free (childs[index]);
    childs[index] = new Node(value);
}

template<class T>
Node<T>::Node(T value) {
    this->state = T (value);
    this->childs = ArrSeq<Node<T> *> ();
}


template<class T>
Node<T> &Node<T>::operator=(const Node<T> &node) {
    this->state = node.state;
    this->state = node.childs;
    return *this;
}

template<class T>
void Node<T>::AddChild(T item, int index) {
    childs.Insert(new Node<T> (item), index);
}

template<class T>
Node<T> *Node<T>::GetChild(int i) {
    return childs[i];
}

template<class T>
T Node<T>::GetState() {
    return state;
}

template<class T>
int Node<T>::GetChildCount() {
    return childs.GetSize();
}

template<class T>
void Node<T>::SetState(T new_item) {
    this->state = new_item;
    std::cout << this->state;
}

template<class T>
void Node<T>::AddChild(T item) {
    childs.Append (new Node<T>(item));
}

template<class T>
ArrSeq<Node<T> *> NTree<T>::GetLeavesPtr(Node<T> *start) {
    ArrSeq<Node<T> *> array;
    ArrSeq<Node<T> *> childs = start->GetChilds();
    if (start->GetChildCount() == 0)
        array.Append(start);
    for (auto it = childs.begin(); it != childs.end(); ++it)
        array = array.Concat(array, GetLeavesPtr(*it));
    return array;
}


template<class T>
NTree<T>::NTree() {
    root = nullptr;
}

template<class T>
Node<T> *NTree<T>::GetRoot() {
    return root;
}

template<class T>
Node<T> *NTree<T>::Find(T item, Node<T> *start) {
    if (start == nullptr)
        return nullptr;
    if (start->GetState() == item)
        return start;
    int size = start->GetChildCount();
    for (int i = 0; i < size; i++)
    {
        Node<T> *ans = Find (item, start->GetChild(i));
        if (ans != nullptr)
            return ans;
    }
    return nullptr;
}

template<class T>
Node<T> *NTree<T>::Find(T item) {
    return Find(item, root);
}

template<class T>
void NTree<T>::Add(T value, T parent, int index) {
    Node<T> *par = Find (parent);
    if (par != nullptr)
        par->AddChild(value, index);
}

template<class T>
NTree<T>::NTree(T root_item) {
    if (root == nullptr)
        root = new Node<T> (root_item);
    else
        root->SetState(root_item);
}

template<class T>
ArrSeq<Node<T> *> NTree<T>::GetLeavesPtr() {
    return GetLeavesPtr(GetRoot());
}

template<class T>
void NTree<T>::Print(Node<T> *start) {
    std::cout << start->GetState() << " ";
    ArrSeq<Node <T> *> childs = start->GetChilds();
    for (auto it = childs.begin(); it != childs.end(); ++it)
        Print (*it);
}

template<class T>
void NTree<T>::Print() {
    Print (GetRoot());
}


void MakeTree(Node<KnapState> *start) {
    if (start->GetState().HasPermutations())
    {
        Knap KnapTemp = start->GetState().GetKnap();
        ArrSeq<Object> ObjectTemp = start->GetState().GetObjects();
        Set<Object> set;
        for (auto it = ObjectTemp.begin(); it != ObjectTemp.end(); ++it)
        {
            if (!set.HasItem(*it)) {
                set.Add(*it);
                ArrSeq<Object> variatives = (*it).GetAllObjects();
                for (auto now_item = variatives.begin(); now_item != variatives.end(); ++now_item) {
                    ArrSeq<Pair<int, int>> places = start->GetState().GetKnap().PossiblePlaces(*now_item);
                    for (auto place = places.begin(); place != places.end(); ++place)
                        start->AddChild(KnapState(KnapTemp.Add(*now_item, *place), ObjectTemp.Remove(*it)));
                }
            }
        }
    }
    ArrSeq<Node<KnapState> *> childs = start->GetChilds();
    for (auto it = childs.begin(); it != childs.end(); ++it)
        MakeTree((*it));
}

template<class T>
std::ostream &operator<<(std::ostream &out, Node<T> node) {
    out << node.GetState();
    return out;
}
