#ifndef HUMAIN_HPP
#define HUMAIN_HPP

#include <iostream>
#include <string>
#include "joueur.hpp"

using namespace std;


class Humain : public Joueur
{
public:
    Humain(const string &n);
    virtual string proposerMot() override;
    virtual char proposerLettre() override;
};

#endif