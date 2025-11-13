#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;

namespace Reader {

int ReadPositiveNumber() {

	int Num = 0;
	do {
		cout << "Enter a positive number : ";
		cin >> Num;
	} while (Num < 0);
	return Num;
}

int ReadNumber() {
	int Num = 0;
	cin >> Num;
	return Num;
}

int ReadNumberWithMassage(string message) {

	int Num = 0;
	cout << message;
	cin >> Num;
return Num;

}

int ReadIntOnly() {

	int Number = 0;

	cout << "Enter a Number Only: ";
	cin >> Number;
	while (cin.fail()) {

		cin.clear();// Clear the error flag
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// Ignore the invalid input include <limits>

		cout << "Invalid Number, Enter a valid one:" << endl;
		cin >> Number;
	}
	return Number;

}

void ReadFile(const string Path) {

	//Myfile
	//#include <fstream>
	fstream Myfile;

	Myfile.open(Path, ios::in);
	if (Myfile.is_open()) {

		string str = "";

		while (getline(Myfile, str))
			cout << str << endl;

		Myfile.close();
	}

}


}

namespace stringFunc {

	void PrintFirstLetterOfEachWord(string S1) {

		bool IsFirstLetter = true;

		for (int i = 0; i < S1.length(); i++) {

			if (S1[i] != ' ' && IsFirstLetter) {

				cout << S1[i] << '\n';
			}
			IsFirstLetter = (S1[i] == ' ' ? true : false);

		}
	}

	string UpperFirstLetterOfEachWord(string S1) {

		bool IsFirstLetter = true;

		for (short i = 0; i < S1.length(); i++) {

			if (S1[i] != ' ' && IsFirstLetter) {

				S1[i] = toupper(S1[i]);
			}


			IsFirstLetter = (S1[i] == ' ' ? true : false);

		}
		return S1;

	}

	string LowerAllString(string S1) {


		for (short i = 0; i < S1.length(); i++) {

			if (isupper(S1[i])) {

				S1[i] = tolower(S1[i]);
			}
		}
		return S1;
	}


	string UpperAllLString(string S1) {


		for (short i = 0; i < S1.length(); i++) {

			if (islower(S1[i])) {

				S1[i] = toupper(S1[i]);
			}
		}
		return S1;
	}

	char InvertLetterCase(char ch) {

	return isupper(ch) ? tolower(ch) : toupper(ch);
	}

	string InvertAllStringLetterCase(string S1) {


		for (short i = 0; i < S1.length(); i++) {

			S1[i] = InvertLetterCase(S1[i]);

		}
		return S1;
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

	short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All) {

		if (WhatToCount == enWhatToCount::All) {
			return S1.length();
		}

		short counter = 0;

		for (short i = 0; i < S1.length(); i++) {

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				counter++;
			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				counter++;

		}
		return counter;
	}

	void PrintEachWordInString(string& S1) {

		string delim = " ";
		string sWord = "";
		short pos = 0;

		while ((pos = S1.find(delim)) != string::npos) {

			sWord = S1.substr(0, pos);

			if (sWord != "") {
				cout << sWord << '\n';
			}

			S1.erase(0, pos + delim.length());

		}

		if (S1 != "") {
			cout << S1;
		}
	}

	short CountWordsInString(string& S1) {


		string delim = " ";
		string sWord = "";
		short pos = 0;
		short counter = 0;

		while ((pos = S1.find(delim)) != string::npos) {

			sWord = S1.substr(0, pos);

			if (sWord != "") {

				counter++;
			}

			S1.erase(0, pos + delim.length());

		}

		if (S1 != "") {
			counter++;
		}

		return counter;

	}

	vector <string> SplitString(string S1, string delim = " ") {


		vector <string>vWords;

		string sWord = "";
		short pos = 0;

		while ((pos = S1.find(delim)) != string::npos) {

			sWord = S1.substr(0, pos);

			if (sWord != "") {
				vWords.push_back(sWord);
			}

			S1.erase(0, pos + delim.length());

		}

		if (S1 != "") {
			vWords.push_back(S1);
		}
		return vWords;

	}

	string ReverseWordsString(string S1) {

		string S2 = "";
		vector <string> vString;
		vString = SplitString(S1);

		vector <string>::iterator iter = vString.end();

		while (iter != vString.begin()) {

			iter--;

			S2 += *iter + ' ';

		}
		S2 = S2.substr(0, S2.length() - 1);
		return S2;

	}

	string ReplaceWordInStringUsingSplitStringToReplace(string& S1, string word, string ReplaceTo) {

		short pos = 0;

		while ((pos = S1.find(word)) != std::string::npos) {


			S1.replace(pos, word.length(), ReplaceTo);

		}
		return S1;
	}

	string TrimLeft(string str) {

		for (int i = 0; i < str.length(); i++) {

			if (str[i] != ' ') {
				//str.erase(0, i);
				return str.substr(i, str.length() - i);
			}
		}
	}

	string TrimRight(string str) {

    	for (int i = str.length() - 1; i >= 0; i--) {

			if (str[i] != ' ') {

				//	str.erase(i+1,strLength);

				return str.substr(0, i + 1);
			}
		}
	}

	string Trim(string str) {

		return TrimLeft(TrimRight(str));;
	}

	string JoinString(vector <string> vString, string delim = " ") {

		string str = "";

		for (string& st : vString) {

			str += st + delim;

		}
		return str.substr(0, str.length() - delim.length());

	}

	string JoinString(string arrString[], short arrLength, string delim = " ") {

		string st = "";

		for (short i = 0; i < arrLength; i++) {

			st += arrString[i] + delim;
		}

		return st.substr(0, st.length() - delim.length());

	}


	string ReplaceWord(string& S1, string word, string ReplaceTo, bool MatchCase = true) {

		short pos = 0;

		vector <string>vString;
		vString = SplitString(S1, " ");

		for (auto& str : vString) {

			if (MatchCase) {

				if (str == word) {

					str = ReplaceTo;
				}
			}
			else {

				if (LowerAllString(str) == LowerAllString(word)) {

					str = ReplaceTo;
				}
			}
		}
		return JoinString(vString, " ");
	}

	int CountAll(string Text)
	{
		int Counter = 0;

		for (int i = 0; Text[i] != '\0'; i++)
		{
			Counter++;
		}
		return Counter;
	}

	int findString(string text, string word) {
		int n = text.length();
		int m = word.length();

		for (int i = 0; i <= n - m; i++) {
			int j = 0;
			while (j < m && text[i + j] == word[j]) {
				j++;
			}
			if (j == m) {
				return i; // لقيتو ورجعنا الاندكس
			}
		}
		return -1; // يعني ما لقيت شي
	}

	int LengthStr(string Text)
	{
		int Counter = 0;

		for (int i = 0; Text[i] != '\0'; i++)
		{
			Counter++;
		}
		return Counter;
	}


}

namespace Random {


//srand((unsigned)time(NULL));	
int Random(int min, int max){
	int r = rand() % (max - min + 1) + min;
	return r;
}


}

namespace Math {

	int Round(float Num) {

		int intPart = (int)Num;
		float floatPart = Num - intPart;
		if (floatPart >= 0.5)
			return intPart + 1;
		else
			return intPart;

	}

	int Floor(float Num) {
		int intPart = (int)Num;
		return intPart;
	}

	int Ceil(float Num) {

		int intPart = (int)Num;
		float floatPart = Num - intPart;
		if (floatPart > 0)
			return intPart + 1;
		else
			return intPart;

	}

	float ABS(float Num) {

		if (Num < 0)
			return(Num * -1);
		else
			return Num;

	}

	int ReverseNumber(int Num) {

		int sum = 0, Remainder = 0;
		while (Num > 0) {

			Remainder = Num % 10;
			Num /= 10;
			sum = sum * 10 + Remainder;
		}
		return sum;
	}

	bool IsPolindromeNumber(int Num) {

		return ReverseNumber(Num) == Num;

	}
 
}

namespace Array {


	int MaxElementInArray(int arr[100], int arrLength) {

		int max = 0;
		for (int i = 0; i < arrLength; i++) {

			if (max < arr[i])
				max = arr[i];
		}
		return max;
	}

	int MinElementInArray(int arr[100], int arrLength) {

		int min = arr[0];

		for (int i=0; i <arrLength;i++) {
			if (min > arr[i])
				min = arr[i];

		}

		return min;
	}

	void PrintArray(int arr[100], int arrLength) {

		for (int i = 0; i < arrLength; i++) {

			cout << arr[i] << " ";
		}
	}

	void FillArrayWithRandom(int arr[100], int arrLength ) {
		//srand((unsigned)time(NULL)); // Initialize random seed

		for (int i = 0; i < arrLength; i++) {

			arr[i]= Random::Random(0, 100); 
		}
	
	}


	void Fill2DArrayWithRandomNum(int arr[3][3], short Rows, short Col) {


		for (int i = 0; i < Rows; i++) {


			for (int j = 0; j < Col; j++) {

				arr[i][j] = Random::Random(1, 100);


			}
		}

	}

	void printArray1(int arr[], int size) {
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
	}

	

	void PrintMatrix(int arr[3][3], short Rows, short Col) {

		for (int i = 0; i < Rows; i++) {

			for (int j = 0; j < Col; j++) {

				cout << setfill('0') << setw(2) << arr[i][j] << "   ";
				//   printf("%02d   ", arr[i][j]);

			}
			cout << "\n";
		}


	}

	int SumOfMatrix(int arr[3][3], short Rows, short Cols) {

		int sum = 0;

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				sum += arr[i][j];
			}
		}
		return sum;

	}
	bool IsScalarMatrix(int arr[3][3], short Rows, short Cols) {

		short Num = arr[0][0];

		for (int i = 0; i < Rows; i++) {

			for (int j = 0; j < Cols; j++) {

				/* if (i == j && arr[i][j] != Num)
					return false;

					else if (i != j && arr[i][j] != 0)
					  return false;*/

				if ((i == j && arr[i][j] != arr[0][0]) || (i != j && arr[i][j] != 0))
					return false;
			}
		}
		return true;

	}

	short NumberCountInMatrix(int arr[3][3], int Number, short Rows, short Cols) {

		short NumberCount = 0;

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {

				if (arr[i][j] == Number)
					NumberCount++;
			}
		}
		return NumberCount;

	}

	bool IsNumberInMatrix(int arr[3][3], int Number, short Rows, short Cols) {



		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {

				if (arr[i][j] == Number)
					return true;
			}
		}
		return false;

	}

	int MaxNumberInMatrix(int arr[3][3], short Rows, short Cols) {

		int Max = arr[0][0];

		for (short i = 0; i < Rows; i++) {
			for (short j = 0; j < Cols; j++) {

				if (arr[i][j] > Max)
					Max = arr[i][j];
			}
		}
		return Max;

	}

	int MinNumberInMatrix(int arr[3][3], short Rows, short Cols) {

		int Min = arr[0][0];

		for (int i = 0; i < Rows; i++) {

			for (int j = 0; j < Cols; j++) {

				if (arr[i][j] < Min)
					Min = arr[i][j];
			}
		}
		return Min;

	}

}

namespace Recursion {

	int Factorial(int N) {

		if (N < 0) {
			return -1;
		}

		if (N <= 1)
			return 1;
		else
			return	N * Factorial(N - 1);
	}

	void PrintNumberFromZtoA(int n) {

		if (n == 1) {
			cout << n << endl;
			PrintNumberFromZtoA(n - 1);
		}
	}

	int Pow(int Num, int Power) {

		if (Power == 0)
			return 1;
		else if (Power >= 1)
			return Num * Pow(Num, Power - 1);
		else
			return -1;

	}

	void PrintFibonacciUsingRecurssion(short Number, int Prev1 = 1, int Prev2 = 0) {

		int FebNumber = 0;

		if (Number > 0) {

			FebNumber = Prev2 + Prev1;
			Prev2 = Prev1;
			Prev1 = FebNumber;   cout << FebNumber << "    ";
			PrintFibonacciUsingRecurssion(Number - 1, Prev1, Prev2);

		}


	}

	void PrintFibonacciUsingRecurssion1(short Number, int Prev1 = 1, int Prev2 = 0) {


		if (Number > 0) {

			cout << Prev1 << "   ";

			PrintFibonacciUsingRecurssion(Number - 1, Prev1 + Prev2, Prev1);

		}
	}



}

namespace Info {

	void automaticVariables() {

		const auto a = 10;// const int
		auto au = 10u;// unsigned int

		auto m = (short)10;        // short   
		auto x = (unsigned short)10;// unsigned short

		auto b = 'B';// char
		auto y = (unsigned char)'A';// unsigned char

		auto e = "Hello"s;// string

		auto d = true;// bool

		auto c = 2.5;// double
		auto h = 3.14l;// long double
		auto f = 3.12f;// float

		auto g = 10000000000;// long long
		auto j = 10000000ll; // long long
		auto i = 1000ull;// unsigned long long
		//register int r = 10;
		//register char ch = 'A';

	}

	void CPlusPlusVersion() {


		cout << "C++ Version: " << __cplusplus << endl;
		switch (__cplusplus) {

		case 199711 :
			cout << "C++98 / C++03\n";
			break;
		case 201103 :
			cout << " C++11\n";
			break;
		case 201402 :
			cout << "C++14\n";
			break;
		case 201703 :
			cout << "C++17\n";
			break;
		case 202002 :
			cout << "c++20\n";
			break;
		case 202302 :
			cout << "C++23\n";
			break;
		default :
			cout << "Unkown Version\n";
			break;
		}
	}


	void printfFunction() {

		unsigned int page = 1, pagetotal = 20;


		printf("%u\n", page);//unsigned int
		printf("%0*d\n", 2, page);//حطلي صفر قبل الواجد لكن القيمة معطاة في 2
		printf("%02d\n", page);//حطلي صفر قبل الواحد
		printf("%2d\n", page);//حطلي قبل الرقم فراغ
		int arr[]{ 10,20,30,40,50 };
		for (int i = 0; i < 5; i++)
			printf("Array[%d] = %d\n", i, arr[i]);


		for (int i : arr)
			printf("Array[] = %d\n", i);


		cout << "\n\nfloat and double\n";
		float a = 3.14;
		double b = 3.145643;
		printf("%.1f \n", a);//طباعة خانة بعد الفاصلة
		printf("%.2f \n", a);//طباعة خانتين بعد الفاصلة
		printf("%.*f \n", 3, a);//طباعة ثلاث خانات بعد الفاصلة لكن بطريقة اخرى
		printf("the Result is %.2f + %.6f = %f\n", a, b, a + b);//تم تحديد كم خانة رح تاخد من كل رقم
		printf("the Result is %f + %f = %f\n", a, b, a + b);//رح تطبع لكل عدد خانات المتغير الي فيه اعلى عدد خانات

		cout << "\n\nStrin And Char\n\n";

		char Name[] = "Ahmed Hicazi";//لاتدعم سترينج في هاي الدالة لهيك عرفناها بي array char
		string Name1 = "Ahmed Hicazi";
		printf("My Name is %s \n", Name);
		printf("My Name using string is %s\n", Name1.c_str());//هاد الفانكشن هو الي رح يعرف الstring لفانكشن printf
		char ch = 'S';
		printf("My Charater is %2c\n", ch);//طباعة سطر والمتغير
		printf("My Charater is %*c\n\n", 2, ch);//طباعة سطر ومتغير

	}

	void setwFunction() {
		//#include <iomanip>
		cout << "|--------------|---------|\n";
		cout << "|" << setw(10) << "Product" << setw(5) << "|" << setw(10) << "Price|" << endl;
		cout << "|--------------" << "|" << "---------|" << endl;
		cout << "|" << setw(10) << "Milk" << setw(5) << "|" << setw(10) << "2.5$|" << endl;
		cout << "|" << setw(10) << "egg" << setw(5) << "|" << setw(10) << "4$|" << endl;
		cout << "|" << setw(10) << "Bread" << setw(5) << "|" << setw(10) << "1.3$|" << endl;
		cout << "|" << setw(10) << "coffee" << setw(5) << "|" << setw(10) << "2$|" << endl;
		cout << "|" << setw(10) << "sandwich" << setw(5) << "|" << setw(10) << "2.3$|" << endl;
		cout << "|--------------|---------|\n";

		cout << "\n\n";
		cout << left;//رح تخلي الفراغات من اليمين الى اليسار من دونها افتراضيا سوف يكون طباعة الخانات من اليسار الى اليمين
		cout << "-----------|--------------------------------|---------|\n";
		cout << "    Code   |             Name               |    Mark |\n";
		cout << "-----------|--------------------------------|---------|\n";
		cout << setw(11) << "c3042" << "|" << setw(32) << "Hardware" << "|" << setw(9) << "76" << "|" << endl;
		cout << setw(11) << "c456" << "|" << setw(32) << "NetWork" << "|" << setw(9) << "87" << "|" << endl;
		cout << setw(11) << "c8564" << "|" << setw(32) << "Object Oriented Programming" << "|" << setw(9) << "90" << "|" << endl;
		cout << "-----------|--------------------------------|---------|\n";

	}

	void VectorFunctions() {
		//#inlcude <vector>
		vector <int> vNumbers;

		vNumbers.push_back(10);//تضيف قيمة 10 للفاكتور
		vNumbers.push_back(20);
		vNumbers.push_back(30);
		vNumbers.push_back(40);
		vNumbers.push_back(50);

		cout << "\nstack size  : " << vNumbers.size() << endl;//معرفة عدد المتغيرات الممتلة ذاخل الفاكتور
	

		cout << "front      : " << vNumbers.front() << endl;//بتطبع اول عنصر في الفكتر
		cout << "back       : " << vNumbers.back() << endl;//بتطبع اخر عنصر في الفكتر
		cout << "at()       : " << vNumbers.at(1) << endl;//اطبع العنصر رقم كذا في المصفوفة وطبعا هاد متل الاري من الصفر بتبلش  
		cout << "Operator[] : " << vNumbers[1] << endl;//نفس الدالة الي فوق بس غير امنة اذا ومابتوقف اذا تجاوز الحدود
		cout << "Empty      : " << vNumbers.empty() << endl;//اذا كان الفكتر فارغ بترجع واحد اذا كان مليان بترجع 0
		cout <<"Capactiy    : " << vNumbers.capacity() << endl;//ترجع عدد العناصر التي يمكن للفكتور تخزينها دون اعادة تخصيص



		if (!vNumbers.empty()) {//اذا كان الفكتور غير فارغ
			vNumbers.pop_back();//بتشيل اخر رقم في الفكتور
		}
		if (vNumbers.size() > 0) {//هاي بتعمل نفس وظفية الي فوق بس الفرق بتشوف عدد الفاكتورس الي المتعبية على اكبر من صفر
			vNumbers.pop_back();
		}

		//vNumbers.clear();//هاي بتسمع كل القيم الي جوى الفاكتور بالمرة

		for (int Numbers : vNumbers) {
			cout << Numbers << " ";
		}

	}

	void Pointers() {

		void* ptr;
		float f1 = 10.5;
		ptr = &f1;

		cout << *(static_cast<float*>(ptr)) << endl;//هاد الامر رح تفهمو جميع المترجمات
		cout << *(float*)ptr << endl;//بعض المترجمات مارح تفهم هاد الامر 


		int a = 30;
		ptr = &a;

		cout << *(int*)ptr << endl;
		cout << *(static_cast<int*>(ptr)) << endl;

		char ch = 'A';
		ptr = &ch;

		cout << &ch << endl;
		cout << *(char*)ptr << endl;
		cout << (static_cast<void*>(ptr));
	}

	void DynamicArrayNewAndDelete() {

		int length = 0;

		cout << "enter a how to student grade you want : ";
		cin >> length;

		float* ptr = new float[length];//يحجز قيمة في الهيب بس البتر بتكون مخزنه في الستاك


		for (int i = 0; i < length; i++) {

			cout << "enter a studnet" << i + 1 << " grade : ";
			cin >> *(ptr + i);

		}
		cout << '\n';
		for (int j = 0; j < length; j++) {
			cout << "student " << j + 1 << " grade : " << *(ptr + j) << endl;
		}
		delete[]ptr;//يحرر الذاكرة في heap فقط
		ptr = nullptr;//يجعل المؤشر آمن ويمنع استخدام عنوان غير صالح
	}

	void Iterator() {

		vector <int>Num{ 1,2,3,4,5 };
		vector <int>::iterator iter;

		for (iter = Num.begin(); iter != Num.end(); iter++) {//endيطبع عنوان  بعد اخر عنصر..begin يطبع عنوان اول عنصر
			cout << *iter << endl;//طباعة الرقم
			cout << &(*iter) << endl;//طباعة العنوان الي داخل المؤشر

		}
		cout << "\n";
		for (iter = Num.end() - 1; iter != Num.begin(); iter--) {//هاي عكس الي فوق بتطبع من اخر عنصر الى اول عنصر

			cout << *iter << endl;
			cout << &(*iter) << endl;
		}

	}

	void StringObject() {


		string str = "My Name is, I Love Programming.";

		cout << str.length() << endl;//طول السلسة سترينغ
		cout << str.size() << endl;//نفس الي فوق

		str.reserve(100);//أمر لحجز سعة معينة وتجنب إعادة التخصيص أثناء التعديل
		cout << str.capacity() << endl;//المساحة المحجوزة مسبقاً للأحرف

		cout << str.insert(10, " Ahmed ") << endl;//ادراج كلمة او نص في مكان معين من السلسلة

		cout << str.replace(10, 5, "Mohammed");// str.replace(start, length, new_string)

		cout << str.substr(11, 5) << endl;//طباعة سلسة نصية فرعية الرقم الاول من وين بدك تبلش طباعة اما الثاني فاكم حرف بدك تطبع

		cout << str.at(1) << endl;//يطبع بناء على موضع الحرف يبدا من صفر

		cout << str.find("Ahmed") << endl;//يبحث عن النص او الكلمة المعطاة في السلسة ويطبع الموضع تبعها في السلسلة

		cout << str.find("ahmed") << endl;//اذا ما لقى الاسم رح يعطيك رقم طويل  فينا نحل هلمشكلة بمثال تحت
		if (str.find("ahmeed") == str.npos) {//اذا مالقى النص في السلسلة يعطي رقم بدل انو مالقى موضع النص 

			cout << "its not found" << endl;
		}

		cout << str.append("@ProgrammingAdvice") << endl;//اضافة نص او كلمة في اخر االسلسلة

		cout << str.erase(0, str.length());//محو السترينج في تمحيه منو اي جزء بس حط موضع بداية الحذف ونهايتو
		str.push_back('X');//رح يضيف الكركتر الى اخر السلسلة
		cout << str << endl;
		str.pop_back();//رح يشيل اخر كركتر في السلسلة 
		cout << str << endl;


		str.clear();//مسح كل القيم المخزنه في السلسلة
		cout << str << endl;
	}

	void SomeCCTypeFunction() {
		//من مكتبة <cctype>
		char x, y;


		x = toupper('a');
		y = tolower('A');


		cout << "x = toupper('a') : " << x << endl;
		cout << "y = tolower('A') : " << y << endl;


		cout << isupper('A') << endl;//اذا كانت صحيحة بترجع عدد موجب واحد او اكتر وذا خطاء بترجع سالب
		cout << islower('a') << endl;
		cout << isdigit('9') << endl;
		cout << ispunct('@') << endl;
	}
	void DateTime() {

//#pragma warning(disable : 4996) // تعطيل تحذير استخدام دوال قديمة في Visual Studio

	
			time_t t = time(0);       // الحصول على الوقت الحالي (عدد الثواني منذ 1 يناير 1970)

			char* dt = ctime(&t);     // تحويل الوقت لشكل نصي readable
			cout << "Local date and time is: " << dt << "\n";

			// تحويل الوقت إلى صيغة UTC (توقيت عالمي)
			tm* gmtm = gmtime(&t);
			dt = asctime(gmtm);       // تحويل الـ tm إلى نص
			cout << "UTC date and time is: " << dt;
		

	}
	void DataTypeNumericLimits() {
		
			cout << "int: " << sizeof(int) << " bytes, "
				<< numeric_limits<int>::min() << " to " << numeric_limits<int>::max() << "\n";

			cout << "short: " << sizeof(short) << " bytes, "
				<< numeric_limits<short>::min() << " to " << numeric_limits<short>::max() << "\n";

			cout << "long: " << sizeof(long) << " bytes, "
				<< numeric_limits<long>::min() << " to " << numeric_limits<long>::max() << "\n";

			cout << "long long: " << sizeof(long long) << " bytes, "
				<< numeric_limits<long long>::min() << " to " << numeric_limits<long long>::max() << "\n";

			cout << "unsigned int: " << sizeof(unsigned int) << " bytes, "
				<< 0 << " to " << numeric_limits<unsigned int>::max() << "\n";

			cout << "unsigned short: " << sizeof(unsigned short) << " bytes, "
				<< 0 << " to " << numeric_limits<unsigned short>::max() << "\n";
	}

}

namespace file {

	void ReadFile(const string Path) {

		//Myfile
		//#include <fstream>
		fstream Myfile;

		Myfile.open(Path, ios::in);
		if (Myfile.is_open()) {

			string str = "";

			while (getline(Myfile, str))
				cout << str << endl;

			Myfile.close();
		};

	}
	void WriteToFile(const string Path) {
		fstream Myfile;

		Myfile.open("Myfile.txt", ios::out | ios::app);

		if (Myfile.is_open()) {

			string line = "";

			getline(cin, line);

			Myfile << line << endl;

		}
	}

	void LoadDataFromFileToVector(const string FileName, vector <string>& vFileContent) {

		fstream Myfile;

		Myfile.open(FileName, ios::in);

		if (Myfile.is_open()) {

			string data = "";

			while (getline(Myfile, data))
				vFileContent.push_back(data);

			Myfile.close();

		}
	}

	void SaveVectorToFile(const string FileName, vector <string>& vFileContent) {

		fstream Myfile;

		Myfile.open(FileName, ios::out);

		if (Myfile.is_open()) {

			for (string& line : vFileContent) {

				if (line != "")
					Myfile << line << endl;
			}
			Myfile.close();

		}
	}
}

namespace Date {

	bool IsLeapYear(short Number) {

		return ((Number % 4 == 0 && Number % 100 != 0)) || (Number % 400 == 0);
	}

	short NumberOfYear(short Year) {
		return IsLeapYear(Year) ? 366 : 365;
	}

	short NumberOfHours(short Year) {

		return NumberOfYear(Year) * 24;
	}

	int NumberOfMinutes(short Year) {

		return NumberOfHours(Year) * 60;
	}

	int NumberOfSeconds(short Year) {

		return NumberOfMinutes(Year) * 60;
	}

	bool IsLeapYear(short Year) {

		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	short DaysInMonth(short Month, short Year) {

		short DaysMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : DaysMonth[Month - 1];
	}

	short DayOfWeekOrder(short Day, short Month, short Year) {

		short a, y, m;

		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + 12 * a - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	struct sDate {
		short Day;
		short Month;
		short Year;
	};

	short DayOfWeekOrder(sDate Date) {

		return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}

	string DayShortName(short DayInMonth) {

		string Days[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return Days[DayInMonth];
	}

	bool IsWeekEnd(sDate Date) {

		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}

	bool IsBusinessDay(sDate Date) {

		return !IsWeekEnd(Date);
	}

	bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {

		return (Date1.Year < Date2.Year) ? true
			: (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true
			: (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false) : false;
	}

	bool IsLastDayInMonth(sDate Date) {

		return Date.Day == DaysInMonth(Date.Month, Date.Year);
	}

	bool IsLastMonthInYear(short Month) {

		return Month == 12;
	}

	sDate IncreaseDateByOneDay(sDate Date) {

		if (IsLastDayInMonth(Date)) {

			if (IsLastMonthInYear(Date.Month)) {

				Date.Day = 1;
				Date.Month = 1;
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

	short CalcVacationPeriod(sDate DateFrom, sDate DateTo) {

		short DayCount = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo)) {

			if (IsBusinessDay(DateFrom))
				DayCount++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return DayCount;
	}
}

namespace ClassesInfo {

	class Person {

	private:

		int _Id = 10;
		string _FirstName;
		string _LastName;

	public:

		//Property Set
		void setFirstName(string FirstName)
		{

			_FirstName = FirstName;
		}

		//Property Get

		string GetFirstName() {
			return _FirstName;
		}

		//Declaration Property

		__declspec(property(get = GetFirstName, put = setFirstName)) string FirstName;

		//Property Set

		void setLastName(string LastName)
		{
			_LastName = LastName;
		}

		//Property Get

		string LastName() {

			return _LastName;
		}

		string FullName() {

			return _FirstName + " " + _LastName;
		}


		//Read Only Property Because we dont have a set funciton
		int Id() {

			return _Id;
		}
	};

	class clsAddress
	{

	private:

		string _AddressLine1;
		string _AddressLine2;
		string _POBox;
		string _ZipCode;

	public:

		//Default Constructor
		clsAddress() {

			cout << "\nI'm Constructor.";
		}

		//Destructor ~
		~clsAddress() {

			cout << "\nI'm Destructor.";
		}

		/*void Func1() {

		clsAddress Address;
	}

	void Func2() {

		//Pointer Type clsAddress

		clsAddress* Address = new clsAddress;

		//Destructor
		delete Address;
	}
	*/

	//Paramter Constructor
		clsAddress(string AddressLine1, string AddressLine2, string POBox, string ZipCode)
		{
			_AddressLine1 = AddressLine1;
			_AddressLine2 = AddressLine2;
			_POBox = POBox;
			_ZipCode = ZipCode;
		}

		//Copy Constructor
		clsAddress(clsAddress& old_Obj)
		{

			_AddressLine1 = old_Obj.AddressLine1();
			_AddressLine2 = old_Obj.AddressLine2();
			_POBox = old_Obj.POBox();
			_ZipCode = old_Obj.ZipCode();
		}

		void setAddressLine1(string AddressLine1)
		{

			_AddressLine1 = AddressLine1;
		}

		string AddressLine1()
		{
			return _AddressLine1;
		}

		void setAddressLine2(string AddressLine2)
		{

			_AddressLine2 = AddressLine2;
		}

		string AddressLine2()
		{

			return _AddressLine2;
		}

		void setPOBox(string POBox) {

			_POBox = POBox;
		}

		string POBox() {
			return _POBox;
		}

		void setZipCode(string ZipCode) {

			_ZipCode = ZipCode;
		}

		string ZipCode() {

			return _ZipCode;
		}

		void Print()
		{

			cout << "\nAddress Details:\n";
			cout << "------------------------";
			cout << "\nAddressLine1: " << _AddressLine1 << endl;
			cout << "AddressLine2: " << _AddressLine2 << endl;
			cout << "POBox       : " << _POBox << endl;
			cout << "ZipCode     : " << _ZipCode << endl;
		}

	};

	class clsPerson {

		//protected:

	private:

		int _ID;
		string _FirstName;
		string _LastName;
		string _Title;
		string _Email;
		string _Phone;
		double _Salary;
		string _Department;

	public:

		//Default Constructor
		

		//Parameterzied Constructor
		clsPerson(int ID, string FirstName, string LastName, string Email, string Phone) {

			_ID = ID;
			_FirstName = FirstName;
			_LastName = LastName;
			_Email = Email;
			_Phone = Phone;
		}

		//Read Only get because dont have set function
		int ID() {

			return _ID;
		}

		//set function
		void setFirstName(string FirstName) {

			_FirstName = FirstName;
		}

		//get function
		string FirstName() {

			return _FirstName;
		}

		//set function
		void setLastName(string LastName) {

			_LastName = LastName;
		}

		//get function
		string LastName() {

			return _LastName;
		}

		//set function
		void setEmail(string Email) {

			_Email = Email;
		}

		//get function
		string Email() {

			return _Email;
		}

		//set function
		void setPhone(string Phone) {

			_Phone = Phone;
		}

		//get function
		string Phone() {

			return _Phone;
		}

		void Print() {

			cout << "\nInfo\n";

			cout << "\n-----------------------";
			cout << "\nID        : " << _ID;
			cout << "\nFirstName : " << _FirstName;
			cout << "\nLastName  : " << _LastName;
			cout << "\nEmail     : " << _Email;
			cout << "\nPhone     : " << _Phone;
			cout << "\n-----------------------";
		}

		void SendEmail(string Subject, string Body) {

			cout << "\n\nThe following massage sent sucessfully to email: " << _Email;
			cout << "\nSubject : " << Subject;
			cout << "\nBody : " << Body;
		}

		void SendSMS(string Message) {

			cout << "\n\nThe following SMS sent successfully to phone: " << _Phone;
			cout << "\n" << Message;
		}
	};

	class clsEmployee : public clsPerson
	{

	private:

		string _Title;
		double _Salary;
		string _Department;


	public:

	clsEmployee(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, double Salary)
			: clsPerson(ID, FirstName, LastName, Email, Phone)
	{

			_Title = Title;
			_Department = Department;
			_Salary = Salary;
		}

		void setTitle(string Title)
		{

			_Title = Title;
		}

		string Title()
		{
			return _Title;
		}

		void setSalary(double Salary)
		{
			_Salary = Salary;
		}

		double Salary()
		{
			return _Salary;
		}

		void setDepartment(string Department)
		{
			_Department = Department;
		}

		string Department()
		{
			return _Department;
		}

		void Print()
		{

			//clsPerson::Print();

			cout << "\nInfo\n";

			cout << "\n-----------------------";
			cout << "\nID        : " << ID();
			cout << "\nFirstName : " << FirstName();
			cout << "\nLastName  : " << LastName();
			cout << "\nEmail     : " << Email();
			cout << "\nPhone     : " << Phone();
			cout << "\nTitle     : " << _Title;
			cout << "\nDepartment: " << _Department;
			cout << "\nSalary    : " << _Salary;
			cout << "\n-----------------------";
		}
	};

	class clsMobile
	{
		//abstract class/Interfaces/Contract
	public:
		virtual void Print() = 0;
		virtual void SendSMS(string Phone, string Text) = 0;



	};

	class clsiphone : public clsMobile
	{
	public:

		void Print()
		{
			cout << "\nHello I'm Print Function.";

		}

		void SendSMS(string Phone, string Text)
		{
			cout << "\nHello I'm SendSMS Function.";
		}

	};




}
