# Project Structure

```.
├── include/                 # Blueprints: All Header Files (.h)
│   ├── auth/                # registration.h, user_info.h
│   ├── core/                # globals.h
│   ├── models/              # classes.h (Transaction, Expense, Income)
│   ├── utils/               # math_utils.h, datetime.h, text_utils.h, templates.h
│   └── validation/          # validation.h
│
├── src/                     # The Engine: Core C++ Logic (.cpp)
│   ├── auth/                # registration.cpp, user_info.cpp
│   ├── core/                # globals.cpp, main.cpp
│   ├── models/              # classes.cpp
│   ├── utils/               # math_utils.cpp, datetime.cpp, text_utils.cpp
│   └── validation/          # validation.cpp
│
├── native/                  # The Translator: JavaScript-to-C++ Bridge
│   └── bridge/              # validation_bridge.cpp
│
├── web/                     # The Dashboard: Node.js & UI
│   ├── public/              # CSS, Images, Client-side JS
│   └── views/               # EJS Templates
│
├── bin/                     # Compiled binaries
├── Makefile                 # Build instructions
└── README.md                # Project documentation
```

### The Path of a "Click"

1. UI: User clicks "Add Expense."
2. Browser: Sends the form data (Name, Amount) to your Node.js server.
3. Node.js: Calls your bridgeAddExpense function.
4. Bridge: Converts the data and calls `new Expense()`.
5. Database: The bridge calls your new `DatabaseManager` to save it.
6. Response: Node.js sends a "Success!" message back to the UI.
