// Experiment - Write a program to implement CPU scheduling for First Come First Serve

#include "bits/stdc++.h"
using namespace std;

void findwaitingtime(int processes[], int n, int at[], int bt[], int wt[]){
    wt[0] = 0;
    for(int i = 1; i < n; i++)
        wt[i] = (at[i - 1] + bt[i  -1] + wt[i - 1] - at[i]);
}

void findturnaroundtime(int processes[], int n, int bt[], int wt[], int tat[]){
    for(int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgtime(int processes[], int n, int at[], int bt[]){
    int wt[n];
    int tat[n];
    int total_wt = 0;
    int total_tat = 0;
    findwaitingtime(processes, n, at, bt, wt);
    findturnaroundtime(processes, n, bt, wt, tat);

    cout << "First Come First Serve Scheduling Algorithm" << "\n";
    cout << "PID" << "\t"  << "AT" << "\t" << "BT" << "\t" << "WT" << "\t" << "TAT" << "\n";
    for(int i = 0; i < n; i++){
        int idx = i + 1;
        total_wt += wt[i];
        total_tat += tat[i];
        cout << idx << "\t" << at[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }
    cout << "Average Waitng Time = " << (double)total_wt/(double)n << "\n";
    cout << "Average Turn Around Time = " << (double)total_tat/(double)n << "\n";
}

signed main(){
    int processes[] = {1, 2, 3, 4, 5};
    int arrival_time[] = {0, 1, 2, 3, 4};
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {4, 3, 1, 2, 5};
    findavgtime(processes, n, arrival_time, burst_time);
    return 0;
}