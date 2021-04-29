#include<iostream>
#include<vector>
#include<iomanip> // for input output manipulation
#include<fstream> // for storing data in files


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





void Vehicle::park(){

    Vehicle* v = new Vehicle;
    cout << "\nEnter Vehicle type\n"
         << "(1 for Car / 2 for Bike) : ";
    cin >> setw(1) >> v->type;
    while (!cin.good() || v->type >= 3){
        //Print Error
        cout << "\n ERROR: Invalid Input, try again...\n";
        
        //  clear stream
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        // Get input again..`
        // cout << "Enter Choice: ";
        cin>> setw(1)>> v->type;

    }


    cout << "\n Plate number : ";
    cin >> v->pltnum;


    cout << "\n Arrival time in hours minutes and seconds : ";
    cin >> v->arrive.hr >> v->arrive.col1 >> v->arrive.min >> v->arrive.col2 >> v->arrive.sec;


    cout << "\n Date in day month and year: ";
    cin >> v->dt.day >> v->dt.sym1 >> v->dt.month >> v->dt.sym2 >> v->dt.year;

    veh.at(i).pltnum = v->pltnum;
    veh.at(i).type = v->type;
    veh.at(i).arrive.hr = v->arrive.hr;
    veh.at(i).arrive.min = v->arrive.min;
    veh.at(i).arrive.sec = v->arrive.sec;
    veh.at(i).dt.day = v->dt.day;
    veh.at(i).dt.month = v->dt.month;
    veh.at(i).dt.year = v->dt.year;



    i++;
    totalvehicle++;

    if (v->type == 1)
    {
        totalcar++;
    }
    else
    {
        totalbike++;
    }

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



void Vehicle::unpark(){

    string pno;
    int typ;
    timee depart;
    int time_diff;
    int charge = 0;

    cout << "Enter vehicle type(1 for Car/2 for Bike) : ";
    cin >> typ;
    cout << "Enter vehicle number : ";
    cin >> pno;
    cout << "Enter departure time in hours minutes and seconds : ";
    cin >> depart.hr >> depart.col1 >> depart.min >> depart.col2 >> depart.sec;
}

























void clear(){ // For clearing screen
    system("CLS");
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
    clear();
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
            case 1:
                clear();
                cout << "\t\t\n Parking vehicle " << endl;
                veh.at(i).park();
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
            clear();
            // choice= getChoice();

        }

        choice = getChoice();
        
    }
    
    system("pause");
    return 0;
}

