# Hospital-towers

The Covid-19 pandemic rages in in Florida. The work that you've been able to do for Tampa General so 
far has been appreciated. However, they have now discovered that they need additional help from you. 
The challenge that they are facing is that they have too many patients and not enough beds. 
When Covid-19 patents show up at the hospital, they can be at various stages of the disease. The initial 
stage ("green") means that the patient has a raspy cough, and feels weak overall. The next stage 
("yellow") happens when the patent starts to have headaches, new loss of taste or smell, nausea or 
vomiting, and diarrhea. The next stage ("red") occurs when they start to have trouble breathing, 
persistent pain or pressure in the chest, new confusion, inability to wake or stay awake, or bluish lips or 
face. The final stage, the most serious stage ("purple"), occurs when the patient can no longer breathe 
by themselves and need the help of a ventilator to breathe.  
Patients who arrive at Tampa General can be at any one of these stages. They'll be given a bed if one is 
available or shipped to another hospital if one is not available. While they are at the hospital their status 
can change on a day-by-day basis. Here's the probability of a patient at one stage transitioning to the 
next stage of severity: 
Green  Yellow  Red  Purple 
50  40  20   
 
Assume that when all patients check into the hospital, they are currently getting worse. Each time a 
patient gets worse, assume that they will either stay the same or get worse for the next three days – 
they won't get better during this time. Note that when a purple patient enters the hospital, they will 
automatically stay in the purple state for 3 days. After three days, you can once again check to see if 
they are starting to get better. 
   
 
If a patient does not get worse, they have then started to get better. Once people start to get better, 
they cannot become worse again. Here's the probability of a patient at one stage transitioning to the 
previous stage of severity: 
Green  Yellow  Red  Purple 
75  60  40  30 
 
You are to write a program that will process a data file that contains patient information. The hospital 
has 100 Covid-19 beds that can be used. When a patient shows up, place them in a bed and note what 
stage they are at. Each day generate a random number to determine if they have gotten worse. If they 
have gotten worse then update their status color. If they have not gotten worse, then generate another 
random number to determine if they have gotten better. If they have gotten better then update their 
status color. If they were a green patient and they got better, discharge them from the hospital. 
The format of the data in the data file will be as follows: 
Sex, Covid-19 status (G/Y/R/P), age 
After all of the data has been processed at the end of each day, you should print out (1) the status of all 
of the beds in the hospital – G/Y/R/P/. and (2) the gender of each patient in a bed in the hospital – M/F/.  
You should also print out the following statistics: 
1. Current number of patients who are in the Green status. 
2. Current number of patients who are in the Yellow status. 
3. Current number of patients who are in the Red status. 
4. Current number of patients who are in the Purple status. 
5. Your program should run until all of the Covid-19 patients have gone home. 
 
Note: As C does not have an inbuilt function for generating a number in the range, but it does have rand 
function which can generate a random number from 0 to RAND_MAX. With the help of rand () a number 
in range can be generated as num = (rand() % (upper – lower + 1)) + lower An example of using this 
would be: 
probEscalateSeverity = (rand() % 100; 
and a value > 50 would mean that a patient would move from green to yellow. 
 
