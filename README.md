
```markdown
## Blood Bank Management System

This project is a Blood Bank Management System implemented in C++. It allows users to manage donor records, track blood inventories, and perform various operations such as adding new donors, searching for existing donors, modifying donor information, and deleting donor records.

## Features

- Add new donors and store their details.
- Search for existing donors using their ID.
- Modify donor information.
- Delete donor records.
- Display a table of all donor records.
- Print a certificate of appreciation for donors.
- Calculate and display the date a donor can next donate blood.
- Refresh and display the blood inventory database.

## Project Structure

- `main.cpp`: The main implementation file containing all the code for the project.
- `donorlist.txt`: A text file used to store donor information.
- `login_page2.txt`: A text file containing login credentials for accessing the system.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++)

### Compiling the Program

To compile the program, run the following command:

```bash
g++ main.cpp -o blood_bank
```

### Running the Program

After compiling, you can run the program with:

```bash
./blood_bank
```

## Usage

Upon running the program, you will be prompted to log in with a username and password. Ensure that the credentials are available in `login_page2.txt`.

After a successful login, you can choose from various options:

1. **Add New Donor**: Enter the donor's details to add them to the database. A certificate of appreciation will be printed, and the next eligible donation date will be calculated.
2. **Search for Donor**: Search for a donor by their ID and display their details.
3. **Modify Donor Information**: Modify the information of an existing donor by their ID.
4. **Delete Donor Record**: Delete a donor's record from the database by their ID.
5. **Buy Blood**: This feature is reserved for future implementation.
6. **Exit**: Exit the program.
7. **Refresh Database**: Refresh the blood inventory database and display the updated inventory.
8. **Print Table**: Display a table of all donor records.
9. **Modify Data**: Alias for modifying donor information.
10. **Delete Donor**: Alias for deleting a donor record.

## File Descriptions

- `main.cpp`: Contains the main logic for the Blood Bank Management System.
- `donorlist.txt`: Stores donor information in a structured format.
- `login_page2.txt`: Contains usernames and passwords for logging into the system.

## Acknowledgements
- C++ standard library for various functionalities.
