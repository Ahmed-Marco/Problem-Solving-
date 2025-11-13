#pragma once

#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include "clsString.h"
using namespace std;

class clsDate
{

private:

	short _Day, _Month, _Year;

public:

	clsDate()
	{

		time_t now = time(0);        // الوقت الحالي كـ timestamp
		tm* localTime = localtime(&now); // تحويله لوقت محلي

		//cout << localTime->tm_mday << "/" << (1 + localTime->tm_mon) << "/" << (1900 + localTime->tm_year);
		_Day = localTime->tm_mday;
		_Month = localTime->tm_mon + 1;
		_Year = localTime->tm_year + 1900;
	}

	clsDate(short Day, short Month, int Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;

	}

	clsDate(short DateOrderInYear, int Year)
	{

		clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);

		_Day = Date1._Day;
		_Month = Date1._Month;
		_Year = Date1._Year;

	}

	clsDate(string Date)
	{

		vector <string>vDate;
		vDate = clsString::Split(Date, "/");

		_Day = stoi(vDate.at(0));
		_Month = stoi(vDate.at(1));
		_Year = stoi(vDate.at(2));
	}

	void SetDay(short Day)
	{
		_Day = Day;
	}

	short GetDay()
	{
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month)
	{
		_Month = Month;
	}

	short GetMonth()
	{
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetYear(int Year)
	{
		_Year = Year;
	}

	int GetYear()
	{
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear)) int Year;

	void Print()
	{
		cout << DateToString() << endl;
	}

	static clsDate GetSystemDate()
	{
		short Day, Month, Year;

		time_t now = time(0);        // الوقت الحالي كـ timestamp
		tm* localTime = localtime(&now); // تحويله لوقت محلي

		Day = localTime->tm_mday;
		Month = localTime->tm_mon + 1;
		Year = localTime->tm_year + 1900;
		return clsDate(Day, Month, Year);
	}

	static bool IsValidDate(clsDate Date)
	{
		return !((Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year)) || (Date.Month < 1 || Date.Month > 12) || (Date.Year < 1));
	}

	bool IsValidDate()
	{
		return IsValidDate(*this);
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	static bool IsLeapYear(int Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short NumberOfDaysInYear(int Year)
	{
		return 	IsLeapYear(Year) ? 366 : 365;
	}

	short NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Year);
	}

	static int NumberOfHoursInYear(int Year)
	{
		return NumberOfDaysInYear(Year) * 24;
	}

	int NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(_Year);
	}

	static int NumberOfMinutesInYear(int Year)
	{
		return NumberOfHoursInYear(Year) * 60;
	}

	int NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(_Year);
	}

	static int NumberOfSecondsInYear(int Year)
	{
		return NumberOfMinutesInYear(Year) * 60;
	}

	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(_Year);
	}

	static short NumberOfDaysInMonth(short Month, int Year)
	{

		short DaysInMonth[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : DaysInMonth[Month - 1];
	}

	short NumberOfDaysInMonth()
	{

		return NumberOfDaysInMonth(_Month, _Year);
	}

	static short NumberOfHoursInMonth(short Month, int Year)
	{
		return NumberOfDaysInMonth(Month, Year) * 24;
	}

	short NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(_Month, _Year);
	}

	static int  NumberOfMinutesInMonth(short Month, int Year)
	{
		return NumberOfHoursInMonth(Month, Year) * 60;
	}

	int  NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(_Month, _Year);
	}

	static int NumberOfSecondsInMonth(short Month, int Year)
	{
		return NumberOfMinutesInMonth(Month, Year) * 60;
	}

	int NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(_Month, _Year);
	}

	static short DayOfWeekOrder(short Day, short Month, short Year) {
		short a, y, m;

		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short DayOfWeekOrder() {

		return DayOfWeekOrder(_Day, _Month, _Year);
	}

	static string DayShortName(short DayOfWeekOrder) {

		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder];
	}

	static string MonthShortName(short MonthNumber) {

		string Months[12] = { "Jan", "Feb", "Mar",
			"Apr", "May", "Jun", "Jul", "Aug",
			"Sep", "Oct", "Nov", "Dec"
		};
		return (Months[MonthNumber - 1]);
	}

	static void MonthCalendar(short Month, int Year)
	{

		int current = DayOfWeekOrder(1, Month, Year);
		int NumberOfDays = NumberOfDaysInMonth(Month, Year);

		printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());

		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		short i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (short j = 1; j <= NumberOfDays; j++)
		{

			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n  __________________________________\n\n");
	}

	void MonthCalendar()
	{
		MonthCalendar(_Month, _Year);
	}

	static void YearCalendar(int Year)
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", Year);
		printf("  _________________________________\n");

		for (short i = 1; i <= 12; i++)
		{
			MonthCalendar(i, Year);
		}
	}

	void YearCalendar()
	{
		YearCalendar(_Year);
	}

	static short DaysFromBeginingOfYear(short Day, short Month, int Year)
	{
		short TotalDays = 0;

		for (int i = 1; i < Month; i++)
		{
			TotalDays += NumberOfDaysInMonth(i, Year);
		}
		TotalDays += Day;
		return TotalDays;

	}

	short DaysFromBeginningOfYear()
	{
		return DaysFromBeginingOfYear(_Day, _Month, _Year);
	}

	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, int Year)
	{

		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;


		short Month = 1;
		short Day = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Month, Year);

			if (MonthDays < RemainingDays)
			{
				RemainingDays -= MonthDays;
				Month++;
			}
			else {

				Day = RemainingDays;
				break;
			}

		}
		return clsDate(Day, Month, Year);
	}

	static 	void AddDays(short Days, short Day, short Month, int Year) {

		short RemainingDays = Days + DaysFromBeginingOfYear(Day, Month, Year);
		short MonthDays = 0;
		Month = 1;

		while (true) {
			MonthDays = NumberOfDaysInMonth(Month, Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Month++;
				if (Month > 12)
				{
					Month = 1;
					Year++;
				}
			}
			else {
				Day = RemainingDays;
				break;
			}
		}
	}

	static clsDate AddOneDay(clsDate Date)
	{

		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._Month))
			{
				Date.Month = 1;
				Date.Day = 1;
				Date.Year++;
			}
			else {
				Date.Day = 1;
				Date.Month++;
			}
		}
		else {
			Date.Day++;
		}
		return Date;
	}

	void AddDays(short Days)
	{
		short RemainingDays = Days + DaysFromBeginingOfYear(_Day, _Month, _Year);
		short MonthDays = 0;
		_Month = 1;

		while (true) {
			MonthDays = NumberOfDaysInMonth(_Month, _Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				_Month++;
				if (_Month > 12)
				{
					_Month = 1;
					_Year++;
				}
			}
			else {
				_Day = RemainingDays;
				break;
			}
		}

	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
			(Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}

	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month)
			? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
	}

	bool IsDate1EqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date1)
	{
		return (Date1.Day == NumberOfDaysInMonth(Date1.Month, Date1.Year));
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate Temp;
		Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		short SawpFlagValue = 1;
		int Days = 0;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SawpFlagValue = -1;
		}
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++; Date1 = AddOneDay(Date1);
		}
		return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
	}

	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	static short CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);

	}

	static clsDate IncreaseDateByOneWeek(clsDate& Date)
	{

		for (int i = 1; i <= 7; i++)
			Date = AddOneDay(Date);
		return Date;
	}

	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}

	clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void IncreaseDateByXWeeks(short Weeks)
	{

		IncreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& Date)
	{

		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}
		return Date;
	}

	void IncreaseDateByOneMonth()
	{
		IncreaseDateByOneMonth(*this);
	}

	static	clsDate IncreaseDateByXDays(short Days, clsDate& Date)
	{
		for (short i = 1; i <= Days; i++) {
			Date = AddOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByXDays(short Days)
	{
		IncreaseDateByXDays(Days, *this);
	}

	static clsDate IncreaseDateByXMonths(short Months, clsDate& Date)
	{
		for (short i = 1; i <= Months; i++) {
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void IncreaseDateByXMonths(short Months)
	{
		IncreaseDateByXMonths(Months, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date)
	{
		Date.Year++;
		return Date;
	}

	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(short Years, clsDate& Date)
	{

		Date.Year += Years;
		return Date;
	}

	void IncreaseDateByXYears(short Years)
	{
		IncreaseDateByXYears(Years);
	}

	static clsDate IncreaseDateByOneDecade(clsDate& Date)
	{
		Date.Year += 10;
		return Date;
	}

	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(short Decade, clsDate& Date)
	{
		Date.Year += Decade * 10;
		return Date;
	}

	void IncreaseDateByXDecades(short Decade)
	{
		IncreaseDateByXDecades(Decade, *this);
	}

	static clsDate IncreaseDateByOneCentury(clsDate& Date)
	{
		Date.Year += 100;
		return Date;
	}

	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}

	static	clsDate IncreaseDateByOneMillennium(clsDate& Date)
	{
		Date.Year += 1000;
		return Date;
	}

	void IncreaseDateByOneMillennium()
	{
		IncreaseDateByOneMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate& Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Month = 12;
				Date.Day = 31;
				Date.Year--;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
			}
		}
		else
		{
			Date.Day--;
		}
		return Date;
	}

	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void DecreaseDateByXWeeks(short Weeks) {

		DecreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
			Date.Month--;

		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXDays(short Days, clsDate& Date)
	{

		for (short i = 1; i <= Days; i++)

		{
			Date = DecreaseDateByOneDay(Date);

		}

		return Date;
	}

	void DecreaseDateByXDays(short Days)
	{
		DecreaseDateByXDays(Days, *this);
	}

	static clsDate DecreaseDateByXMonths(short Months, clsDate& Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonths(short Months)
	{
		DecreaseDateByXMonths(Months, *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate& Date)
	{
		Date.Year--;
		return Date;
	}

	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(short Years, clsDate& Date)
	{
		Date.Year -= Years;
		return Date;

	}

	void DecreaseDateByXYears(short Years)
	{
		DecreaseDateByXYears(Years, *this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate& Date)
	{
		Date.Year -= 10;
		return Date;
	}

	void DecreaseDateByOneDecade() 
	{
		DecreaseDateByOneDecade(*this);
	}
	
	static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date)
	{
		Date.Year -= Decades * 10;
		return Date;
	}

	void DecreaseDateByXDecades(short Decades) 
	{ 
		DecreaseDateByXDecades(Decades, *this);
	}
	
	static clsDate DecreaseDateByOneCentury(clsDate& Date)
	{
		Date.Year -= 100;
		return Date; 
	} 
	
	void DecreaseDateByOneCentury() 
	{    
		DecreaseDateByOneCentury(*this);  
	
	}
	
	static clsDate DecreaseDateByOneMillennium(clsDate &Date)   
	{ 
		Date.Year -= 1000; 
		return Date; 
	}
	
	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}

	static bool IsEndOfWeek(clsDate Date) 
	{
		return  DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6;
	}
	
	bool IsEndOfWeek() 
	{
		return IsEndOfWeek(*this); 
	}
	
	static bool IsWeekEnd(clsDate Date)
	{
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		return  (DayIndex == 0 || DayIndex == 6);  
	} 
	
	bool IsWeekEnd() 
	{
		return  IsWeekEnd(*this); 
	}
	
	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}

	bool IsBusinessDay()
	{ 
		return  IsBusinessDay(*this);   
	
	} 

	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}

	short DaysUntilTheEndOfWeek()
	{ 
		return  DaysUntilTheEndOfWeek(*this); 
	} 
	
	static short DaysUntilTheEndOfMonth(clsDate Date1) 
	{ 
		clsDate EndOfMontDate;  

		EndOfMontDate.Day = NumberOfDaysInMonth(Date1.Month, Date1.Year);  
		EndOfMontDate.Month = Date1.Month; 
		EndOfMontDate.Year = Date1.Year;
		return GetDifferenceInDays(Date1, EndOfMontDate, true); 
	}
	
	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date1) 
	{ 
		clsDate EndOfYearDate;   

		EndOfYearDate.Day = 31;  
		EndOfYearDate.Month = 12;  
		EndOfYearDate.Year = Date1.Year;
		return GetDifferenceInDays(Date1, EndOfYearDate, true);
	}
	
	short DaysUntilTheEndOfYear() 
	{
		return  DaysUntilTheEndOfYear(*this);
	}

	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo) 
	{
		short Days = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo)) {
			if (IsBusinessDay(DateFrom)) 
				Days++; DateFrom = AddOneDay(DateFrom); 
		} 
		return Days;
	} 

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo) { 
		
		return CalculateBusinessDays(DateFrom, DateTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{
		short WeekEndCounter = 0;

		for (short i = 1; i <= VacationDays; i++)
		{
			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;
			DateFrom = AddOneDay(DateFrom);
		}

		for (short i = 1; i <= WeekEndCounter; i++)
			DateFrom = AddOneDay(DateFrom);

		return DateFrom;
	}
	
	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) 
	{ 
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));  
	} 

	bool IsDateAfterDate2( clsDate Date2)  
	{
		return IsDate1AfterDate2(*this, Date2); 
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };
	
	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;
	}

	enDateCompare CompareDates(clsDate Date2)
	{ 
		return CompareDates(*this, Date2);
	}

};

