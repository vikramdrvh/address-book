# Address Book in C

This is a custom C implementation of a command-line Address Book application. It provides a lightweight, modular system for managing contact information and persisting data to a local file.

## Core Features
* **Contact Management:** Handles the core logic for organizing and manipulating contact records via `contact.c`.
* **Data Persistence:** Stores and retrieves contact information using a standard CSV file format (`contacts.csv`), ensuring data is saved between application sessions.
* **Testing Utility:** Includes a `dummy_contact.c` file to easily populate the address book with mock data for testing and development.
* **Modular Architecture:** Separates data structures and function declarations (`contact.h`) from the primary application loop (`main.c`).
