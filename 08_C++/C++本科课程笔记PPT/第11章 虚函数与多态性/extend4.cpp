#include <iostream>
using namespace std;

class Animal {
public:
	void shout() {
		cout << "Shout" << endl;
	}
};

class Cat : public Animal {
public:
	void shout() {
		cout << "Meow" << endl;
	}
};

void main() {
	Animal a;
	Cat c;

	c.shout();
	c.Animal::shout();

	Animal ap = c;
	Cat cp = a;

	//Animal* ap = &c;
	//Cat* cp = &a;

	//Animal& ap = c;
	//Cat& cp = a;

	ap.shout();
}