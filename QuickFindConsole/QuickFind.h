#pragma once

namespace Sort {
	class QuickFind {
		static int GetPivotByMedian3(int& start, int& middle, int& end); //return pivot
		static void Swap(int& left, int& right);
		static int GetSortedValue(int targetIndex, int arr[], int startIndex, int endIndex);
	public:
		static int GetSortedValue(int targetIndex, int arr[], int length);
		static int GetMedian(int arr[], int length);
		static int GetMinimum(int arr[], int length);
		static int GetMaximum(int arr[], int length);
	};
}
