# Phonebook

A simple console-based phonebook application written in C. It allows users to store, search, modify, and delete personal contact records using binary file storage.

---

## Features

- **Add Contact** — Save a new contact with full personal details
- **List Contacts** — View all stored contacts one by one
- **Search Contact** — Find a contact by name
- **Modify Contact** — Update an existing contact's information
- **Delete Contact** — Remove a contact record by name
- **Persistent Storage** — All records are saved to a binary file (`project`) and retained between sessions

---

## Contact Record Fields

Each contact stores the following information:

| Field          | Description                  |
|----------------|------------------------------|
| Name           | Full name (up to 35 chars)   |
| Address        | Home address (up to 50 chars)|
| Father's Name  | Father's name (up to 35 chars)|
| Mother's Name  | Mother's name (up to 30 chars)|
| Mobile Number  | Phone number (long int)      |
| Sex            | Gender (up to 8 chars)       |
| Email          | Email address (up to 100 chars)|
| Citizenship No | ID/citizenship number        |

---

## Requirements

- **OS:** Windows (uses `<windows.h>`, `<conio.h>`, and `system()` calls)
- **Compiler:** Any C compiler supporting the C standard library (e.g., GCC via MinGW, Turbo C, or MSVC)

---

## How to Compile

Using GCC (MinGW on Windows):

```bash
gcc phonebook.c -o phonebook.exe
```

Then run:

```bash
phonebook.exe
```

---

## Usage

On launch, a menu is displayed. Press the corresponding number key to perform an action — **no Enter key needed**:

```
**********WELCOME TO PHONEBOOK*************

            MENU

    1. Add New      2. List     3. Exit
    4. Modify       5. Search   6. Delete
```

Navigate using keys `1`–`6`. After each operation, you are returned to the main menu automatically.

---

## File Storage

Records are stored in a binary file named `project` in the same directory as the executable. This file is created automatically when the first contact is added.

> Do not manually edit or rename the `project` file, as it stores data in raw binary format.

---

## Known Limitations

- The application is **Windows-only** due to its use of `<conio.h>` and `system("cls")` / `system("color")`.
- The search and delete operations use **exact name matching** (case-sensitive).
- Mobile number is stored as `long int`, which may not suit all phone number formats.

---

## Project Structure

```
phonebook/
├── phonebook.c   # Main source file containing all logic
├── project       # Binary data file (auto-generated at runtime)
└── README.md
