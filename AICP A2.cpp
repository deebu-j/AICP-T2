#include <iostream>
using namespace std;

const int NUM_JOURNEYS = 4;

struct JourneyData {
    int passengers;
    double money;
};

int main() {
    JourneyData upJourneys[NUM_JOURNEYS];
    JourneyData downJourneys[NUM_JOURNEYS];

    cout << "\t\t\t=== Start of the Day ===" << endl;

    cout << "\nInput data for Up Journeys:" << endl;
    for (int i = 0; i < NUM_JOURNEYS; ++i) {
        cout << "Journey " << i + 1 << ": " << endl;
        cout << "   Passengers: ";
        cin >> upJourneys[i].passengers;
		
		double fare=500;
        cout << "   Fare per passenger: Rs"<<fare<<endl;
        upJourneys[i].money = upJourneys[i].passengers * fare;
    }

    cout << "\nInput data for Down Journeys:" << endl;
    for (int i = 0; i < NUM_JOURNEYS; ++i) {
        cout << "Journey " << i + 1 << ": " << endl;
        cout << "   Passengers: ";
        cin >> downJourneys[i].passengers;
		
		double fare=500;
        cout << "   Fare per passenger: Rs"<<fare<<endl;
       
        downJourneys[i].money = downJourneys[i].passengers * fare;
    }

    cout << "\n=== Totals for Up Journeys ===" << endl;
    for (int i = 0; i < NUM_JOURNEYS; ++i) {
        cout << "Journey " << i + 1 << ": "
                  << "Passengers: " << upJourneys[i].passengers
                  << ", Money: Rs" << upJourneys[i].money
                  << endl;
    }

    cout << "\n=== Totals for Down Journeys ===" << endl;
    for (int i = 0; i < NUM_JOURNEYS; ++i) {
        cout << "Journey " << i + 1 << ": "
                  << "Passengers: " << downJourneys[i].passengers
                  << ", Money: Rs" << downJourneys[i].money
                  << endl;
    }

    return 0;
}
