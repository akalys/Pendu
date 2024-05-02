#ifndef PENDAISON_HPP
#define PENDAISON_HPP

#include <iostream>
#include <string>

using namespace std;

class Pendaison
{
public:
    static void afficher(unsigned int j_etape);
    static bool estPendu(unsigned int j_etape);
};

#endif