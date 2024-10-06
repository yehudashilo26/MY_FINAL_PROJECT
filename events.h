#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "player.h"
#include "tile.h"

enum class EventType
{
    PlayerPositionChanged,
    PlayerIsInJail,
    PlayerIsOutOfJailEvent,
    PlayerRolledDice,
    PlayerRolledDoubles,
    PlayerBoughtProperty,
    PlayerBoughtHouse,
    PlayerBoughtHotel,
    PlayerPaidRent,
    PlayerPaidBail,
    PlayerBankrupt,
    PlayerWon,
    PlayerLost,
    PlayerTurnStart,
    PlayerTurnEnd,
};


// Base class for events
class Event
{
public:
    virtual ~Event() = default;
    virtual std::string toString() const = 0;
    virtual EventType getType() const = 0;
};


class PlayerPositionChangedEvent : public Event
{
    public:
        PlayerPositionChangedEvent(const Player &player, const Tile &tile) : player(player), tile(tile) {};
        std::string toString() const override { return "PlayerPositionChangedEvent"; };
        EventType getType() const override { return EventType::PlayerPositionChanged; };
        const Player &player;
        const Tile &tile;
};

class PlayerPaidRentEvent : public Event
{
    public:
        PlayerPaidRentEvent(const Player &player, const Player &owner, int amount) : player(player), owner(owner), amount(amount) {};
        std::string toString() const override { return "PlayerPaidRentEvent"; };
        EventType getType() const override { return EventType::PlayerPaidRent; };
        const Player &player;
        const Player &owner;
        int amount;
};

class PlayerIsInJailEvent : public Event
{
    public:
        PlayerIsInJailEvent(const Player &player) : player(player) {};
        std::string toString() const override { return "PlayerIsInJailEvent"; };
        EventType getType() const override { return EventType::PlayerIsInJail; };
        const Player &player;
};

class PlayerIsOutOfJailEvent : public Event
{
public:
    PlayerIsOutOfJailEvent(const Player &player) : player(player) {};
    std::string toString() const override { return "Player " + player.getName() + " is out of jail.";};
    EventType getType() const override { return EventType::PlayerIsOutOfJailEvent; };
    const Player &player;
};

class PlayerRolledDiceEvent : public Event
{
    public:
        PlayerRolledDiceEvent(const Player &player, int dice1, int dice2) : player(player), dice1(dice1), dice2(dice2) {};
        std::string toString() const override { return "PlayerRolledDiceEvent"; };
        EventType getType() const override { return EventType::PlayerRolledDice; };
        const Player &player;
        int dice1;
        int dice2;
};

class PlayerRolledDoublesEvent : public Event
{
    public:
        PlayerRolledDoublesEvent(const Player &player, int dice1, int dice2) : player(player), dice1(dice1), dice2(dice2) {};
        std::string toString() const override { return "PlayerRolledDoublesEvent"; };
        EventType getType() const override { return EventType::PlayerRolledDoubles; };
        const Player &player;
        int dice1;
        int dice2;
};

class PlayerBoughtPropertyEvent : public Event
{
    public:
        PlayerBoughtPropertyEvent(const Player &player, const Tile &tile) : player(player), tile(tile) {};
        std::string toString() const override { return "PlayerBoughtPropertyEvent"; };
        EventType getType() const override { return EventType::PlayerBoughtProperty; };
        const Player &player;
        const Tile &tile;
};

class PlayerBoughtHouseEvent : public Event
{
    public:
        PlayerBoughtHouseEvent(const Player &player, const Tile &tile) : player(player), tile(tile) {};
        std::string toString() const override { return "PlayerBoughtHouseEvent"; };
        EventType getType() const override { return EventType::PlayerBoughtHouse; };
        const Player &player;
        const Tile &tile;
};

class PlayerBoughtHotelEvent : public Event
{
    public:
        PlayerBoughtHotelEvent(const Player &player, const Tile &tile) : player(player), tile(tile) {};
        std::string toString() const override { return "PlayerBoughtHotelEvent"; };
        EventType getType() const override { return EventType::PlayerBoughtHotel; };
        const Player &player;
        const Tile &tile;
};

class PlayerPaidBailEvent : public Event
{
    public:
        PlayerPaidBailEvent(const Player &player) : player(player) {};
        std::string toString() const override { return "PlayerPaidBailEvent"; };
        EventType getType() const override { return EventType::PlayerPaidBail; };
        const Player &player;
};

class PlayerBankruptEvent : public Event
{
    public:
        PlayerBankruptEvent(const Player &player,const Player *paid_to=nullptr) : player(player), paid_to(paid_to) {};
        std::string toString() const override { return "PlayerBankruptEvent"; };
        EventType getType() const override { return EventType::PlayerBankrupt; };
        const Player &player;
        const Player *paid_to;
};

class PlayerWonEvent : public Event
{
    public:
        PlayerWonEvent(const Player &player) : player(player) {};
        std::string toString() const override { return "PlayerWonEvent"; };
        EventType getType() const override { return EventType::PlayerWon; };
        const Player &player;
};

class PlayerLostEvent : public Event
{
    public:
        PlayerLostEvent(const Player &player) : player(player) {};
        std::string toString() const override { return "PlayerLostEvent"; };
        EventType getType() const override { return EventType::PlayerLost; };
        const Player &player;
};

class PlayerTurnStartEvent : public Event
{
    public:
        PlayerTurnStartEvent(const Player &player) : player(player) {};
        std::string toString() const override { return "PlayerTurnStartEvent"; };
        EventType getType() const override { return EventType::PlayerTurnStart; };
        const Player &player;
};

class PlayerTurnEndEvent : public Event
{
    public:
        PlayerTurnEndEvent(const Player &player) : player(player) {};
        std::string toString() const override { return "PlayerTurnEndEvent"; };
        EventType getType() const override { return EventType::PlayerTurnEnd; };
        const Player &player;
};



#endif // EVENT_H
