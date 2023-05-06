#pragma once

namespace Sort {
	class QuickSort {
	private:
		static int GetPivotByMedian3(int& start, int& middle, int& end); //return pivot
		static void Swap(int& left, int& right);
		//static void Swap(int arr[], int left, int right);
		static void QSort(int arr[], int startIndex, int endIndex);
		static void ThreeWayQSort(int arr[], int startIndex, int endIndex);
	public:
		static void QSort(int arr[], int length);
		static void ThreeWayQSort(int arr[], int length);
	};
}
