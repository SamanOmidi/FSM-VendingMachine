#include <bits/stdc++.h>

using namespace std;

void vendingMachine(){
    int cardPassword = 1234;

    int state = 0;

    /*
    state 0 menu
    state 1 choosing product
    state 2 show price
    state 3 Enter card
    state 4 Enter Password
    state 5 machine gives product
    state 6 trap
    */

    bool machine = true;

    int action;

    string resultUser;

    string product;
    int price = 0;

    vector<int> vendingMachine(3);
    vendingMachine[0] = vendingMachine[1] = vendingMachine[2] = 10;
    //price Coke = 4$
    //price Cake = 5$
    //price water = 6$
    
    while(machine){

        switch(state){
            case 0:
                cout << "--------------" << endl;
                cout << "1. Buy Products\n"
                     << "2. Exit\n";
                cout << "Enter action : ";
                cin >> action;
                if(action == 1){
                    state = 1;
                    resultUser += '1';
                }
                else{
                    state = 0;
                    resultUser += '0';
                }
                break;
            case 1:
                int productChoose;
                cout << "--------------" << endl;
                cout << "This Machine have below products:\n"
                     << "1. Coke\n"
                     << "2. Cake\n"
                     << "3. Water\n";
                     cout << "Enter Product number: ";
                cin >> productChoose;
                if(productChoose == 1)
                    product = "Coke";
                else if(productChoose == 2)
                    product = "Cake";
                else if(productChoose == 3)
                    product = "Water";
                

                cout << "--------------" << endl;
                //asking if user wants to buy more or continue

                vendingMachine[productChoose - 1] -= 1;
                cout << "1. Continue\n"
                     << "2. Buy More\n";
                cout << "Enter Action : ";
                cin >> action;

                if(action == 1){
                    if(product == "Coke")
                        resultUser += "01";

                    else if(product == "Cake")
                        resultUser += "00";

                    else if(product == "Water")
                        resultUser += "10";

                    resultUser += '1';

                    state = 2;
                }
                else{
                    if(product == "Coke")
                        resultUser += "01";

                    else if(product == "Cake")
                        resultUser += "00";

                    else if(product == "Water")
                        resultUser += "10";
                    
                    resultUser += '0';
                    state = 1;
                }
                break;
            case 2:
                price = (4*(10 - vendingMachine[0])) +
                            (5*(10 - vendingMachine[1])) +
                            (6*(10 - vendingMachine[2]));
                cout << "--------------" << endl;
                cout << "Your total price is " << price << endl;
                cout << "1. Continue\n" 
                     << "2. Exit\n";
                cout << "Enter your action : ";
                cin >> action;
                if(action == 1){
                    resultUser += '1';
                    state = 3;
                }
                else{
                    resultUser += '0';
                    vendingMachine[0] += 10 - vendingMachine[0];
                    vendingMachine[1] += 10 - vendingMachine[1];
                    vendingMachine[2] += 10 - vendingMachine[2];
                    state = 6;
                }
                break;
            case 3:
                cout << "--------------" << endl;
                cout << "Enter your credit card and press continue" << endl;
                cout << "1. Continue \n"
                     << "2. Cancel\n";
                cout << "Enter your action: ";
                cin >> action;
                if(action == 1){
                    resultUser += '1';
                    state = 4;
                }
                else{
                    resultUser += '0';
                    vendingMachine[0] += 10 - vendingMachine[0];
                    vendingMachine[1] += 10 - vendingMachine[1];
                    vendingMachine[2] += 10 - vendingMachine[2];
                    state = 6;
                }
                break;
            case 4:
                cout << "--------------" << endl;
                cout << "Enter Your Password : ";
                cin >> action;
                if(action == cardPassword){
                    resultUser += '1';
                    state = 5;
                }
                else{
                    cout << "ERROR: Enter The Correct Password\n";
                    resultUser += '0';
                    state = 4;
                }
            break;
            case 5:
                cout << "--------------" << endl;
                cout << "Your products are ready\n"
                     << "Do you want to buy more?\n"
                     << "1. Yes\n"
                     << "2. No\n";
                cout << "Enter your action : ";
                cin >> action;
                if(action == 1){
                    resultUser += '1';
                    state = 0;
                }
                else{
                    machine = false;
                    break;
                }
                break;
            case 6:
                state = 0;
                break;
        }
    }
    cout << "Your Products: " << endl;
    for(int i=0 ; i<3 ; i++){
            if(10 - vendingMachine[i] != 0){
                switch(i){
                    case 0:
                        cout << "Coke = " << 10 - vendingMachine[i] << endl;
                        break;
                    case 1:
                        cout << "Cake = " << 10 - vendingMachine[i] << endl;
                        break;
                    case 2:
                        cout << "Water = " << 10 - vendingMachine[i] << endl;
                        break;
                }
            }
        }
    cout << resultUser << endl;
    cout << "=======================" << endl;
}

void validateUserInput(){
    cout << "Enter Buy Instructions: ";
    string input;
    cin >> input;

    unsigned int size = input.size();

    unsigned int i=0;
    int state = 0;
    /*
    state 0 menu
    state 1 choosing product
    state 2 show price
    state 3 Enter card
    state 4 Enter Password
    state 5 machine gives product
    state 6 trap
    */
   vector<int> vendingMachine(3);
   vendingMachine[0] = vendingMachine[1] = vendingMachine[2] = 10;
   //vendingMachine[0] = Coke
   //vendingMachine[1] = Cake
   //vendingMachine[2] = Water
   string temp;

   bool machine = true;

    while(machine && i < size){
        unsigned int x = input[i] - '0';        
        switch(state){
            case 0:
                if(x == 0)
                    state = 0;
                else
                    state = 1;
                i++;
                break;
            case 1:
                temp.clear();
                temp += input[i];
                if(i+1 < size){
                    i++;
                    temp += input[i];
                }
                if(temp == "01" || temp == "00" || temp == "10"){
                    i++;
                    state = 2;
                    if(temp == "01"){
                        if(vendingMachine[0] - 1 <= 0){
                            machine = false;
                            break;
                        }
                        else
                            vendingMachine[0] -= 1;
                    }
                    if(temp == "00"){
                        if(vendingMachine[1] - 1 <= 0){
                            machine = false;
                            break;
                        }
                        else
                            vendingMachine[1] -= 1;
                    }
                    else if(temp == "10"){
                        if(vendingMachine[2] - 1 <= 0){
                            machine = false;
                            break;
                        }
                        else
                            vendingMachine[2] -= 1;
                    }
                }
                else{
                    cout << "ERROR: Invalid Input" << endl;
                    machine = false;
                }
                break;
            case 2:
                if(x == 0)
                    state = 1;
                else
                    state = 3;
                i++;
                break;
            case 3:
                if(x == 0){
                    state = 0;
                    vendingMachine[0] += 10 - vendingMachine[0];
                    vendingMachine[1] += 10 - vendingMachine[1];
                    vendingMachine[2] += 10 - vendingMachine[2];
                }
                else
                    state = 4;
                i++;
                break;
            case 4:
                if(x == 0){
                    state = 0;
                    vendingMachine[0] += 10 - vendingMachine[0];
                    vendingMachine[1] += 10 - vendingMachine[1];
                    vendingMachine[2] += 10 - vendingMachine[2];
                }
                else{
                    state = 5;
                }
                i++;
                break;
            case 5:
                if(x == 0)
                    state = 5;
                else
                    state = 6;
                i++;    
                break;
            case 6:
                if(x == 1 || x == 0)
                    state = 0;
                
                i++;
                break;
        }
    }

    if(i >= size && state != 6){
        cout << "REJECTED" << endl;
    }
    else if((machine == false || i >= size ) && state == 6){
        cout << "ACCEPETED" << endl;
        cout << "Your Products: \n";
        for(int i=0 ; i<3 ; i++){
            if(10 - vendingMachine[i] != 0){
                switch(i){
                    case 0:
                        cout << "Coke = " << 10 - vendingMachine[i] << endl;
                        break;
                    case 1:
                        cout << "Cake = " << 10 - vendingMachine[i] << endl;
                        break;
                    case 2:
                        cout << "Water = " << 10 - vendingMachine[i] << endl;
                        break;
                }
            }
        }
    }
    cout << "=======================" << endl;
}

int main(){

    bool machine = true;

    int action;

    while(machine){
        
        cout << "1. Buy\n"
             << "2. Validate Buy Instruction\n"
             << "0. Exit\n";
        cout << "Enter Action : ";
        cin >> action;
        switch(action){
            case 1:
                vendingMachine();
                break;
            case 2:
                validateUserInput();
                break;
            case 0:
                machine = false;
                break;
        }
        
    }


    return 0;
}