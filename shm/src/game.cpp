#include "game.hpp"

#include <cstddef>
#include <iostream>

Game::Game(size_t money, size_t days, size_t final_goal)
    : money_(money), days_(days), final_goal_(final_goal), time_(std::make_unique<Time>()) {
    map_ = std::make_unique<Map>();
    current_day_ = time_->getElapsedTime();
    ship_ = std::make_unique<Ship>(100, 20, 60, "PlayerShip", 1);
    player_ = std::make_shared<Player>(ship_, 250, 30);
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
              << "4. Print cargo\n"
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
    while (true) {
        player_->printShipCargo();
        std::cout << store_ << "Select product and quantity: ";
        size_t product, amount;
        std::cin >> product >> amount;
        Cargo* cargo = player_.getCargo(--product);
        Store::Response response = store_.sell(cargo, amount, player_.get());
        switch (response) {
        case Store::Response::done:
            std::cout << "Sell " << amount << " " << product << "\n";
            return;
        case Store::Response::lack_of_cargo:
            std::cout << "There is no enough cargo to sell \n";
        case Store::Response::lack_of_space:
            std::cout << "There is no enough space in storess \n";
        }
        store_.printCargo();
    }
}

void Game::Buy() {
    while (true) {
        player_->printShipCargo();
        std::cout << store_ << "Select product and quantity: ";
        size_t product, amount;
        std::cin >> product >> amount;
        Cargo* cargo = store_.getCargo(--product);
        Store::Response response = store_.buy(cargo, amount, player_.get());
        switch (response) {
        case Store::Response::done:
            std::cout << "Buy " << amount << " " << product << "\n";
            return;
        case Store::Response::lack_of_cargo:
            std::cout << "There is no enough cargo to buy \n";
        case Store::Response::lack_of_money:
            std::cout << "You do not have enough money \n";
        case Store::Response::lack_of_space:
            std::cout << "You do not have enough space on your ship \n";
        }
        store_.printCargo();
    }
}

void Game::PrintCargo() {
    std::"You have:\n";
    player_->printShipCargo();
}