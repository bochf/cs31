#include <MovieTicket.h>
#include <gtest/gtest.h>

#include <string>

using namespace std;
using namespace ::testing;

#define MT MovieTicket

const MT::Day allDays[] = {MT::MONDAY,   MT::TUESDAY, MT::WEDNESDAY,
                           MT::THURSDAY, MT::FRIDAY,  MT::SATURDAY,
                           MT::SUNDAY};
const MT::Time allTimes[] = {MT::NOON,    MT::TWOPM, MT::FOURPM,  MT::SIXPM,
                             MT::EIGHTPM, MT::TENPM, MT::MIDNIGHT};
const MT::Type allTypes[] = {MT::CHILD, MT::ADULT, MT::SENIOR};
const MT::Kind allKinds[] = {MT::GRANDOPENING, MT::BLOCKBUSTER, MT::REGULAR,
                             MT::BOMB};
const string name = "abc";

TEST(MovieTicket, TestCreation) {
  MovieTicket ticket(name, MT::MONDAY, MT::TWOPM, MT::BLOCKBUSTER, MT::ADULT);

  EXPECT_EQ(name, ticket.getMovie());
  EXPECT_EQ(MT::MONDAY, ticket.getDay());
  EXPECT_EQ(MT::TWOPM, ticket.getTime());
  EXPECT_EQ(MT::BLOCKBUSTER, ticket.getKind());
  EXPECT_EQ(MT::ADULT, ticket.getType());
  EXPECT_TRUE(ticket.isWeekdayTicket());
  EXPECT_FALSE(ticket.isWeekendTicket());
  EXPECT_TRUE(ticket.isMatineeTicket());
  EXPECT_FALSE(ticket.isEveningTicket());

  // cost: 6.50
  //   ADULT: +7.5
  //   MATINEE: -2
  EXPECT_EQ(6.5, ticket.getCost());
}

TEST(MovieTicket, TestTypeCost) {
  for (const auto day : allDays) {
    for (const auto time : allTimes) {
      for (const auto kind : allKinds) {
        MovieTicket child(name, day, time, kind, MT::CHILD);
        MovieTicket adult(name, day, time, kind, MT::ADULT);
        MovieTicket senior(name, day, time, kind, MT::SENIOR);

        EXPECT_EQ(child.getCost() + 4, adult.getCost());
        EXPECT_EQ(child.getCost() + 1, senior.getCost());
      }
    }
  }
}

TEST(MovieTicket, TestTimeCost) {
  for (const auto day : allDays) {
    for (const auto kind : allKinds) {
      for (const auto type : allTypes) {
        MovieTicket matinee(name, day, MT::NOON, kind, type);
        MovieTicket evening(name, day, MT::MIDNIGHT, kind, type);

        EXPECT_EQ(evening.getCost() - 2, matinee.getCost());
        for (const auto time : allTimes) {
          MovieTicket ticket(name, day, time, kind, type);
          EXPECT_EQ(ticket.isMatineeTicket() ? matinee.getCost()
                                             : evening.getCost(),
                    ticket.getCost());
        }
      }
    }
  }
}

TEST(MovieTicket, TestKindCost) {
  for (const auto day : allDays) {
    for (const auto time : allTimes) {
      for (const auto type : allTypes) {
        MovieTicket regular(name, day, time, MT::REGULAR, type);
        MovieTicket grandopen(name, day, time, MT::GRANDOPENING, type);
        MovieTicket blockbuster(name, day, time, MT::BLOCKBUSTER, type);
        MovieTicket bomb(name, day, time, MT::BOMB, type);

        EXPECT_EQ(regular.getCost() + 2, grandopen.getCost());
        EXPECT_EQ(regular.getCost() + 1, blockbuster.getCost());
        EXPECT_EQ(regular.getCost() - 1, bomb.getCost());
      }
    }
  }
}
