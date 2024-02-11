#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_PA_CANDIDATES = 10;

struct PollingDataPA {
    string name;
    string constituency;
    string party;
    int votes;
};

bool addPA_Candidate(PollingDataPA candidates[], int& count) {
    if (count >= MAX_PA_CANDIDATES) {
        cout << "Maximum candidates reached." << endl;
        return false;
    }

    ofstream fout("PA.txt", ios::app);
    if (!fout.is_open()) {
        cout << "Error opening file." << endl;
        return false;
    }

    PollingDataPA newCandidate;
    cout << "Enter the Name of the Candidate: ";
    cin >> newCandidate.name;

    for (int i = 0; i < count; ++i) {
        if (candidates[i].name == newCandidate.name) {
            cout << "The candidate is already in the list! Please enter another." << endl;
            return false;
        }
    }

    cout << "Enter the Constituency of the Candidate: ";
    cin >> newCandidate.constituency;
    cout << "Enter the Party of the Candidate: ";
    cin >> newCandidate.party;
    cout << "Enter the Votes of the Candidate: ";
    cin >> newCandidate.votes;

    fout << newCandidate.name << " " << newCandidate.constituency << " " << newCandidate.party << " " << newCandidate.votes << endl;
    candidates[count++] = newCandidate;

    fout.close();
    return true;
}

void viewPA_Candidate(const PollingDataPA candidates[], int count) {
    ifstream fin("PA.txt");
    if (!fin.is_open()) {
        cout << "File is not available" << endl;
        return;
    }

    cout << left << setw(25) << "Name" << setw(15) << "Constituency" << setw(20) << "Party" << setw(10) << "Votes" << endl;

    for (int i = 0; i < count; ++i) {
        cout << left << setw(25) << candidates[i].name << setw(15) << candidates[i].constituency << setw(20) << candidates[i].party << setw(10) << candidates[i].votes << endl;
    }

    fin.close();
}
