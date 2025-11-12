#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int PID[n], AT[n], BT[n], WT[n], TAT[n],ET[n];

    for (int i = 0; i < n; i++) {
        printf("Enter process ID for process %d: ", i + 1);
        scanf("%d", &PID[i]);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &AT[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &BT[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (BT[j] > BT[j + 1] || BT[j] == BT[j + 1] && AT[j] > AT[j + 1]) {
                int temp = AT[j];
                AT[j] = AT[j + 1];
                AT[j + 1] = temp;

                temp = BT[j];
                BT[j] = BT[j + 1];
                BT[j + 1] = temp;

                temp = PID[j];
                PID[j] = PID[j + 1];
                PID[j + 1] = temp;
            }
        }
    }
    ET[0] = AT[0]+BT[0];
    for(int i = 1; i < n ;i++){
        if (ET[i-1] < AT[i]){
            ET[i] = AT[i] + BT[i];       
        }
        else{
            ET[i] = ET[i-1] + BT[i];
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        TAT[i] = ET[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }
    printf("PROCESS_ID\t, ARRIVAL_TIME\t, BURST_TIME\t, WAITING_TIME\t, TURN_AROUND_TIME\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t, %d\t\t, %d\t\t, %d\t\t, %d\n", PID[i], AT[i], BT[i], WT[i], TAT[i]);
    }
    return 0;

}
