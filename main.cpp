#include "./Array/ArrSeq.cpp"
#include "Pair.cpp"
#include "Body.cpp"
#include "Knap.cpp"
#include "KnapState.cpp"
#include "Set.cpp"
#include "NTree.cpp"
#include "Menu+helpful functions.cpp"
#include "Dictionary.cpp"


int main() {
//    dialog();
    Dictionary<int> dict;
    int *a = new int (13);
    std::string s = "abcd";
    dict.Add(s, a);
    std::cout << dict.ContainsKey("abcd");
    return 0;
}


