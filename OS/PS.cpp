// Write a program to implement Proiority Scheduling algorithm

#include "bits/stdc++.h"
using namespace std;
const int INF = 1e9;

struct Task {
    int arrival, burst, pri, id, wt, tot;
    bool done;
    bool operator<(Task&t) {
        if (pri != t.pri) return pri <= t.pri;
        return arrival <= t.arrival;
    }
};

int main() {
    int n;
    cout << "Enter the no of process: ";
    cin >> n;
    Task task[n];
    cout << "Enter the arrival time, burst time, priority \n";
    for (int i = 0; i < n; i++) {
        cin >> task[i].arrival >> task[i].burst >> task[i].pri;
        task[i].done = false;
        task[i].id = i + 1;
        task[i].wt = 0;
        task[i].tot = 0;
    }

    sort(task, task + n);
    int done = 0;
    vector<int> taskdone;
    for (int tim = 0;; tim++) {
        for (int t = 0; t < n; t++) {
            if (task[t].done) continue;
            if (task[t].arrival <= tim) {
                task[t].wt += tim - task[t].arrival;
                task[t].tot += tim - task[t].arrival + 1;
                task[t].burst--;
                taskdone.push_back(task[t].id);
                if (task[t].burst == 0) task[t].done = true, done++;
                break;
            }
        }
        if (done == n) break;
    }
    int tot_wt = 0, tot_tt = 0;
    for (int i = 0; i < n; i++) tot_tt += task[i].tot, tot_wt += task[i].wt;
    taskdone.erase(unique(taskdone.begin(), taskdone.end()), taskdone.end());

    cout << "Gantt Chart: |";
    for (int x : taskdone) cout << " P" << x << " | ";
    cout << '\n';

    cout << "Avg wt time: " << (double)tot_wt / n << '\n';
    cout << "Avg turnaround time: " << (double)tot_tt / n << '\n';
}