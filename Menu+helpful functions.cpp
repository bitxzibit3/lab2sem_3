//
// Created by Timur on 18.12.2021.
//

#include "Menu+helpful functions.h"

std::string MSGS[] = {"0. Quit", "1. Volume knap task (weight limit)", "2. Volume knap task (weight min)",
                      "3. Search for the most frequent subsequences by length",
                      "4. Search for the most frequent subsequences by relative valuation"};

int MSGS_SIZE = sizeof(MSGS)/sizeof(MSGS[0]);

void dialog() {
    int choice = 1;
    while (true)
    {
        std::cout << "Make your choice:" << std::endl;
        for (int i = 0; i < MSGS_SIZE; i++)
            std::cout << MSGS[i] << std::endl;
        std::cin >> choice;
        switch (choice)
        {
            case (0):
                return;
            case(1):
            {
                int limit;
                std::cout << "Input weight limit : ";
                std::cin >> limit;
                std::cout << GetKnapAnswer1 (limit);
                break;
            }
            case (2):
            {
                std::cout << GetKnapAnswer2();
                break;
            }
            case (3):
            {
                std::cout << "Input string : ";
                std::string data;
                std::cin >> data;
                ArrSeq<char> str (StrToChar(data), data.length());
                int min, max;
                std::cout << "Input min and max length of strings : ";
                std::cin >> min >> max;
                ArrSeq<Pair<ArrSeq<char>, int> > array;
                array = mfs(str, min, max);
                array = sort_mfs(array);
                std::cout << array << std::endl;
                break;
            }
            case (4):
            {
                std::cout << "Input string : ";
                std::string data;
                std::cin >> data;
                ArrSeq<char> str (StrToChar(data), data.length());
                int length = str.GetSize();
                ArrSeq<Pair<ArrSeq<char>, int> > array = mfs(str, 1, length);
                array = sort_mfs_relative(array, length);
                for (auto it = array.begin(); it != array.end(); ++it)
                    std::cout << (*it).GetFirst() << " was met " << (*it).GetSecond() << " with valuation = " << mfs_valuation (*it, length) << std::endl;
                break;
            }
            default:
            {
                std::cout << "You made a wrong choice!" << std::endl;
                break;
            }
        }
    }
}

NTree <KnapState> input_volume() {
    std::cout << "Enter knap parameters: dimendions, params" << std::endl;
    int m, n;
    std::cin >> m >> n;
    Knap knap(m, n);
    ArrSeq<Object> objects;
    std::cout << "Enter number of items: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int m1, n1, weight, cost;
        std::cout << "Enter item weight: ";
        std::cin >> weight;
        std::cout << "Enter item cost: ";
        std::cin >> cost;
        std::cout << "Enter item dimensions: ";
        std::cin >> m1 >> n1;
        std::cout << "Enter object params: " << std::endl;
        objects.Append(Object(weight, m1, n1, cost));
    }
    KnapState state(knap, objects);
    NTree<KnapState> tree(state);
    MakeTree(tree.GetRoot());
    return tree;
}

KnapState GetKnapAnswer1(int limit) {
    NTree<KnapState> tree = input_volume();
    ArrSeq<Node<KnapState> *> states = tree.GetLeavesPtr();
    KnapState ans = (states[0])->GetState();
    for (auto it = states.begin(); it != states.end(); ++it) {
        KnapState tmp = (*it)->GetState();
        if (tmp.GetWeight() <= limit) {
            if (tmp.GetCost() > ans.GetCost())
                ans = tmp;
            else if (tmp.GetCost() == ans.GetCost())
                if (tmp.GetWeight() < ans.GetWeight())
                    ans = tmp;
        }
    }
    std::cout << "Ans weight " << ans.GetWeight() << ", ans cost = " << ans.GetKnap().GetCost() << std::endl;
    return ans;
}

KnapState GetKnapAnswer2() {
    NTree<KnapState> tree = input_volume();
    ArrSeq<Node<KnapState> *> states = tree.GetLeavesPtr();
    KnapState ans = (states[0])->GetState();
    for (auto it = states.begin(); it != states.end(); ++it)
    {
        KnapState tmp = (*it)->GetState();
        if (tmp.GetCost() > ans.GetCost())
            ans = tmp;
        else if (tmp.GetCost() == ans.GetCost())
            if (tmp.GetWeight() < ans.GetWeight())
                ans = tmp;
    }
    std::cout << "Ans weight " << ans.GetWeight() << ", ans cost = " << ans.GetCost() << std::endl;
    return ans;
}

ArrSeq<char> SubStr (ArrSeq<char> str, int beg, int end)
{
    ArrSeq<char> ans;
    for (int i = beg; i < end; i++)
        ans.Append(str[i]);
    return ans;
}

ArrSeq<Pair<ArrSeq<char>, int> > sort_mfs (ArrSeq<Pair<ArrSeq<char>, int> > orig)
{
    int size = orig.GetSize();
    for (int i = 0; i < size; i++)
        for (int j = i; j < size; j++)
            if (orig[i].GetSecond() > orig[j].GetSecond())
                orig.Swap(i, j);
    return ArrSeq<Pair<ArrSeq<char>, int> > (orig);
}

float mfs_valuation (Pair <ArrSeq<char>, int> pair, int length)
{
    return ((float)pair.GetFirst().GetSize() / (float)length)*((float)(pair.GetSecond())) * ((float)pair.GetFirst().GetSize() / (float)length);
}

ArrSeq<Pair<ArrSeq<char>, int> > sort_mfs_relative(ArrSeq<Pair<ArrSeq<char>, int> > orig, int length)
{
    int size = orig.GetSize();
    for (int i = 0; i < size; i++)
        for (int j = i; j < size; j++)
            if (mfs_valuation(orig[i], length) < mfs_valuation((orig[j]), length))
                orig.Swap(i, j);
    return ArrSeq<Pair<ArrSeq<char>, int> > (orig);
}

ArrSeq<Pair<ArrSeq<char>, int>> mfs(ArrSeq<char> str, int min, int max) {
    ArrSeq<Pair<ArrSeq<char>, int> > arr;
    int size = str.GetSize();
    for (int begin = 0; begin < size; begin++) {
        for (int length = min; length <= max; length++) {
            if (begin + length > size)
                break;
            ArrSeq<char> sstr = SubStr(str, begin, begin + length);
            bool flag = false;
            for (auto it = arr.begin(); it != arr.end(); ++it)
            {
                if ((*it).GetFirst() == sstr)
                {
                    flag = true;
                    (*it).SetSecond((*it).GetSecond() + 1);
                    break;
                }
            }
            if (!flag)
            {
                Pair<ArrSeq<char>, int> pair (sstr, 1);
                arr.Append(pair);
            }
        }
    }
    return arr;
}

bool operator==(ArrSeq<char> first, ArrSeq<char> second) {
    if (first.GetSize() == second.GetSize()) {
        for (int i = 0; i < first.GetSize(); i++)
            if (first[i] != second[i])
                return false;
        return true;
    }
    return false;
}

char *StrToChar(std::string str) {
    int size = str.length();
    char *ans = (char *) calloc (size, sizeof(char));
    for (int i = 0; i < size; i++)
        ans[i] = str[i];
    return ans;
}

