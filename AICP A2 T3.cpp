#include <iostream>
using namespace std;

const int NUM_JOURNEYS = 4;
const double GROUP_DISCOUNT_RATE = 0.1;

struct JourneyData {
    int availableTickets;
    int passengers;
    double money;
};

void purchaseTickets(JourneyData& journey, int numTickets, double fare=200) {
    if (journey.availableTickets >= numTickets) {
        journey.availableTickets -= numTickets;
        journey.passengers += numTickets;
        journey.money += numTickets * fare * (1.0 - (numTickets > 1 ? GROUP_DISCOUNT_RATE : 0.0));
        cout << "Tickets purchased successfully!" << endl;
    } else {
        cout << "Not enough available tickets." << endl;
    }
}

void displayJourneySummary(const JourneyData& journey, int journeyNum) {
    cout << "\nJourney " << journeyNum << " Summary:" << endl;
    cout << "Available Tickets: " << journey.availableTickets << endl;
    cout << "Passengers: " << journey.passengers << endl;
    cout << "Money: Rs" << journey.money << endl;
}

int main() {
    JourneyData upJourneys[NUM_JOURNEYS] = { {500}, {500}, {500}, {500} };
    JourneyData downJourneys[NUM_JOURNEYS] = { {500}, {500}, {500}, {500} };

    cout << "=== Start of the Day ===" << endl;

    int totalPassengers = 0;
    double totalMoney = 0;
    int maxPassengers = 0;
    int maxPassengersJourney = 0;

    for (int i = 0; i < NUM_JOURNEYS; ++i) {
        cout << "\nJourney " << i + 1 << " Details:" << endl;
        int numTickets;
        double fare=200;

        cout << "Available Tickets for Up Journey " << i + 1 << ": " << upJourneys[i].availableTickets << endl;
        cout << "Number of Tickets to Purchase: ";
        cin >> numTickets;

      
       

        purchaseTickets(upJourneys[i], numTickets, fare);

        displayJourneySummary(upJourneys[i], i + 1);

        totalPassengers += upJourneys[i].passengers;
        totalMoney += upJourneys[i].money;

        if (upJourneys[i].passengers > maxPassengers) {
            maxPassengers = upJourneys[i].passengers;
            maxPassengersJourney = i + 1;
        }
    }

    // Display Totals
    cout << "\n=== Totals for the Day ===" << endl;
    cout << "Total Passengers: " << totalPassengers << endl;
    cout << "Total Money: Rs" << totalMoney << endl;

    // Display Journey with Most Passengers
    cout << "\nJourney with the Most Passengers: Journey " << maxPassengersJourney << " with " << maxPassengers << " passengers." << endl;

    return 0;
}
