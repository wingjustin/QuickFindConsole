#include "QuickSort.h"

using namespace Sort;

void QuickSort::QSort(int arr[], const int length) {
	QSort(arr, 0, length - 1);
}

void QuickSort::ThreeWayQSort(int arr[], const int length) {
	ThreeWayQSort(arr, 0, length - 1);
}

int QuickSort::GetPivotByMedian3(int& start, int& middle, int& end) {
	// first find max and switch to the end
	if (start > end && start >= middle)
		Swap(start, end);
	else if (middle > end && middle >= start)
		Swap(middle, end);
	//second find min
	if (start > middle)
		Swap(start, middle);
	//return median as pivot
	return middle;
	//-----------------------------------------------
	/*if (start > middle)
		Swap(start, middle);
	if (middle > end)
		Swap(middle, end);
	if (start > middle)
		Swap(start, middle);
	return middle;*/
}

void QuickSort::QSort(int arr[], const int startIndex, const int endIndex) {
	if (startIndex >= endIndex)
		return;
	int pivot = GetPivotByMedian3(arr[startIndex], arr[(startIndex + endIndex) >> 1], arr[endIndex]); // reorder first, middle and last number and get median as pivot
	int leftIndex = startIndex;
	int rightIndex = endIndex;

	while (true) {
		while (leftIndex < endIndex && arr[++leftIndex] <= pivot);
		while (rightIndex > startIndex && arr[--rightIndex] >= pivot);

		if (leftIndex < rightIndex)
			Swap(arr[leftIndex], arr[rightIndex]);
		else
			break;
	}
	QSort(arr, startIndex, rightIndex);
	QSort(arr, leftIndex, endIndex);
	return;
}

//3-way quickSort, for too many same elements in array
void QuickSort::ThreeWayQSort(int arr[], const int startIndex, const int endIndex) {
	if (startIndex >= endIndex)
		return;
	int pivot = GetPivotByMedian3(arr[startIndex], arr[(startIndex + endIndex) >> 1], arr[endIndex]); // reorder first, middle and last number and get median as pivot
	int lowPivotIndex = startIndex;
	int highPivotIndex = endIndex;
	int current = lowPivotIndex;
	while (current <= highPivotIndex) {
		if (arr[current] < pivot)
			Swap(arr[current++], arr[lowPivotIndex++]);
		else if (arr[current] > pivot)
			Swap(arr[current], arr[highPivotIndex--]);
		else
			current++;
	}
	ThreeWayQSort(arr, startIndex, lowPivotIndex - 1);
	ThreeWayQSort(arr, highPivotIndex + 1, endIndex);
}

void QuickSort::Swap(int& left, int& right) {
	if (left == right)
		return;
	const int temp = left;
	left = right;
	right = temp;
}

//void QuickSort::QSort(int arr[], const int startIndex, const int endIndex) {
//	if (startIndex >= endIndex)
//		return;
//	int pivot = GetPivotByMedian3(arr[startIndex], arr[(startIndex + endIndex) >> 1], arr[endIndex]); // reorder first, middle and last number and get median as pivot
//	int leftIndex = startIndex;
//	int rightIndex = endIndex;
//
//	while (true) {
//		while (arr[++leftIndex] < pivot);
//		while (arr[--rightIndex] > pivot);
//
//		if (leftIndex < rightIndex)
//			Swap(arr[leftIndex], arr[rightIndex]);
//		else
//			break;
//	}
//	if (leftIndex == rightIndex) {
//		QSort(arr, startIndex, rightIndex - 1);
//		QSort(arr, leftIndex + 1, endIndex);
//		return;
//	}
//	else {
//		QSort(arr, startIndex, rightIndex);
//		QSort(arr, leftIndex, endIndex);
//		return;
//	}
//}

////**basic 1
//void QuickSort::QSort(int arr[], const int startIndex, const int endIndex) {
//	if (startIndex >= endIndex)
//		return;
//	int pivotIndex = startIndex;
//	int leftIndex = startIndex + 1;
//	int rightIndex = endIndex;
//	//
//	do {
//		for (; leftIndex != rightIndex && arr[leftIndex] <= arr[pivotIndex]; leftIndex++);
//		for (; leftIndex != rightIndex && arr[pivotIndex] <= arr[rightIndex]; rightIndex--);
//		//
//		if (leftIndex < rightIndex)
//			Swap(arr[leftIndex], arr[rightIndex]); // swap when left > right
//	} while (leftIndex < rightIndex); // get out when left == right
//	//check the where indices crossed and discuss swap who
//	if (arr[pivotIndex] > arr[leftIndex])
//		Swap(arr[pivotIndex], arr[leftIndex]);
//	else if (arr[pivotIndex] < arr[rightIndex])
//		Swap(arr[pivotIndex], arr[leftIndex = rightIndex - 1]);
//	pivotIndex = leftIndex;
//	//
//	QSort(arr, startIndex, pivotIndex - 1);
//	QSort(arr, pivotIndex + 1, endIndex);
//}
