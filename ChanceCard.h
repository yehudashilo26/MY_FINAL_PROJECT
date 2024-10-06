#ifndef CHANCECARD_H
#define CHANCECARD_H

#include <string>
#define NUM_CARDS 16 // needs to be changed if more cards are added
#define BANK_DIVIDEND 50
#define POOR_TAX 15
#define GENERAL_REPAIRS_HOUSE 25
#define GENERAL_REPAIRS_HOTEL 100
#define PROPERTY_REPAIRS_HOUSE 40
#define PROPERTY_REPAIRS_HOTEL 115

#define BUILDING_LOAN 150
#define CHAIRMAN 50
#define BOARDWALK 200

class Player;
class Monopoly;

enum class CollectableCardType {
    outOfJail
    };

class ChanceCard {
    friend class Monopoly;  // Monopoly is a friend to access protected members
public:
    virtual ~ChanceCard() = default;
    const std::string& getName() const { return name; }
    const std::string& getDescription() const { return description; }
    
protected:
    Monopoly& game;  // Reference to Monopoly to use game functions
    std::string description;   // Description of the card
    std::string name;          // Type of the card
    ChanceCard(Monopoly& game, const std::string& name, const std::string& description) : game(game), description(description), name(name) {}
    virtual void activate(Player& player) = 0;  // Abstract method to apply card effect to a player
};

class CollectableCard : public ChanceCard {
    friend class Monopoly;
public:
    CollectableCard(Monopoly& game, const std::string& name, const std::string& description, CollectableCardType type) : ChanceCard(game, name, description), type(type) {};
    CollectableCardType getType() const { return type; }
protected:
    void activate(Player& player) override = 0;
    CollectableCardType type;
};

class outOfJailCard : public CollectableCard {
        friend class Monopoly;
public:
    outOfJailCard(Monopoly& game, const std::string& name, const std::string& description);
private:
    void activate(Player& player) override;
};

class AdvanceToGoCard : public ChanceCard {
public:
    AdvanceToGoCard(Monopoly& game, const std::string& name, const std::string& description);
private:
    void activate(Player& player) override;
};

class BankDividendCard : public ChanceCard {
public:
    BankDividendCard(Monopoly& game, const std::string& name, const std::string& description);
private:
    void activate(Player& player) override;
};

class GoBackCard : public ChanceCard {
public:
    GoBackCard(Monopoly& game, const std::string& name, const std::string& description);
private:
    void activate(Player& player) override;
};

class GoToJailCard : public ChanceCard {
public:
    GoToJailCard(Monopoly& game, const std::string& name, const std::string& description);
private:
    void activate(Player& player) override;
};

class GeneralRepairsCard : public ChanceCard {
public:
    GeneralRepairsCard(Monopoly& game, const std::string& name, const std::string& description);
private:
    void activate(Player& player) override;
};

class PoorTaxCard : public ChanceCard {
public:
    PoorTaxCard(Monopoly& game, const std::string& name, const std::string& description);
private:
    void activate(Player& player) override;
};

class ReadingRailroadCard : public ChanceCard {
public:
    ReadingRailroadCard(Monopoly& game, const std::string& name, const std::string& description);
private:
    void activate(Player& player) override;
};

class BoardwalkCard : public ChanceCard {
public:
    BoardwalkCard(Monopoly& game, const std::string& name, const std::string& description);
private:
    void activate(Player& player) override;
};

class ChairmanCard : public ChanceCard {
public:
    ChairmanCard(Monopoly& game, const std::string& name, const std::string& description);
private:
    void activate(Player& player) override;
};

class BuildingLoanCard : public ChanceCard {
public:
    BuildingLoanCard(Monopoly& game, const std::string& name, const std::string& description);
private:
    void activate(Player& player) override;
};

class IllinoisAveCard : public ChanceCard {
public:
    IllinoisAveCard(Monopoly& game, const std::string& name, const std::string& description);
private:
    void activate(Player& player) override;
};

class StCharlesPlaceCard : public ChanceCard {
public:
    StCharlesPlaceCard(Monopoly& game, const std::string& name, const std::string& description);
private:
    void activate(Player& player) override;
};

class PropertyRepairsCard : public ChanceCard {
public:
    PropertyRepairsCard(Monopoly& game, const std::string& name, const std::string& description);
private:
    void activate(Player& player) override;
};

class NearestUtilityCard : public ChanceCard {
public:
    NearestUtilityCard(Monopoly& game, const std::string& name, const std::string& description);
private:

    void activate(Player& player) override;
};

class NearestRailroadCard : public ChanceCard {
public:
    NearestRailroadCard(Monopoly& game, const std::string& name, const std::string& description);
private:
    void activate(Player& player) override;
};



#endif // CHANCECARD_H
