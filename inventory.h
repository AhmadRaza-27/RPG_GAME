class Inventory {
public:
    vector<Potions> potions;
    list<Wands> wands;
    unordered_map<string, vector<Cloak>> cloaks;
    unordered_map<string, vector<MagicalRings>> magicalRings;

    int maxItems;
    int currentItems;
    float maxWeight;  // New attribute for maximum weight limit
    float currentWeight;  // New attribute for tracking the total weight

    Inventory() : maxItems(100), currentItems(0), maxWeight(5000.0f), currentWeight(0.0f) {}  // Assuming max weight is 500 units

    bool addPotion(const Potions& potion) {
        if (currentItems >= maxItems || currentWeight + potion.weight > maxWeight) {
            cout << "Cannot add potion " << potion.name << ". Inventory is full or exceeds weight limit!\n";
            return false;
        }
        potions.push_back(potion);
        currentItems++;
        currentWeight += potion.weight;  // Add potion's weight to total weight
        cout << "Added potion: " << potion.name << endl;
        return true;
    }

    bool addWand(const Wands& wand) {
        if (currentItems >= maxItems || currentWeight + wand.weight > maxWeight) {
            cout << "Cannot add wand " << wand.name << ". Inventory is full or exceeds weight limit!\n";
            return false;
        }
        wands.push_back(wand);
        currentItems++;
        currentWeight += wand.weight;  // Add wand's weight to total weight
        cout << "Added wand: " << wand.name << endl;
        return true;
    }

    bool addCloak(const Cloak& cloak) {
        if (currentItems >= maxItems || currentWeight + cloak.weight > maxWeight) {
            cout << "Cannot add cloak " << cloak.name << ". Inventory is full or exceeds weight limit!\n";
            return false;
        }
        cloaks[cloak.name].push_back(cloak);
        currentItems++;
        currentWeight += cloak.weight;  // Add cloak's weight to total weight
        cout << "Added cloak: " << cloak.name << endl;
        return true;
    }

    bool addMagicalRing(const MagicalRings& ring) {
        if (currentItems >= maxItems || currentWeight + ring.weight > maxWeight) {
            cout << "Cannot add ring " << ring.name << ". Inventory is full or exceeds weight limit!\n";
            return false;
        }
        magicalRings[ring.name].push_back(ring);
        currentItems++;
        currentWeight += ring.weight;  // Add ring's weight to total weight
        cout << "Added ring: " << ring.name << endl;
        return true;
    }

    bool removePotion(const string& potionName) {
        for (int i = 0; i < potions.size(); i++) {
            if (potions[i].name == potionName) {
                currentWeight -= potions[i].weight;  // Subtract potion's weight
                potions.erase(potions.begin() + i);
                currentItems--;
                cout << "Removed potion: " << potionName << endl;
                return true;
            }
        }
        cout << "Potion " << potionName << " not found in the inventory.\n";
        return false;
    }

    bool removeWand(const string& wandName) {
        for (auto it = wands.begin(); it != wands.end();) {
            if (it->name == wandName) {
                currentWeight -= it->weight;  // Subtract wand's weight
                it = wands.erase(it);
                currentItems--;
                cout << "Removed wand: " << wandName << endl;
                return true;
            } else {
                ++it;
            }
        }
        cout << "Wand " << wandName << " not found in the inventory.\n";
        return false;
    }

    bool removeCloak(const string& cloakName) {
        auto it = cloaks.find(cloakName);
        if (it != cloaks.end()) {
            vector<Cloak>& cloakList = it->second;
            if (!cloakList.empty()) {
                currentWeight -= cloakList.front().weight;  // Subtract cloak's weight
                cloakList.erase(cloakList.begin());
                currentItems--;
                if (cloakList.empty()) {
                    cloaks.erase(it);
                }
                cout << "Removed one cloak: " << cloakName << endl;
                return true;
            }
        }
        cout << "Cloak " << cloakName << " not found.\n";
        return false;
    }

    bool removeMagicalRing(const string& ringName) {
        auto it = magicalRings.find(ringName);
        if (it != magicalRings.end()) {
            vector<MagicalRings>& ringList = it->second;
            if (!ringList.empty()) {
                currentWeight -= ringList.front().weight;  // Subtract ring's weight
                ringList.erase(ringList.begin());
                currentItems--;
                if (ringList.empty()) {
                    magicalRings.erase(it);
                }
                cout << "Removed one ring: " << ringName << endl;
                return true;
            }
        }
        cout << "Ring " << ringName << " not found.\n";
        return false;
    }
    void displayPotions() const {
        if (potions.empty()) {
            cout << "No potions in the inventory.\n";
            return;
        }
        cout << "Potions in inventory:\n";
        for (const auto& potion : potions) {
            cout << "Name: " << potion.name 
                 << ", Health: " << potion.health 
                 << ", Defense: " << potion.defense
                 <<" , Weight: " <<potion.weight <<endl;
        }
    }

    void displayWands() const {
        if (wands.empty()) {
            cout << "No wands in the inventory.\n";
            return;
        }
        cout << "Wands in inventory:\n";
        for (const auto& wand : wands) {
            cout << "Name: " << wand.name 
                 << ", Casting Speed: " << wand.casting_speed 
                 << ", Defense: " << wand.defense 
                 <<" , Weight: " <<wand.weight <<endl;
        }
    }

 void displayCloaks() const {
    if (cloaks.empty()) {
        cout << "No cloaks in the inventory." << endl;
        return;
    }

    cout << "Cloaks in inventory:" << endl;

    // Iterate over the unordered_map to display each cloak's name and attributes
    for (const auto& entry : cloaks) {
        const string& cloakName = entry.first;
        const vector<Cloak>& cloakList = entry.second;

        // Display the name of the cloak group (all cloaks with the same name)
        cout << "Name: " << cloakName << endl;

        // Display details of each cloak in the vector for this name
        for (const auto& cloak : cloakList) {
            cout << "Resistance:  " << cloak.resistance <<endl;
			cout << "Stealth: " << cloak.stealth<<endl;
			cout <<" , Weight: " <<cloak.weight <<endl;
        }
    }
}



void displayMagicalRings() const {
    if (magicalRings.empty()) {
        cout << "No magical rings in the inventory." << endl;
        return;
    }

    cout << "Magical Rings in inventory:" << endl;

    // Iterate over the unordered_map to display each ring's name and attributes
    for (const auto& entry : magicalRings) {
        const string& ringName = entry.first;
        const vector<MagicalRings>& ringList = entry.second;

        // Display the name of the magical ring group (all rings with the same name)
        cout << "Name: " << ringName << endl;

        // Display details of each ring in the vector for this name
        for (const auto& ring : ringList) {
            cout << "Power: " << ring.power <<endl;
			cout << "Luck: " << ring.luck << endl;
			cout << "Weight: " <<ring.weight <<endl;
        }
    }
}

    void displayTotalWeight() const {
        cout << "Current total weight in inventory: " << currentWeight << " units.\n";
    }
};
