#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

class clsString
{

private:

	string _Value;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void setValue(string Value)
	{
		_Value = Value;
	}

	string getValue()
	{
		return _Value;
	}

	__declspec(property(get = getValue, put = setValue)) string Value;

	static void PrintFirstLetterEachWords(string str)
	{

		bool IsFirstLetter = true;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && IsFirstLetter)
			{
				cout << str[i] << '\n';
			}
			IsFirstLetter = (str[i] == ' ');
		}

	}

	void PrintFirstLetterEachWords()
	{

		PrintFirstLetterEachWords(_Value);
	}

	static string UpperFirstLetterOfEachWord(string str)
	{

		bool IsFirstLetter = true;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && IsFirstLetter)
			{
				str[i] = toupper(str[i]);
			}
			IsFirstLetter = (str[i] == ' ');
		}
		return str;
	}

	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string str)
	{

		bool IsFirstLetter = true;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && IsFirstLetter)
			{
				str[i] = tolower(str[i]);
			}
			IsFirstLetter = (str[i] == ' ');
		}
		return str;
	}

	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string str)
	{

		for (int i = 0; i < str.length(); i++)
		{

			str[i] = toupper(str[i]);
		}
		return str;
	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string str)
	{

		for (int i = 0; i < str.length(); i++)
		{

			str[i] = tolower(str[i]);
		}
		return str;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static char InvertLetterCase(char ch)
	{
		return isupper(ch) ? tolower(ch) : toupper(ch);
	}

	static string InvertAllLettersCase(string str)
	{

		for (int i = 0; i < str.length(); i++)
		{
			str[i] = InvertLetterCase(str[i]);

		}
		return str;
	}

	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	static int CountCapitalLetters(string str)
	{
		int Counter = 0;

		for (int i = 0; i < str.length(); i++)
		{

			if (isupper(str[i]))
				Counter++;
		}
		return Counter;
	}

	int CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static int CountSmallerLetters(string str)
	{
		int Counter = 0;

		for (int i = 0; i < str.length(); i++)
		{

			if (islower(str[i]))
				Counter++;
		}
		return Counter;
	}

	int CountSmallerLetters()
	{
		return CountSmallerLetters(_Value);
	}

	static int Length(string str)
	{
		int Counter = 0;

		for (int i = 0; str[i] != '\0'; i++)
		{
			Counter++;
		}
		return Counter;
	}
	
	int Length()
	{
		return 	Length(_Value);
	}

	static int CountLetter(string str, char Letter, bool MatchCase = true)
	{
		int Counter = 0;

		for (int i = 0; i < str.length(); i++)
		{
			if (MatchCase) {

				if (str[i] == Letter)
					Counter++;
			}
			else {

				if (tolower(str[i]) == tolower(Letter))
					Counter++;
			}
		}
		return Counter;
	}

	int CountLetter(char Letter, bool MatchCase = true)
	{
		return CountLetter(_Value, Letter, MatchCase);
	}

	static bool IsVowel(char Letter)
	{
		Letter = tolower(Letter);

		return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
	}

	static int CountVowels(string str)
	{
		int Counter = 0;

		for (int i = 0; i < str.length(); i++)
		{
			if (IsVowel(str[i]))
				Counter++;
		}
		return Counter;
	}

	int CountVowels()
	{
		return CountVowels(_Value);
	}

	static void PrintEachWordInString(string str)
	{
		int pos = 0;
		string delim = " ";
		string sWord = "";

		while ((pos = str.find(delim)) != std::string::npos)
		{

			sWord = str.substr(0, pos);

			if (sWord != "")
			{
				cout << sWord << '\n';
			}
			str.erase(0, pos + delim.length());
		}

		if (str != "")
		{
			cout << str;
		}

	}

	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	int CountEachWordInString(string str)
	{
		int pos = 0;
		string delim = " ";
		string sWord = "";
		int Counter = 0;

		while ((pos = str.find(delim)) != std::string::npos)
		{

			sWord = str.substr(0, pos);

			if (sWord != "")
			{
				Counter++;
			}
			str.erase(0, pos + delim.length());
		}

		if (str != "")
		{
			Counter++;
		}
		return Counter;
	}

	int CountEachWordInString()
	{
		return CountEachWordInString(_Value);
	}

	static vector <string>Split(string str, string delim = " ")
	{
		vector <string> vString;
		string sWord = "";
		int pos = 0;

		while ((pos = str.find(delim)) != string::npos)
		{
			sWord = str.substr(0, pos);

			if (sWord != "")
			{
				vString.push_back(sWord);
			}
			str.erase(0, pos + delim.length());
		}

		if (str != "")
		{
			vString.push_back(str);
		}
		return vString;
	}

	vector <string>Split(string delim=" ")
	{
		return Split(_Value, delim);
	}

	string JoinString(vector <string>vString, string Separator = " ")
	{

		for (auto& v : vString)
		{
			_Value += v + Separator;
		}
		_Value.erase(_Value.length() - Separator.length());
		return _Value;
	}

	string JoinString(string arr[], int arrLength, string Separator = " ")
	{
		for (int i=0;i < arrLength;i++)
		{
			_Value += arr[i] + Separator;
		}
		_Value.erase(_Value.length() - Separator.length());
		return _Value;
	}

	static string TrimLeft(string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ')
			{
				return str.substr(i, str.length() - i);
			}
		}
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string str)
	{
		for (int i = str.length() - 1; i >= 0; i--)
		{
			if (str[i] != ' ')
			{
				return str.substr(0, i + 1);
			}
		}
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string str)
	{
		return TrimLeft(TrimRight(str));
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string ReverseWords(string str)
	{
		vector <string>vString = clsString::Split(str, " ");

		vector <string>::iterator iter = vString.end();
		string str2 = "";

		while (iter != vString.begin())
		{
			iter--;
			str2 += *iter + " ";;
		}
		str2 = str2.substr(0, str2.length() - 1);
		return str2;
	}

	void ReverseWords()
	{
		_Value = ReverseWords(_Value);
	}

	static string ReplaceWord(string str, string StringReplaceTo, string ReplaceTo)
	{
		int pos = str.find(StringReplaceTo);

		while (pos != string::npos) {

			str.replace(pos, StringReplaceTo.length(), ReplaceTo);
			pos = str.find(StringReplaceTo);
		}
		return str;
	}

	void ReplaceWord(string StringReplaceTo, string ReplaceTo)
	{
		_Value = ReplaceWord(_Value, StringReplaceTo, ReplaceTo);
	}

};

