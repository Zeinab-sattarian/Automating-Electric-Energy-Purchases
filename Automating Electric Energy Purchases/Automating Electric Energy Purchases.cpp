#include<iostream>
#include<string>
using namespace std;
class ElectricBill {
public:
	ElectricBill(double ap) {
		setAmountPaid(ap);
		getVAT();
		getEWURA();
		getREA();
		getUnits();
	}
	void setAmountPaid(double ap) {
		if (ap > 0) { amountPaid = ap; }
		else ap = 0;
	}
	double getAmountPaid() {
		return amountPaid;
	}
	double getVAT() {
		return ((amountPaid * 18) / 100);
	}
	double getEWURA() {
		return ((amountPaid * 1) / 100);
	}
	double getREA() {
		return ((amountPaid * 3) / 100);
	}
	double getUnits() {
		return ((((amountPaid * 78) / 100) - 5000) / 295);
		// if we add all the deductions together, a total of 22% (18%(VAT) + 3 % (REA)+1 % (EWURA) ) will be reduced
		//in other words, only 78% - 5000 Tanzanian Shillings(monthly service charge)
	    // of the initial paid amount will be spent on buying electricity
		//based on the given information, we can calculate the number of kilowatt 
		//hours a customer gets if we divide the remaining money by 295
		//295 Tanzanian Shillings is the price per kilowatt hour
	}
private:
	double amountPaid;
};
int main() {
	double ap;
	cout << "please enter the amount that you want to pay:" << endl;
	cin >> ap;
	ElectricBill eb(ap);
	cout << endl << "--------------------------------------------" << endl;
	cout << "the amount you want to pay is: " << eb.getAmountPaid() << endl;
	cout << eb.getVAT() << " Tanzanian Shillings will be deducted for VAT..." << endl;
	cout << eb.getEWURA() << " Tanzanian Shillings will be deducted for EWURA..." <<
		endl;
	cout << eb.getREA() << " Tanzanian Shillings will be deducted for REA..." << endl;
	cout << "5000 Tanzanian Shillings will be deducted for fixed monthly service charge..." << endl;
		cout << "after deducting all the contributing factors you purchased " <<
		eb.getUnits();
	cout << " kilowatt hours of electricity" << endl;
	return 0;
}
