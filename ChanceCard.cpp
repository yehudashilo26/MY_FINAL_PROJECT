#include "ChanceCard.h"
#include "Monopoly.h"
#include <cmath>

outOfJailCard::outOfJailCard(Monopoly &gm, const std::string &name, const std::string &description)
    : CollectableCard(gm, name, description, CollectableCardType::outOfJail)
{
}

void outOfJailCard::activate(Player &player)
{
    this->game.moveOutOfJail(player);
}

AdvanceToGoCard::AdvanceToGoCard(Monopoly &gm, const std::string &name, const std::string &description)
    : ChanceCard(gm, name, description)
{
}

void AdvanceToGoCard::activate(Player &player)
{
    game.movePlayer(player, 0);
}

BankDividendCard::BankDividendCard(Monopoly &gm, const std::string &name, const std::string &description)
    : ChanceCard(gm, name, description)
{
}

void BankDividendCard::activate(Player &player)
{
    //
}

GoBackCard::GoBackCard(Monopoly &gm, const std::string &name, const std::string &description)
    : ChanceCard(gm, name, description)
{
}

void GoBackCard::activate(Player &player)
{
    game.movePlayer(player, -3);
}

GoToJailCard::GoToJailCard(Monopoly &gm, const std::string &name, const std::string &description)
    : ChanceCard(gm, name, description)
{
}

void GoToJailCard::activate(Player &player)
{
    game.moveToJail(player);
}

GeneralRepairsCard::GeneralRepairsCard(Monopoly &gm, const std::string &name, const std::string &description)
    : ChanceCard(gm, name, description)
{
}

void GeneralRepairsCard::activate(Player &player)
{
    // int totalCost = 0;

    // for (Buyable *property : player.getProperties())
    // {
    //     if (dynamic_cast<Property *>(property))
    //     {
    //         Property *prop = dynamic_cast<Property *>(property);
    //         totalCost += prop->getNumberOfHouses() * GENERAL_REPAIRS_HOTEL;
    //         if (prop->hasHotel())
    //         {
    //             totalCost += GENERAL_REPAIRS_HOTEL;
    //         }
    //     }
    // }

    // game.payRent(player, totalCost);
}

PoorTaxCard::PoorTaxCard(Monopoly &gm, const std::string &name, const std::string &description)
    : ChanceCard(gm, name, description)
{
}

void PoorTaxCard::activate(Player &player)
{
    // game.payRent(player, POOR_TAX);
}

ReadingRailroadCard::ReadingRailroadCard(Monopoly &gm, const std::string &name, const std::string &description)
    : ChanceCard(gm, name, description)
{
}

void ReadingRailroadCard::activate(Player &player)
{
    for (const Tile *tile : game.getBoard())
    {
        if (const Railroad *railroad = dynamic_cast<const Railroad *>(tile))
        {
            if (railroad->getName() == "Reading Railroad")
            {
                game.movePlayer(player, tile->getId());
                return;
            }
        }
    }
}

BoardwalkCard::BoardwalkCard(Monopoly &gm, const std::string &name, const std::string &description)
    : ChanceCard(gm, name, description)
{
}

void BoardwalkCard::activate(Player &player)
{
    for (const Tile *tile : game.getBoard())
    {
        if (const Property *property = dynamic_cast<const Property *>(tile))
        {
            if (property->getName() == "Boardwalk")
            {
                game.movePlayer(player, tile->getId());
                return;
            }
        }
    }
}

StCharlesPlaceCard::StCharlesPlaceCard(Monopoly &gm, const std::string &name, const std::string &description)
    : ChanceCard(gm, name, description)
{
}

void StCharlesPlaceCard::activate(Player &player)
{
    for (const Tile *tile : game.getBoard())
    {
        if (const Property *property = dynamic_cast<const Property *>(tile))
        {
            if (property->getName() == "St. Charles Place")
            {
                game.movePlayer(player, tile->getId());
                return;
            }
        }
    }
}

IllinoisAveCard::IllinoisAveCard(Monopoly &gm, const std::string &name, const std::string &description)
    : ChanceCard(gm, name, description)
{
}

void IllinoisAveCard::activate(Player &player)
{
    for (const Tile *tile : game.getBoard())
    {
        if (const Property *property = dynamic_cast<const Property *>(tile))
        {
            if (property->getName() == "Illinois Avenue")
            {
                game.movePlayer(player, tile->getId());
                return;
            }
        }
    }
}

BuildingLoanCard::BuildingLoanCard(Monopoly &gm, const std::string &name, const std::string &description)
    : ChanceCard(gm, name, description)
{
}

void BuildingLoanCard::activate(Player &player)
{
    // game.addFunds(player, BUILDING_LOAN);
}

ChairmanCard::ChairmanCard(Monopoly &gm, const std::string &name, const std::string &description)
    : ChanceCard(gm, name, description)
{
}

void ChairmanCard::activate(Player &player)
{
    // game.addFunds(player, CHAIRMAN);
}

NearestRailroadCard::NearestRailroadCard(Monopoly &gm, const std::string &name, const std::string &description)
    : ChanceCard(gm, name, description)
{
}

void NearestRailroadCard::activate(Player &player)
{
    int minDistance = BOARD_SIZE;
    const Railroad *nearestRailroad = nullptr;

    for (const Tile *tile : game.getBoard())
    {
        if (const Railroad *railroad = dynamic_cast<const Railroad *>(tile))
        {
            int distance = (player.getPosition() - tile->getId());
            distance = distance >= 0 ? distance : -distance;
            if (distance < minDistance)
            {
                minDistance = distance;
                nearestRailroad = railroad;
            }
        }
    }

    game.movePlayer(player, nearestRailroad->getId());
}

NearestUtilityCard::NearestUtilityCard(Monopoly &gm, const std::string &name, const std::string &description)
    : ChanceCard(gm, name, description)
{
}

void NearestUtilityCard::activate(Player &player)
{
    int minDistance = BOARD_SIZE;
    const Utility *nearestUtility = nullptr;

    for (const Tile *tile : game.getBoard())
    {
        if (const Utility *utility = dynamic_cast<const Utility *>(tile))
        {
            int distance = (player.getPosition() - tile->getId());
            distance = distance >= 0 ? distance : -distance;
            if (distance < minDistance)
            {
                minDistance = distance;
                nearestUtility = utility;
            }
        }
    }

    game.movePlayer(player, nearestUtility->getId());
}

PropertyRepairsCard::PropertyRepairsCard(Monopoly &gm, const std::string &name, const std::string &description)
    : ChanceCard(gm, name, description)
{
}

void PropertyRepairsCard::activate(Player &player)
{
    // int totalCost = 0;

    // for (Buyable *property : player.getProperties())
    // {
    //     if (dynamic_cast<Property *>(property))
    //     {
    //         Property *prop = dynamic_cast<Property *>(property);
    //         totalCost += prop->getHouses() * PROPERTY_REPAIRS_HOUSE;
    //         if (prop->hasHotel())
    //         {
    //             totalCost += PROPERTY_REPAIRS_HOTEL;
    //         }
    //     }
    // }

    // // game.payRent(player, totalCost);
}
