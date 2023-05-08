#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int profit;
    int deadline;
};

bool compare(Job j1, Job j2) {
    return j1.profit > j2.profit;
}

void scheduleJobs(Job jobs[], int n) {
    sort(jobs, jobs + n, compare);
    
    int result[n];
    bool slots[n];
    
    for (int i = 0; i < n; i++) {
        slots[i] = false;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slots[j] == false) {
                result[j] = i;
                slots[j] = true;
                break;
            }
        }
    }
    
    cout << "Scheduled Jobs:" << endl;
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        if (slots[i]) {
            cout << "Job " << jobs[result[i]].id << " (Profit: " << jobs[result[i]].profit << ")" << endl;
            totalProfit += jobs[result[i]].profit;
        }
    }
    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    
    Job jobs[n];
    
    cout << "Enter the profit and deadline for each job:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ":" << endl;
        cout << "Profit: ";
        cin >> jobs[i].profit;
        cout << "Deadline: ";
        cin >> jobs[i].deadline;
        jobs[i].id = i + 1;
    }
    
    scheduleJobs(jobs, n);
    
    return 0;
}
