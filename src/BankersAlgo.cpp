/*
Hareez Sidqi Bin Mohd Fuad 2015199
Nabilah Hakim binti Hazri 2013672
Tanjim MST Mobasshira Sadia 1824612
Mohammed Fahmi Ahmed 1914939
*/


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main() {

	int process = 5, resource = 3;
	int p, r, n = 0, ans = 0;

	int status[5];
	int sequence[5];

    int available[1][3] = {10, 5, 7};
    int newAvailable[5][3];

    int need[5][3];
    
    int max[5][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };
    int alloc[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

	int thread, option;
	int req[1][3];
//---------------------------------------------
    cout << "Test existing sequence (0) or requested sequence (1)?: ";
	cin >> option;
	if(option == 1) {
		string requestLine, temp;
		ifstream requestFile("inputfile.txt");
		
		while(getline(requestFile, requestLine)) {
			istringstream token(requestLine);
			
			getline(token, temp, ' ');
			stringstream t1(temp);
			t1 >> thread; 
			
			getline(token, temp, ' ');
			stringstream t2(temp);
			t2 >> req[0][0]; 
			
			getline(token, temp, ' ');
			stringstream t3(temp);
			t3 >> req[0][1]; 

			getline(token, temp, ' ');
			stringstream t4(temp);
			t4 >> req[0][2]; 
		}
//---------------------------------------------
	  	int flag = 0;
	  	for(p=0; p<process; p++) {
			for(r=0; r<resource; r++) {
				need[p][r] = max[p][r] - alloc[p][r];
			}
		}
		for(r = 0; r<resource; r++){
			if(req[0][r] > need[thread][r]) {
				flag = 1;
				break;
			}
			if(req[0][r] > need[thread][r]) {
				flag = 1;
				break;
			}
		}
//---------------------------------------------
		if(flag == 0) {
	cout << "\tAVAIL \t\t\t\tALLOCATION\t\t\tNEED" << endl;
	cout << "\t----------------------------------------------------------------------------------------------" << endl << "\t";
			for(r = 0; r<resource; r++){
				available[0][r] -= req[0][r]; 
				cout << available[0][r] << "\t";	
			}
			cout << "\t";
			for(r = 0; r<resource; r++){
				alloc[thread][r] += req[0][r];
				cout << alloc[thread][r] << "\t";	
			}
			cout << "\t";			
			for(r = 0; r<resource; r++){
				need[thread][r] -= req[0][r];	
				cout << need[thread][r] << "\t";	
			}
		cout << "\n\n";			
		} else {
			cout << "-1: Request cannot be granted.";
			return (0);
		}
	}
//---------------------------------------------
	cout << "\tMAX \t\t\t\tALLOCATION\t\t\tNEED" << endl;
	cout << "\t----------------------------------------------------------------------------------------------" << endl;


	//for each proccess
	for(p=0; p<process; p++) {
		//print each process name
		cout << "P" << p+1 << "\t";
		for(r=0; r<resource; r++) {
			cout << max[p][r] << "\t";
		}
		cout << "\t";
		for(r=0; r<resource; r++) {
			cout << alloc[p][r] << "\t";
		}
		cout << "\t";
		for(r=0; r<resource; r++) {
			cout << need[p][r] << "\t";
		}
		cout << "\n\n";
	}	

//---------------------------------------------
	for (int q = 0; q < process; q++) {
    	status[q] = 0;
	}
	for (int q = 0; q < 5; q++) {
    	for (p = 0; p < process; p++) {
      		if (status[p] == 0) {
        	
			int flag = 0;
        
        	for (r = 0; r < resource ; r++) {
          		if (need[p][r] > available[0][r]) {
            		flag = 1;
            		break;
          		}
	        }	
 
		        if (flag == 0) {
					sequence[ans++] = p;
				
					for (n = 0; n < resource; n++) {
						available[0][n] += alloc[p][n];
						newAvailable[p][n] = available[0][n];
					}
					status[p] = 1;
        		}
    		}
    	}
	}
	int flag = 1;
	
//---------------------------------------------

	cout << "\n\n";
    cout << "\tNEED \t\t\t\tNEW RESOURCE\t\t\tSAFE?" << endl;
    cout << "\t----------------------------------------------------------------------------------------------" << endl;
    for(p=0; p<process; p++) {
		//print each process name
		cout << "P" << p+1 << "\t";
		for(r=0; r<resource; r++) {
			cout << need[p][r] << "\t";
		}
		cout << "\t";
		for(r=0; r<resource; r++) {
			cout << newAvailable[p][r] << "\t";
		}
		cout << "\t";
		
		if(status[p] == 0) {
			cout << "F";
		} else { cout << "T";}
		
		cout << "\n\n";
	}
	
	// To check if sequence is safe or not
	for(p = 0; p<process; p++) {
	    if(status[p] == 0) {
		    flag = 0;
		    cout << "-1: Sequence is not safe.";
		    break;
		}
	}
	
	if(flag == 1) {
		cout << "0: Sequence is safe. " << endl;
		cout << "Safe sequence: ";
		for (p = 0; p < process - 1; p++) {
			cout << " P" << sequence[p] << " ->";
		}
		cout << " P" << sequence[process - 1] <<endl;
	}

	return (0);
}    


