//
// Created by Timur on 18.12.2021.
//

#ifndef LAB2_MENU_HELPFUL_FUNCTIONS_H
#define LAB2_MENU_HELPFUL_FUNCTIONS_H

NTree <KnapState> input_volume();

KnapState GetKnapAnswer1 (int);

KnapState GetKnapAnswer2 ();

void dialog ();

ArrSeq<char> SubStr (ArrSeq<char>, int, int);

bool operator== (ArrSeq<char>, ArrSeq<char>);

char *StrToChar (std::string);

ArrSeq<Pair<ArrSeq<char>, int> > sort_mfs (ArrSeq<Pair<ArrSeq<char>, int> >);

float mfs_valuation (Pair<ArrSeq<char>, int>, int);

ArrSeq<Pair<ArrSeq<char>, int> > sort_mfs_relative(ArrSeq<Pair<ArrSeq<char>, int> >, int);

ArrSeq<Pair<ArrSeq<char>, int> > mfs (ArrSeq<char>, int, int);

#endif //LAB2_MENU_HELPFUL_FUNCTIONS_H
