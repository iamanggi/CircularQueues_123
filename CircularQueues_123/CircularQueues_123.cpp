#include <iostream>
using namespace std;

class Queues {
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

		// cek apakah antrian penuh 
		if ((FRONT == 0 && REAR == Max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueue overflow\n";
			return;
		}

		// cek apakah antrian kosong 
		if (FRONT == -1) {						// STEP 1 
			FRONT = 0;							// STEP 1.a
			REAR = 0;							// STEP 1.b
		}
		else {
			//Jika REAR berada di posisi terakhir array, kembali ke awal array
			if (REAR == Max - 1)				//STEP 2
				REAR = 0;						//STEP 2.a
			else
				REAR = REAR + 1;				//STEP 3	
		}
		Queue_Array[REAR] = num;				//STEP 4
	}

	void remove() {
		// cek apakah antrian kosong 
		if (FRONT == -1) {
			cout << "Queue underflow\n";
			return;
		}
		cout << "\nThe element deleted from the queue is: " << Queue_Array[FRONT] << "\n";

		//cek jika antrian hanya memiliki satu element
		if (FRONT == REAR) {				//STEP 1
			FRONT = -1;						//STEP 1.a
			REAR = -1;						//STEP 1.b
		}
		else {
			//Jika element yang dihapus berada di posisi terakhir array, kembali ke awal array
			if (FRONT == Max - 1)			//STEP 2
				FRONT = 0;					//STEP 2.a
			else
				FRONT = FRONT + 1;			//STEP 3
		}
	}
	void display() {
		int FRONT_POSITION = FRONT;
		int REAR_POSITION = REAR;

		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue is empty\n";
			return;
		}

		cout << "\nElement in the queue are ...\n";

		//jika FRONT_POSITION <= REAR_POSITION, iterasi dari FRONT hingga REAR
		if (FRONT_POSITION <= REAR_POSITION) {
			while (FRONT_POSITION <= REAR_POSITION) {
				cout << Queue_Array[FRONT_POSITION] << "   ";
				FRONT_POSITION++;
			}
			cout << endl;
		}
		else {
			//jika FRONT_POSITION > REAR_POSITION, iterasi dari FRONT hingga akhir array
			while (FRONT_POSITION <= Max - 1) {
				cout << Queue_Array[FRONT_POSITION] << "   ";
				FRONT_POSITION++;
			}
			FRONT_POSITION = 0;

			//iterasi dari awal array hingga REAR 
			while (FRONT_POSITION <= REAR_POSITION) {
				cout << Queue_Array[FRONT_POSITION] << "   ";
				FRONT_POSITION++;
			}
			cout << endl;
		}
	}
};