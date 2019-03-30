//  Jonathan Osborne
//  jwo0010
//  hw3_jwo0010.cpp
//  This program takes no input from users besides enter key.
//  The output simulates two scenarios of three friends' duels
//  and
//  I received no help on this homework assignment.
//

# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include<ctime>
using namespace std;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
/*
 Return: true if at least two are alive; otherwise return false */


void Aaron_shoots1(bool& B_alive, bool& C_alive);
/* Strategy 1: Use call by reference
 * Input: B_alive indicates whether Bob alive or dead
 *  C_alive indicates whether Charlie is alive or dead
 * Return: Change B_alive into false if Bob is killed.
 *  Change C_alive into false if Charlie is killed.
 */


void Bob_shoots(bool& A_alive, bool& C_alive);
/* Call by reference
 * Input: A_alive indicates if Aaron is alive or dead
 *  C_alive indicates whether Charlie is alive or dead
 * Return: Change A_alive into false if Aaron is killed.
 *  Change C_alive into false if Charlie is killed.
 */

void Charlie_shoots(bool& A_alive, bool& B_alive);
/* Call by reference
 * Input: A_alive indicates if Aaron is alive or dead
 *  B_alive indicates whether Bob is alive or dead
 * Return: Change A_alive into false if Aaron is killed.
 *  Change B_alive into false if Bob is killed.
 */


void Aaron_shoots2(bool& B_alive, bool& C_alive);
/* Strategy 2: Use call by reference
 * Input: B_alive indicates whether Bob alive or dead
 *  C_alive indicates whether Charlie is alive or dead
 * Return: Change B_alive into false if Bob is killed.
 *  Change C_alive into false if Charlie is killed.
 */

bool shoot(double rate);
/* Input: rate indicates the rate the person shooting has
 * Return: true if shot hit; false if shot missed.
 */

int sim1(double A_RATE, double B_RATE, double C_RATE, bool& A, bool& B, bool& C);
int sim2(double A_RATE, double B_RATE, double C_RATE, bool& A, bool& B, bool& C);
void test_at_least_two_alive();
const double A_HIT_RATE = (1.0/3.0), B_HIT_RATE = 0.5, C_HIT_RATE = 1;
const int NUMBER_OF_DUELS = 10000;


int main(int argc, const char * argv[]) {
    cout << "*** Welcome to the Duel Simulator ***" << endl;
    test_at_least_two_alive(); //run test driver for ALTA function
    bool A_alive, B_alive, C_alive; //boolean values for state of well-being of our puzzle-solvers
    int aCount = 0; //aCount, bCount, cCount are values for how many times
    int bCount = 0; //  each particular person wins a duel.
    int cCount = 0;
    srand(time(0));
    cout << "Press Enter to continue...";
    cin.get();
    cout << "Ready to test strategy 1 (run 10000 times)\nPress Enter to continue...";
    cin.get();
    // run the first simulation (sim1) ten thousand times.
    for (int i = 0; i < NUMBER_OF_DUELS; i++) {
        int winner = sim1(A_HIT_RATE, B_HIT_RATE, C_HIT_RATE, A_alive, B_alive, C_alive);
        //winner is the value for which person wins, specified in sim1
        if (winner == 0) {
            aCount++;
        }
        else if (winner == 1) {
            bCount++;
        }
        else if (winner == 2) {
            cCount++;
        }
    }
    
    double s1p = aCount/100.0; //strategy 1 percentage
    cout << "Aaron won " << aCount << "/10000 duels or " << s1p << "%" << endl;
    cout << "Bob won " << bCount << "/10000 duels or " << bCount/100.0 << "%" << endl;
    cout << "Charlie won " << cCount << "/10000 duels or " << cCount/100.0 << "%\n" << endl;
    aCount = 0;//
    bCount = 0;//   reset all values back to zero
    cCount = 0;//
    cout << "Ready to test strategy 2 (run 10000 times)\nPress Enter to continue...";
    cin.get();
    for (int i = 0; i < NUMBER_OF_DUELS; i++) {
        
        int winner = sim2(A_HIT_RATE, B_HIT_RATE, C_HIT_RATE, A_alive, B_alive, C_alive);
        if (winner == 0) {
            aCount++;
        }
        else if (winner == 1) {
            bCount++;
        }
        else if (winner == 2) {
            cCount++;
        }
    }
    double s2p = aCount/100.0; //strategy 2 percentage
    cout << "Aaron won " << aCount << "/10000 duels or " << s2p << "%" << endl;
    cout << "Bob won " << bCount << "/10000 duels or " << bCount/100.0 << "%" << endl;
    cout << "Charlie won " << cCount << "/10000 duels or " << cCount/100.0 << "%\n" << endl;
    //Determine which strategy is best.
    if (s1p > s2p) {
        cout << "Strategy 1 is better than Strategy 2" << endl;
    }
    else if (s2p > s1p) {
        cout << "Strategy 2 is better than Strategy 1" << endl;
    }
    return 0;
}


int sim1(double A_RATE, double B_RATE, double C_RATE, bool& A, bool& B, bool& C) {
    A = true;
    B = true;
    C = true;
    while (at_least_two_alive(A, B, C)) {
                if (A) {
                    Aaron_shoots1(B, C);
                }
                if (B) {
                    Bob_shoots(A, C);
                }
                if (C) {
                    Charlie_shoots(A, B);
                }
    }
    int winner = -1;
    if (A) {
        winner = 0;
    }
    else if (B) {
        winner = 1;
    }
    else if (C) {
        winner = 2;
    }
    return winner;
}

int sim2(double A_RATE, double B_RATE, double C_RATE, bool& A, bool& B, bool& C) {
    A = true;
    B = true;
    C = true;
    while (at_least_two_alive(A, B, C)) {
        if (A) {
            Aaron_shoots2(B, C);
        }
        if (B) {
            Bob_shoots(A, C);
        }
        if (C) {
            Charlie_shoots(A, B);
        }
    }
    int winner = -1;
    if (A) {
        winner = 0;
    }
    else if (B) {
        winner = 1;
    }
    else if (C) {
        winner = 2;
    }
    return winner;
}

bool shoot(double rate) {
    
    int roll = rand()%100;
    if (roll <= rate*100) {
        return true;
    }
    return false;
}

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    bool parts[3] = {A_alive, B_alive, C_alive};
    int alive = 0;
    for (int i = 0; i < 3; i++) {
        if (parts[i] == true) {
            alive++;
        }
        if (alive > 1) {
            return true;
        }
    }
    return false;
}


void Aaron_shoots1(bool& B_alive, bool& C_alive) {
    bool hit = shoot(A_HIT_RATE);
    if (hit && C_alive) {
        C_alive = false;
    }
    else if (hit && B_alive) {
        B_alive = false;
    }
}


void Bob_shoots(bool& A_alive, bool& C_alive) {
    bool hit = shoot(B_HIT_RATE);
    if (hit && C_alive) {
        C_alive = false;
    }
    else if (hit && A_alive) {
        A_alive = false;
    }
}


void Charlie_shoots(bool& A_alive, bool& B_alive) {
    if (B_alive) {
        B_alive = false;
    }
    else if (A_alive) {
        A_alive = false;
    }
}


void Aaron_shoots2(bool& B_alive, bool& C_alive) {
    if (!B_alive || !C_alive) {
        bool hit = shoot(A_HIT_RATE);
        if (hit) {
            B_alive = false;
            C_alive = false;
        }
    }
}

void test_at_least_two_alive() {
    cout << "Unit Testing 1: Function – at_least_two_alive()\n";
    
    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "\tCase passed ...\n";
    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));
    cout << "\tCase passed ...\n";
    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));
    cout << "\tCase passed ...\n";
    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));
    cout << "\tCase passed ...\n";
    cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == at_least_two_alive(false, false, true));
    cout << "\tCase passed ...\n";
    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false));
    cout << "\tCase passed ...\n";
    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(true, false, false));
    cout << "\tCase passed ...\n";
    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(false, false, false));
    cout << "\tCase passed ...\n";
}
