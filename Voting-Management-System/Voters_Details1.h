#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

const int MAX_VOTERS = 10000;

struct voter {
    string name;
    int House_No;
    string CNIC;
    string PA_Constituency;
    string NA_Constituency;
    int Serial_num;
} info[MAX_VOTERS];

void addVoter_List() {
    ofstream fout("Voter.txt", ios::app);
    if (!fout.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    char choice;
    for (int i = 0; i < MAX_VOTERS; i++) {
        cout << "Enter the CNIC of the Voter" << endl;
        cin >> info[i].CNIC;
        
        
        cout << "Enter the Name of the Voter" << endl;
        cin >> info[i].name;
        cout << "Enter the House Number of the Voter" << endl;
        cin >> info[i].House_No;
        cout << "Enter the Serial Number of the Voter" << endl;
        cin >> info[i].Serial_num;
        cout << "Enter the PA_Constituency of the Voter" << endl;
        cin >> info[i].PA_Constituency;
        cout << "Enter the NA_Constituency of the Voter" << endl;
        cin >> info[i].NA_Constituency;
        fout << info[i].CNIC << " " << info[i].name << " " << info[i].House_No << " " << info[i].Serial_num << " " << info[i].PA_Constituency << " " << info[i].NA_Constituency << endl;
        cout << "Enter 'Y' if you want to add the data of another Voter and press any other button to exit" << endl;
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }
    fout.close();
}

void viewVoter_List() {
    ifstream fin("Voter.txt");
    if (!fin.is_open()) {
        cout << "File is not available" << endl;
        return;
    }

    cout << left << setw(15) << "CNIC" << setw(15) << "Name" << setw(15) << "House_Number" << setw(15) << "Serial_Number" << setw(20) << "PA_Constituency" << setw(20) << "NA_Constituency" << endl;

    int count = 0;
    while (fin >> info[count].CNIC >> info[count].name >> info[count].House_No >> info[count].Serial_num >> info[count].PA_Constituency >> info[count].NA_Constituency) {
        cout << left << setw(15) << info[count].CNIC << setw(15) << info[count].name << setw(15) << info[count].House_No << setw(15) << info[count].Serial_num << setw(20) << info[count].PA_Constituency << setw(20) << info[count].NA_Constituency << endl;
        count++;
        if (count >= MAX_VOTERS) {
            break;
        }
    }

    fin.close();
}

void searchVoter_List() {
    ifstream fin("Voter.txt");
    if (!fin.is_open()) {
        cout << "File is not Available" << endl;
        return;
    }

    string Search_CNIC;
    cout << "Enter the CNIC of the person for searching Voter Details:" << endl;
    cin >> Search_CNIC;

    cout << left << setw(15) << "CNIC" << setw(15) << "Name" << setw(15) << "House_Number" << setw(15) << "Serial_Number" << setw(20) << "PA_Constituency" << setw(20) << "NA_Constituency" << endl;

    voter temp;
    while (fin >> temp.CNIC >> temp.name >> temp.House_No >> temp.Serial_num >> temp.PA_Constituency >> temp.NA_Constituency) {
        if (Search_CNIC == temp.CNIC) {
            cout << left << setw(15) << temp.CNIC << setw(15) << temp.name << setw(15) << temp.House_No << setw(15) << temp.Serial_num << setw(20) << temp.PA_Constituency << setw(20) << temp.NA_Constituency << endl;
            break; 
        }
    }

    fin.close();
}
