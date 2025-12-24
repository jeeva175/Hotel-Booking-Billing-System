#include <bits/stdc++.h>
using namespace std;

// Room Class
class Room {
private:
    int id;
    string type;
    double rate;
    bool available;

public:
    Room(int i, string t, double r) {
        id = i;
        type = t;
        rate = r;
        available = true;
    }

    bool isAvailable() {
        return available;
    }

    void book() {
        available = false;   // Encapsulation: controlled state change
    }

    double getRate() {
        return rate;
    }
};

// Booking Class
class Booking {
private:
    string name;
    int days;
    Room* room;

public:
    Booking(string n, int d, Room* r) {
        name = n;
        days = d;
        room = r;
        room->book();
    }

    double calcBill() {
        return days * room->getRate();   // Core billing logic
    }
};

int main() {
    Room r1(101, "Deluxe", 2000);
    Booking b("Jeeva", 2, &r1);

    cout << "Total Bill: Rs." << b.calcBill();

    return 0;
}
