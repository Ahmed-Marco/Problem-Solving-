#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsUtil.h"
using namespace std;


class clsInputValidate
{

public:

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{

		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate FromDate, clsDate ToDate)
	{

		if (clsDate::IsDate1BeforeDate2(ToDate, FromDate))
		{
			clsUtil::Swap(FromDate, ToDate);
		}
		return !(Date.IsDate1BeforeDate2(FromDate)
			|| Date.IsDate1AfterDate2(ToDate));
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again : ")
	{
		double Num = 0;
		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			cout << ErrorMessage;
		}
		return Num;
	}

	static int ReadIntNumber(string ErrorMessage="Invalid Number , Enter again: ")
	{
		int Num = 0;
		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Num;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage= "Number is not within range, enter again: ")
	{
		int Num = ReadIntNumber();
		while (!IsNumberBetween(Num,From,To))
		{
			cout << ErrorMessage;
			Num = ReadIntNumber();
		}
		return Num;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage= "Number is not within range, enter again: ")
	{
		double Num = ReadDblNumber();
		while (!IsNumberBetween(Num, From, To))
		{
			cout << ErrorMessage;
			Num = ReadDblNumber();
		}
		return Num;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

};

