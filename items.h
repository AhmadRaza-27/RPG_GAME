#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <limits> //clear input buffer
#include <list>
#include <cctype>
#include <algorithm>
#include <cstdlib>  // For rand() and srand()
#include <iomanip> //The following three libraries are for print centered.
#include <string>
#include <windows.h> // For Windows terminal width (if applicable)

void sleepFor(int milliseconds);
using namespace std;

#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    float weight;  // Ensure weight is of type float

    Item(string n, float w) : name(n), weight(w) {}

    virtual ~Item() {}
};

class Potions : public Item {
public:
    int health;
    int defense;

    // Default constructor
    Potions() : Item("", 0.0f), health(0), defense(0) {}

    // Parameterized constructor
    Potions(string n, float w, int h, int d) : Item(n, w), health(h), defense(d) {}
};

class Wands : public Item {
public:
    int casting_speed;
    int defense;

    // Default constructor
    Wands() : Item("", 0.0f), casting_speed(0), defense(0) {}

    // Parameterized constructor
    Wands(string n, float w, int c, int d) : Item(n, w), casting_speed(c), defense(d) {}
};

class Cloak : public Item {
public:
    int resistance;
    int stealth;

    // Default constructor
    Cloak() : Item("", 0.0f), resistance(0), stealth(0) {}

    // Parameterized constructor
    Cloak(string n, float w, int r, int s) : Item(n, w), resistance(r), stealth(s) {}
};

class MagicalRings : public Item {
public:
    int power;
    int luck;

    // Default constructor
    MagicalRings() : Item("", 0.0f), power(0), luck(0) {}

    // Parameterized constructor
    MagicalRings(string n, float w, int p, int l) : Item(n, w), power(p), luck(l) {}
};


// Function to print text centered
void printCentered(const string& text) {
    int width = 200; // Assuming 80-character wide console
    int padding = (width - text.length()) / 2;
    string spaces(padding, ' '); // Create a string of spaces to pad text
    cout << spaces << text << endl;
}

void availableItems() {
    // Print the heading centered
    printCentered("ITEMS YOU CAN ADD TO THE INVENTORY:");
    sleepFor(500); // Delay for 500ms

    // Potions
    printCentered("Potions: ");
    sleepFor(300); // Delay for 300ms
    printCentered("1. Elixir of Life.");
     
    printCentered("2. Guardian's Draught.");
    
    printCentered("3. Elixir of the Moonlit Veil");
  
    printCentered("4. Flameheart Draught");
   
    printCentered("5. Vial of Eternal Twilight\n");
    sleepFor(300);
    

    // Wands
    printCentered("Wands: ");
    sleepFor(300); // Delay for 300ms
    printCentered("1. Elder Wand");
  
    printCentered("2. Phoenix Wand.");
   
    printCentered("3. Soulbinder's Cane.");
   
    printCentered("4. Owl Wand");
  
    printCentered("5. Glistening Wand. \n");
    sleepFor(500); // Delay for 500ms

    // Cloaks
    printCentered("Cloaks: ");
    sleepFor(300); // Delay for 300ms
    printCentered("1. Shadow Cloak.");
  
    printCentered("2. Elixir Cloak.");
 
    printCentered("3. Armour Cloak.");
  
    printCentered("4. Invisibility Cloak. \n");
    sleepFor(300); // Delay for 500ms

    // Magical Rings
    printCentered("Magical Rings: ");
    sleepFor(300); // Delay for 300ms
    printCentered("1. Ring of Eternity.");
    
    printCentered("2. Fate's Band.");
 
    printCentered("3. Charm of Luck.");
 
    printCentered("4. Destiny's Ring.");

    printCentered("5. Soul-binding Ring.");
    sleepFor(300); // Delay for 500ms

    cout << endl;
}
void sleepFor(int milliseconds) {
    Sleep(milliseconds);
}