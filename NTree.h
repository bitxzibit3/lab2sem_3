//
// Created by Timur on 20.11.2021.
//

#ifndef LAB2_NTREE_H
#define LAB2_NTREE_H

//#include "Knap.h"
#include "KnapState.h"


template <class T>
class Node
{
private:
    T state;
    ArrSeq<Node<T> *> childs;
public:
    Node (T);
    T GetState ();
    ArrSeq<Node<T> *> GetChilds ();
    void SetChild (T, int);
    void AddChild (T);
    void AddChild (T, int);
    Node<T> *GetChild (int);
    int GetChildCount ();
    Node<T>& operator= (const Node<T>&);
    void SetState (T);
};

template <class T>
class NTree
{
private:
    Node<T> *root = nullptr;
    Node<T> *Find (T, Node<T> *);
    ArrSeq<Node<T> *> GetLeavesPtr (Node<T> *);
    void Print (Node<T> *);
public:
    NTree();
    NTree(T);
    void Add (T, T, int);
    Node<T> *GetRoot ();
    Node<T> *Find (T);
    void Print ();
    ArrSeq<Node<T> *> GetLeavesPtr ();
};

template <class T>
std::ostream& operator<< (std::ostream &, Node<T>);

void MakeTree (Node<KnapState> *);

#endif //LAB2_NTREE_H