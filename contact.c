#include "contact.h"
#include <string.h>
#include <ctype.h>

void listContacts(AddressBook *addressBook) // Function to list all contacts in the address book
{
    for (int i = 0; i < addressBook->contactCount; i++)
    { // Loop through all contacts and print their details
        printf("%32s%32s%32s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
}

void createContact(AddressBook *addressBook)
{
    addressBook->contacts= realloc(addressBook->contacts,addressBook->contactCount+1);
    getchar();
    printf("Enter the new name :"); // Read the name input
    scanf("%[^\n]", addressBook->contacts[addressBook->contactCount].name);

    char phone[20];
    while (1)
    {
        getchar();
        printf("Enter the new phone number :");
        scanf("%[^\n]", phone); // get users input
        int flag = 1;
        if (strlen(phone) != 10)
        { // Check if phone number length is 10
            flag = 0;
        }
        else
        {
            for (int i = 0; i < 10; ++i)
            {
                if (!isdigit(phone[i]))
                { // Check if all characters are digits
                    flag = 0;
                    break;
                }
            }
        }

        if (flag)
        {
            strcpy(addressBook->contacts[addressBook->contactCount].phone, phone); // if its proper ph no then create it
            break;
        }
        else
        {
            printf("Invalid phone number. Please enter a 10-digit number\n");
        }
    }

    char email[20];
    while (1)
    {
        getchar();
        printf("Enter the new mail id: ");
        scanf(" %[^\n]", email); // Read the email input

        int flag = 1;
        char *atSymbol = strchr(email, '@');  // Check for '@' in email
        char *dotCom = strstr(email, ".com"); // Check for '.com' in email

        if (atSymbol == NULL || dotCom == NULL || atSymbol == email || dotCom <= atSymbol + 1)
        {
            flag = 0; // if anything is missing make flag 0
        }

        if (flag)
        {
            strcpy(addressBook->contacts[addressBook->contactCount].email, email); // if its proper email then create it
            break;
        }
        else
        {
            printf("Invalid email. Please enter a valid email containing @ and ending with .com.\n");
        }
    }
    addressBook->contactCount = addressBook->contactCount + 1; // Increment the contact count in the address book
}

void searchContact(AddressBook *addressBook)
{
    int choice;
    char strToCompare[100];
    int i;
    printf("1.Name\n2.Phone number\n3.email id\nEnter an option to search by :"); // ask for selection
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        getchar();
        printf("Enter the name search: ");
        scanf("%[^\n]", strToCompare);

        for (i = 0; i < addressBook->contactCount; i++)
        {                                                             // Loop through all contacts to find a matching name
            if (!strcmp(strToCompare, addressBook->contacts[i].name)) // if name is found then print the details associated with that particular name
            {
                printf("\n%32s %32s %32s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                break;
            }
        }
        break;
    case 2:
        getchar();
        printf("Enter the phone number to search: ");
        scanf("%[^\n]", strToCompare);

        for (i = 0; i < addressBook->contactCount; i++)
        {
            if (!strcmp(strToCompare, addressBook->contacts[i].phone)) // if phne number is found then print the details associated with that particular name
            {
                printf("\n%32s %32s %32s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                break;
            }
        }
        break;
    case 3:
        getchar();
        printf("Enter the email.id to search: ");
        scanf("%[^\n]", strToCompare);

        for (i = 0; i < addressBook->contactCount; i++)
        {
            if (!strcmp(strToCompare, addressBook->contacts[i].email)) // if email id is found then print the details associated with that particular name
            {
                printf("\n%32s %32s %32s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                break;
            }
        }
        break;
    default:
        printf("Invalid input");
    }
}

void editContact(AddressBook *addressBook)
{
    char input = 'y';
    int choice;
    char strToCompare[100];
    int i;
    int found = 0;
    printf("1.Name\n2.Phone number\n3.email id\nEnter an option to search by :");
    scanf("%d", &choice); // Read the user's choice for search criteria
    switch (choice)
    {
    case 1:
        getchar();
        printf("Enter the name search: ");
        scanf("%[^\n]", strToCompare); // Read the name to search

        for (i = 0; i < addressBook->contactCount; i++)
        {
            if (!strcmp(strToCompare, addressBook->contacts[i].name))
            {
                printf("\n%32s %32s %32s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                found = 1;
                break;
            }
        }

        break;

    case 2:
        getchar(); // Consume newline character left in the input buffer
        printf("Enter the phone number to search: ");
        scanf("%[^\n]", strToCompare); // Read the phone number to search

        for (i = 0; i < addressBook->contactCount; i++)
        {
            if (!strcmp(strToCompare, addressBook->contacts[i].phone)) // Loop through all contacts to find a matching phone number
            {
                printf("\n%32s %32s %32s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                found = 1;
                break;
            }
        }

        break;
    case 3:

        getchar();
        printf("Enter the email.id to search: ");
        scanf("%[^\n]", strToCompare); // Read the email id to search

        for (i = 0; i < addressBook->contactCount; i++)
        {
            if (!strcmp(strToCompare, addressBook->contacts[i].email))
            {
                printf("\n%32s %32s %32s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                found = 1;
                break;
            }
        }

        break;
    }
    if (found)
    { // If a matching contact is found, allow user to edit it
        do
        {
            int sub_choice;
            getchar();
            printf("1.Name\n2.Phone number\n3.email id\nChoose a option to edit the corresponding :");
            scanf("%d", &sub_choice);
            switch (sub_choice)
            {
            case 1:
                getchar();
                printf("Enter the new name :");
                scanf("%[^\n]", addressBook->contacts[i].name);
                break;
            case 2:
                char phone[20];
                while (1)
                {
                    getchar();
                    printf("Enter the new phone number :");
                    scanf("%[^\n]", phone);
                    int flag = 1;
                    if (strlen(phone) != 10)
                    {
                        flag = 0;
                    }
                    else
                    {
                        for (int i = 0; i < 10; ++i)
                        {
                            if (!isdigit(phone[i]))
                            {
                                flag = 0;
                                break;
                            }
                        }
                    }

                    if (flag)
                    {

                        strcpy(addressBook->contacts[i].phone, phone);
                        break;
                    }
                    else
                    {
                        printf("Invalid phone number. Please enter a 10-digit number\n");
                    }
                }
                break;
            case 3:
                char email[20];
                while (1)
                {
                    getchar();
                    printf("Enter the new mail id: ");
                    scanf("%[^\n]", email);

                    int flag = 1;
                    char *atSymbol = strchr(email, '@');
                    char *dotCom = strstr(email, ".com");

                    if (atSymbol == NULL || dotCom == NULL || atSymbol == email || dotCom <= atSymbol + 1)
                    {
                        flag = 0;
                    }

                    if (flag)
                    {
                        strcpy(addressBook->contacts[i].email, email);
                        break;
                    }
                    else
                    {
                        printf("Invalid email. Please enter a valid email containing @ and ending with .com.\n");
                    }
                }
                break;
            default:
                printf("Invalid input");
            }
            getchar();
            printf("\nDo you want continue?(y/n):");
            scanf("%c", &input);
            printf("\n");
        } while (input == 'y');
    }
}

void deleteContact(AddressBook *addressBook)
{
    char strToCompare[100];
    char c;
    getchar();
    printf("Enter the name of contact to be delete : ");
    scanf("%[^\n]", strToCompare);
    int i;
    int matchFound = 0;
    int indexTobeDeleted;
    for (i = 0; i < addressBook->contactCount; i++)
    {
        if (!strcmp(strToCompare, addressBook->contacts[i].name))
        {
            matchFound++;
            if (matchFound > 1)
            {
                printf("\n Index no : %d.  %20s %32s %32s \n", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                printf("\n");
                printf(" Found %d matches,please enter index number of the contact to be deleted : ", matchFound);
                scanf("%d", &indexTobeDeleted);
            }
            else
            {
                printf("\n Index no : %d.  %20s %32s %32s \n", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                indexTobeDeleted = i;
            }
        }
    }
    getchar();
    printf("Do want to delete?\n press y/n :");
    scanf("%c", &c);
    if (c == 'y')
    {
        for (int j = indexTobeDeleted; j < addressBook->contactCount - 1; j++)
        {
            addressBook->contacts[j] = addressBook->contacts[j + 1];
        }
        addressBook->contactCount--;
    }
}


void fileSave(AddressBook *addressBook)
{
    char ch;
    printf("Do you want to save this file (Y/N): ");
    scanf(" %c", &ch); // Note the space before %c to consume any whitespace characters

    if (ch == 'Y' || ch == 'y')
    {
        FILE *fp = fopen("contacts.csv", "w+"); // open the same file in read mode and append the data
        if (fp == NULL)
        {
            printf("Error opening file\n");
            return;
        }
        int i = 0;
         fprintf(fp, "#%d#\n", addressBook->contactCount);
        printf("size of add ---> %d\n", addressBook->contactCount);
        while (i < addressBook->contactCount)
        {
            printf("%s\n",addressBook->contacts[i].name);
      
                fprintf(fp, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            i++;
        }

        printf("File has been saved successfully\n");
        fclose(fp);

        return;
    }
    else
    {
        printf("File is not saved\n");
        return;
    }
}
