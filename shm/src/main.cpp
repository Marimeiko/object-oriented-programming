#include "game.hpp"

constexpr size_t start_money = 100;
constexpr size_t game_days = 10;
constexpr size_t final_goal = 200;

int main() {
    Game game(start_money, game_days, final_goal);
    game.StartGame();

    return 0;
}
