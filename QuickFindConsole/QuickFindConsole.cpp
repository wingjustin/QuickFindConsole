// QuickFindConsole.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<string>
#include<conio.h>
#include <random>
#include "QuickSort.h"
#include "QuickFind.h"

using namespace std;
using namespace Sort;

int main()
{
	const int sortArrayLength = 24;
	//const int targetIndex = 0;
	//const int targetIndex = sortArrayLength - 1;
	//const int targetIndex = (sortArrayLength - 1) >> 1;
	const int targetIndex = 18;

	const bool showSort = true;

	int sort[sortArrayLength];

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 220);

	char operKey = 'E';
	do {
		int round = 22;
		bool health = true;
		for (int r = 0; r < round; r++) {
			for (int i = 0; i < sortArrayLength; i++)
				sort[i] = dist6(rng);

			if (showSort) {
				cout << "Round : " << r + 1 << "\n";

				cout << to_string(sort[0]);

				for (int i = 1; i < sortArrayLength; i++)
					cout << "," << to_string(sort[i]);

				cout << "\n" << "----------------------------------------------------------------" << "\n";
			}
			const int targetValue = QuickFind::GetSortedValue(targetIndex, sort, sortArrayLength);

			//check bug
			QuickSort::QSort(sort, sortArrayLength); // faster if the random range is large, there will be many different elements in array
			//QuickSort::ThreeWayQSort(sort, sortArrayLength); // faster if the random range is small, there will be many same elements in array

			if (showSort) {
				cout << to_string(sort[0]);

				for (int i = 1; i < sortArrayLength; i++)
					cout << "," << to_string(sort[i]);

				cout << "\n" << "----------------------------------------------------------------";

				cout << "\n" << "Found Value " << " [Index = " << to_string(targetIndex) << "] : " << to_string(targetValue);
				cout << "\n" << "Sorted Value " << " [Index = " << to_string(targetIndex) << "] : " << to_string(sort[targetIndex]);

				cout << "\n" << "////////////////////////////////////////////////////////////////" << "\n";
			}

			//check 
			health = targetValue == sort[targetIndex];
			if (!health)
				break;
		}

		cout << "\n" << "Health : " << (health ? "OK, no BUG!" : "Warning! Error occured!") << "\n";
		cout << "Press Any Key to Sort Again; \"E\" for Stop : ";
		operKey = _getch();
		cout << "\n";

	} while (operKey != 'e' && operKey != 'E');
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
