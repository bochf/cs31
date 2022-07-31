#include <BoxOffice.h>
#include <MovieTicket.h>

#include <stdexcept>
#include <string>

using namespace std;

BoxOffice::BoxOffice(const std::string &address,
                     const std::string &whatsPlaying)
    : mAddress(address), mMovie(whatsPlaying), mMatineeTickets(0),
      mEveningTickets(0), mWeekdayTickets(0), mWeekendTickets(0),
      mEarnedRevenue(0.0) {}

BoxOffice::~BoxOffice() {}

MovieTicket BoxOffice::buyTicket(const std::string &movie, MovieTicket::Day day,
                                 MovieTicket::Time time, MovieTicket::Kind kind,
                                 MovieTicket::Type type) {
  if (movie != mMovie) {
    throw logic_error("Movie does not exist");
  }

  MovieTicket ticket(movie, day, time, kind, type);
  if (ticket.isMatineeTicket()) {
    ++mMatineeTickets;
  } else {
    ++mEveningTickets;
  }

  if (ticket.isWeekendTicket()) {
    ++mWeekendTickets;
  } else {
    ++mWeekdayTickets;
  }

  mEarnedRevenue += ticket.getCost();

  return ticket;
}
