#include<stdio.h>
#include<stdlib.h>
int main(){
    int n ;
    printf("Enter the Number of Processed :");
    scanf("%d", &n);
    int PID[n] , BT[n], priority[n] , ET[n] , WT[n], TAT[n] ;
    for (int i = 0 ; i<n ;i++){
        printf("Enter the ProcessID for %d process ", i+1);
        scanf("%d",&PID[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &BT[i]);
        printf("Enter priority for process %d (lower value means higher priority): ", i + 1);
        scanf("%d", &priority[i]);
    }
        for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] < priority[j + 1] || (priority[j] == priority[j + 1] && PID[j] > PID[j + 1])) {
                int temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp; 

                temp = BT[j];
                BT[j] = BT[j + 1];
                BT[j + 1] = temp;

                temp = PID[j];
                PID[j] = PID[j + 1];
                PID[j + 1] = temp;
            }
        }
    }
    ET[0] = BT[0];
    for (int i = 1; i < n; i++) {
        ET[i] = ET[i - 1] + BT[i];
    }
    for (int i = 0; i < n; i++) {
        TAT[i] = ET[i];
        WT[i] = TAT[i] - BT[i];
    }

    printf("PROCESS_ID\t, PRIORITY\t, BURST_TIME\t, WAITING_TIME\t, TURN_AROUND_TIME\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t, %d\t\t, %d\t\t, %d\t\t, %d\n", PID[i], priority[i], BT[i], WT[i], TAT[i]);
    }

    return 0;


}