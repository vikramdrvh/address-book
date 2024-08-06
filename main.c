#include "contact.h"
#include<stdlib.h>

int main()
{
    int choice;

    AddressBook addressBook; //declaring a structure variable

    initialize(&addressBook);


    do{
		
	printf("\nAddress Book Menu \n1.Create contact\n2.Search Contact\n3.Edit contact\n4.Delete contact\n5.List all the contact\n6.Exit\n\nEnter your choice: ");
	scanf("%d",&choice);


	switch (choice) {
	    case 1: createContact(&addressBook);
		    break;
	    case 2: searchContact(&addressBook);
		    break;
	    case 3: editContact(&addressBook);
		    break;
        case 4: deleteContact(&addressBook);
		    break;
        case 5: listContacts(&addressBook);
		    break;
		case 6: fileSave(&addressBook);
		break;
	    default: printf("Enter a vaild option 1 to 6\n");
	}

}while(choice !=6);

}

