#pragma once

#include <memory>
#include "map.hpp"
#include "player.hpp"
#include "time.hpp"
#include "store.hpp"


class Game {
public:
    Game(size_t money, size_t days, size_t final_goal);
    ~Game() = default;

    enum class Action { Travel = 1,
                        Sell = 2,
                        Buy = 3,
                        PrintCargo = 4,
                        Exit = 0 };

    void StartGame();

private:
    bool CheckWinCondition() const;  
    bool CheckLooseCodition() const;
    void PrintMenu();
    void PrintOptions();
    void PrintWinScreen();
    void PrintLooseScreen();
    void MakeAction(Action choice);
    void Travel();
    void Buy();
    void Sell();
    void PrintCargo();

    size_t money_;
    size_t days_;
    size_t final_goal_;
    size_t current_day_;
    std::unique_ptr<Map> map_;
    std::unique_ptr<Time> time_;
    std::shared_ptr<Player> player_;
    std::unique_ptr<Store> store_;

    std::unique_ptr<Ship> ship_;
};
