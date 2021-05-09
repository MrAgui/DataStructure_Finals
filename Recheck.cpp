#include<iostream>
#include<vector>
#include<iomanip>  // for input output manipulation
#include<fstream> // for storing data in files
#include<limits>  // for checking inputss
#include<math.h>
#include <algorithm>
#include<iterator>
#include<cstring> // fpr string lenght

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

        void find();
        void park();
        void unpark();
        void printvehicle(Vehicle v);
        void show();
		void compute();
};

////////// DATA STRUCTURE USED 
vector <Vehicle> veh(11);
int static totalvehicle = 0, totalcar = 0, totalbike = 0, totalsales = 0, i = 0;

fstream file;

///////// Functions

// void check(){
//     cout<< " this is checking if element exists";

// }

void Vehicle::park(){

    Vehicle* v  = new Vehicle;
    void char_limit(){
    strlen(v->pltnum)
    }
    // cout << "\n\n Plate number : ";
    // cin >> setw(6) >>  v->pltnum;
    // cin.ignore(INT_MAX, '\n');

//////////////////////////////////////////////////////////////////////////////////////

    // cout << "\n\n Plate number : ";
    // cin >> setw(6) >> v->pltnum;
    // cin.ignore(INT_MAX, '\n');



/////////////////////////////////////////////////////////////////////////////////////

/////////SAVIOUR
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


/////////////////////////////////////////////////

    //     bool dontexist = true;

    // while( dontexist ){
    //     cout << "\nEnter vehicle number : ";
    //     getline(cin, v->pltnum);        
    //     // cout << "\nEntered value is : ";
    //     // cout << pno;
    //     // cout << "\n";

    //     for(int i = 0; i < veh.size(); i++){

    //         if(veh.at(i).pltnum ==  v->pltnum){ 

    //         cout << "\n already exists EXISTS enter again \n ";
    //         cout << "\nEnter vehicle number : ";
    //         getline(cin, v->pltnum);           

    //         }        
    //     }
  
    //     if(dontexist ==true){
            
    //         cout<<" plate number not found\n";

    //         dontexist=false;

    //         veh.at(i).pltnum = v->pltnum;   

    //         i++;    
    //         cout << "\n---Vehicle added successfully! ---\n" << endl;   
    //         break;
      
    //     }

    // }


// /////////////////////////////////////////////////////////
    // bool dontexist = true;

    // for(int i = 0; i < veh.size(); i++){

    //     while(dontexist){

    //         cout << "\nEnter vehicle number : ";
    //         getline(cin, v->pltnum);        
    //         // cout << "\nEntered value is : ";
    //         // cout << pno;
    //         // cout << "\n";
    //         while ((veh.at(i).pltnum ==  v->pltnum)){ 
                
    //             cout<< "\nList of Plates:\n";
    //             for (auto& it : veh){   
    //                 cout << it.pltnum << "\n";
    //             }	

    //             cout << "\n already exists please enter again \n ";
    //             cin.clear();
    //             cin.ignore(INT_MAX, '\n');

    //             cout << "\nEnter vehicle number : ";
    //             getline(cin, v->pltnum);

    //         }        

    //         if(dontexist ==true){
                
    //             cout<<"\nplate number not found\n";

    //             dontexist=false;

    //             veh.at(i).pltnum = v->pltnum;   

    //             i++;    
    //             cout << "\n---Vehicle added successfully! ---\n" << endl;   
    //             break;
        
    //         }

    //     }

    // }
    // cout<< "EXITS the loop\n";
/////////////////////////////////////////////////////////

    // bool dontexist = true;

    // for(int i = 0; i < veh.size(); i++){

    //     while(dontexist){

    //         cout << "\nEnter vehicle number : ";
    //         getline(cin, v->pltnum);        
    //         // cout << "\nEntered value is : ";
    //         // cout << pno;
    //         // cout << "\n";
    //         while ((veh.at(i).pltnum ==  v->pltnum)){ 
                
    //             cout<< "\nList of Plates:\n";
    //             for (auto& it : veh){   
    //                 cout << it.pltnum << "\n";
    //             }	

    //             cout << "\n already exists please enter again \n ";
    //             cin.clear();
    //             cin.ignore(INT_MAX, '\n');

    //             cout << "\nEnter vehicle number : ";
    //             getline(cin, v->pltnum);

    //         }        

    //         if(dontexist ==true){
                
    //             cout<<"\nplate number not found\n";

    //             dontexist=false;

    //             veh.at(i).pltnum = v->pltnum;   

    //             i++;    
    //             cout << "\n---Vehicle added successfully! ---\n" << endl;   
    //             break;
        
    //         }

    //     }

    // }
    // cout<< "EXITS the loop\n";


////////////////////////////////////////////////////////

    // Vehicle::find(string pltnum) const{
    //     for(int i = 0; i < veh.size(); i++){
    //         if(veh.at(i).pltnum == pltnum ){

    //             return pltnum.at(i);

    //         }
    //     }
    // }














/////////////////////////////////////////////////////////////////////////////////////
    // fial

    // bool notfound_2 = true;

    // while( notfound_2 ){
    //     cout << "\nEnter vehicle number : ";
    //     getline(cin, v->pltnum);  

    //     cout<< "\nentered valuse" << v->pltnum << endl;
     
    //     for(int i = 0; i < veh.size(); i++){
    //         if( notfound_2 == false){

    //             cout<<"Continue to append\n";

    //             notfound_2=false;

    //             break;        
    //         }        
    //     }
    //     if(veh.at(i).pltnum == pltnum){
    //         cout<<"Plate number Already exists"<< v->pltnum;
    //         notfound_2 == true;
    //     }
    // }
///////////////////////////////////////////////////////////////////////////////////////

//////// fail 
    // bool notfound_p=true;

    // while( notfound_p ){
    //     cout << "\nEnter vehicle number : ";
    //     getline(cin, v->pltnum);        
    //     // cout << "\nEntered value is : ";
    //     // cout << pno;
    //     // cout << "\n";

    //     for(int j = 0; j < veh.size(); j++){

    //         if(veh.at(j).pltnum != ""){               
    //             cout << "\nsaved pn: "<< v->pltnum;
    //             cout << " == " << veh.at(i).pltnum;
    //             cout << "\n";
    //             if(veh.at(j).pltnum == v->pltnum){
    //                 cout<<" plate number found loop again\n";
    //                 notfound_p=false;
    //                 break;
    //             }

    //         }

    //     }
    //     if(notfound_p==true){
    //         cout<<"\n Plate number not found\n";
    //         notfound_p=false;
    //         break;
      
    //     }

    // }
///////////////////////////////////////////////////////////////////////////////


    /////////// fail 
    // cout << "\n\n Plate number : ";
    // cin >> setw(6) >> v->pltnum;
    // cin.ignore(INT_MAX, '\n');
    // if ( std::find(veh.begin(), veh.end(), veh.at(i).pltnum) != veh.end() ){

    //     cout<< "item exist";
    // }
        
    // else{
    //     cout<< "dont exist";
    // }
    // cout << " Program runned\n";








//////////////////////////////////////////////////////////////////////////////////////////////
    // veh.at(i).pltnum = v->pltnum;   

    // i++;    
    //totalvehicle++;
    cout<< "\nList of Plates:\n";
    for (auto& it : veh){   
        cout << it.pltnum << "\n";
    }	

    // cout << "\n---Vehicle added successfully! ---\n" << endl;
    system("pause");
    system("CLS");
    veh.at(i).park();
 
}
int main(){
    cout<<"\n\nstart\n";

    veh.at(i).park();

    cout<<"\n end";
}