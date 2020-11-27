#include <stdio.h>
#include "Controllers.h"
#include <string.h>
int main()
{
    patient* pq;
    int total_patient, total_cure;
    char input[255];
    char cmonth[255];
    int day, month, year;
    scanf("%d %d", &total_patient, &total_cure);
    int age[total_patient+1];
    char patientdata[total_patient+1][255];
    for(int i = 0; i < total_patient; i++)
    {
        int flag = 0;
        scanf("%d %s %d -  %[^\n]", &day, cmonth, &year, input);
        month = checkmonth(cmonth);
        age[i] = countage(day, month, year, 27, 11, 2020);
        strcpy(patientdata[i], input);
        pushMid(input, cmonth, day, year, age[i]);
    }
    for(int i = 0; i < total_cure; i++)
    {
        popHead();
    }
    showCured(total_patient-total_cure, total_patient);
    return 0;   
}
