#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>
#include <string>
using namespace std;
/*
1. class Suit
2. class Rank
3. class Card (contains suit and rank, toString)
4. class Deck (do initialize, shuffle, drawCard, reset)
*/
enum class Suit{Club, Diamond, Heart, Spade};
enum class Rank{Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
class Card {
public:
    Card (Suit suit, Rank rank) : suit(suit), rank(rank) {}
    string toString () {
        return suitToString() + " " + rankToString();
    }
    string suitToString () const { // const member func means it won't change any member variable
        switch (suit) {
            case Suit::Club : return "Club";
            case Suit::Diamond : return "Diamond";
            case Suit::Heart : return "Heart";
            case Suit::Spade : return "Spade";
        }
        return "unknown";
    }
    string rankToString () const { // const member func means it won't change any member variable
        switch (rank) {
            case Rank::Jack:  return "Jack";
            case Rank::Queen: return "Queen";
            case Rank::King:  return "King";
            case Rank::Ace:   return "Ace";
            default: return std::to_string(static_cast<int>(rank));
        }
    }
    void getSuit () {
        cout << static_cast<int>(suit);
    }
private:
    Suit suit;
    Rank rank;
};


class Deck
{
private:
    vector<Card> cards;
    // handwrite shuffle
    void shuffle() {
        std::random_device rd;
        std::mt19937 gen(rd());

        for (size_t i = cards.size() - 1; i > 0; --i) {
            std::uniform_int_distribution<size_t> dist(0, i);
            size_t j = dist(gen);
            std::swap(cards[i], cards[j]);
        }
    }
public:
    Deck () {
        initialize();
        shuffle();
    }
    void initialize () {
        for (size_t i = 0 ; i < 4 ; ++i) {
            for (size_t j = 1 ; j <= 13 ; ++j) {
                cards.emplace_back(Card(static_cast<Suit>(i), static_cast<Rank>(j)));
                // Do static cast when doing initialization, cast from int -> class.
            }
        }
        
    }
    Card drawCard () {
        if (cards.empty()) {
            cout << "empty";
        }
        Card top = cards.back();
        cards.pop_back();
        return top;
    }
    // reset
    void reset () {
        initialize();
        shuffle();
    }
    
    // Return size
    size_t size() {return cards.size();}

};


int main () {
    Deck deck;
    Card c = deck.drawCard();
    cout << c.toString();
    
}
