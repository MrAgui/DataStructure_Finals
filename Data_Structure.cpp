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
    while (!cin.good()){
        //Print Error
        cout << "\nERROR: Invalid Input, try again...\n";
        
        //  clear stream
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        // Get input again..`
        cout << "Enter Choice: ";
        cin>> setw(1)>> choice;

    }
    //  clear stream
    clear();
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    return choice;
}


////////  Main

int main(){

    int choice = -1;
    char ans;
    
    choice = getChoice();

    //CHOICES 
    
    while(choice > 0 ){ 
        switch (choice){
            case 1:
                clear();
                cout<< " this is 1\n";
                break;
            case 2:
                clear();
                cout<<"this is 2\n";               
                break;
            case 3:
                clear();
                cout<<"this is 3\n";
                break;                
            case 4:
                clear();
                cout<<"this is 4\n";
                break;
            case 5:
                clear();
                cout<<"this is 5\n";
                break;
            case 6:
                clear();
                cout<<"\nEXITING PROGRAM...\n";
                exit(0);
            default:
                clear();
                cout<< "\nERROR: Invalid input, try again...\n";
                break;
        }
        // cout<< "asdqwe" + choice;

        cout << "\nPress N to exit or any key to Continue " << endl;
        cin>> setw(1)>> ans;
        if (ans == 'n'|| ans == 'N'){
            break;
        }
        else{
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            clear();
            // choice= getChoice();

        }
        choice = getChoice();
        
    }
    
    system("pause");
    return 0;
}

