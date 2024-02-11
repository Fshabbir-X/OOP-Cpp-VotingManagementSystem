#include <iostream>
#include <fstream>
#include <iomanip>
#include "NA_candidate1.h"
#include "PA_candidate1.h"
#include"Voters_Details1.h"
using namespace std;

void addNA_Candidate();
void viewNA_Candidate();
void addPA_Candidate();
void viewPA_Candidate();
void addVoter_List();
void viewVoter_List();
void searchVoter_List();
void menu();

int main() {
    while (true) {
        menu();
    }
    return 0;
}

void menu() {
    cout << "~~~~~~Voting-Management-System~~~~~" << endl;
    cout << endl;
    int menu;
    int choice;
    cout << "~~Choose one out of following options~~" << endl;
    cout << "1:Management of NA Candidate\n2:Management of PA Candidate\n3:Check Voter details\n0:Exit" << endl;
    cin >> menu;
    switch (menu) {
        case 1:
            cout << "Choose one out of following options:" << endl;
            cout << "1:Add-NA-Candidate\n2:View-NA-Candidate\n0:Exit" << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    addNA_Candidate();
                    break;
                case 2:
                    viewNA_Candidate();
                    break;
                case 0:
                    exit(0);
            }
            break;
        case 2:
            cout << "Choose one out of following options:" << endl;
            cout << "1:Add-PA-Candidate\n2:View-PA-Candidate\n0:Exit" << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    addPA_Candidate();
                    break;
                case 2:
                    viewPA_Candidate();
                    break;
                case 0:
                    exit(0);
            }
            break;
        case 3:
            cout << "Choose one out of following options:" << endl;
            cout << "1:Add-Voter-Info\n2:View-Voter-Info\n3:Search-Voter-Info\n0:Exit" << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    addVoter_List();
                    break;
                case 2:
                    viewVoter_List();
                    break;
                case 3:
                    searchVoter_List();
                    break;
                case 0:
                    exit(0);
            }
            break;
        case 0:
            exit(0);
    }
}
