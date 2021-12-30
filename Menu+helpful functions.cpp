//
// Created by Timur on 18.12.2021.
//

#include "Menu+helpful functions.h"

KnapState GetKnapAnswer(NTree<KnapState> tree) {
    ArrSeq<Node<KnapState> *> states = tree.GetLeavesPtr();
    KnapState ans = (states[0])->GetState();
    for (auto it = states.begin(); it != states.end(); ++it)
    {
        KnapState tmp = (*it)->GetState();
        if (tmp.GetKnap().GetCost() > ans.GetKnap().GetCost())
            ans = tmp;
        else if (tmp.GetKnap().GetCost() == ans.GetKnap().GetCost())
            if (tmp.GetWeight() < ans.GetWeight())
                ans = tmp;
    }
    std::cout << "Ans weight " << ans.GetWeight() << ", ans cost = " << ans.GetKnap().GetCost() << std::endl;
    return ans;
}
