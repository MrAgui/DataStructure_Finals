#include<iostream>
#include<windows.h>
#include<vector>

using namespace std;


// // CLASS 
// class car {
//     public:
//         string name;
//         int Con_num;
//         int Pl_num;

// };



// ////////  Functions
// void clear(){
//     system("CLS");
// }

// ////////  Display Welcome 

// void WCP(){
//     cout<<"**********************************************************\n";
//     cout<<"\n\t\t\t WELCOME TO \n\n";
//     cout<<"\n\t\t  PARKING MANAGEMENT SYSTEM\t\t\n";
//     cout <<"\n\n\t\t  Press Enter to Continue...\n\n";
//     cout<<"**********************************************************\n";
//     cin.ignore();
//     clear();
// }

// void PARK(){
//     car car1;
//     cout<<"Enter Name:";
//     // getline(cin,car1.name);

// }






////////  Display MENU

// void MENU(){
    // int option;


    // cout<<"\n********************************************************************************************************************\n";
    // cout<<"\t\t\t\t\t\t VEHICLE PARKED\n\n";
    // cout<<"\t\t ID \t\t" << "Plate Number \t\t" << " Name of owner \t\t" << " Contact Number\t\t\n"; 


    // cout<<"\n\n********************************************************************************************************************\n";

    // cout<<"\t\t\t\tMENU\n\n";
    // cout<<"\t\t1. PARK \n";
    // cout<<"\t\t2. UNPARK \n";
    // cout<<"\t\t3. SEARCH \n";
    // cout<<"\t\t4. VIEW TOTAL VEHICLES \n";
    // cout<<"\t\t5. VIEW TOTAL SALES\n";
    // cout<<"\t\t6. EXIT\n\n";
    // cout<<"\t\t\t\tSELECT OPTION:";
    // cin>> option ;
    // while(option!=6){
    //     switch(option)
    //     {   
    //         case 1:
    //             clear();
    //             PARK();
    //             break;
    //         case 2:
    //             clear();
    //             cout<< "Car Removed successfuly";
    //             cin.ignore();
    //             MENU();
    //             break;
    //         case 3:
    //             clear();
    //             cout<< "Search";
    //             cin.ignore();
    //             MENU();
    //             break;
    //         case 4:
    //             clear();
    //             cout<< "Total Cars";
    //             cin.ignore();
    //             MENU();
    //             break;
    //         case 5:
    //             clear();
    //             cout<< "Total Sales";
    //             cin.ignore();
    //             MENU();
    //             break;
    //         case 6:
    //             clear();
    //             cout<< "Exiting system";
    //             cin.ignore();
    //             MENU();
    //             break;                
    //         default:
    //             clear();
    //             cout<<"INVALID INPUT...";
                
    //             // clear();
    //             // cout<<"Prees Enter to try again";
    //             break;
    //     }


    // }
   
    // }
// int main(){
//     WCP();
//     int option;
//     clear();
//     cout<<"\n********************************************************************************************************************\n";
//     cout<<"\t\t\t\t\t\t VEHICLE PARKED\n\n";
//     cout<<"\t\t ID \t\t" << "Plate Number \t\t" << " Name of owner \t\t" << " Contact Number\t\t\n"; 


//     cout<<"\n\n********************************************************************************************************************\n";

//     cout<<"\t\t\t\tMENU\n\n";
//     cout<<"\t\t1. PARK \n";
//     cout<<"\t\t2. UNPARK \n";
//     cout<<"\t\t3. SEARCH \n";
//     cout<<"\t\t4. VIEW TOTAL VEHICLES \n";
//     cout<<"\t\t5. VIEW TOTAL SALES\n";
//     cout<<"\t\t6. EXIT\n\n";
//     cout<<"\t\t\t\tSELECT OPTION:";
//     cin>> option ; 
//     while(option !=6)
//     {
//         switch(option)
//         {
//         case 1:
//             clear();
//             PARK();
//             break;
//         case 2: 
//             clear();
//             cout<<"this is number 2";
//             break;
//         default:
//             cout<<"invalid"; 
//             break;
//         }
//     }


   
// return 0;
// }








int main()
{
    int choice;
    char ans;
    system("cls");

    do
    {
        system("cls");
        cout<< "********************************************************************" <<endl
            << "\t\t\t\tPARKING MANAGEMENT SYSTEM " <<endl
            << "\t\t1. PARK" << endl
            << "\t\t2. UNPARK" << endl
            << "\t\t3. TOTAL VEHICLE" << endl
            << "\t\t4. TOTAL SALES" << endl
            << "\t\t5. SEARCH" << endl
            << "\t\t6. Exit" << endl
            << "********************************************************************" << endl
            << "Enter your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1: system("cls");
            cout << "Add : " << endl;
            // veh.at(i).addVehicle();
            break;

        case 2: system("cls");
            cout<<"this is 2";
            // totalveh();
            break;

        case 3: system("cls");
            cout << "Departure : " << endl;
            // veh.at(i).deleteVehicle();
            break;

        case 4: system("cls");
            cout<<"this is 2";
            // totalamount();
            break;

        case 5: system("cls");
            cout<<"this is 2";
            // veh.at(i).show();
            break;
        case 6: 
            exit(0);
        }

        cout << "\nDo you want to continue, press y/n : " << endl;
        cin >> ans;
        if (ans == 'n')
        {
            break;
        }
        else
        {
            continue;
        }

    } while (1);

    return 0;
}

