#include <MovieTicket.h>

#include <string>

using namespace std;

MovieTicket::MovieTicket(const string &movie, const Day day, const Time time,
                         const Kind kind, const Type type)
    : mMovie(movie), mDay(day), mTime(time), mKind(kind), mType(type) {}

MovieTicket::~MovieTicket() {}

bool MovieTicket::isWeekendTicket() const { return mDay >= FRIDAY; }

bool MovieTicket::isWeekdayTicket() const { return !isWeekendTicket(); }

bool MovieTicket::isMatineeTicket() const { return mTime < SIXPM; }

bool MovieTicket::isEveningTicket() const { return !isMatineeTicket(); }

double MovieTicket::getCost() const {
  double price = 3.5; // base child ticket

  switch (mType) {
  case ADULT:
    price = 7.5;
    break;
  case SENIOR:
    price = 4.5;
    break;
  default:
    break;
  }

  if (isMatineeTicket()) {
    price -= 2;
  }

  if (mKind == BLOCKBUSTER) {
    price += 1;
  }

  if (mKind == GRANDOPENING) {
    price += 2;
  }

  if (mKind == BOMB) {
    price -= 1;
  }

  return price;
}
