#include "QuickFind.h"

using namespace Sort;

int QuickFind::GetSortedValue(const int targetIndex, int arr[], const int length) {
	int startIndex = 0;
	int endIndex = length - 1;

	return GetSortedValue(targetIndex, arr, startIndex, endIndex);
}

int QuickFind::GetMedian(int arr[], const int length) {
	int startIndex = 0;
	int endIndex = length - 1;
	int targetIndex = (startIndex + endIndex) >> 1;

	return GetSortedValue(targetIndex, arr, startIndex, endIndex);
}

int QuickFind::GetMinimum(int arr[], const int length) {
	int startIndex = 0;
	int endIndex = length - 1;
	int targetIndex = startIndex;

	return GetSortedValue(targetIndex, arr, startIndex, endIndex);
}

int QuickFind::GetMaximum(int arr[], const int length) {
	int startIndex = 0;
	int endIndex = length - 1;
	int targetIndex = endIndex;

	return GetSortedValue(targetIndex, arr, startIndex, endIndex);
}

int QuickFind::GetPivotByMedian3(int& start, int& middle, int& end) {
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
}

int QuickFind::GetSortedValue(const int targetIndex, int arr[], int startIndex, int endIndex) {
	if (startIndex >= endIndex)
		return arr[targetIndex];

	int pivot, leftIndex, rightIndex;

	while (startIndex < endIndex) {
		// like quick sort, but no need to do recursion
		pivot = GetPivotByMedian3(arr[startIndex], arr[(startIndex + endIndex) >> 1], arr[endIndex]); // reorder first, middle and last number and get median as pivot
		leftIndex = startIndex;
		rightIndex = endIndex;

		while (true) {
			while (leftIndex < endIndex && arr[++leftIndex] <= pivot);
			while (rightIndex > startIndex && arr[--rightIndex] >= pivot);

			if (leftIndex < rightIndex)
				Swap(arr[leftIndex], arr[rightIndex]);
			else
				break;
		}

		if (rightIndex >= targetIndex)
			endIndex = rightIndex;
		else if (leftIndex <= targetIndex)
			startIndex = leftIndex;
		//all lower values on left side and higher values on right side
		else
			return arr[targetIndex];
	}
	return arr[targetIndex];
}

void QuickFind::Swap(int& left, int& right) {
	if (left == right)
		return;
	const int temp = left;
	left = right;
	right = temp;
}
