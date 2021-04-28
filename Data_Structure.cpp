#include<iostream>
#include<vector>

using namespace std;

///////// Functions

void clear() // For clearing screen
{
    system("cls");
}

////////  Main

int main(){

    int choice;
    char ans;


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
        cin >> choice;

    return 0;
}

