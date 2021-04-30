#include<iostream>
#include<vector>
#include<iomanip> // for input output manipulation
#include<fstream> // for storing data in files
#include<limits> // fpr checking inputss

using namespace std;



struct date{
    
    int day; 
    int month;
    int year;
    char sym1;
    char sym2;
};

struct timee{

    int hr;
    int min;
    int sec;
    char col1;
    char col2;
};

class Vehicle{
    public:

        string pltnum;
        int type;
        date dt;
        timee arrive;
        timee departure;

    
        void park();
        void unpark();
        void printvehicle(Vehicle v);
        void show();


};
 
vector <Vehicle> veh(20);
int static totalvehicle = 0, totalcar = 0, totalbike = 0, totalsales = 0, i = 0;

fstream file;

///////// Functions
bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
}

void Vehicle::park(){

    Vehicle* v = new Vehicle;
    cout << "\n  Enter Vehicle type \n"
         << "|1 for Car | 2 for Bike|  ";
    cin >> setw(1) >> v->type;

    veh.at(i).type = v->type;
    cout<< v->type;
    if (v->type == 1)
    {
        totalcar++;
    }
    else if(v->type == 2)
    {
        totalbike++;
    }
    else
    {
        while (!cin.good() || v->type >=3 || v->type <=0 ){
        //Print Error
        cout << "\n ERROR: Invalid Input, try again...\n";
        
        //  clear stream
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        // Get input again..`
        // cout << "Enter Choice: ";
        cin>> setw(1)>> v->type;

    }

    }

    cout << "\n Plate number : ";
    cin >> setw(6) >>  v->pltnum;
    veh.at(i).pltnum = v->pltnum;

    // cout<< v->pltnum;

    cout << "\n Arrival time in \n";//HOURS : MINUTES : SECONDS = "
    cout << "\tHOURS   : ";
    cin  >> setw(2) >> v->arrive.hr;

    while ( ((cin >> v->arrive.hr ) && (v->arrive.hr <= 24) )==false){
        cout << "--- ERROR: Invalid input, only numbers are accepted... ---\n"
                << " Enter hours again  : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //cin >> v->arrive.hr;
    }



    // while(v->arrive.hr == 0){
    //     if(v->arrive.hr == 0){
    //         cout << "\tHOURS is invalid, please enter valid hour   : ";
    //         cin  >> setw(2) >> v->arrive.hr;
    //     }else{
    //         break;
    //     }
    // }

    // while(true){
    //     //if((cin >> v->arrive.hr) == false){
    //     string check= "";
    //     cout<< "value - "<< + v->arrive.hr;
    //     cout << "\n";
    //     check = v->arrive.hr + "";
    //     cout<< "value str - " + check;
    //     cout << "\n";
    //     if(check_number(check)){
    //         break;
            
    //     }else{
    //         cout << "\tHOURS is invalid, please enter valid hour   : ";
    //         cin  >> setw(2) >> v->arrive.hr;
    //     }
    // }

    cout << "\tMINUTES : ";
    cin  >> setw(2) >> v->arrive.min;

    cout << "\tSECONDS : ";
    cin  >> setw(2) >> v->arrive.sec;

    veh.at(i).arrive.hr = v->arrive.hr;
    veh.at(i).arrive.min = v->arrive.min;
    veh.at(i).arrive.sec = v->arrive.sec;

    cout << " Confirmed time of arrival ( "<< v->arrive.hr << " : "<< v->arrive.min << " : " << v->arrive.sec<< " )";



    // while ( ((cin >> v->arrive.hr) && (cin >> v->arrive.min) &&  (cin >> v->arrive.sec)) == false){
    //     cout << "--- ERROR: Invalid input, only numbers are accepted... ---\n"
    //             << " Enter again = ";
    //     cin.clear();
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // }

    // cout << " Confirmed time of arrival ( "<< v->arrive.hr << " : "<< v->arrive.min << " : " << v->arrive.sec<< " )";

  
  
    // while (true)
    // {
    //     cin >> v->arrive.hr >> v->arrive.col1;
    //     if (!cin.good())
    //     {
    //         cout <<" --- ERROR: Invalid input, only numbers are accepted... --- " << endl;
    //         cin.clear();
    //         cin.ignore(INT_MAX, '\n');
    //         continue;
    //     }
    // else break;
    // }

    // while(! ((cin >> v->arrive.hr) && (cin >> v->arrive.min) &&  (cin >> v->arrive.sec)) ){
    //     cout << "--- ERROR: Invalid input, only numbers are accepted... ---\n"
    //          << " Enter again = ";
    //     cin.clear();
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // }

    // cout<< v->arrive.hr; 

    // veh.at(i).arrive.hr = v->arrive.hr;





    // veh.at(i).arrive.min = v->arrive.min;




    // veh.at(i).arrive.sec = v->arrive.sec;





//////////////////////////////////////////////////////////////


    // cout << "\n Arrival time in hours minutes and seconds : ";
    // cin >> v->arrive.hr >> v->arrive.col1 >> v->arrive.min >> v->arrive.col2 >> v->arrive.sec;

    // veh.at(i).arrive.hr = v->arrive.hr;





    // veh.at(i).arrive.min = v->arrive.min;




    // veh.at(i).arrive.sec = v->arrive.sec;




    // while (!(cin.good() >> v->arrive.hr)){
    //     //Print Error
    //     cout << "\n ERROR: Invalid Input, try again...\n";
    //     //  clear stream
    //     cin.clear();
    //     cin.ignore(INT_MAX, '\n');
    //     // Get input again..`
    //     // cout << "Enter Choice: ";
    //     cin >> v->arrive.hr 
    //         >> v->arrive.col1 
    //         >> v->arrive.min 
    //         >> v->arrive.col2 
    //         >> v->arrive.sec;
    // }


    cout << "\n Date in day month and year: ";
    cin >> v->dt.day >> v->dt.sym1 >> v->dt.month >> v->dt.sym2 >> v->dt.year;



    // // veh.at(i).type = v->type;
    // veh.at(i).pltnum = v->pltnum;
    // veh.at(i).arrive.hr = v->arrive.hr;
    // veh.at(i).arrive.min = v->arrive.min;
    // veh.at(i).arrive.sec = v->arrive.sec;
    veh.at(i).dt.day = v->dt.day;
    veh.at(i).dt.month = v->dt.month;
    veh.at(i).dt.year = v->dt.year;



    i++;
    totalvehicle++;

    // if (v->type == 1)
    // {
    //     totalcar++;
    // }
    // else
    // {
    //     totalbike++;
    // }

    cout << "\nVehicle added successfully" << endl;
 
}







int computeTimeDifference(timee t1, timee t2){

    int sec1, sec2, totalsec;
    timee t3;
    //calculate difference
    //get time in total seconds
    sec1 = t1.hr * 60 * 60 + t1.min * 60 + t1.sec;
    sec2 = t2.hr * 60 * 60 + t2.min * 60 + t2.sec;

    totalsec = sec2 - sec1;

    //extract time in Hours, Minutes and Seconds
    t3.min = totalsec / 60;
    t3.hr  = t3.min / 60;
    t3.min = t3.min % 60;
    t3.sec = totalsec % 60;

    // cout<<"Time difference:" <<hh<<":"<<mm<<":"<<ss<<endl;
    return t3.hr;
}




















// void Vehicle::unpark(){

//     string pno;
//     int typ;
//     timee depart;
//     int time_diff;
//     int charge = 0;

//     cout << "\n  Enter Vehicle type \n"
//          << "|1 for Car | 2 for Bike|  ";
//     cin >> setw(1) >> typ;
//     veh.at(j).type = typ;

//     // cout << "Enter vehicle type(1 for Car/2 for Bike) : ";
//     // cin >> typ;
//     cout << "Enter vehicle number : ";
//     cin >> pno;
//     cout << "Enter departure time in hours minutes and seconds : ";
//     cin >> depart.hr >> depart.col1 >> depart.min >> depart.col2 >> depart.sec;

//  for (int j = 0; j <= i; j++)
//     {
//         if ((veh.at(j).pltno == pno) && (veh.at(j).type == typ))
//         {
//             veh.at(j).departure.hr = depart.hr;
//             veh.at(j).departure.min = depart.min;
//             veh.at(j).departure.sec = depart.sec;

//             time_diff = computeTimeDifference(veh.at(j).arrive, depart);

//             if (veh.at(j).type == 1)
//             {
//                 totalcar--;
//                 if (time_diff < 2)
//                 {
//                     charge = 20;
//                 }
//                 else
//                 {
//                     if ((time_diff > 2) && ((time_diff < 5))) {
//                         charge = 40;
//                     }
//                     else
//                     {
//                         charge = 50;
//                     }
//                 }

//             }
//             else
//             {
//                 totalbike--;

//                 if (time_diff < 2)
//                 {
//                     charge = 5;
//                 }
//                 else
//                 {
//                     if ((time_diff > 2) && ((time_diff < 5)))
//                     {
//                         charge = 10;
//                     }
//                     else
//                     {
//                         charge = 20;
//                     }
//                 }

//             }

//             cout << "\nVehicle having vehicle number  : " << veh.at(j).pltno << " has left the parking after paying Rs. " << charge << endl;
//             file.open("parkingDatabase.txt", ios::app);
//             if (!file)
//             {
//                 cerr << "Error: file could not be opened" << endl;
//                 exit(1);
//             }

//             file << veh.at(j).type << "\t\t\t" << veh.at(j).pltno << "\t\t\t" << veh.at(j).dt.day << "/" << veh.at(j).dt.month << "/" << veh.at(j).dt.year << "\t\t\t" << veh.at(j).arrive.hh << ":" << veh.at(j).arrive.mm << ":" << veh.at(j).arrive.ss << "\t\t\t" << veh.at(j).departure.hh << ":" << veh.at(j).departure.mm << ":" << veh.at(j).departure.ss << endl;
//             file.close();
//             veh.erase(veh.begin() + j);
//             i--;
//             totalvehicle--;
//             totalamt = totalamt + charge;
//             break;

//         }

//         if (j == i)
//         {
//             cout << "\nWrong Entry , Try Again " << endl;
//             cout << "Departure : " << endl;
//             deleteVehicle();
//         }

//     }

// }




























void clear_scr(){ // For clearing screen
    //system("CLS");
}



int getChoice()

{
    int choice = 0;

    cout<<"*******************************************************************************" <<endl
    << "\t\t\tPARKING MANAGEMENT SYSTEM" <<endl
    << "*******************************************************************************\n" << endl
    << "\t\t\t1. PARK          " << endl
    << "\t\t\t2. UNPARK        " << endl
    << "\t\t\t3. TOTAL VEHICLE " << endl
    << "\t\t\t4. TOTAL SALES   " << endl
    << "\t\t\t5. SEARCH VEHICLE" << endl
    << "\t\t\t6. Exit SYSTEM   " << endl
    << "_______________________________________________________________________________" << endl
    << "Enter choice : ";
    cin>> setw(1)>> choice;
    // Error check 
    while (!cin.good()){
        //Print Error
        cout << "\n ERROR: Invalid Input, try again...\n";
        
        //  clear stream
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        // Get input again..`
        cout << "Enter Choice: ";
        cin>> setw(1)>> choice;

    }
    //  clear stream
    clear_scr();
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    return choice;
}


////////  Main

int main(){

    int choice = 0;
    char ans;
    choice = getChoice();

    //CHOICES IN MAIN MENU
    
    while(choice > 0 ){ 
        switch (choice){
            case 1: // FOR PARKING 
                clear_scr();
                cout << "\t\t\n---PARKING VEHICLE---" << endl;
                veh.at(i).park();
                break;
            case 2: //FOR UNPARKING
                clear_scr();
                // veh.at(i).unpark();          
                break;
            case 3:
                clear_scr();
                cout<<"this is 3\n";
                break;                
            case 4:
                clear_scr();
                cout<<"this is 4\n";
                break;
            case 5:
                clear_scr();
                cout<<"this is 5\n";
                break;
            case 6:
                clear_scr();
                cout<<"\nEXITING PROGRAM...\n";
                exit(0);
            default:
                clear_scr();
                cout<< "\nERROR: Option not available, try again...\n";
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
            clear_scr();
            // choice= getChoice();

        }

        choice = getChoice();
        
    }
    cout<< "Exiting Program...";
    system("pause");
    return 0;
}

