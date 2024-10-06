#ifndef CHANCECARDFACTORY_H
#define CHANCECARDFACTORY_H

#include "ChanceCard.h"
#include <random>

class ChanceCardFactory {
public:

private:
    static std::mt19937 rng; 
    static std::uniform_int_distribution<int> dist;

    ChanceCardFactory() = default;
    static ChanceCard * createCard(Monopoly& gm);

friend class Monopoly;
};

#endif // CHANCECARDFACTORY_H
