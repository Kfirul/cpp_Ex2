
#include <card.hpp>
#include <string>

using namespace std;
using namespace ariel;

card::card(int num, string suit) { // Constructor for a card object with a given number and suit
    this->num = num;
    this->suit = suit;
}

int card::compare(card other) { // Compare two card objects and return an integer representing their relative values
    if (this->num == other.num) {
        return 0;
    } else if (this->num == 1) {
        if (other.num == 2) {
            return -1;
        }
        return 1;
    } else if (other.num == 1) {
        if (this->num == 2) {
            return 1;
        }
        return -1;
    } else if (this->num > other.num) {
        return 1;
    }
    return -1;
}

string card::toString() { // Return a string representation of the card object

    if (this->num == 1) {
        return "Ace of " + this->suit;
    } else if (this->num == 11) {
        return "Prince of " + this->suit;
    } else if (this->num == 12) {
        return "Queen of " + this->suit;
    } else if (this->num == 13) {
        return "King of " + this->suit;
    } else {
        return to_string(this->num) + " of " + this->suit;
    }
}


