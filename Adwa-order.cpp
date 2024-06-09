#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Definisi struktur data untuk informasi order tiket
struct TicketOrder {
    int sequence;
    bool processed;
    string ticketCode;
    string user;
    string orderedSeat;
};

int main() {
    // Membuat queue untuk menyimpan order tiket
    queue<TicketOrder> ticketQueue;

    // Fungsi untuk menambahkan order tiket ke dalam queue
    auto addTicketOrder = [&ticketQueue](int sequence, bool processed, const string& ticketCode, const string& user, const string& orderedSeat) {
        TicketOrder order;
        order.sequence = sequence;
        order.processed = processed;
        order.ticketCode = ticketCode;
        order.user = user;
        order.orderedSeat = orderedSeat;
        ticketQueue.push(order);
    };

    // Fungsi untuk memproses order tiket dari queue
    auto processTicketOrder = [&ticketQueue]() {
        if (!ticketQueue.empty()) {
            TicketOrder order = ticketQueue.front();
            ticketQueue.pop();
            // Proses order disini, misalnya mencetak informasi order
            cout << "Processing ticket order:" << endl;
            cout << "Sequence: " << order.sequence << endl;
            cout << "Ticket Code: " << order.ticketCode << endl;
            cout << "User: " << order.user << endl;
            cout << "Ordered Seat: " << order.orderedSeat << endl;
            cout << endl;
        } else {
            cout << "No ticket orders to process." << endl;
        }
    };

    // Menambahkan beberapa order tiket ke dalam queue
    addTicketOrder(1, false, "ABC123", "John", "A1");
    addTicketOrder(2, false, "DEF456", "Alice", "B2");
    addTicketOrder(3, false, "GHI789", "Bob", "C3");

    // Memproses order tiket dari queue
    cout << "Processing ticket orders..." << endl;
    processTicketOrder();
    processTicketOrder();
    processTicketOrder();

    return 0;
}
