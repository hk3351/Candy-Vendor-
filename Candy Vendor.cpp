/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/


#include <iostream>
using namespace std;
class dispenserType {
    private:
        int cost;
        int numberOfItems;
    public:
        dispenserType();
        dispenserType(int setNoOfItems, int setCost);
        int getCost();
        int getNoOfItems (); 
        void makeSale();
};
class cashRegister {
    private:
    int cashOnHand;
    public:
    cashRegister();
    cashRegister (int cashIn); 
    int getCurrentBalance();
    void acceptAmount (int amountIn);
};
cashRegister :: cashRegister () {
    cashOnHand = 500;
}
cashRegister :: cashRegister (int cashIn) {
        cashOnHand = cashIn;
}
int cashRegister :: getCurrentBalance() {
    return cashOnHand;
}
void cashRegister :: acceptAmount (int amountIn) {
    cashOnHand = cashOnHand + amountIn;
}
dispenserType :: dispenserType () {
    numberOfItems = 50;
    cost = 50;
}
dispenserType :: dispenserType (int setNoOfItems, int setCost) {
    numberOfItems = setNoOfItems;
    cost = setCost;
}
int dispenserType :: getNoOfItems () {
    return numberOfItems;
}
int dispenserType :: getCost () {
    return cost;
}
void dispenserType :: makeSale() {
    numberOfItems--;
}
void showSelection();
void sellProduct (dispenserType& product, cashRegister& pCounter);
int main ()
{
    cashRegister counter;
    dispenserType candy (10, 50); 
    dispenserType chips (10, 65);
    dispenserType gum (10, 45);
    dispenserType cookies (10, 85);
    int choice;
    showSelection();
    cin >> choice;
    while (choice != 5) {
        switch(choice) {
           case 1:
                sellProduct (candy, counter);
                break;
            case 2:
                sellProduct (chips, counter);
                break;
            case 3:
                sellProduct (gum, counter);
                break;
            case 4:
                sellProduct (cookies, counter);
                break;
            case 5:
                break;
            default:
            cout << "Invalid selection." << endl;
        }
        showSelection();
        cin >> choice;
    }
    return 0;
}
void showSelection() {
    cout << "***Welcome to Candy Shop***" << endl;
    cout << "To select an item, enter " << endl;
    cout << "1 for Candy" << endl; 
    cout << "2 for Chips" << endl;
    cout << "3 for Gum" << endl;
    cout << "4 for Cookies" << endl;
    cout << "5 to exit" << endl;
}
void sellProduct (dispenserType& product, cashRegister& pCounter) {
int amount_1; 
int amount_2;
if (product.getNoOfItems () > 0)
{
    cout << "Please deposit" << product.getCost() << " cents" << endl;
    cin >> amount_1;
    if (amount_1 < product.getCost ()) {
        	cout << "Please deposit"  <<  product.getCost() - amount_1 <<  " cents" <<endl;
        	cin >> amount_2;
        	amount_1 = amount_1+ amount_2;
    }
    if (amount_1 == product. getCost ()) {
        pCounter.acceptAmount ( amount_1);
        product. makeSale();
        cout<< "Collect your item at the bottom and enjoy." << endl;
    }
    else{
			cout << "The amount is not enough. " << "Collect what you deposited." << endl;
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
		}
	}
	else
		cout << "Sorry, this item is sold out." << endl;
};

        
