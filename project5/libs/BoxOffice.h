#ifndef __BOX_OFFICE__
#define __BOX_OFFICE__

#include <string>

#include <MovieTicket.h>

class BoxOffice {
public:
  // constructor
  BoxOffice(const std::string &address, const std::string &whatsPlaying);
  virtual ~BoxOffice();

  // accessors
  std::string getAddress() const { return mAddress; }

  std::string whatsPlaying() const { return mMovie; }

  int getWeekendTickets() const { return mWeekendTickets; }

  int getWeekdayTickets() const { return mWeekdayTickets; }

  int getMatineeTickets() const { return mMatineeTickets; }

  int getEveningTickets() const { return mEveningTickets; }

  double getRevenue() const { return mEarnedRevenue; }

  // public methods
  /**
   * @brief buy a movie ticket at given movie name, day, time, kind and type
   * the movie name must match what's playing
   *
   * @param movie, the name of the movie
   * @param day, the day the showing is held
   * @param time, the time the showing is held
   * @param kind, the kind of the show
   * @param type, the type of the visitor
   *
   * @return a MovieTicket object
   * @exception std::logic_error if the movie does not match whatsPlaying
   */
  MovieTicket buyTicket(const std::string &movie, MovieTicket::Day day,
                        MovieTicket::Time time, MovieTicket::Kind kind,
                        MovieTicket::Type type);

  /**
   * @brief cleanup all the tickets purchase information
   */
  void reset() {
    mMatineeTickets = 0;
    mEveningTickets = 0;
    mWeekendTickets = 0;
    mWeekdayTickets = 0;
    mEarnedRevenue = 0.0;
  }

private:
  // data
  std::string mAddress;
  std::string mMovie;
  int mMatineeTickets;
  int mEveningTickets;
  int mWeekendTickets;
  int mWeekdayTickets;
  double mEarnedRevenue;
};

#endif
