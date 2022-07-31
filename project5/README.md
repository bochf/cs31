# Homework Project 5
*MovieTicket / BoxOffice*

## Introduction
According to Variety, an industry paper, North American box office revenue in 2002 jumped 101 percent to $4.5 billion but still lagged far behind pre-pandemic levels.

## Your task
Your assignment is to produce two classes that work together to simulate a MovieTicket and a BoxOffice.  In an effort to help you, the design of these two classes will be discussed here.  In addition, some sample code has been provided to assist you with this task.  Various UML diagrams are shown below to communicate the code you need to create.  Please follow the steps outlined below and don't jump ahead until you have finished the earlier step.

### MovieTicket class
Please review the UML diagram shown here.  Each of the following enumerations should be a public part of the class MovieTicket
| Time     | Day       | Kind         | Type   |
|:--------:|:---------:|:------------:|:------:|
| NOON     | MONDAY    | GRANDOPENING | CHILD  |
| TOWPM    | TUESDAY   | BLOCKBUSTER  | ADULT  |
| FOURPM   | WEDNESDAY | REGULAR      | SENIOR |
| SIXPM    | THURSDAY  | BOMB         |
| EIGHTPM  | FRIDAY    |
| TENPM    | SATURDAY  |
| MIDNIGHT | SUNDAY    |

Based on these enumerations, please review the MovieTicket class diagram shown below:
|MovieTicket                                                                |
|:--------------------------------------------------------------------------|
| -mMovie : string                                                          |
| -mDay : Day                                                               |
| -mTime : Time                                                             |
| -mKind : Kind                                                             |
| -mType : Type                                                             |
|                                                                           |
| +MovieTicket(movie: string, day: Day, time: Time, kind: Kind, type: Type) |
|                                                                           |
| +getMovie() : string                                                      |
| +getDay() : Day                                                           |
| +getTime() : Time                                                         |
| +getKind() : Kind                                                         |
| +getType() : Type                                                         |
|                                                                           |
| +isWeekendTicket() : bool                                                 |
| +isWeekdayTicket() : bool                                                 |
| +isMatineeTicket() : bool                                                 |
| +isEveningTicket() : bool                                                 |
|                                                                           |
| +getCost() : double                                                       |

A MovieTicket class holds a string value for the name of the movie, a Day and Time enumerated value for the movie showing, a Type enumerated value for the ticket and a Kind enumerated value for the movie showing.  Each of these five data members has an accessor method (a "getter" method).  In addition, each ticket tracks whether it is a weekend or weekday ticket or whether it is a matinee or evening ticket.  Weekend tickets are for showings held on Friday, Saturday or Sunday.  Weekday tickets are for showings held on Monday, Tuesday, Wednesday or Thursday.  Matinee tickets are for showings that start prior to 5 PM.  Evening tickets are for showings that start after 5 PM.  In addition, every MovieTicket has a method named getCost is called to determine the ticket's cost based on the following table:

**Ticket Costs**
* Base Price
	* **$3.50** for a Child ticket, 
	* **$7.50** for an Adult ticket 
	* **$4.50** for a Senior ticket
* Matinee discount **$2.00** off for any showing that starts prior to 5 PM
* Blockbuster upgrade **$1.00** more for any Blockbuster showing
* GrandOpening upgrade **$2.00** more for any GrandOpening showing
* Bomb discount **$1.00** off for any Bomb showing

### BoxOffice class
Please review the BoxOffice class diagram shown below:
| BoxOffice                                                                                                                                |          
|------------------------------------------------------------------------------------------------------------------------------------------|
| -mAddress, mMovie : string                                                                                                               |
|                                                                                                                                          |
| -mTicketCount : int                                                                                                                      |
| -mMatineeTickets, mEveningTickets : int                                                                                                  |
| -mWeekdayTickets, mWeekendTickets : int                                                                                                  |
|                                                                                                                                          |
| mEarnedRevenue : double                                                                                                                  |                        
|                                                                                                                                          |
| +BoxOffice(address: string, whatsPlaying: string)                                                                                        |          
|                                                                                                                                          |
| +buyTicket(movie: string, day:MovieTicket::Day, time: MovieTicket::Time, kind: MovieTicket::Kind, type: MovieTicket::Type) : MovieTicket |
|                                                                                                                                          |
| +getWeekendTickets() : int                                                                                                               |
| +getWeekdayTickets() : int                                                                                                               |
| +getMatineeTickets() : int                                                                                                               |
| +getEveningTickets() : int                                                                                                               |
|                                                                                                                                          |
| +getRevenue() : double                                                                                                                   |

A BoxOffice class holds two string values, one for its address and one for the movie it is playing.  Both of these data members have an accessor method.  As tickets are purchased via buyTicket( ... ), the BoxOffice keeps track of how many weekend tickets, how many weekday tickets, how many matinee tickets and how many evening tickets have been sold.  Exactly like a MovieTicket, weekend tickets are for showings held on Friday, Saturday or Sunday.  Weekday tickets are for showings held on Monday, Tuesday, Wednesday or Thursday.  Matinee tickets are for showings that start prior to 5 PM.  Evening tickets are for showings that start after 5 PM.  The BoxOffice also keeps track of the cumulative total cost of every ticket returned by calls to buyTicket( ... ) which is returned by the accessor method getRevenue( ).  Calls to buyTicket( ... ) returns a MovieTicket based on the values of the five passed parameters.  The requested movie string value must match the BoxOffice's mMovie value.  If these two strings do not match, then buyTicket( ... ) should throw a std::logic_error back at the calling code.

For this project, you will create both a .h and .cpp for these two classes.  Write some sample driver code in your main( ) and create assertions to verify that your accessor methods are all working properly.  Some sample code is shown below to further document how this class should work.  You should be guarding your .H files as shown in class to ensure they can be properly included by anyone who uses them.

You are free to create additional public and private methods and data members as you see fit.  However, the test cases will only be driving the public methods of the two classes diagrammed here.
