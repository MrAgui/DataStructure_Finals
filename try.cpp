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
		void compute();


};
////////// DATA STRUCTURE USED 
vector <Vehicle> veh(20);
int static totalvehicle = 0, totalcar = 0, totalbike = 0, totalsales = 0, i = 0;

fstream file;

///////// Functions

void Vehicle::compute(){
	totalvehicle = 0, totalcar = 0, totalbike = 0;
	for (auto& it : veh) {
        // Print the values
        cout << it.type << "\n";	
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


void Vehicle::park(){
		Vehicle* v = new Vehicle;
		cout << "\n  Enter Vehicle type \n"
			 << "\n 1 for Car / 2 for Bike : ";

		//cin >> setw(1) >> v->type;
		//veh.at(i).type = v->type;

///////////////////////

		while ((cin>> setw(1)>> v->type) && !cin.good() || v->type >=3 || v->type <=0 ){
			//Prints Error
			cout << "\n ERROR: Invalid Input, try again...\n";
			
			//  clear stream
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			

		}



//////////////////////
		cout << "\n  Entered value is: \n";
		cout<< v->type;
	    veh.at(i).type = v->type;
		// if (v->type == 1){
		// 	//totalcar++;
		// }
		// 	else if(v->type == 2){
		// 		//totalbike++;
		// 	}
		// 		else{
		// 			while (!cin.good() || v->type >=3 || v->type <=0 ){
		// 				//Prints Error
		// 				cout << "\n ERROR: Invalid Input, try again...\n";
						
		// 				//  clear stream
		// 				cin.clear();
		// 				cin.ignore(INT_MAX, '\n');

		// 				cin>> setw(1)>> v->type;

		// 			}

    	// 		}


//////////////////////
    cout << "\n Arrival time in (MILITARY TIME) \n";//HOURS : MINUTES : SECONDS = "

    cout << "\tHOURS   : ";
        while ( ((cin >> setw(2) >> v->arrive.hr ) && (v->arrive.hr <= 24) )==false){

            cout << "--- ERROR: Invalid input, only numbers are accepted... ---\n"
                    << " Enter hours again  : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }

    cout << "\tMINUTES : ";

        while ( ((cin >> setw(2) >> v->arrive.min ) && (v->arrive.min <= 59) )==false){

            cout << "--- ERROR: Invalid input, only numbers are accepted... ---\n"
                    << " Enter minutes again  : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    cout << "\tSECONDS : ";

        while ( ((cin >> setw(2) >> v->arrive.sec) && (v->arrive.sec <= 59) )==false){

            cout << "--- ERROR: Invalid input, only numbers are accepted... ---\n"
                    << " Enter seconds again  : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

	veh.at(i).arrive.hr = v->arrive.hr;
	veh.at(i).arrive.min = v->arrive.min;
	veh.at(i).arrive.sec = v->arrive.sec;

	cout << "\n Confirmed time of arrival ( "<< v->arrive.hr << " : "<< v->arrive.min << " : " << v->arrive.sec<< " )";

    // cout << "\n Plate number : ";
    // cin >> setw(6) >>  v->pltnum;
    // veh.at(i).pltnum = v->pltnum;


//////////////////////////////////////////////////////////////



    cout << "\n\n Date in DAY / MONTH / YEAR ";

    cout<< "\n\tDAY   : ";

        while ( ((cin >> setw(2) >> v->dt.day ) && (v->dt.day <= 31) )==false){

            cout << "--- ERROR: Invalid input, only numbers are accepted... ---\n"
                    << " Enter day again  : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
    cout<< "\tMONTH : ";

        while ( ((cin >> setw(2) >> v->dt.month  ) && (v->dt.month  <= 12) )==false){

            cout << "--- ERROR: Invalid input, only numbers are accepted... ---\n"
                    << " Enter month again  : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    
    cout<< "\tYEAR  : ";

        while ( ((cin >> setw(2) >> v->dt.year  ) && true )==false){

            cout << "--- ERROR: Invalid input, only numbers are accepted... ---\n"
                    << " Enter year again  : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    
    veh.at(i).dt.day = v->dt.day;
    veh.at(i).dt.month = v->dt.month;
    veh.at(i).dt.year = v->dt.year;

    cout << "\n Confirmed date of arrival ( "<< v->dt.day << " / "<< v->dt.month << " / " << v->dt.year<< " )";


    cout << "\n\n Plate number : ";
    cin >> setw(6) >>  v->pltnum;
    cin.ignore(INT_MAX, '\n');
    veh.at(i).pltnum = v->pltnum;
   
    cout << veh.at(i).pltnum;
    
    i++;
    //totalvehicle++;


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








/////////////////////////////////////////////////////////////











// void Vehicle::unpark(){

//     string pno;
//     int typ;
//     timee depart;
//     int time_diff;
//     int charge = 0;

//     cout << "\n  Enter Vehicle type \n"
//          << "|1 for Car | 2 for Bike|  ";
//     cin >> setw(1) >> typ;
//     // veh.at(j).type = typ;

//     // cout << "Enter vehicle type(1 for Car/2 for Bike) : ";
//     // cin >> typ;
//     cout << "Enter vehicle number : ";
//     cin >> pno;
//     cout << "Enter departure time in hours minutes and seconds : ";
//     cin >> depart.hr >> depart.col1 >> depart.min >> depart.col2 >> depart.sec;

//     for (int j = 0; j <= i; j++)
//         {
//             if ((veh.at(j).pltnum == pno) && (veh.at(j).type == typ))
//             {
//                 veh.at(j).departure.hr = depart.hr;
//                 veh.at(j).departure.min = depart.min;
//                 veh.at(j).departure.sec = depart.sec;

//                 time_diff = computeTimeDifference(veh.at(j).arrive, depart);

//                 if (veh.at(j).type == 1)
//                 {
//                     totalcar--;
//                     if (time_diff < 2)
//                     {
//                         charge = 20;
//                     }
//                     else
//                     {
//                         if ((time_diff > 2) && ((time_diff < 5))) {
//                             charge = 40;
//                         }
//                         else
//                         {
//                             charge = 50;
//                         }
//                     }

//                 }
//                 else
//                 {
//                     totalbike--;

//                     if (time_diff < 2)
//                     {
//                         charge = 5;
//                     }
//                     else
//                     {
//                         if ((time_diff > 2) && ((time_diff < 5)))
//                         {
//                             charge = 10;
//                         }
//                         else
//                         {
//                             charge = 20;
//                         }
//                     }

//                 }

//                 cout << "\nVehicle having vehicle number  : " << veh.at(j).pltnum << " has left the parking after paying Rs. " << charge << endl;
//                 file.open("parkingDatabase.txt", ios::app);
//                 if (!file)
//                 {
//                     cerr << "Error: file could not be opened" << endl;
//                     exit(1);
//                 }

//                 file << veh.at(j).type << "\t\t\t" << veh.at(j).pltnum << "\t\t\t" << veh.at(j).dt.day << "/" << veh.at(j).dt.month << "/" << veh.at(j).dt.year << "\t\t\t" << veh.at(j).arrive.hr << ":" << veh.at(j).arrive.min << ":" << veh.at(j).arrive.sec << "\t\t\t" << veh.at(j).departure.hr << ":" << veh.at(j).departure.min << ":" << veh.at(j).departure.sec << endl;
//                 file.close();
//                 veh.erase(veh.begin() + j);
//                 i--;
//                 totalvehicle--;
//                 totalsales = totalsales + charge;
//                 break;

//             }

//             if (j == i)
//             {
//                 cout << "\nWrong Entry , Try Again " << endl;
//                 cout << "Departure : " << endl;
//                 unpark();
//             }

//         }

// }

void Vehicle::unpark(){

    string pno;
    int typ;
    timee depart;
    int time_diff;
    int charge = 0;

    cout << "\n  Enter Vehicle type \n"
         << "|1 for Car | 2 for Bike|  ";
    cin >> setw(1) >> typ;
		while(1){ 
			if((typ == 1) && (typ == 2)){
				break;
			}	
				else{
					while (!cin.good() || typ  >=3 || typ  <=0 ){
						//Prints Error
						cout << "\n ERROR: Invalid Input, try again...\n";
						
						//  clear stream
						cin.clear();
						cin.ignore(INT_MAX, '\n');

						cin>> setw(1)>> typ;

					}
				break;
				}
		}		
	cout<< typ;


    // veh.at(j).type = typ;
	cout << veh.at(i).pltnum;
    // cout << "Enter vehicle type(1 for Car/2 for Bike) : ";
    // cin >> typ;
    cout << "\nEnter vehicle number : ";
	
	//////////////
    // cin >> pno;
	for (int j = 0; j <= i; j++){

		cin >> pno;

			if ((veh.at(j).pltnum == pno) && (veh.at(j).type == typ)){

//////////////////////////////
				cout << "\n Arrival time in (MILITARY TIME) \n";//HOURS : MINUTES : SECONDS = "

				cout << "\tHOURS   : ";
					while ( ((cin >> setw(2) >> depart.hr) && (depart.hr<= 24) )==false){

						cout << "--- ERROR: Invalid input, only numbers are accepted... ---\n"
								<< " Enter hours again  : ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

					}

				cout << "\tMINUTES : ";

					while ( ((cin >> setw(2) >> depart.min ) && (depart.min<= 59) )==false){

						cout << "--- ERROR: Invalid input, only numbers are accepted... ---\n"
								<< " Enter minutes again  : ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}

				cout << "\tSECONDS : ";

					while ( ((cin >> setw(2) >> depart.sec) && (depart.sec <= 59) )==false){

						cout << "--- ERROR: Invalid input, only numbers are accepted... ---\n"
								<< " Enter seconds again  : ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}




////////////////////////////
				// cout << "Enter departure time in HOURS : MINUTES : SECONDS  \n";
				// cin >> depart.hr >> depart.col1 >> depart.min >> depart.col2 >> depart.sec;


				veh.at(j).departure.hr = depart.hr;
				veh.at(j).departure.min = depart.min;
				veh.at(j).departure.sec = depart.sec;

				time_diff = computeTimeDifference(veh.at(j).arrive, depart);

				if (veh.at(j).type == 1)
				{
					totalcar--;
					if (time_diff < 2)
					{
						charge = 20;
					}
					else
					{
						if ((time_diff > 2) && ((time_diff < 5))) {
							charge = 40;
						}
						else
						{
							charge = 50;
						}
					}

				}
				else
				{
					totalbike--;

					if (time_diff < 2)
					{
						charge = 5;
					}
					else
					{
						if ((time_diff > 2) && ((time_diff < 5)))
						{
							charge = 10;
						}
						else
						{
							charge = 20;
						}
					}

				}

				cout << "\nVehicle having vehicle number  : " << veh.at(j).pltnum << " has left the parking after paying Rs. " << charge << endl;
				file.open("parkingDatabase.txt", ios::app);
				if (!file)
				{
					cerr << "Error: file could not be opened" << endl;
					exit(1);
				}

				file << veh.at(j).type << "\t\t\t" << veh.at(j).pltnum << "\t\t\t" << veh.at(j).dt.day << "/" << veh.at(j).dt.month << "/" << veh.at(j).dt.year << "\t\t\t" << veh.at(j).arrive.hr << ":" << veh.at(j).arrive.min << ":" << veh.at(j).arrive.sec << "\t\t\t" << veh.at(j).departure.hr << ":" << veh.at(j).departure.min << ":" << veh.at(j).departure.sec << endl;
				file.close();
				veh.erase(veh.begin() + j);
				i--;
				totalvehicle--;
				totalsales = totalsales + charge;
				break;

			}

		// if (j == i){
		// 	cout << "\nWrong Entry , Try Again " << endl;
		// 	cout << "Departure : " << endl;
		// 	unpark();
		// }

	}

}





void Vehicle::printvehicle(Vehicle v){
    cout << v.type << "\t\t\t" << v.pltnum << "\t\t\t" << v.dt.day << "/" << v.dt.month << "/" << v.dt.year << "\t\t\t" << v.arrive.hr << ":" << v.arrive.min << ":" << v.arrive.sec << endl;
}

void Vehicle::show(){

    cout << "Vehicle Type\t\tVehicle Number\t\tDate\t\t\tArrival Time" << endl;
    for (int j = 0; j < i; j++)
    {
        printvehicle(veh[j]);
    }
}

void totalveh(){
    cout << "Total number of vehicle parked : " << totalvehicle << endl;
    cout << "Total number of car parked : " << totalcar << endl;
    cout << "Total number of bike parked : " << totalbike << endl;

}

void totalamount(){
    cout << "Total Collection till now : " << totalsales<< endl;
}




    // cout << "Enter departure time in HOURS : MINUTES : SECONDS  \n";
    // cin >> depart.hr >> depart.col1 >> depart.min >> depart.col2 >> depart.sec;

//     for (int j = 0; j <= i; j++)
//         {
//             if ((veh.at(j).pltnum == pno) && (veh.at(j).type == typ))
//             {
//                 veh.at(j).departure.hr = depart.hr;
//                 veh.at(j).departure.min = depart.min;
//                 veh.at(j).departure.sec = depart.sec;

//                 time_diff = computeTimeDifference(veh.at(j).arrive, depart);

//                 if (veh.at(j).type == 1)
//                 {
//                     totalcar--;
//                     if (time_diff < 2)
//                     {
//                         charge = 20;
//                     }
//                     else
//                     {
//                         if ((time_diff > 2) && ((time_diff < 5))) {
//                             charge = 40;
//                         }
//                         else
//                         {
//                             charge = 50;
//                         }
//                     }

//                 }
//                 else
//                 {
//                     totalbike--;

//                     if (time_diff < 2)
//                     {
//                         charge = 5;
//                     }
//                     else
//                     {
//                         if ((time_diff > 2) && ((time_diff < 5)))
//                         {
//                             charge = 10;
//                         }
//                         else
//                         {
//                             charge = 20;
//                         }
//                     }

//                 }

//                 cout << "\nVehicle having vehicle number  : " << veh.at(j).pltnum << " has left the parking after paying Rs. " << charge << endl;
//                 file.open("parkingDatabase.txt", ios::app);
//                 if (!file)
//                 {
//                     cerr << "Error: file could not be opened" << endl;
//                     exit(1);
//                 }

//                 file << veh.at(j).type << "\t\t\t" << veh.at(j).pltnum << "\t\t\t" << veh.at(j).dt.day << "/" << veh.at(j).dt.month << "/" << veh.at(j).dt.year << "\t\t\t" << veh.at(j).arrive.hr << ":" << veh.at(j).arrive.min << ":" << veh.at(j).arrive.sec << "\t\t\t" << veh.at(j).departure.hr << ":" << veh.at(j).departure.min << ":" << veh.at(j).departure.sec << endl;
//                 file.close();
//                 veh.erase(veh.begin() + j);
//                 i--;
//                 totalvehicle--;
//                 totalsales = totalsales + charge;
//                 break;

//             }

//             if (j == i)
//             {
//                 cout << "\nWrong Entry , Try Again " << endl;
//                 cout << "Departure : " << endl;
//                 unpark();
//             }

//         }

// }






//////////////////////////////////////////////////////



















void clear_scr(){ // For clearing screen
    // system("CLS");
}



int getChoice()

{
    int choice = 0;

    // cout<<"*******************************************************************************" <<endl
    // << "\t\t\tPARKING MANAGEMENT SYSTEM" <<endl
    // << "*******************************************************************************\n" << endl
    // << "\t\t\t1. PARK          " << endl
    // << "\t\t\t2. UNPARK        " << endl
    // << "\t\t\t3. TOTAL VEHICLE " << endl
    // << "\t\t\t4. TOTAL SALES   " << endl
    // << "\t\t\t5. SEARCH VEHICLE" << endl
    // << "\t\t\t6. Exit SYSTEM   " << endl
    // << "_______________________________________________________________________________" << endl
    // << "Enter choice : ";
	veh.at(i).compute();
	cout<<"\n*******************************************************************************" <<endl
    << "\t\t\tPARKING MANAGEMENT SYSTEM" <<endl
    << "*******************************************************************************" << endl
    << "\t\t1. PARK            |" << "\tTotal number of vehicle parked : " << totalvehicle  << endl
    << "\t\t2. UNPARK          |" << "\tTotal number of car parked     : " << totalcar      << endl
    << "\t\t3. TOTAL VEHICLE   |" << "\tTotal number of bike parked    : " << totalbike     << endl
    << "\t\t4. TOTAL SALES     |" << endl
    << "\t\t5. SHOW DATA	   |" << endl
    << "\t\t6. Exit SYSTEM     |" << endl
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
				cout << "\t\t\n---UNPARKING VEHICLE---" << endl;
                veh.at(i).unpark();          
                break;
            case 3:
                clear_scr();
				totalveh();
                break;                
            case 4:
                clear_scr();
                cout<<"this is 4\n";
                break;
            case 5:
                clear_scr();
                veh.at(i).show();
				
				//compute(veh);
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