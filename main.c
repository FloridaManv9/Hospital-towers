#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
/*
 * COP 3515 – Fall Semester, 2020
 *
 * Homework #3: Go Green, Go Home
 *
 * (Matthew Signore)
 *
 */

/* This structure stores the data for each patient in the hospital or at home */
struct patient{
    char gender;
    int number;
    char color;
    int age;
    int timer;
    bool gottenBetter;
    int daysLeft;
};


int main() {
    void escalateSeverity (int patientNum, struct patient im[]);
    int *counter(int *counter[5], struct patient im[]);
    struct patient patients[100];
    FILE *file;
    char string[30];
    int count = 0;
    char gender;
    char tempNumber[2];
    file = fopen("C:\\Users\\polan\\CLionProjects\\homework3\\data.txt", "r");


    /* This takes in the data file and assigns the data to the patient structure for each patient */
    while  (fgets(string, 30, file)){
       patients[count].gender = string[0];
       patients[count].number = count;
       patients[count].color = string[2];
       patients[count].gottenBetter = false;
       patients[count].timer = 3;

       tempNumber[0]  = string[4];
       tempNumber[1] = string[5];
       patients[count].age = atoi(tempNumber);


       count++;
    }
    /* This is the loop for each day that handles the calling of severity functions and printing the daily data*/
    for (int x = 1; x <=100; x++){
        printf("Today is day %d \n Format is Color/Gender \n Floor 1:", x);
        int floor = 2;
        int floorcount = 0;
        for (int y = 0; y <= 99; y++){
            escalateSeverity(y, patients);
            if (patients[y].color != 'O') {
                printf(" %c-%c", patients[y].color, patients[y].gender);
            }
            else {printf(" *-* ");
            }
            floorcount++;
            if (floorcount == 10 && floor != 11){
                printf("\n Floor %i:", floor);
                floor++;
                floorcount = 0;
            }

        }
        int *countArray[5];
        setbuf(stdout, 0);
        *countArray = counter(countArray, patients);
        /* This is printing the current status of all patients */
        printf(" \n %d patients have been sent home, %d are in Green, %d are in Yellow, %d are in Red, %d are in Purple \n",
               (int)countArray[0], (int)countArray[1], (int)countArray[2], (int)countArray[3], (int)countArray[4]);
        /* This checks if the patients are all home  */
        if ((int)countArray[0] == 100){
            break;
        }
        printf("Enter 'N' for the next day");
        char c;
        setbuf(stdin, 0);
        scanf("%c", &c);
    }


    printf("All patients have been released! \n");
    return 0;
}

/* This function takes in the patient struct and current patient # and assesses if they will stay the same
 * get worse, or get better and saves this data in the patient array*/

void escalateSeverity(int patientNum, struct patient im[]) {
    char severity;
    int randNum;
    severity = im[patientNum].color;
    switch (severity) {
        case 'G': /* This is for patients that are currently green */
            if (im[patientNum].timer != 0) {
                im[patientNum].timer--;
            }
            else {
                randNum = rand() % 100;
                if (randNum > 25){
                    im[patientNum].color = 'O';
                }
                else if (im[patientNum].gottenBetter == false){
                    randNum = rand() % 100;
                    if (randNum > 50){
                        im[patientNum].timer = 3;
                        im[patientNum].color = 'Y';
                    }
                }
            }
            break;
        case 'Y': /* This is for patients that are currently yellow*/
            if (im[patientNum].timer != 0) {
                im[patientNum].timer--;
            }
            else {
                randNum = rand() % 100;
                if (randNum > 40){
                    im[patientNum].color = 'G';
                    im[patientNum].gottenBetter = true;
                }
                else if (im[patientNum].gottenBetter == false){
                    randNum = rand() % 100;
                    if (randNum > 60){
                        im[patientNum].timer = 3;
                        im[patientNum].color = 'R';
                    }
                }
            }
            break;
                case 'R': /* This is for patients who are currently red */
                    if (im[patientNum].timer != 0) {
                        im[patientNum].timer--;
                    }
                    else {
                        randNum = rand() % 100;
                        if (randNum > 60){
                            im[patientNum].color = 'Y';
                            im[patientNum].gottenBetter = true;
                        }
                        else if (im[patientNum].gottenBetter == false){
                            randNum = rand() % 100;
                            if (randNum > 80){
                                im[patientNum].timer = 3;
                                im[patientNum].color = 'P';
                            }
                        }
                    }
                break;
                case 'P': /* This is for patients who are currently purple*/
                    if (im[patientNum].timer != 0) {
                        im[patientNum].timer--;
                    }
                    else {
                        randNum = rand() % 100;
                        if (randNum > 70){
                            im[patientNum].color = 'R';
                            im[patientNum].gottenBetter = true;
                        }
                    }
                break;
                default:
                    break;

            }
    }
/* This function is for returning the current count of the status of each patient in the hosptial,
 * and returns this data as an integer array*/
int *counter(int *counter[5], struct patient im[]) {
        int hCounter = 0;
        int gCounter = 0;
        int yCounter = 0;
        int rCounter = 0;
        int pCounter = 0;

        for (int x = 0; x < 100; x++) {
            switch (im[x].color) {
                case 'O':
                    hCounter++;
                    break;
                case 'G':
                    gCounter++;
                    break;
                case 'Y':
                    yCounter++;
                    break;
                case 'R':
                    rCounter++;
                    break;
                case 'P':
                    pCounter++;
                    break;
            }
        }
    /* Taking the temp variables into the int array*/
    counter[0] = (int *) hCounter;
        counter[1] = (int *) gCounter;
        counter[2] = (int *) yCounter;
        counter[3] = (int *) rCounter;
        counter[4] = (int *) pCounter;
        return *counter;
    }
