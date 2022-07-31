#include <BoxOffice.h>
#include <MovieTicket.h>

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <random>

using namespace std;
using namespace ::testing;

#define MT MovieTicket
#define BO BoxOffice

const string addr("1900 Pico Boulevard");
const string name("Titanic");
const MT::Day allDays[] = {MT::MONDAY,   MT::TUESDAY, MT::WEDNESDAY,
                           MT::THURSDAY, MT::FRIDAY,  MT::SATURDAY,
                           MT::SUNDAY};
const MT::Time allTimes[] = {MT::NOON,    MT::TWOPM, MT::FOURPM,  MT::SIXPM,
                             MT::EIGHTPM, MT::TENPM, MT::MIDNIGHT};
const MT::Kind allKinds[] = {MT::GRANDOPENING, MT::BLOCKBUSTER, MT::REGULAR, MT::BOMB};
const MT::Type allTypes[] = {MT::CHILD, MT::ADULT, MT::SENIOR};

TEST(BoxOffice, TestCreation) {
  BO box(addr, name);

  EXPECT_EQ(addr, box.getAddress());
  EXPECT_EQ(name, box.whatsPlaying());
  EXPECT_EQ(0, box.getWeekendTickets());
  EXPECT_EQ(0, box.getWeekdayTickets());
  EXPECT_EQ(0, box.getMatineeTickets());
  EXPECT_EQ(0, box.getEveningTickets());
  EXPECT_DOUBLE_EQ(0.0, box.getRevenue());
}

TEST(BoxOffice, TestInvalidMovie) {
  BO box(addr, name);

  EXPECT_THROW(box.buyTicket("The Lake House", MT::MONDAY, MT::NOON,
                             MT::REGULAR, MT::CHILD),
               logic_error);
}

TEST(BoxOffice, TestBuyTicket) {
  for (const auto day : allDays)
  {
    for (const auto time : allTimes)
    {
      for (const auto kind : allKinds)
      {
        for (const auto type : allTypes) {
          BO box(addr, name);
          MovieTicket ticket = box.buyTicket(name, day, time, kind, type);

          EXPECT_EQ(ticket.isWeekendTicket() ? 1 : 0, box.getWeekendTickets());
          EXPECT_EQ(ticket.isWeekdayTicket() ? 1 : 0, box.getWeekdayTickets());
          EXPECT_EQ(ticket.isMatineeTicket() ? 1 : 0, box.getMatineeTickets());
          EXPECT_EQ(ticket.isEveningTicket() ? 1 : 0, box.getEveningTickets());
          EXPECT_DOUBLE_EQ(ticket.getCost(), box.getRevenue());
        }
      }
    }
  }
}

TEST(BoxOffice, TestRevenue) {
  BO box(addr, name);
  int totalDays = sizeof(allDays) / sizeof(MT::Day);
  int totalTimes = sizeof(allTimes) / sizeof(MT::Time);
  int totalKinds = sizeof(allKinds) / sizeof(MT::Kind);
  int totalTypes = sizeof(allTypes) / sizeof(MT::Type);
  double revenue = 0.0;

  for (int i = 0; i < 1000; ++i)
  {
    // randomly buy a ticket
    MT::Day day = allDays[rand() % totalDays];
    MT::Time time = allTimes[rand() % totalTimes];
    MT::Kind kind = allKinds[rand() % totalKinds];
    MT::Type type = allTypes[rand() % totalTypes];

    const auto ticket = box.buyTicket(name, day, time, kind, type);
    EXPECT_DOUBLE_EQ(revenue + ticket.getCost(), box.getRevenue());
    revenue = box.getRevenue();
  }
}
