//	Jonathan Osborne
//  jwo0010
//  hw1_jwo0010.cpp
//	This program takes 3 inputs from users: mouse weight,
//	amount of diet coke to kill a mouse, and weight of a human
//	in order to calculate the amount of diet coke to kill the human.
//	I recieved no help for this homework assignment.

#include <iostream>
#include <cmath>
using namespace std;

double calcFatalAmount(double mouseWeightIn, double fatalAmountMouseIn, double weightFriendIn);

int main() {
	double mouseWeight, fatalAmountMouse, weightFriend, fatalAmount;
	
	cout << "Please input the weight of the mouse in kg" << endl;;
	cin >> mouseWeight;
    cout << "Please input the fatal amount of sweetener for mouse in kg" << endl;;
	cin >> fatalAmountMouse;
	cout << "Please input the weight of your dear friend in kg" << endl;;
	cin >> weightFriend;
	fatalAmount = calcFatalAmount(mouseWeight, fatalAmountMouse, weightFriend);
	cout << "The fatal amount of Coke for your friend is: " << fatalAmount << " kg" << endl;;
    return 0;
}

double calcFatalAmount(double mouseWeightIn, double fatalAmountMouseIn, double weightFriendIn) {
	double const ARTIFICIAL_SWEETENER = 0.001;
	return (fatalAmountMouseIn * weightFriendIn) / (mouseWeightIn * ARTIFICIAL_SWEETENER);
}
