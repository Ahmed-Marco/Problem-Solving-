#pragma once
#include <iostream>
#include "clsDate.h"
#include <cstdlib>
using namespace std;

class clsUtil
{

public:

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		return rand() % (To - From + 1) + From;
	}

	enum enCharater { Digit = 1, SmallLetter = 2, CapitalLetter = 3, MixChars = 4, SpecialCharacter=5};

	static char GetRandomCharacter(enCharater eChar)
	{
		if (eChar == MixChars)
		{
			eChar = (enCharater)RandomNumber(1, 3);
		}

		switch (eChar)
		{
		case enCharater::Digit:
			return (char)RandomNumber(48, 57);

		case enCharater::SmallLetter:
			return (char)RandomNumber(97, 122);

		case enCharater::CapitalLetter:
			return (char)RandomNumber(65, 90);

		case enCharater::SpecialCharacter:
			return (enCharater)RandomNumber(33, 47);
		}

	}

	static string GenerateWord(enCharater eChar, short CharCount)
	{
		string Word="";

		for (short i = 1; i <= CharCount; i++)
		{
			Word += GetRandomCharacter(eChar);
		}
		return Word;
	}

	static string GenerateKey(enCharater eChar)
	{
		string Key = "";

		Key = GenerateWord(eChar, 4) + "-";
		Key = Key + GenerateWord(eChar, 4) + "-";
		Key = Key + GenerateWord(eChar, 4) + "-";
		Key = Key + GenerateWord(eChar, 4);

		return Key;
	}

	static void GenerateKeys(short KeysCount, enCharater eChar)
	{

		for (short i = 1; i <= KeysCount; i++)
		{
			cout << "Key [" << i <<"] " << GenerateKey(eChar) << endl;
		}
	}

	static void Swap(int& Num1, int& Num2)
	{
		int Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}

	static void Swap(double& Num1, double& Num2)
	{
		double Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}

	static void Swap(string &S1, string &S2)
	{
		string TempStr;
		TempStr = S1;
		S1 = S2;
		S2 = TempStr;
	}

	static void Swap(clsDate &Date1, clsDate &Date2)
	{
		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	static void ShuffleArray(int arr[5], int arrLength)
	{

		for (short i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(0, arrLength - 1)], arr[RandomNumber(0, arrLength - 1)]);
		}
	}

	static void ShuffleArray(string arr[], int arrLength)
	{

		for (short i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(0, arrLength - 1)], arr[RandomNumber(0, arrLength - 1)]);
		}
	}

	static void FillArrayWithRandomNumbers(int arr[], int arrLength, int From, int To)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = RandomNumber(From, To);
		}
	}

	static void FillArrayWithRandomWords(string arr[], int arrLength,enCharater eChar, int CharCount)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(eChar, CharCount);
		
	}

	static void FillArrayWithRandomKeys(string arr[], int arrLength, enCharater eChar)
	{
		for (int i = 0; i < arrLength; i++)
		
			arr[i] = GenerateKey(eChar);
		
	}

	static string Tabs(short Count)
	{
		string S1="";

		for (short i = 1; i <= Count; i++)
		{
			S1 += '\t';
		}
		return S1;
	}

	static string EncryptText(string S1, short Key)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = S1[i] + Key;
		}
		return S1;
	}

	static string DecryptText(string S1, short Key)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = S1[i] - Key;
		}
		return S1;
	}

};

