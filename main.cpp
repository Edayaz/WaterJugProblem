#include <iostream>
using namespace std;

class Jug {
private:

	double water = 0;
	double capacity;

public:

	Jug(double _capacity) {
		if (_capacity > 0) {
			capacity = _capacity;
		}
		else {
			capacity = 0;
		}
	}

	double getWater() {
		return water;
	}

	void setWater(double _water) {
		if ((_water <= capacity) && (_water >= 0)) {
			water = _water;
		}
		else if (_water > capacity) {
			water = capacity;
		}
		else {
			water = 0;
		}
	}

	double getCapacity() {
		return capacity;
	}

	void emptyJug() {
		water = 0;
		
		cout << "Operation: Empty " << capacity << " - Gallon Jug" << endl;
		cout << "------------------------------------------------" << endl;
		
	}

	void fillJug() {
		water = capacity;
		
		cout << "Operation: Fill " << capacity << " - Gallon Jug" << endl;
		cout << "------------------------------------------------" << endl;
		
	}

	void pour(Jug& jug) {
		double transferWater = 0;
		if (jug.getCapacity() - jug.getWater() > this->getWater()) {
			transferWater = this->getWater();
		}
		else {
			transferWater = (jug.getCapacity() - jug.getWater());
		}

		if (transferWater > 0) {
			this->setWater(this->getWater() - transferWater);
			jug.setWater(transferWater + jug.getWater());
		}
		
		cout << "Operation: Pour water from " << capacity << " gallon jug to " << jug.getCapacity() << " gallon jug" << endl;
		cout << "------------------------------------------------" << endl;
	}
};




int main() {
	Jug threeGallonJug(3);
	Jug fourGallonJug(4);
	double water;
	cout << "Please enter initial state of 3-gallon jug" << endl;
	cin >> water;
	threeGallonJug.setWater(water);
	cout << "Please enter initial state of 4-gallon jug" << endl;
	cin >> water;
	fourGallonJug.setWater(water);
	
	cout << "3-gallon jug contains " << threeGallonJug.getWater() << endl;
	cout << "4-gallon jug contains " << fourGallonJug.getWater() << endl;
	cout << "------------------------------------------------" << endl;


		
		threeGallonJug.fillJug();
		fourGallonJug.emptyJug();
		threeGallonJug.pour(fourGallonJug);
		
		threeGallonJug.fillJug();
		
		threeGallonJug.pour(fourGallonJug);
		
		fourGallonJug.emptyJug();
		
		threeGallonJug.pour(fourGallonJug);
		cout << "3-gallon jug contains " << threeGallonJug.getWater() << endl;
		cout << "4-gallon jug contains " << fourGallonJug.getWater() << endl;
	

	system("pause");
	return 0;
}
