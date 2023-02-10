#include <stdio.h>
#include <stdlib.h>

struct Date
{
	int jour ;
	int mois ;
	int annee;
};
typedef struct Date DATE;

struct PatientFile{
	char nom[20];
	int numTel;
	int cnam;
	int weight;
	DATE date_rendez_vous;
};
typedef struct PatientFile PATIENT_FILE;



void SasirNumberOfPatient(int *x){
	do
	{
		printf("Write The Number of Patient Today\n");
		scanf("%d",x);
	}while(x<=0);
}


void RemplissageFilePatient(int *n,struct PatientFile *PF ){
	int i=0;
	printf("File of %d Clients\n",*n);
	for(i=0;i<*n;i++){

		//Name
		printf("Write Patient %d Name:\n",i+1);
		scanf("%s" ,&PF[i].nom);

		//Phone number
		printf("Write Patient %d numTel: \n",i+1);
		scanf("%d" ,&PF[i].numTel);

		//Cnam

		do{
			printf("Is Patient %d have a CNAM:\n",i+1);
			printf("If yes type 1 else type 0\n");
			scanf("%d" ,&PF[i].cnam);
		} while(PF[i].cnam!=0 && PF[i].cnam!=1);

		//weight
		printf("Write Patient %d weight: \n",i+1);
		scanf("%d" ,&PF[i].weight);

		//date_rendez_vous
		printf("Write Patient %d date_rendez_vous: \n",i+1);
		printf("Jour= ");
		scanf("%d" ,&PF[i].date_rendez_vous.jour);
		printf("Mois= ");
		scanf("%d" ,&PF[i].date_rendez_vous.mois);
		printf("Annee= ");
		scanf("%d" ,&PF[i].date_rendez_vous.annee);


		printf("\n");
		//scanf("%s",PF[i].numTel);
	}
}

void Affichage(int *n,struct PatientFile *PF){

	int i;
	for(i=0;i<*n;i++){
		printf("Patient %d Name= %s \n",i+1,PF[i].nom);
		printf("Patient %d Number= %d \n",i+1,PF[i].numTel);
		printf("Patient %d Cnam etat= %d \n",i+1,PF[i].cnam);
		printf("Patient %d Weight= %d \n",i+1,PF[i].weight);
		printf("Patient %d Date rendezvous = %d/%d/%d \n",i+1,PF[i].date_rendez_vous.jour
		,PF[i].date_rendez_vous.mois,PF[i].date_rendez_vous.annee);
		printf("\n");
		//scanf("%s",&PF.nom);
	}

	if (*n == 0){
        printf("Patients list is empty \n\n");
	}
}

void SearchForPatient (int *n,struct PatientFile *PF){
    int phoneNumber = -1;

    printf("Please enter the patient's phone number: ");
    scanf("%d", &phoneNumber);

    int i;
    int patientFound = 0;
    for(i=0;i<*n;i++){
        if(phoneNumber == PF[i].numTel){
            patientFound = 1;
            printf("\n\nPatient found\nPatient CNAM: %d\n", PF[i].cnam);
            printf("Patient name: %s\n", PF[i].nom);
            printf("Patient phone number: %d\n", PF[i].numTel);
            printf("Patient Weight: %d\n", PF[i].weight);
            printf("Patient rendezvous Date: %d/%d/%d \n\n", PF[i].date_rendez_vous.jour, PF[i].date_rendez_vous.mois, PF[i].date_rendez_vous.annee);
        }
    }

    if (patientFound == 0){
        printf("\n\nPatient NOT found.\n\n");
    }

    system("pause");
}


int main(){

	int optionChoosed;
	int n;
	struct PatientFile PF[20];

    int exit = 0;
    while (exit == 0){
        system("cls");
        printf("=============================\n");
        printf("Welcome to Hichem's app \n");
        printf("=============================\n");
        printf(" 1: Enter patient information. \n 2: Show all patients. \n 3: Search for a patient.\n 0: Exit the application.\n");
        printf("=============================\n");
        printf("Select an option by typing the number of the option.\n");

        scanf("%d", &optionChoosed);

        switch(optionChoosed)
        {
            case 0: exit = 1; system("cls"); printf("Application Closed. \n\n"); break;
            case 1: system("cls"); SasirNumberOfPatient(&n); RemplissageFilePatient(&n,&PF); break;
            case 2: system("cls"); Affichage(&n,&PF); system("pause"); break;
            case 3: system("cls"); SearchForPatient(&n,&PF); break;
            default: system("cls"); printf("Error, please enter a valid option \n"); system("pause"); break;
        }
    }



	//SasirNumberOfPatient(&n);

	//RemplissageFilePatient(&n,&PF);

	//Affichage(&n,&PF);


	return 0;
}
