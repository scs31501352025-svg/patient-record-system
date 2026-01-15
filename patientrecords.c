/*SCS3/150165/2025-KELCEY
SCS3/150436/2025-FAITH
SCS3/9695/2025-GABRIEL
SCS3/150135/2025-SAMUEL*/
#include<stdio.h>



void addPatient() {
    FILE *fp;
    int patientNo, age;
    char name[50], gender[10], disease[50];
    char filename[60];

    printf("Enter Patient Number: ");
    scanf("%d", &patientNo);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Gender: ");
    scanf(" %[^\n]", gender);

    printf("Enter Age: ");
    scanf("%d", &age);

    printf("Enter Disease: ");
    scanf(" %[^\n]", disease);


    sprintf(filename, "%s.txt", name);

    fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error saving patient details!\n");
        return;
    }

    fprintf(fp, "Patient Number: %d\n", patientNo);
    fprintf(fp, "Patient Name: %s\n", name);
    fprintf(fp, "Gender: %s\n", gender);
    fprintf(fp, "Age: %d\n", age);
    fprintf(fp, "Disease: %s\n", disease);

    fclose(fp);

    printf("Patient details saved successfully!\n");
}

void viewpatient() {
    FILE *fp;
    char pname[50];
    char filename[60];
    char line[100];

    printf("Enter Patient Name to View Details: ");
    scanf(" %[^\n]", pname);


    sprintf(filename, "%s.txt", pname);

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Patient record not found!\n");
        return;
    }

    printf("\n--- Patient Details ---\n");
    while(fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp);
}
int main()
{
    int choice;
    do
    {
       printf("\n---PATIENTS DETAILS---\n");
       printf("1.Add patient's details\n");
       printf("2.View patient's details\n");
       printf("3.Exit\n");
       printf("Enter your choice: \n");
       scanf(" %d",&choice);

       switch(choice)
       {
       case 1:
        addPatient();
        break;
       case 2:
        viewpatient();
        break;
       case 3:
        printf("Exiting...\n");
        break;
       default:
        printf("Invalid choice!Try again\n");
       }
    }while(choice!=3);
}
