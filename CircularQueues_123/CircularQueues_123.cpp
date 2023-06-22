#include <iostream>
using namespace std;

class Queues{
	int FRONT, REAR, Max = 5;
	int Queue_Array[5];

public:
	Queues() {
		FRONT = -1;
		REAR = -1;
	}
	void insert() {
		int num;
		cout << "Enter a Number : ";
		cin >> num;
		cout << endl;
	}
}