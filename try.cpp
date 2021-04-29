#include<iostream>
#include<vector>
#include<iomanip> // for input output manipulation


using namespace std;

///////// Functions

void clear(){ // For clearing screen
    system("CLS");
}

int getChoice()

{

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
    while (!cin.good())
    {
        //Print Error
        cout << "ERROR: Invalid Input, try again...\n";

        cout << "\nERROR: Invalid Input, try again...\n";
        
        //  clear stream
        cin.clear();
        cin.ignore(INT_MAX, '\n');
                cout<< "Invalid input, try again...\n";
                break;
        }
        
        cout<< " asdqwe " + choice + " \n ";

        cout << "\nPress N to exit or any key to Continue " << endl;
        cin >> ans;
        if (ans == 'n'|| ans == 'N'){
            break;
        }
        else{
            clear();
            // choice= getChoice();

        }
        choice= getChoice();
        // cout<< "asdqwe" + choice;

        // cout << "\nPress N to exit or any key to Continue " << endl;
        // cin >> ans;
        // if (ans == 'n'|| ans == 'N'){
        //     break;
        // }
        // else{
        //     clear();
        //     // choice= getChoice();

        // }
        choice = getChoice();
        
    }
    
    system("pause");
    return 0;
}