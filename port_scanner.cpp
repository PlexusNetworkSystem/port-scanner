//prm: -lncurses -lpthread
#include <iostream>
#include <boost/asio.hpp>
#include <ncurses.h>
#include <ctime>
#include <cstdio>

using namespace std;
using namespace boost::asio;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Invalid amount of arguments." << endl;
        cerr << "Syntax : scanner <ip>" << endl;
        return -1;
    }
    string target = argv[1];
    io_service ios;
    ip::tcp::resolver resolver(ios);
    ip::tcp::resolver::query query(target, "");
    ip::tcp::resolver::iterator it = resolver.resolve(query);
    ip::tcp::endpoint endpoint = *it;
    target = endpoint.address().to_string();

    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    curs_set(0);
    time_t start = time(0);
    attron(COLOR_PAIR(2));
    printw("%.*s", 50, "-");
    printw("Scanning target: %s", target.c_str());
    printw("Time started: %s", ctime(&start));
    printw("%.*s", 50, "-");
    attroff(COLOR_PAIR(2));

    int found = 0;

    try {
        for (int port = 1; port <= 65535; port++) {
            std::cout << "Scanning port:" << port << "\r" << flush;
            ip::tcp::socket socket(ios);
            ip::tcp::endpoint endpoint(ip::address::from_string(target), port);
            socket.connect(endpoint);
            if (socket.is_open()) {
                //print of port feature
                if (port == 20 || port == 21 || port == 445 || port == 139 || port == 1001 || 1900) {
                    attron(COLOR_PAIR(2));
                    printw("TCP Port %d Found\n", port);
                    attroff(COLOR_PAIR(2));
                } else if (port == 22) {
                    attron(COLOR_PAIR(2));
                    printw("SSH Port %d Found\n", port);
                    attroff(COLOR_PAIR(2));
                } else if (port == 23) {
                    attron(COLOR_PAIR(2));
                    printw("Telnet - Remote login service Port %d Found\n", port);
                    attroff(COLOR_PAIR(2));
                } else if (port == 25) {
                    attron(COLOR_PAIR(2));
                    printw("SMTP Port %d Found\n", port);
                    attroff(COLOR_PAIR(2));
                } else if (port == 53) {
                    attron(COLOR_PAIR(2));
                    printw("DNS Port %d Found\n", port);
                    attroff(COLOR_PAIR(2));
                } else if (port == 80) {
                    attron(COLOR_PAIR(2));
                    printw("HTTP Port %d Found\n", port);
                    attroff(COLOR_PAIR(2));
                } else if (port == 110) {
                    attron(COLOR_PAIR(2));
                    printw("POP3 Port %d Found\n", port);
                    attroff(COLOR_PAIR(2));
                } else if (port == 119) {
                    attron(COLOR_PAIR(2));
                    printw("NNTP Port %d Found\n", port);
                    attroff(COLOR_PAIR(2));
                } else if (port == 123) {
                    attron(COLOR_PAIR(2));
                    printw("NTP Port %d Found\n", port);
                    attroff(COLOR_PAIR(2));
                } else if (port == 143) {
                    attron(COLOR_PAIR(2));
                    printw("IMAP Port %d Found\n",port);
                    attroff(COLOR_PAIR(2));
                } else if (port == 161) {
                    attron(COLOR_PAIR(2));
                    printw("SNMP Port %d Found\n", port);
                    attroff(COLOR_PAIR(2));
                } else if (port == 194) {
                    attron(COLOR_PAIR(2));
                    printw("IRC Port %d Found\n", port);
                    attroff(COLOR_PAIR(2));
                } else if (port == 443) {
                    attron(COLOR_PAIR(2));
                    printw("HTTPS Port %d Found\n", port);
                    attroff(COLOR_PAIR(2));
                } else {
                    attron(COLOR_PAIR(4));
                    printw("Port %d is open\n", port);
                    attroff(COLOR_PAIR(4));
                }
              found++;
             }
              socket.close();
           }
        } catch (exception& e) {
              cerr << e.what() << endl;
            }
            attron(COLOR_PAIR(3));
            printw("\nScanning completed\n");
            printw("Time taken: %ld secs\n", time(0) - start);
            printw("Found %d open ports\n", found);
            attroff(COLOR_PAIR(3));
            getch();
            endwin();
            return 0;
          }
