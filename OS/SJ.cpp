// Experiment - Write a program to implement shortest job CPU scheduling algorithm

#include <stdio.h>
#include <stdlib.h>

int getNextProcess(int *arrivalTimes, int *isProcessCompleted, int *bustTimes, int clock, int numberOfProcesses){
    if (clock == -1) { // the first process is the one which arrived first, irrespective of its burst time
        int min = 0;
        for (int i = 0; i < numberOfProcesses; i++){
            if (arrivalTimes[i] < arrivalTimes[min]) min = i;
        }
        return min;
    }
    int min = 0;
    while (isProcessCompleted[min]) min++;
    if (min >= numberOfProcesses) return -1;
    for (int i = min; i < numberOfProcesses; i++){
        if (isProcessCompleted[i] || arrivalTimes[i] > clock){ // process has not yet arrived or it is already completed
            continue;
        }
        if (bustTimes[i] < bustTimes[min]) min = i;
    }
    return min;
}

void findAverageTimes(int *arrivalTimes, int *bustTimes, int numberOfProcesses){
    int *completionTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *turnAroundTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *waitingTimes = (int *)calloc(numberOfProcesses, sizeof(int));
    int *isProcessCompleted = (int *)calloc(numberOfProcesses, sizeof(int));
    int clock = -1;
    int process = getNextProcess(arrivalTimes, isProcessCompleted, bustTimes, clock, numberOfProcesses);
    clock = arrivalTimes[process];
    while (process != -1){
        waitingTimes[process] = clock - arrivalTimes[process];
        clock += bustTimes[process];
        completionTimes[process] = clock;
        turnAroundTimes[process] = waitingTimes[process] + bustTimes[process];
        isProcessCompleted[process] = 1;
        process = getNextProcess(arrivalTimes, isProcessCompleted, bustTimes, clock, numberOfProcesses);
    }
    float averageWaitingTime = 0;
    float averageTurnaroundTime = 0;
    for (int i = 0; i < numberOfProcesses; i++){
        averageWaitingTime += waitingTimes[i];
        averageTurnaroundTime += turnAroundTimes[i];
    }
    averageTurnaroundTime /= numberOfProcesses;
    averageWaitingTime /= numberOfProcesses;
    // display the data
    printf("PID\tAT\tBT\tComp\tTA\tWT\n");
    for (int i = 0; i < numberOfProcesses; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrivalTimes[i], bustTimes[i],
               completionTimes[i], turnAroundTimes[i], waitingTimes[i]);
    }
    printf("\nAverage Waiting Time: %0.2f\n", averageWaitingTime);
    printf("Average Turn Around Time: %0.2f\n", averageTurnaroundTime);
    free(completionTimes);
    free(turnAroundTimes);
    free(waitingTimes);
    free(isProcessCompleted);
}

int main(){
    int arrivalTime[5] = {1, 2, 3, 4, 5};
    int bustTime[5] = {7, 5, 1, 2, 8};
    findAverageTimes(arrivalTime, bustTime, 5);
    return 0;
}