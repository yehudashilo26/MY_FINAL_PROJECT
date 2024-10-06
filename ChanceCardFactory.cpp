#include "ChanceCardFactory.h"
#include <memory>

std::mt19937 ChanceCardFactory::rng;
std::uniform_int_distribution<int> ChanceCardFactory::dist;

ChanceCard *ChanceCardFactory::createCard(Monopoly &game)
{
    dist = std::uniform_int_distribution<int>(1, NUM_CARDS);
    std::unique_ptr<ChanceCard> card = nullptr;
    int cardNumber = dist(rng);
    switch (cardNumber)
    {
    case 1:
        return new AdvanceToGoCard(game, "Advance to Go", "Advance to Go");
    case 2:
        return new BankDividendCard(game, "Bank Dividend", "Bank Dividend");
    case 3:
        return new GoToJailCard(game, "Go to Jail", "Go to Jail");
    case 4:
        return new outOfJailCard(game, "Out of Jail", "Out of Jail");
    case 5:
        return new GeneralRepairsCard(game, "General Repairs", "General Repairs");
    case 6:
        return new PoorTaxCard(game, "Poor Tax", "Poor Tax");
    case 7:
        return new ReadingRailroadCard(game, "Reading Railroad", "Reading Railroad");
    case 8:
        return new BoardwalkCard(game, "Boardwalk", "Boardwalk");
    case 9:
        return new GoBackCard(game, "Go Back", "Go Back");
    case 10:
        return new ChairmanCard(game, "Advance to Tile", "Advance to Tile");
        case 11:
        return new IllinoisAveCard(game, "Advance to Illinois Ave", "Advance to Illinois Ave");
        case 12:
        return new StCharlesPlaceCard(game, "Advance to St. Charles Place", "Advance to St. Charles Place");
        case 13:
        return new NearestRailroadCard(game, "Advance to Nearest Railroad", "Advance to Nearest Railroad");
        case 14:
        return new NearestUtilityCard(game, "Advance to Nearest Utility", "Advance to Nearest Utility");
        case 15:
        return new BuildingLoanCard(game, "Building Loan", "Building Loan");
        case 16:
        return new PropertyRepairsCard(game, "Property Repairs", "Property Repairs");
        default:
        return nullptr;
    }
}
