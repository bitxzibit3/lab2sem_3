#include "./Array/ArrSeq.cpp"
#include "Pair.cpp"
#include "Body.cpp"
#include "Knap.cpp"
#include "KnapState.cpp"
#include "Set.cpp"
#include "NTree.cpp"
#include "Menu+helpful functions.cpp"
#include <fstream>

int main() {
//    std::ifstream in ("C:\\Users\\Timur\\Labs_3semester\\Lab2\\data.txt");
    std::cout << "Enter knap parameters: dimendions, params" << std::endl;
    int m, n;
//    in >> m >> n;
    std::cin >> m >> n;
    Knap knap (m, n);
    ArrSeq<Object> objects;
    std::cout << "Enter number of items: ";
    //in >> n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "step = " << i << std::endl;
        int m1, n1, weight, cost;
        std::cout << "Enter item weight: ";
        std::cin >> weight;
//        in >> weight;
        std::cout << "Enter item cost: ";
//        in >> cost;
        std::cin >> cost;
                std::cout << "Enter item dimensions: ";
//        in >> m1 >> n1;
        std::cin >> m1 >> n1;
        objects.Append(Object (weight, m1, n1, cost));
    }
//    in.close();
    KnapState state (knap, objects);
    NTree<KnapState> tree (state);
    MakeTree (tree.GetRoot());
//    ArrSeq<Node<KnapState> *> last = tree.GetLeavesPtr();
    std::cout << "ANSWER IS:" << std::endl << GetKnapAnswer(tree);
    return 0;
}


