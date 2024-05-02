#ifndef MACHINE_HPP
#define MACHINE_HPP

#include <iostream>
#include <vector>
#include <string>
#include "joueur.hpp"

using namespace std;

class Machine : public Joueur {
public:
    Machine(const string& n, const vector<string>& d);
    virtual string proposerMot() override;
    virtual char proposerLettre() override;
private:
    const vector<string>& m_dict; // Dictionnaire de mots
};

#endif
