#include <iostream>
using namespace std;
void displayArray(int *arr, int len) {
	for (int i = 0; i < len; i++)
		switch (arr[i]) {
			case 1:
				cout << "A ";
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
				cout << arr[i] << ' ';
				break;
			case 11:
				cout << "J ";
				break;
			case 12:
				cout << "Q ";
				break;
			case 13:
				cout << "K ";
				break;
			default:
				cerr << "Wrong card number!\nHow can you do this?" << endl;
		}
	cout << endl;
}
int leftShiftArray(int *arr, int len) {
	// left shift the array and return its original first element
	int front = arr[0];
	for (int i = 1; i < len; i++)
		arr[i - 1] = arr[i];
	return front;
}
int main(int argc, char const *argv[]) {
	srand(time(NULL));
	bool selected[13]; // check if the card is selected
	int arr[13];
	int cnt = 0; // number of selected card
	// initialize check array
	for (int i = 0; i < 13; i++)
		selected[i] = false;
	// choose card randomly and put them into array
	while (cnt < 13) {
		int chosen = rand()%13;
		if (!selected[chosen]) {
			arr[cnt++] = chosen + 1;
			selected[chosen] = true;
		}
	}
	int length = 13; // represent the length of the array and the number to
	while (length > 0) {
		// display original array
		displayArray(arr, length);
		// get first element of array and left shift the array
		int front = leftShiftArray(arr, length);
		if (front == length)
			// draw it out
			length--;
		else
			// put to the end
			arr[length - 1] = front;
	}
	return 0;
}
