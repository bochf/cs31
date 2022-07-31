#ifndef __MOVIE_TICKET__
#define __MOVIE_TICKET__

#include <string>

class MovieTicket {
public:
  enum Time { NOON, TWOPM, FOURPM, SIXPM, EIGHTPM, TENPM, MIDNIGHT };

  enum Day { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };

  enum Type { CHILD, ADULT, SENIOR };

  enum Kind { GRANDOPENING, BLOCKBUSTER, REGULAR, BOMB };

  // constructor
  MovieTicket(const std::string &movie, const Day day, const Time time,
              const Kind kind, const Type type);
  virtual ~MovieTicket();

  // accessors
  std::string getMovie() const { return mMovie; }

  Day getDay() const { return mDay; }

  Time getTime() const { return mTime; }

  Kind getKind() const { return mKind; }

  Type getType() const { return mType; }

  // public methods
  /**
   * @brief is the ticket is for showing held on weekend
   * weekend is Friday, Saturday, or Sunday
   *
   * @return true if the ticket is showings held on weekend
   */
  bool isWeekendTicket() const;

  /**
   * @brief is the ticket is for showings held on weekday
   * weekday is Monday to Thursday
   *
   * @return true if the ticket is showings held on weekday
   */
  bool isWeekdayTicket() const;

  /**
   * @brief is the ticket is for showings that start prior to 5PM
   *
   * @return true if the ticket is for showings that start prior to 5PM
   */
  bool isMatineeTicket() const;

  /**
   * @brief is the ticket is for showings that start after 5PM
   *
   * @return true if the ticket is for showings that start after 5PM
   */
  bool isEveningTicket() const;

  /** @brief calculate the price of the ticket based on its time, type and kind
   *
   * @return the ticket price
   */
  double getCost() const;

private:
  // data
  std::string mMovie;
  Day mDay;
  Time mTime;
  Kind mKind;
  Type mType;
};

#endif
