#include "gtest/gtest.h"

#include "player.hpp"
#include "ship.hpp"
#include "time.hpp"

namespace SHM_test {

constexpr int SHIP_MAX_CREW = 20;
constexpr int SHIP_SPEED = 666;
constexpr size_t SHIP_ID = 7;
constexpr int SHIP_CREW = 5;
constexpr size_t MONEY = 1000;
constexpr size_t SALARY = 20;
constexpr size_t AVAILABLE_SPACE = 100;

Time time;
Ship ship(SHIP_MAX_CREW, SHIP_SPEED, SHIP_ID, &time);
Player player(ship, MONEY, AVAILABLE_SPACE);

TEST(ShipTest, ShouldInitShip) {
    EXPECT_EQ(ship.getMaxCrew(), SHIP_MAX_CREW);
    EXPECT_EQ(ship.getSpeed(), SHIP_SPEED);
    EXPECT_EQ(ship.getId(), SHIP_ID);
}
TEST(ShipTest, ShouldAddCrew) {
    ship += SHIP_CREW;
    EXPECT_EQ(ship.getCrew(), SHIP_CREW);
}
TEST(ShipTest, ShouldSubtractCrew) {
    ship -= SHIP_CREW;
    EXPECT_EQ(ship.getCrew(), 0);
}
TEST(PlayerTest, ShouldInitPlayer) {
    EXPECT_EQ(player.getMoney(), MONEY);
}
TEST(PlayerTest, ShouldPayCrew) {
    size_t crew = ship.getCrew();
    size_t money = player.getMoney();

    ++time;
    EXPECT_EQ(player.getMoney(), money - crew);
}
TEST(TimeTest, ShouldTimePass) {
    ++time;
    EXPECT_EQ(time.getElapsedTime(), 2);
}
}
