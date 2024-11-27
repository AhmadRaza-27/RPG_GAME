#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <list>
#include <cctype>
#include <algorithm>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include "items.h"
#include "sorting.h"
#include "inventory.h"
using namespace std;




void makelower(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

int randomNumber() {
    return rand() % 100 + 1;  
}
// Random functions
float randomFloat() {
    return rand() % 100 + 1 + static_cast<float>(rand()) / RAND_MAX;  // Generate a float
}



class Game {
public:
    Inventory &inv;
    string correct;
    string guess;
    int score;

    Game(Inventory& inventory) : inv(inventory), score(0) {}
    
    void print_ascii_final() {
    // Define the ASCII art as a vector of strings
    vector<string> ascii_art = {
        "/ ___/ _ \\| \\ | |/ ___|  _ \\    / \\|_   _| | | | |      / \\|_   _|_ _/ _ \\| \\ | / ___|| |",
        "| |  | | | |  \\| | |  _| |_) |  / _ \\ | | | | | | |     / _ \\ | |  | | | | |  \\| \\___ \\| |",
        "| |__| |_| | |\\  | |_| |  _ <  / ___ \\| | | |_| | |___ / ___ \\| |  | | |_| | |\\  |___) |_|",
        "_\\____\\___/|_| \\_|\\____|_| \\_\\/_/ __\\_\\_| _\\___/|_____/_/   \\_\\_| |___\\___/|_| \\_|____/(_)",
        "\\ \\ / / _ \\| | | | \\ \\      / / _ \\| \\ | | |                                               ",
        " \\ V / | | | | | |  \\ \\ /\\ / / | | |  \\| | |                                               ",
        "  | || |_| | |_| |   \\ V  V /| |_| | |\\  |_|                                               ",
        "  |_| \\___/ \\___/     \\_/\\_/  \\___/|_| \\_(_)                                              "
    };

    // Print each line of the ASCII art centered
    for (const string& line : ascii_art) {
        printCentered(line);  // Assuming an 80-character wide terminal
    }
 }

    // Comparison functions for sorting Potions
    bool static compareByHealth(const Potions& a, const Potions& b) {
        return a.health < b.health;
    }

    bool static compareByDefense(const Potions& a, const Potions& b) {
        return a.defense < b.defense;
    }

    bool static compareWandByCastingSpeed(const Wands& a, const Wands& b) {
    return a.casting_speed < b.casting_speed;  // Ascending by casting speed
   }

    bool static compareWandByDefense(const Wands& a, const Wands& b) {
    return a.defense < b.defense;  // Ascending by defense
    }

  bool static compareCloakByResistance(const Cloak& a, const Cloak& b) {
        return a.resistance < b.resistance;
    }

    static bool compareCloakByStealth(const Cloak& a, const Cloak& b) {
        return a.stealth < b.stealth;
    }

    static bool compareRingByPower(const MagicalRings& a, const MagicalRings& b) {
    return a.power < b.power; // Ascending order by power
    }

    static bool compareRingByLuck(const MagicalRings& a, const MagicalRings& b) {
    return a.luck < b.luck; // Ascending order by luck
    }

   void level1() {
    cout << "Your score is: " << score << endl;
    cout << endl;
    inv.displayPotions();  // Assuming displayPotions() is defined in your PotionInventory class
    cout << endl;

    cout << "Choose between bubble, selection, insertion sort, quick or merge sort" << endl;
    getline(cin, guess);
    makelower(guess);
    system("cls");
    
    if (guess != "bubble" && guess != "selection" && guess != "insertion" && guess != "quick" && guess != "merge") {
    cout << "Error: Invalid choice! You must choose one of the following sorting algorithms: 'bubble', 'selection', 'insertion', 'quick', or 'merge'." << endl;
    return;
    }
    
    if (inv.potions.size()==0) {
    	cout<<"Fill your potions first!"<<endl;
    	return;
	}

    if (inv.potions.size() <= 20) {
        // For smaller inventory, ask for basic sorting methods (Bubble, Insertion, Selection)
        vector<Potions> sortedPotions = inv.potions; // Copy potions directly

        string ans;
        cout << "By which attribute do you want your potions to be sorted? Health or defense?" << endl;
        getline(cin, ans);
        system("cls");

        if (ans == "health") {
            correct = compareSortingAlgorithmsLevel1(sortedPotions, guess, compareByHealth);
            if (guess == correct) {
                cout << "You move to round 2" << endl;
                score += 10;
            } else {
                cout << "You failed this level. Better luck for round 2" << endl;
            }

            // Sorting based on basic algorithms
            if (guess == "bubble") {
                bubbleSort(sortedPotions, compareByHealth);
            } else if (guess == "insertion") {
                insertionSort(sortedPotions, compareByHealth);
            } else if (guess == "selection") {
                selectionSort(sortedPotions, compareByHealth);
            }

            // Display sorted potions before clearing the screen
            cout << "Sorted Potions by Health:" << endl;
            for (int i = 0; i < sortedPotions.size(); i++) {
                cout << "Name: " << sortedPotions[i].name
                     << ", Health: " << sortedPotions[i].health
                     << ", Defense: " << sortedPotions[i].defense << endl;
            }
            // Wait before clearing the screen
            sleep(3);  // Optional: Use sleep to allow the user to read the sorted potions

        } else if (ans == "defense") {
            correct = compareSortingAlgorithmsLevel1(sortedPotions, guess, compareByDefense);
            if (guess == correct) {
                cout << "Congrats! You won this level. You move to round 2" << endl;
                score += 10;
            } else {
                cout << "You failed this level. Better luck for round 2" << endl;
            }

            // Sorting based on basic algorithms
            if (guess == "bubble") {
                bubbleSort(sortedPotions, compareByDefense);
            } else if (guess == "insertion") {
                insertionSort(sortedPotions, compareByDefense);
            } else if (guess == "selection") {
                selectionSort(sortedPotions, compareByDefense);
            }

            // Display sorted potions before clearing the screen
            cout << "Sorted Potions by Defense:" << endl;
            for (int i = 0; i < sortedPotions.size(); i++) {
                cout << "Name: " << sortedPotions[i].name
                     << ", Health: " << sortedPotions[i].health
                     << ", Defense: " << sortedPotions[i].defense << endl;
            }
            // Wait before clearing the screen
            sleep(7);  // Optional: Use sleep to allow the user to read the sorted potions

        } else {
            cout << "Invalid attribute" << endl;
        }
    } else if (inv.potions.size() > 20) {
        // For larger inventory, ask for advanced sorting methods (Quick, Merge)
        vector<Potions> sortedPotions = inv.potions; // Copy potions directly

        string ans;
        cout << "By which attribute do you want your potions to be sorted? Health or defense?" << endl;
        getline(cin, ans);

        if (ans == "health") {
            correct = compareAdvancedSortingAlgorithmsLevel1(sortedPotions, guess, compareByHealth);
            if (guess == correct) {
                cout << "Congrats! You won this level. You move to round 2" << endl;
                score += 10;
            } else {
                cout << "You failed this level. Better luck for round 2" << endl;
            }

            // Sorting based on advanced algorithms
            if (guess == "quick") {
                quickSort(sortedPotions, 0, sortedPotions.size() - 1, compareByHealth);
            } else if (guess == "merge") {
                mergeSort(sortedPotions, 0, sortedPotions.size() - 1, compareByHealth);
            }

            // Display sorted potions before clearing the screen
            cout << "Sorted Potions by Health:" << endl;
            for (int i = 0; i < sortedPotions.size(); i++) {
                cout << "Name: " << sortedPotions[i].name
                     << ", Health: " << sortedPotions[i].health
                     << ", Defense: " << sortedPotions[i].defense << endl;
            }
            // Wait before clearing the screen
            sleep(3);  // Optional: Use sleep to allow the user to read the sorted potions

        } else if (ans == "defense") {
            correct = compareAdvancedSortingAlgorithmsLevel1(sortedPotions, guess, compareByDefense);
            if (guess == correct) {
                cout << "Congrats! You won this level. You move to round 2" << endl;
                score += 10;
            } else {
                cout << "You failed this level. Better luck for round 2" << endl;
            }

            // Sorting based on advanced algorithms
            if (guess == "quick") {
                quickSort(sortedPotions, 0, sortedPotions.size() - 1, compareByDefense);
            } else if (guess == "merge") {
                mergeSort(sortedPotions, 0, sortedPotions.size() - 1, compareByDefense);
            }

            // Display sorted potions before clearing the screen
            cout << "Sorted Potions by Defense:" << endl;
            for (int i = 0; i < sortedPotions.size(); i++) {
                cout << "Name: " << sortedPotions[i].name
                     << ", Health: " << sortedPotions[i].health
                     << ", Defense: " << sortedPotions[i].defense << endl;
            }
            // Wait before clearing the screen
            sleep(7);  // Optional: Use sleep to allow the user to read the sorted potions

        } else {
            cout << "Invalid attribute" << endl;
        }
    }

    // Clear the screen before moving to the next level
    system("cls");
    level2();  // Assuming this is the next level function you are calling
}



void level2() {
    vector<Wands> sortedWands;

    // Copy wands into a separate vector
    for (const auto& wand : inv.wands) {
        sortedWands.push_back(wand);
    }
    
    cout << "Your score is: " << score << endl;
    cout << endl;
    inv.displayWands();  // Assuming displayWands() is defined in your WandInventory class
    cout << endl;

    cout << "Choose between bubble, selection, insertion or merge sort" << endl;
    getline(cin, guess);
    makelower(guess);
    system("cls");
    
    if (guess != "bubble" && guess != "selection" && guess != "insertion" && guess != "quick" && guess != "merge") {
    cout << "Error: Invalid choice! You must choose one of the following sorting algorithms: 'bubble', 'selection', 'insertion', 'quick', or 'merge'." << endl;
    return;
    }
    
    // Get the size of the wands inventory
    int wandListSize = inv.wands.size();
    
    if (wandListSize==0) {
    	cout<<"Fill your wands first!"<<endl;
    	return;
	} 

    if (wandListSize <= 20) {
        string ans;
        cout << "By which attribute do you want your wands to be sorted? Casting Speed or Defense?" << endl;
        getline(cin, ans);

        if (ans == "casting speed") {
            correct = compareSortingAlgorithmsLevel2(sortedWands, guess, compareWandByCastingSpeed);
            if (guess == correct) {
                cout << "Congrats! You won this level. You move to round 3" << endl;
                score += 10;
            } else {
                cout << "You failed this level. Better luck for round 3" << endl;
            }

            // Sorting based on selected algorithm
            if (guess == "bubble") {
                bubbleSort(sortedWands, compareWandByCastingSpeed);
            } else if (guess == "insertion") {
                insertionSort(sortedWands, compareWandByCastingSpeed);
            } else if (guess == "selection") {
                selectionSort(sortedWands, compareWandByCastingSpeed);
            }

            // Display sorted wands before clearing screen
            cout << "Sorted Wands by casting speed: " << endl;
            for (int i = 0; i < sortedWands.size(); i++) {
                cout << "Name: " << sortedWands[i].name
                     << ", Casting Speed: " << sortedWands[i].casting_speed
                     << ", Defense: " << sortedWands[i].defense << endl;
            }

            // Optional: Wait for a few seconds before clearing screen
            sleep(3);  // Use sleep to give the player time to read the output

        } else if (ans == "defense") {
            correct = compareSortingAlgorithmsLevel2(sortedWands, guess, compareWandByDefense);
            if (guess == correct) {
                cout << "Congrats! You won this level. You move to round 3" << endl;
                score += 10;
            } else {
                cout << "You failed this level. Better luck for round 3" << endl;
            }

            // Sorting based on selected algorithm
            if (guess == "bubble") {
                bubbleSort(sortedWands, compareWandByDefense);
            } else if (guess == "insertion") {
                insertionSort(sortedWands, compareWandByDefense);
            } else if (guess == "selection") {
                selectionSort(sortedWands, compareWandByDefense);
            }

            // Display sorted wands before clearing screen
            cout << "Sorted Wands by defense: " << endl;
            for (int i = 0; i < sortedWands.size(); i++) {
                cout << "Name: " << sortedWands[i].name
                     << ", Casting Speed: " << sortedWands[i].casting_speed
                     << ", Defense: " << sortedWands[i].defense << endl;
            }

            // Optional: Wait for a few seconds before clearing screen
            sleep(7);  // Use sleep to give the player time to read the output

        } else {
            cout << "Invalid attribute" << endl;
        }
    } else if (wandListSize > 20) {
        string ans;
        cout << "By which attribute do you want your wands to be sorted? Casting Speed or Defense?" << endl;
        getline(cin, ans);

        if (ans == "casting speed") {
            correct = compareAdvancedSortingAlgorithmsLevel2(sortedWands, guess, compareWandByCastingSpeed);
            if (guess == correct) {
                cout << "Congrats! You won this level. You move to round 3" << endl;
                score += 10;
            } else {
                cout << "You failed this level. Better luck for round 3" << endl;
            }

            // Sorting based on advanced algorithms
            if (guess == "quick") {
                quickSort(sortedWands, 0, sortedWands.size() - 1, compareWandByCastingSpeed);
            } else if (guess == "merge") {
                mergeSort(sortedWands, 0, sortedWands.size() - 1, compareWandByCastingSpeed);
            }

            // Display sorted wands before clearing screen
            cout << "Sorted Wands by casting speed: " << endl;
            for (int i = 0; i < sortedWands.size(); i++) {
                cout << "Name: " << sortedWands[i].name
                     << ", Casting Speed: " << sortedWands[i].casting_speed
                     << ", Defense: " << sortedWands[i].defense << endl;
            }

            // Optional: Wait for a few seconds before clearing screen
            sleep(3);  // Use sleep to give the player time to read the output

        } else if (ans == "defense") {
            correct = compareAdvancedSortingAlgorithmsLevel2(sortedWands, guess, compareWandByDefense);
            if (guess == correct) {
                cout << "Congrats! You won this level. You move to round 3" << endl;
                score += 10;
            } else {
                cout << "You failed this level. Better luck for round 3" << endl;
            }

            // Sorting based on advanced algorithms
            if (guess == "quick") {
                quickSort(sortedWands, 0, sortedWands.size() - 1, compareWandByDefense);
            } else if (guess == "merge") {
                mergeSort(sortedWands, 0, sortedWands.size() - 1, compareWandByDefense);
            }

            // Display sorted wands before clearing screen
            cout << "Sorted Wands by defense: " << endl;
            for (int i = 0; i < sortedWands.size(); i++) {
                cout << "Name: " << sortedWands[i].name
                     << ", Casting Speed: " << sortedWands[i].casting_speed
                     << ", Defense: " << sortedWands[i].defense << endl;
            }

            // Optional: Wait for a few seconds before clearing screen
            sleep(7);  // Use sleep to give the player time to read the output

        } else {
            cout << "Invalid attribute" << endl;
        }
    }

    // Clear screen before moving to next level
    system("cls");
    level3();  // Assuming level3() is the next function
}

void level3() {
    vector<Cloak> sortedCloaks; 

    // Copy all cloaks from the unordered map into a vector
    for (const auto& pair : inv.cloaks) {
        const vector<Cloak>& cloakList = pair.second;
        for (const auto& cloak : cloakList) {
            sortedCloaks.push_back(cloak);  // Add each cloak to the sortedCloaks vector
        }
    }
    
    cout << "Your score is: " << score << endl;
    cout << endl;
    inv.displayCloaks();  // Display all cloaks in the inventory
    cout << endl;

    cout << "Choose between bubble, selection, insertion, quick, or merge sort:" << endl;
    getline(cin, guess);
    makelower(guess);
    system("cls");
    
    int cloakListSize = sortedCloaks.size();
    if (guess != "bubble" && guess != "selection" && guess != "insertion" && guess != "quick" && guess != "merge") {
    cout << "Error: Invalid choice! You must choose one of the following sorting algorithms: 'bubble', 'selection', 'insertion', 'quick', or 'merge'." << endl;
    return;
    }
    
    if (cloakListSize==0) {
    	cout<<"Fill your cloaks first!"<<endl;
    	return;
	} 
    if (cloakListSize <= 20) {
        string ans;
        cout << "By which attribute do you want your cloaks to be sorted? Resistance or Stealth?" << endl;
        getline(cin, ans);
        makelower(ans);
        system("cls");

        bool (*compareFunc)(const Cloak&, const Cloak&);
        if (ans == "resistance") {
            compareFunc = compareCloakByResistance;
        } else if (ans == "stealth") {
            compareFunc = compareCloakByStealth;
        } else {
            cout << "Invalid attribute! Please choose 'Resistance' or 'Stealth'." << endl;
            return;
        }

        // Call the comparison function to determine the correct answer
        string correctAnswer = compareSortingAlgorithmsLevel3(sortedCloaks, guess, compareFunc);

        if (guess == correctAnswer) {
            cout << "Congrats! You won this level. You move to round 4!" << endl;
            score += 10;
        } else {
            cout << "You failed this level. Better luck in round 4!" << endl;
        }

        // Sort based on the guessed algorithm
        if (guess == "bubble") {
            bubbleSort(sortedCloaks, compareFunc);
        } else if (guess == "insertion") {
            insertionSort(sortedCloaks, compareFunc);
        } else if (guess == "selection") {
            selectionSort(sortedCloaks, compareFunc);
        }

        // Display sorted cloaks
        cout << "Sorted Cloaks by " << ans << ":\n";
        for (const auto& cloak : sortedCloaks) {
            cout << "Name: " << cloak.name
                 << ", Resistance: " << cloak.resistance
                 << ", Stealth: " << cloak.stealth << endl;
        }

        // Pause for 3 seconds before clearing the screen
        sleep(7);
        system("cls");
    }
    else if (cloakListSize > 20) {
        string ans;
        cout << "By which attribute do you want your cloaks to be sorted? Resistance or Stealth?" << endl;
        getline(cin, ans);
        makelower(ans);
        system("cls");

        bool (*compareFunc)(const Cloak&, const Cloak&);
        if (ans == "resistance") {
            compareFunc = compareCloakByResistance;
        } else if (ans == "stealth") {
            compareFunc = compareCloakByStealth;
        } else {
            cout << "Invalid attribute! Please choose 'Resistance' or 'Stealth'." << endl;
            return;
        }

        // Call the comparison function to determine the correct answer
        string correctAnswer = compareSortingAdvancedAlgorithmsLevel3(sortedCloaks, guess, compareFunc);

        if (guess == correctAnswer) {
            cout << "Congrats! You won this level. You move to round 4!" << endl;
            score += 10;
        } else {
            cout << "You failed this level. Better luck in round 4!" << endl;
        }

        // Sort based on the guessed algorithm
        if (guess == "quick") {
            quickSort(sortedCloaks, 0, sortedCloaks.size() - 1, compareFunc);
        } else if (guess == "merge") {
            mergeSort(sortedCloaks, 0, sortedCloaks.size() - 1, compareFunc);
        }

        // Display sorted cloaks
        cout << "Sorted Cloaks by " << ans << ":\n";
        for (const auto& cloak : sortedCloaks) {
            cout << "Name: " << cloak.name
                 << ", Resistance: " << cloak.resistance
                 << ", Stealth: " << cloak.stealth << endl;
        }

        // Pause for 3 seconds before clearing the screen
        sleep(7);
        system("cls");
    }
    
    level4();
}


void level4() {
    vector<MagicalRings> sortedRings;
    
    int ListSize = sortedRings.size();


    // Reserve memory to optimize performance
    sortedRings.reserve(inv.magicalRings.size());

    // Copy magical rings from the inventory map to the vector
    for (const auto& ringPair : inv.magicalRings) {
        const vector<MagicalRings>& ringList = ringPair.second;
        for (const auto& ring : ringList) {
            sortedRings.push_back(ring);  // Add each ring to the sortedRings vector
        }
    }
    int ringsListSize = sortedRings.size();
    cout<<"Your score is: "<<score<<endl;
    cout << endl;
    inv.displayMagicalRings();  // Display all magical rings in the inventory
    cout << endl;

    cout << "Choose between bubble, selection, insertion, quick, or merge sort:" << endl;
    getline(cin, guess);
    makelower(guess);
    system("cls");
    
     if (guess != "bubble" && guess != "selection" && guess != "insertion" && guess != "quick" && guess != "merge") {
    cout << "Error: Invalid choice! You must choose one of the following sorting algorithms: 'bubble', 'selection', 'insertion', 'quick', or 'merge'." << endl;
    return;
    }
    
    if (ringsListSize==0) {
    	cout<<"Fill your cloaks first!"<<endl;
    	return;
	} 
    
if (ringsListSize<=20) {
    string ans;
    cout << "By which attribute do you want your magical rings to be sorted? Power or Luck?" << endl;
    getline(cin, ans);
    makelower(ans);
    system("cls");

    bool (*compareFunc)(const MagicalRings&, const MagicalRings&);
    if (ans == "power") {
        compareFunc = compareRingByPower;
    } else if (ans == "luck") {
        compareFunc = compareRingByLuck;
    } else {
        cout << "Invalid attribute! Please choose 'Power' or 'Luck'." << endl;
        return;
    }

    // Determine the correct sorting algorithm
    string correct = compareSortingAlgorithmsLevel4(sortedRings, guess, compareFunc);

    if (guess == correct) {
        cout << "Congrats! You won this level!" << endl;
        score+=10;
    } else {
        cout << "You failed this level. Try again!" << endl;
    }

    // Apply the chosen sorting algorithm
    if (guess == "bubble") {
        bubbleSort(sortedRings, compareFunc);
    } else if (guess == "insertion") {
        insertionSort(sortedRings, compareFunc);
    } else if (guess == "selection") {
        selectionSort(sortedRings, compareFunc);
    }

    // Display the sorted magical rings
    cout << "Sorted Magical Rings by " << ans << ":\n";
    for (const auto& ring : sortedRings) {
        cout << "Name: " << ring.name
             << ", Power: " << ring.power
             << ", Luck: " << ring.luck << endl;
    }
 }
 
 else if (ringsListSize>20) {
 	string ans;
    cout << "By which attribute do you want your magical rings to be sorted? Power or Luck?" << endl;
    getline(cin, ans);
    makelower(ans);
    system("cls");

    bool (*compareFunc)(const MagicalRings&, const MagicalRings&);
    if (ans == "power") {
        compareFunc = compareRingByPower;
    } else if (ans == "luck") {
        compareFunc = compareRingByLuck;
    } else {
        cout << "Invalid attribute! Please choose 'Power' or 'Luck'." << endl;
        return;
    }

    // Determine the correct sorting algorithm
    string correct = compareAdvancedSortingAlgorithmsLevel4(sortedRings, guess, compareFunc);

    if (guess == correct) {
        cout << "Congrats! You won this level!" << endl;
        score+=10;
    } else {
        cout << "You failed this level. Try again!" << endl;
    }

    // Apply the chosen sorting algorithm
    if (guess == "quick") {
        quickSort(sortedRings, 0, sortedRings.size() - 1, compareFunc);
    } 
    else if (guess=="merge") {
    	mergeSort(sortedRings, 0, sortedRings.size() - 1, compareFunc);
	}

    // Display the sorted magical rings
    cout << "Sorted Magical Rings by " << ans << ":\n";
    for (const auto& ring : sortedRings) {
        cout << "Name: " << ring.name
             << ", Power: " << ring.power
             << ", Luck: " << ring.luck << endl;
    }
 }

      
       cout<<"Your score is: "<<score<<endl;
       sleep(5);
       if (score>=20) {
       	   print_ascii_final();
       	   sleep(6);
	   }
	   else {
	   	   cout<<"You lose"<<endl;
	   	   sleep(6);
	   }
       system("cls");

}
string compareSortingAlgorithmsLevel1(vector<Potions>& originalData, string guess, bool (*compareFunc)(const Potions&, const Potions&)) {
        string correctAnswer;

        vector<Potions> dataForBubble = originalData;
        vector<Potions> dataForInsertion = originalData;
        vector<Potions> dataForSelection = originalData;

        int bubblePasses = bubbleSort(dataForBubble, compareFunc);
        int insertionPasses = insertionSort(dataForInsertion, compareFunc);
        int selectionPasses = selectionSort(dataForSelection, compareFunc);

        cout << "Bubble Sort made: " << bubblePasses << " passes\n";
        cout << "Insertion Sort made: " << insertionPasses << " passes\n";
        cout << "Selection Sort made: " << selectionPasses << " passes\n";

        if (bubblePasses < insertionPasses && bubblePasses < selectionPasses) {
            correctAnswer = "bubble";
        } else if (insertionPasses < bubblePasses && insertionPasses < selectionPasses) {
            correctAnswer = "insertion";
        } else if (selectionPasses < bubblePasses && selectionPasses < insertionPasses) {
            correctAnswer = "selection";
        } else {
            correctAnswer = guess;
        }

        return correctAnswer;
    }

    string compareSortingAlgorithmsLevel2(vector<Wands>& originalData, string guess, bool (*compareFunc)(const Wands&, const Wands&)) {
        string correctAnswer;

        vector<Wands> dataForBubble = originalData;
        vector<Wands> dataForInsertion = originalData;
        vector<Wands> dataForSelection = originalData;

        int bubblePasses = bubbleSort(dataForBubble, compareFunc);
        int insertionPasses = insertionSort(dataForInsertion, compareFunc);
        int selectionPasses = selectionSort(dataForSelection, compareFunc);

        cout << "Bubble Sort made: " << bubblePasses << " passes\n";
        cout << "Insertion Sort made: " << insertionPasses << " passes\n";
        cout << "Selection Sort made: " << selectionPasses << " passes\n";

        if (bubblePasses < insertionPasses && bubblePasses < selectionPasses) {
            correctAnswer = "bubble";
        } else if (insertionPasses < bubblePasses && insertionPasses < selectionPasses) {
            correctAnswer = "insertion";
        } else if (selectionPasses < bubblePasses && selectionPasses < insertionPasses) {
            correctAnswer = "selection";
        } else {
            correctAnswer = guess;
        }

        return correctAnswer;
    }

string compareSortingAlgorithmsLevel3(vector<Cloak>& originalData, string guess, bool (*compareFunc)(const Cloak&, const Cloak&)) {
    string correctAnswer;

    vector<Cloak> dataForBubble = originalData;
    vector<Cloak> dataForInsertion = originalData;
    vector<Cloak> dataForSelection = originalData;

    int bubblePasses = bubbleSort(dataForBubble, compareFunc);
    int insertionPasses = insertionSort(dataForInsertion, compareFunc);
    int selectionPasses = selectionSort(dataForSelection, compareFunc);

    cout << "Bubble Sort made: " << bubblePasses << " passes\n";
    cout << "Insertion Sort made: " << insertionPasses << " passes\n";
    cout << "Selection Sort made: " << selectionPasses << " passes\n";

    if (bubblePasses < insertionPasses && bubblePasses < selectionPasses) {
        correctAnswer = "bubble";
    } else if (insertionPasses < bubblePasses && insertionPasses < selectionPasses) {
        correctAnswer = "insertion";
    } else if (selectionPasses < bubblePasses && selectionPasses < insertionPasses) {
        correctAnswer = "selection";
    } else {
        correctAnswer = guess;
    }

    return correctAnswer;
}

string compareSortingAlgorithmsLevel4(vector<MagicalRings>& originalData, string guess, bool (*compareFunc)(const MagicalRings&, const MagicalRings&)) {
    string correctAnswer;

    vector<MagicalRings> dataForBubble = originalData;
    vector<MagicalRings> dataForInsertion = originalData;
    vector<MagicalRings> dataForSelection = originalData;

    int bubblePasses = bubbleSort(dataForBubble, compareFunc);
    int insertionPasses = insertionSort(dataForInsertion, compareFunc);
    int selectionPasses = selectionSort(dataForSelection, compareFunc);

    cout << "Bubble Sort made: " << bubblePasses << " passes\n";
    cout << "Insertion Sort made: " << insertionPasses << " passes\n";
    cout << "Selection Sort made: " << selectionPasses << " passes\n";

    if (bubblePasses < insertionPasses && bubblePasses < selectionPasses) {
        correctAnswer = "bubble";
    } else if (insertionPasses < bubblePasses && insertionPasses < selectionPasses) {
        correctAnswer = "insertion";
    } else if (selectionPasses < bubblePasses && selectionPasses < insertionPasses) {
        correctAnswer = "selection";
    } else {
        correctAnswer = guess;
    }

    return correctAnswer;
}
    // Compare for Level 1 - Potions-Advanced.
string compareAdvancedSortingAlgorithmsLevel1(vector<Potions>& originalData, string guess, bool (*compareFunc)(const Potions&, const Potions&)) {
    string correctAnswer;
    vector<Potions> dataForQuick = originalData;
    vector<Potions> dataForMerge = originalData;

    int quickPasses = quickSort(dataForQuick, 0, dataForQuick.size() - 1, compareFunc); // Adjusted for correct call
    int mergePasses = mergeSort(dataForMerge, 0, dataForMerge.size() - 1, compareFunc); // Adjusted for correct call

    cout << "Quick Sort made: " << quickPasses << " passes\n";
    cout << "Merge Sort made: " << mergePasses << " passes\n";

    if (quickPasses < mergePasses) {
        correctAnswer = "quick";
    } else if (mergePasses < quickPasses) {
        correctAnswer = "merge";
    } else {
        correctAnswer = guess;  // If both sorts made the same number of passes, use the provided guess
    }

    return correctAnswer;
}

// Compare for Level 2 - Wands
string compareAdvancedSortingAlgorithmsLevel2(vector<Wands>& originalData, string guess, bool (*compareFunc)(const Wands&, const Wands&)) {
    string correctAnswer;
    vector<Wands> dataForQuick = originalData;
    vector<Wands> dataForMerge = originalData;

    int quickPasses = quickSort(dataForQuick, 0, dataForQuick.size() - 1, compareFunc); // Adjusted for correct call
    int mergePasses = mergeSort(dataForMerge, 0, dataForMerge.size() - 1, compareFunc); // Adjusted for correct call

    cout << "Quick Sort made: " << quickPasses << " passes\n";
    cout << "Merge Sort made: " << mergePasses << " passes\n";

    if (quickPasses < mergePasses) {
        correctAnswer = "quick";
    } else if (mergePasses < quickPasses) {
        correctAnswer = "merge";
    } else {
        correctAnswer = guess;  // If both sorts made the same number of passes, use the provided guess
    }

    return correctAnswer;
}

// Compare for Level 3 - Cloaks
string compareSortingAdvancedAlgorithmsLevel3(vector<Cloak>& originalData, string guess, bool (*compareFunc)(const Cloak&, const Cloak&)) {
    string correctAnswer;
    vector<Cloak> dataForQuick = originalData;
    vector<Cloak> dataForMerge = originalData;

    int quickPasses = quickSort(dataForQuick, 0, dataForQuick.size() - 1, compareFunc); // Adjusted for correct call
    int mergePasses = mergeSort(dataForMerge, 0, dataForMerge.size() - 1, compareFunc); // Adjusted for correct call

    cout << "Quick Sort made: " << quickPasses << " passes\n";
    cout << "Merge Sort made: " << mergePasses << " passes\n";

    if (quickPasses < mergePasses) {
        correctAnswer = "quick";
    } else if (mergePasses < quickPasses) {
        correctAnswer = "merge";
    } else {
        correctAnswer = guess;  // If both sorts made the same number of passes, use the provided guess
    }

    return correctAnswer;
}

// Compare for Level 4 - MagicalRings
string compareAdvancedSortingAlgorithmsLevel4(vector<MagicalRings>& originalData, string guess, bool (*compareFunc)(const MagicalRings&, const MagicalRings&)) {
    string correctAnswer;
    vector<MagicalRings> dataForQuick = originalData;
    vector<MagicalRings> dataForMerge = originalData;

    int quickPasses = quickSort(dataForQuick, 0, dataForQuick.size() - 1, compareFunc); // Adjusted for correct call
    int mergePasses = mergeSort(dataForMerge, 0, dataForMerge.size() - 1, compareFunc); // Adjusted for correct call

    cout << "Quick Sort made: " << quickPasses << " passes\n";
    cout << "Merge Sort made: " << mergePasses << " passes\n";

    if (quickPasses < mergePasses) {
        correctAnswer = "quick";
    } else if (mergePasses < quickPasses) {
        correctAnswer = "merge";
    } else {
        correctAnswer = guess;  // If both sorts made the same number of passes, use the provided guess
    }

    return correctAnswer;
}


}; 
void print_ascii_intro() {
   vector<string> ascii_art = {
        "  _    ____ _____ ___ _____ _    ____ _____    ___  _   _ _____ ____ _____ ",
        "   / \\  |  _ \\_   _|_ _|  ___/ \\  / ___|_   _|  / _ \\| | | | ____/ ___|_   _|",
        "  / _ \\ | |_) || |  | || |_ / _ \\| |     | |   | | | | | | |  _| \\___ \\ | |  ",
        " / ___ \\|  _ < | |  | ||  _/ ___ \\ |___  | |   | |_| | |_| | |___ ___) || |  ",
        "/_/ __\\_\\_| \\_\\|_|_|___|_|/_/ __\\_\\____|_|_|____\\__\\_\\\\___/|_____|____/ |_|  ",
        "| |/ / ____| ____|  _ \\| ____|  _ \\   / _ \\|  ___|                            ",
        "| ' /|  _| |  _| | |_) |  _| | |_) | | | | | |_                               ",
        "| . \\| |___| |___|  __/| |___|  _ <  | |_| |  _|                              ",
        "|_|\\\\_\\_____|_____|_|   |_____|_|_\\\\_\\  \\\\___/|_|                              ",
        "\\ \\   / / \\ | | | | | |_   _/ ___|                                            ",
        " \\ \\ / / _ \\| | | | |   | | \\___ \\                                            ",
        "  \\ V / ___ \\ |_| | |___| |  ___) |                                           ",
        "   \\_/_/   \\_\\___/|_____|_| |____/                                            "
    };


    // Print each line of the ASCII art centered
    for (const string& line : ascii_art) {
        printCentered(line);
    }
}

int main() {
	 print_ascii_intro();
     string statement = "Step into the world of algorithms where speed matters!\nCan you guess which sorting technique will conquer the chaos and sort the fastest?!";

    for (char letter : statement) {
        cout<<letter;
        cout.flush();  
        Sleep(50);  
    }

    cout << endl;  
    sleep(3);
    

    // Clear the console
    system("cls");  //
	srand(time(NULL));
    
    Inventory inv;
    availableItems();
    int choice;
    do {
        cout << "\nMenu:\n1. Add Item\n2. Remove Item\n3. Display Items\n4. Play a Game\n5. Exit\n ";
        cout <<"Choose an option: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        switch (choice) {
            case 1: { // Add Item
                string type, name;
                cout << "Enter item type (Potion, Wand, Cloak, Ring): ";
                getline(cin, type);
                makelower(type);

                if (type == "potion") {
                    cout << "Enter potion name: ";
                    getline(cin, name);
                    makelower(name); // Convert name to lowercase
                    if (name == "elixir of life") {
                        inv.addPotion(Potions("Elixir of Life",randomFloat(),randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    } 
					else if (name == "guardian's draught") {
                        inv.addPotion(Potions("Guardian's Draught",randomFloat(),randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    }
					else if (name == "elixir of the moonlit veil") {
   						 inv.addPotion(Potions("Elixir of the Moonlit Veil",randomFloat(), randomNumber(), randomNumber()));
   						 sleepFor(200);
                         system("cls");
                         availableItems();
					}


					else if (name=="flameheart draught") {
                        	inv.addPotion(Potions("Flameheart Draught",randomFloat(),randomNumber(),randomNumber()));
                        	sleepFor(200);
                            system("cls");
                            availableItems();
						}
					else if (name=="vial of eternal twilight") {
                        	inv.addPotion(Potions("Vial of Eternal Twilight",randomFloat(),randomNumber(),randomNumber()));
                        	sleepFor(200);
                            system("cls");
                            availableItems();
						}
                     else {
                        cout << "Invalid potion name!\n";
                    }
                } 
				else if (type == "wand") {
                    cout << "Enter wand name: ";
                    getline(cin, name);
                    makelower(name); // Convert name to lowercase
                    if (name == "elder wand") {
                        inv.addWand(Wands("Elder Wand",randomFloat(),randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    } 
					else if (name == "phoenix wand") {
                        inv.addWand(Wands("Phoenix Wand",randomFloat(),randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    } 
					else if (name == "soulbinder's cane") {
                        inv.addWand(Wands("Soulbinder's Cane",randomFloat(), randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    }
					else if (name == "owl wand") {
                        inv.addWand(Wands("Owl Wand",randomFloat(), randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    }
                    else if (name == "glistening wand") {
                        inv.addWand(Wands("Glistening Wand",randomFloat(), randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    }
					else {
                        cout << "Invalid wand name!\n";
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    }
                } else if (type == "cloak") {
                    cout << "Enter cloak name: ";
                    getline(cin, name);
                    makelower(name); // Convert name to lowercase
                    if (name == "shadow cloak") {
                        inv.addCloak(Cloak("Shadow Cloak",randomFloat(), randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    } 
					else if (name == "elixir cloak") {
                        inv.addCloak(Cloak("Elixir Cloak",randomFloat(),randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    } 
					else if (name == "armour cloak") {
                        inv.addCloak(Cloak("Armour Cloak",randomFloat(),randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    } 
                    else if (name == "invisibility cloak") {
                        inv.addCloak(Cloak("Invisibility Cloak",randomFloat(),randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    } 
                    else if (name == "ruby cloak") {
                        inv.addCloak(Cloak("Ruby Cloak",randomFloat(),randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    } 
					else {
                        cout << "Invalid cloak name!\n";
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    }
                } else if (type == "ring") {
                    cout << "Enter ring name: ";
                    getline(cin, name);
                    makelower(name); // Convert name to lowercase
                    if (name == "ring of eternity") {
                        inv.addMagicalRing(MagicalRings("Ring of Eternity",randomFloat(),randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    } 
					else if (name == "fate's band") {
                        inv.addMagicalRing(MagicalRings("Fate's Band",randomFloat(), randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    } 
					else if (name == "charm of luck") {
                        inv.addMagicalRing(MagicalRings("Charm of Luck",randomFloat(), randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    } 
                    else if (name == "destiny's ring") {
                        inv.addMagicalRing(MagicalRings("Destiny's Ring'",randomFloat(), randomNumber(),randomNumber()));
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    }
					else if (name == "soul-binding ring") {
    					inv.addMagicalRing(MagicalRings("Soul-binding Ring",randomFloat(), randomNumber(), randomNumber()));
    					sleepFor(200);
                        system("cls");
                        availableItems();
					}		
 
                    
					else {
                        cout << "Invalid ring name!\n";
                        sleepFor(200);
                        system("cls");
                        availableItems();
                    }
                } else {
                    cout << "Invalid item type!\n";
                }
                break;
            }
            case 2: { // Remove Item
                string type, name;
                cout << "Enter item type to remove (Potion, Wand, Cloak, Ring): ";
                getline(cin, type);
                makelower(type);

                cout << "Enter item name: ";
                getline(cin, name);
                

                if (type == "potion") {
                    inv.removePotion(name);
                    sleepFor(200);
                    system("cls");
                    availableItems();
                } else if (type == "wand") {
                    inv.removeWand(name);
                    sleepFor(200);
                    system("cls");
                    availableItems();
                } else if (type == "cloak") {
                    inv.removeCloak(name);
                    sleepFor(200);
                    system("cls");
                    availableItems();
                } else if (type == "ring") {
                    inv.removeMagicalRing(name);
                    sleepFor(200);
                    system("cls");
                    availableItems();
                } else {
                    cout << "Invalid item type!\n";
                    sleepFor(200);
                    system("cls");
                    availableItems();
                }
                break;
            }
            case 3: { // Display Items
                sleepFor(200);
                inv.displayPotions();
                cout<<endl;
                sleepFor(200);
                inv.displayWands();
                cout<<endl;
                sleepFor(200);
                inv.displayCloaks();
                cout<<endl;
                sleepFor(200);
                inv.displayMagicalRings();
                cout<<endl;
                sleep(10);
                system("cls");
                break;
            }
            case 4:{
            	system("cls");
                Game play(inv);
            	play.level1();
            	sleepFor(200);
                system("cls");
                availableItems();
            	break;
            }
            case 5: {
            	 cout << "Exiting...\n";
            	 system("cls");
            	 break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}