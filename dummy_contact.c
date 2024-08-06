#include "contact.h"


void initialize(AddressBook *addressBook) {
    FILE *fptr; // File pointer for opening the contacts file
    fptr = fopen("contacts.csv", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");// Print an error message if file could not be opened
        return;
    }

    char str[100]; // Buffer for reading lines from the file
    fscanf(fptr,"%[^\n]%*c",str);// Read the first line of the file (expected to contain the number of contacts)

    char *token = strtok(str+1, "#"); // Extract the number of contacts from the first line

    int num = atoi(token); // Convert the extracted string to an integer

    addressBook->contacts= malloc(num * sizeof(Contact)); // Allocate memory for the contacts

    addressBook->contactCount = num;

    int i = 0;
    while (fscanf(fptr, "%[^\n]%*c",str) != EOF && i < num) {
        
        strcpy(addressBook->contacts[i].name, strtok(str,",")); //copying the contents from file to dynamically allocated memory
        strcpy(addressBook->contacts[i].phone, strtok(NULL,","));
        strcpy(addressBook->contacts[i].email, strtok(NULL,","));
        i++;
    }

    fclose(fptr);
}


