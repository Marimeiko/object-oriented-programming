#include "game.hpp"

#include <iostream>

Game::Game(size_t money, size_t days, size_t final_goal)
    : money_(money), days_(days), final_goal_(final_goal), time_(std::make_unique<Time>()) {
    map_ = std::make_unique<Map>();
    current_day_ = time_->getElapsedTime();
}

void Game::StartGame() {
    std::cout << "Welcome in SHM, you have: " << days_
              << " days, to gain: " << final_goal_ << "\n";

    while (days_ < current_day_) {
        if (CheckWinCondition()) {
            PrintWinScreen();
            return;
        } else if (CheckLooseCodition()) {
            break;
        }

        PrintMenu();
        PrintOptions();
        size_t action;
        std::cin.clear();
        std::cin >> action;
        if (action == 0) {
            break;
        }
        MakeAction(static_cast<Action>(action));
    }
    PrintLooseScreen();
}

bool Game::CheckWinCondition() const {
    return player_->getMoney() >= final_goal_;
}

bool Game::CheckLooseCodition() const {
    return player_->getMoney() == SIZE_MAX;
}

void Game::PrintMenu() {
    std::cout << "Money: " << player_->getMoney()
              << " Day: " << current_day_
              << " Days left: " << days_ - current_day_
              << "\n";
}

void Game::PrintOptions() {
    std::cout << "1. Travel\n"
              << "2. Sell\n"
              << "3. Buy\n"
              << "0. Exit\n"
              << "Choice: ";
}

void Game::MakeAction(Action choice) {
    switch (choice) {
    case Action::Travel:
        Travel();
        break;
    case Action::Sell:
        Sell();
        break;
    case Action::Buy:
        Buy();
        break;
    default:
        std::cout << "Wrong option!\n";
        break;
    }
}

void Game::PrintWinScreen() {
    std::cout << "Congratulation! You earn: " << player_->getMoney()
              << " money in: " << current_day_ << "days";
}

void Game::PrintLooseScreen() {
    std::cout << "Game Over! You earn: " << player_->getMoney()
              << " money in: " << current_day_ << "days";
}

void Game::Travel() {
    while (true) {
        std::cout << "\n";
        map_->printMap();
        std::cout << "\nChoose destination: ";
        size_t x, y;
        std::cin >> x >> y;
        Island* island = map_->getIsland(Coordinates(x, y));
        if (island != nullptr) {
            map_->travel(island);

            const size_t distance = map_->getDistanceToIsland(island);
            const size_t player_speed = player_->getSpeed();
            const size_t travel_time = (distance + player_speed - 1) / player_speed;
            std::cout << "Travel time: " << travel_time << "\n";
            for (size_t i = 0; i < travel_time; i++) {
                ++*time_;
            }
            break;
        }
        std::cout << "\nWrong desination!\n";
    }
}

void Game::Sell() {
}

void Game::Buy() {
}

void Game::PrintCargo() {
}