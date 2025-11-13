#include <iostream>
#include <limits>
using namespace std;

struct sDate {
	short Day;
	short Month;
	short Year;
};

bool IsLeapYear(short Year) {

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short DaysInMonth(short Month, short Year) {

	short DaysMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year)? 29 : 28) : DaysMonth[Month - 1];
}

sDate DecreaseDateByOneDay(sDate Date) {

	if (Date.Day == 1) {

		if (Date.Month == 1) {

			Date.Day = 31;
			Date.Month=12;
			Date.Year--;
		}
		else {
			Date.Month--;
			Date.Day = DaysInMonth(Date.Month, Date.Year);
		}
	}
	else {
		Date.Day--;
	}
	return Date;
}

sDate DecreaseDateByXDays(sDate Date, short Days) {

	for (short i = 1; i <= Days; i++) 
		Date = DecreaseDateByOneDay(Date);
	return Date;
}

sDate DecreaseDateByOneWeek(sDate Date) {

	return DecreaseDateByXDays(Date, 7);
}

sDate DecreaseDateByXWeeks(sDate Date, short Weeks) {

	for (short i = 1; i <= Weeks; i++)
		Date = DecreaseDateByOneWeek(Date);
	return Date;
}

sDate DecreaseDateByOneMonth(sDate Date) {

	if (Date.Month == 1) {

		Date.Month = 12;
		Date.Year--;
	}
	else {
		Date.Month--;
	}

	short NumberOfDaysInMonth = DaysInMonth(Date.Month, Date.Year);

	if (Date.Day > NumberOfDaysInMonth) {
		Date.Day = NumberOfDaysInMonth;
	}
	return Date;
}

sDate DecreaseDateByXMonths(sDate Date, short Month) {

	for (short i = 1; i <= Month; i++)
		Date = DecreaseDateByOneMonth(Date);
	return Date;
}

sDate DecreaseDateByOneYear(sDate Date) {

	Date.Year--;

	if ((Date.Month == 2 && Date.Day == 29) && !IsLeapYear(Date.Year)) {
		Date.Day = 28;
	}
	return Date;
}

sDate DecreaseDateByXYears(sDate Date, short Years) {

	bool WasFeb29 = (Date.Month == 2 && Date.Day == 29);

	for (short i = 1; i <= Years; i++)
		Date = DecreaseDateByOneYear(Date);

	if (WasFeb29 && IsLeapYear(Date.Year)) Date.Day = 29;

	return Date;
}

sDate DecreaseDateByXYearsFaster(sDate Date, short Years) {

	Date.Year -= Years;

	if ((Date.Month == 2 && Date.Day == 29) && !IsLeapYear(Date.Year)) Date.Day = 28;
	
	return Date;
}

sDate DecreaseDateByOneDecade(sDate Date) {

	return DecreaseDateByXYearsFaster(Date, 10);
}

sDate DecreaseDateByXDecades(sDate Date, short Decades) {

	for (short i = 1; i <= Decades; i++)
		Date = DecreaseDateByOneDecade(Date);
	return Date;

}

sDate DecreaseDateByXDecadesFaster(sDate Date, short Decades) {

	return DecreaseDateByXYearsFaster(Date, 10 * Decades);

}

sDate DencreaseDateByOneCentury(sDate Date) {

	return DecreaseDateByXDecadesFaster(Date, 10);
}

sDate DecreaseDateByOneMillennium(sDate Date) {

	return DecreaseDateByXDecadesFaster(Date, 100);
}

short CheckToEnterNumberOnly(string str) {

	short Num;
	cout << str;
	cin >> Num;

	while (cin.fail()) {

		cin.clear();
		cin.ignore(std::numeric_limits < std:: streamsize > ::max(), '\n');

		cout << "\nPlease enter only numbers. Maximum possible value is 32767.";
		cout << str;
		cin >> Num;
	}
	return Num;
}
short ReadYear() {

	return	CheckToEnterNumberOnly("Enter a Year? ");
}

short ReadMonth() {

	return CheckToEnterNumberOnly("Enter a Month? ");
}

short ReadDay() {

	return CheckToEnterNumberOnly("Enter a Day? ");
}

bool CheckIsWrongDate(sDate Date) {

	return (Date.Year < 1) ? true : 
		(Date.Month < 1 || Date.Month >12) ? true : 
		(Date.Day > DaysInMonth(Date.Month, Date.Year)) ? true : false;
}

sDate ReadFullDate() {

	sDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	cout << '\n';

	while (CheckIsWrongDate(Date)) {

		cout << "\nWorng Date Press Any Key to add new date...";
		system("pause>0");
		system("cls");
	
		Date.Day = ReadDay();
		Date.Month = ReadMonth();
		Date.Year = ReadYear();
		cout << '\n';
	}

	return Date;
}

int main() {

	sDate Date = ReadFullDate();
	//sDate Date;
	//Date.Day = 31, Date.Month = 12, Date.Year = 2022;

	cout << "\nDate After:\n";

	Date = DecreaseDateByOneDay(Date);
	printf("\n01-Subtracting one day is: %02d/%02d/%d", Date.Day, Date.Month, Date.Year);

	short Days = 10;
	Date = DecreaseDateByXDays(Date, Days);
	printf("\n02-Subtracting %d days is: %02d/%02d/%d", Days, Date.Day, Date.Month, Date.Year);

	Date = DecreaseDateByOneWeek(Date);
	printf("\n03-Subtracting one week is: %02d/%02d/%d", Date.Day, Date.Month, Date.Year);

	short Weeks = 10;
	Date = DecreaseDateByXWeeks(Date, Weeks);
	printf("\n04-Subtracting %d weeks is: %02d/%02d/%d", Weeks, Date.Day, Date.Month, Date.Year);

	Date = DecreaseDateByOneMonth(Date);
	printf("\n05-Subtracting one month is: %02d/%02d/%d", Date.Day, Date.Month, Date.Year);

	short Months = 5;
	Date = DecreaseDateByXMonths(Date, Months);
	printf("\n06-Subtracting %d months is: %02d/%02d/%d", Months, Date.Day, Date.Month, Date.Year);

	Date = DecreaseDateByOneYear(Date);
	printf("\n07-Subtracting one year is: %02d/%02d/%d", Date.Day, Date.Month, Date.Year);

	short Years = 10;
	Date = DecreaseDateByXYears(Date, Years);
	printf("\n08-Subtracting %d Years is: %02d/%02d/%d", Years, Date.Day, Date.Month, Date.Year);
	
	Date = DecreaseDateByXYearsFaster(Date, Years);
	printf("\n09-Subtreacting %d Years (faster) is: %02d/%02d/%d", Years, Date.Day, Date.Month, Date.Year);

	Date = DecreaseDateByOneDecade(Date);
	printf("\n10-Subtracting one Decade is: %02d/%02d/%d", Date.Day, Date.Month, Date.Year);

	short Decades = 10;
	Date = DecreaseDateByXDecades(Date, Decades);
	printf("\n11-Subtracting %d Decades is: %02d/%02d/%d", Decades, Date.Day, Date.Month, Date.Year);

	Date = DecreaseDateByXDecadesFaster(Date, Decades);
	printf("\n12-Subtracting %d Decades (faster) is: %02d/%02d/%d", Decades, Date.Day, Date.Month, Date.Year);
	
	Date = DencreaseDateByOneCentury(Date);
	printf("\n13-Subtracting One Century is: %02d/%02d/%d", Date.Day, Date.Month, Date.Year);

	Date = DecreaseDateByOneMillennium(Date);
	printf("\n14-Subtracting One Millennium is: %02d/%02d/%d", Date.Day, Date.Month, Date.Year);

	system("pause>0");

	return 0;
}
