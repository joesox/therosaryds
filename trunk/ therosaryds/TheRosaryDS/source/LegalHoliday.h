#ifndef _LEGALHOLIDAY_H_
#define _LEGALHOLIDAY_H_

#include "DoomsdayDate.h"

namespace
{

// New Year's Day, January 1.
DoomsdayDate NewYears(int year)
{
    return DoomsdayDate(Month::JAN, 1, year);
}

// Birthday of Martin Luther King, Jr., the third Monday in January.
DoomsdayDate MartinLutherKingJr(int year)
{
    DoomsdayDate dd;
    dd.SetThird(Weekday::MONDAY, Month::JAN, year);
    return dd;
}

// Washington's Birthday, the third Monday in February.
DoomsdayDate WashingtonsBirthday(int year)
{
    DoomsdayDate dd;
    dd.SetThird(Weekday::MONDAY, Month::FEB, year);
    return dd;    
}

// Memorial Day, the last Monday in May.
DoomsdayDate MemorialDay(int year)
{
    DoomsdayDate dd;
    dd.SetFourth(Weekday::MONDAY, Month::MAY, year);
    return dd;    
}

// Independence Day, July 4.
DoomsdayDate IndependenceDay(int year)
{
    return DoomsdayDate(Month::JUL, 4, year);
}

// Labor Day, the first Monday in September.
DoomsdayDate LaborDay(int year)
{
    DoomsdayDate dd;
    dd.SetFirst(Weekday::MONDAY, Month::SEP, year);
    return dd;    
}

// Columbus Day, the second Monday in October.
DoomsdayDate ColumbusDay(int year)
{
    DoomsdayDate dd;
    dd.SetSecond(Weekday::MONDAY, Month::OCT, year);
    return dd;    
}

// Veterans Day, November 11.
DoomsdayDate VeteransDay(int year)
{
    return DoomsdayDate(Month::NOV, 11, year);
}

// Thanksgiving Day, the fourth Thursday in November.
DoomsdayDate ThanksgivingDay(int year)
{
    DoomsdayDate dd;
    dd.SetFourth(Weekday::THURSDAY, Month::NOV, year);
    return dd;    
}

// Christmas Day, December 25.
DoomsdayDate ChristmasDay(int year)
{
    return DoomsdayDate(Month::DEC, 25, year);
}

};

#endif

