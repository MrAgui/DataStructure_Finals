#include<iostream>
#include<vector>
#include<iomanip> // for input output manipulation

using namespace std;

///////// Functions

void clear(){ // For clearing screen
    system("cls");
}

int getChoice(){

    int choice = 0;
    cout<< "*******************************************************************************" <<endl
    << "\t\t\tPARKING MANAGEMENT SYSTEM " <<endl
    << "*******************************************************************************\n" << endl
    << "\t\t\t1. PARK" << endl
    << "\t\t\t2. UNPARK" << endl
    << "\t\t\t3. TOTAL VEHICLE" << endl
    << "\t\t\t4. TOTAL SALES" << endl
    << "\t\t\t5. SEARCH VEHICLE" << endl
    << "\t\t\t6. Exit SYSTEM" << endl
    << "_______________________________________________________________________________" << endl
    << "Enter choice : ";
    cin>> setw(1)>> choice;

    // Error check 
    while (!cin.good()){
        //Print Error
        cout << "ERROR: Invalid Input, try again...\n";
        

        //  clear stream
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        //Get input again..
        cout << "Enter Choice: ";
        cin>> setw(1)>> choice;

    }
    //  clear stream
    cin.clear();
    cin.ignore(INT_MAX, '\n');

    return choice;
}


////////  Main

int main(){

    int choice = -1;
    char ans;
    
    choice = getChoice();

    while   (choice > 0 ){ // menu
        switch (choice){
            case 1:
                clear();
                cout<< " this is 1";
                break;
            case 2:
                clear();
                cout<<"this is 2";               
                break;
            case 3:
                clear();
                cout<<"this is 3";
                break;                
            case 4:
                clear();
                cout<<"this is 4";
                break;
            case 5:
                clear();
                cout<<"this is 5";
                break;
            case 6:
                exit(0);
                break;
            default:
                clear();
                cout<< " Invalid input try again";
                break;
        }

        cout << "\nDo you want to continue, press y/n : " << endl;
        cin >> ans;
        if (ans == 'n'){
            break;
        }
        else{
            clear();
            getChoice();
        }
    }

    system("pause");
    return 0;
}

