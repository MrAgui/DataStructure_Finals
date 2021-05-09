#include<iostream>
#include<vector>   // Data structure used
#include<iomanip>  // for input output manipulation
#include<fstream> // for storing data in files
#include<limits>  // for checking inputss
#include<iterator>

using namespace std;



struct date{

    int day; 
    int month;
    int year;
};

struct timee{

    int hr;
    int min;
    int sec;
};

class Vehicle{

    public:

        string pltnum;
        int type;
        date dt;
        timee arrive;
        timee departure;
        int size = 20;

        void park();
        void unpark();
        void printvehicle(Vehicle v);
        void show();
		void compute();
};

// //============== DATA STRUCTURE USED 

// //============== SIZE OF VECTOR == 11
// //============== MAC CAPACITY OF PARKING LOT == 10

vector <Vehicle> veh(11);
int static totalvehicle = 0, totalcar = 0, totalbike = 0, totalsales = 0, i = 0;

// //============= FUNCTIONS

void Vehicle::compute(){
	totalvehicle = 0, totalcar = 0, totalbike = 0;
	for (auto& it : veh) {
        // Print the values
        // cout << it.type << "\n";	
		if(it.type != 0){
			totalvehicle++;
		}
		if(it.type ==1){
			totalcar++;
		}
		if(it.type ==2){
			totalbike++;
		}
    }
}

fstream file;
// // ============= F_PARKING
void Vehicle::park(){

    Vehicle* v = new Vehicle;

    cout<< "\n  Enter Vehicle type \n"
        << "\n 1 for Car / 2 for Bike : ";

    while ((cin >> setw(1) >> v->type) && !cin.good() || v->type >=3 || v->type <=0 ){

        cout << "\n--- ERROR: Invalid Input, try again... ---\n";
        
        //  clear stream
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    veh.at(i).type = v->type;

    // //  =============  F_PARKING_TIME  //HOURS : MINUTES : SECONDS 
    cout << "\n Arrival time (MILITARY TIME) \n";

    cout << "\tHOURS   : ";
    while ((cin >> setw(2) >> v->arrive.hr ) && !cin.good() || v->arrive.hr >= 24 || v->arrive.hr <=0  ){

        cout << "--- ERROR: Invalid input, enter again... ---\n"
                << " Enter hours   : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }

    cout << "\tMINUTES : ";
    while ( (cin >> setw(2) >> v->arrive.min ) && !cin.good() || v->arrive.min >= 60 || v->arrive.min <=0 ){

        cout << "--- ERROR: Invalid input, enter again... ---\n"
                << " Enter minutes   : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    cout << "\tSECONDS : ";
    while ( (cin >> setw(2) >> v->arrive.sec) && !cin.good() || v->arrive.sec >= 60 || v->arrive.sec <=0){

        cout << "--- ERROR: Invalid input, enter again... ---\n"
                << " Enter seconds again  : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

	veh.at(i).arrive.hr = v->arrive.hr;
	veh.at(i).arrive.min = v->arrive.min;
	veh.at(i).arrive.sec = v->arrive.sec;

	cout << "\n Confirmed time of arrival ( "<< v->arrive.hr << " : "<< v->arrive.min << " : " << v->arrive.sec<< " )";

    // //  =============  F_PARKING_DATE
    cout << "\n\n Date in DAY / MONTH / YEAR ";

    cout<< "\n\tDAY   : ";

        while ( ((cin >> setw(2) >> v->dt.day ) && (v->dt.day <= 31) )==false){

            cout << "--- ERROR: Invalid input, enter again... ---\n"
                    << " Enter day again  : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
    cout<< "\tMONTH : ";

        while ( ((cin >> setw(2) >> v->dt.month  ) && (v->dt.month  <= 12) )==false){

            cout << "--- ERROR: Invalid input, enter again... ---\n"
                    << " Enter month again  : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    
    cout<< "\tYEAR  : ";

        while ( ((cin >> setw(2) >> v->dt.year  ) && cin.good() )==false){

            cout << "--- ERROR: Invalid input, enter again... ---\n"
                    << " Enter year again  : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    
    veh.at(i).dt.day = v->dt.day;
    veh.at(i).dt.month = v->dt.month;
    veh.at(i).dt.year = v->dt.year;

    cout << "\n Confirmed date of arrival ( "<< v->dt.day << " / "<< v->dt.month << " / " << v->dt.year<< " )";

    bool dontexist = true;

    while(dontexist){

        cout << "\n\n Plate number : ";
        cin >> setw(6) >>  v->pltnum;
        cin.ignore(INT_MAX, '\n');
       
        for(int i = 0; i < veh.size(); i++){

            while(veh.at(i).pltnum == v->pltnum ){
                cin.clear();    
                
                cout << "\n ERROR : "                      
                     << " Plate | "<< v->pltnum  << " | already exists \n\n --- Unique plate number required... --- \n\n"
                     << "\n\n Unique plate number : ";

                cin >> setw(6) >>  v->pltnum;
                cin.ignore(INT_MAX, '\n');
            }
        }

        if( dontexist == true ){
           

            veh.at(i).pltnum = v->pltnum;   
            i++;    
            cout << "\n---Vehicle added successfully! ---\n" << endl;  
            dontexist=false;
            break;
        }
    }
}




// //  =============  F_COMPUTE_TIME_DIFFERENCE
int computeTimeDifference(timee t1, timee t2){

    int Totalsec1, Totalsec2, Totalsec;
    timee t3;
    
    // // == Convert all units to seconds
    Totalsec1 = t1.hr * 60 * 60 + t1.min * 60 + t1.sec;
    Totalsec2 = t2.hr * 60 * 60 + t2.min * 60 + t2.sec;

    
    // // == Calculate the difference by total seconds
    Totalsec = Totalsec2 - Totalsec1;

    
    // // == extract time in Hours, Minutes and Seconds
    t3.min = Totalsec / 60;
    t3.hr  = t3.min / 60;


    return t3.hr;
}




// //  =============  F_UNPARKING
void Vehicle::unpark(){

    
    string pno;
    int ind;
    int typ;
    timee depart;
    int time_diff;
    int charge = 0;
    bool notfound=true;
    
    // cout<< veh.size();
    cout<< "List of Plates:\n";
    for (auto& it : veh){   
        cout << it.pltnum << "\n";
    }	
    
    while( notfound){
        cout << "\nEnter vehicle number : ";
        getline(cin, pno);        


        for(int j = 0; j < veh.size(); j++){

            // if(veh.at(j).pltnum != ""){               

            //     // continue;
            //     // cout << "\nsaved pn: "<< pno;
            //     // cout << " == " << veh.at(j).pltnum;
            //     cout << "\n";

                if(veh.at(j).pltnum == pno){
                    cout << "\n Departure time (MILITARY TIME) \n";

                    cout << "\tHOURS   : ";
                        while ( ((cin >> setw(2) >> depart.hr) && (depart.hr<= 24) )==false){

                            cout << "--- ERROR: Invalid input, enter again... ---\n"
                                    << " Enter hours again  : ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        }

                    cout << "\tMINUTES : ";

                        while ( ((cin >> setw(2) >> depart.min ) && (depart.min<= 59) )==false){

                            cout << "--- ERROR: Invalid input, enter again... ---\n"
                                    << " Enter minutes again  : ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                    cout << "\tSECONDS : ";

                        while ( ((cin >> setw(2) >> depart.sec) && (depart.sec <= 59) )==false){

                            cout << "--- ERROR: Invalid input, enter again... ---\n"
                                    << " Enter seconds again  : ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    veh.at(j).departure.hr = depart.hr;
                    veh.at(j).departure.min = depart.min;
                    veh.at(j).departure.sec = depart.sec;

                    time_diff = computeTimeDifference(veh.at(j).arrive, depart);

                    if (veh.at(j).type == 1){

                        totalcar--;

                        if ((time_diff == 0) || (time_diff < 2) && (time_diff == 1)){

                            charge = 20;

                        }
                        else{

                            if ((time_diff > 2) && ((time_diff < 5))){

                                charge = 30;

                            }

                            else{
                                
                                charge = 60;
                            }
                        }

                    }
                    else{
                        totalbike--;

                        if ((time_diff == 0) || (time_diff < 2) && (time_diff == 1)){
                            charge = 15;
                        }
                        else{
                            if ((time_diff > 2) && ((time_diff < 5))){
                                charge =25;
                            }
                            else{
                                charge = 50;
                            }
                        }

                    }
                    cout << "\n Duration in Parking lot    : " << time_diff << "hrs" ; 
                    cout << "\n Vehicle wtih plate number  : " << veh.at(j).pltnum << " are charged with PHP. " << charge << endl;
                    
                    file.open("parkingDatabase.txt", ios::app);
                    // if (!file){
                    //     cout << "Error: file could not be opened" << endl;
                    //     exit(1);
                    // }   

                    file << veh.at(j).type << "\t\t\t" << veh.at(j).pltnum << "\t\t\t" << veh.at(j).dt.day << "/" << veh.at(j).dt.month << "/" << veh.at(j).dt.year << "\t\t\t" << veh.at(j).arrive.hr << ":" << veh.at(j).arrive.min << ":" << veh.at(j).arrive.sec << "\t\t\t" << veh.at(j).departure.hr << ":" << veh.at(j).departure.min << ":" << veh.at(j).departure.sec << endl;
                    file.close();   
                    ////////////
                    veh.erase(veh.begin() + j);
                    i--;
                    totalvehicle--;
                    totalsales = totalsales + charge;
                    notfound = false;

                    break;
                    
                }

            // }

        }
        if(notfound==true){
            cout<<" plate number not found\n";
      
        }

    }

    cout << " \n---Vehicle unparked... ---";

}
//////////////////////////////////////////////////////

void Vehicle::printvehicle(Vehicle v){
    cout << v.type << "\t\t\t" << v.pltnum << "\t\t\t\t" << v.dt.day << "/" << v.dt.month << "/" << v.dt.year << "\t\t\t" << v.arrive.hr << ":" << v.arrive.min << ":" << v.arrive.sec << endl;
}

void Vehicle::show(){

    cout << "Vehicle Type\t\tVehicle Number\t\t\tDate\t\t\t\tArrival Time" << endl;
    for (int j = 0; j < i; j++)
    {
        printvehicle(veh[j]);
    }
}

void totalamount(){
    cout << "Total Collection till now : " << totalsales<< endl;
}


void clear_scr(){ // For clearing screen
    system("CLS");
}



int getChoice()

{
    int choice = 0;


	veh.at(i).compute();

	cout<<"\n*******************************************************************************" <<endl
    << "\t\t\tPARKING MANAGEMENT SYSTEM" <<endl
    << "*******************************************************************************" << endl
    << "\t\t1. PARK              |" << "\tTotal number of vehicle parked : " << totalvehicle  << endl
    << "\t\t2. UNPARK            |" << "\tTotal number of car parked     : " << totalcar      << endl
    << "\t\t3. TOTAL SALES       |" << "\tTotal number of bike parked    : " << totalbike     << endl
    << "\t\t4. SHOW DATA         |" << endl
    << "\t\t5. EXIT              |" << endl
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
        cout << " Enter Choice: ";
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
                if (totalvehicle == 10){
                    cout<< "\n---Parking lot is full---\n\n";
                    system("PAUSE");
                    clear_scr();
                    main();
                }else{
                cout << "\t\t\n---PARKING VEHICLE---" << endl;
                veh.at(i).park();
                break;
                }
                break;
            case 2: //FOR UNPARKING
                clear_scr();
                
                if (totalvehicle == 0){
                    cout<< "\n---Parking lot is empty---\n\n";
                    system("PAUSE");
                    clear_scr();
                    main();
                }
                else{
                    cout << "\t\t\n---UNPARKING VEHICLE---" << endl;
                    veh.at(i).unpark();          
                    break;
                }
                break;
            case 3:
                clear_scr();
                totalamount();
                break;                
            case 4: // SHOW DATA
                clear_scr();
                veh.at(i).show();
                break;
            case 5:
                clear_scr();
                cout<<" \n ---- EXITING PROGRAM ... ----\n";
                exit(0);
                break;
            default:
                cout<< "\nERROR: Option not available, try again...\n";
                break;
        }

        cout<<"\n";
        system("pause");
        clear_scr();

        choice = getChoice();
        
    }
    cout<<"\n";
    system("pause");
    return 0;
}