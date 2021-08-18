#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

void Pour(int a, int b, pii cur);
void BFS(int a, int b, int target);

// Map is used to store the states, every
// state is hashed to binary value to
// indicate either that state is visited
// before or not
// number of steps to (X , Y ) State
map<pii, int> level;
queue<pii> q; // queue to maintain states

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    BFS(a, b, c);
    return 0;
}

// Change state of jugs from ( u1 , u2 ) to (a , b )
void Pour(int a, int b, pii cur) {
    // if this state isn't visited
    if (level[{a, b}] == 0) {
        // save
        q.push({a, b});
        level[{a, b}] = level[{cur.first, cur.second}] + 1;
    }
}

void BFS(int a, int b, int target) {
    bool isSolvable = false;
    level.clear();
    q = queue<pii>();
    q.push({0, 0}); // init state
    level[{0, 0}] = 1;

    while (!q.empty()) {
        pii u = q.front (); // current state
        q . pop (); // pop off used state
        // if we reach solution state
        if ( u.first == target || u.second == target ){
            isSolvable = true ;
            cout << level [{ u . first , u . second }] - 1;
            break ;
        }
        Pour ( u.first , b, u ); // fill Jug2
        Pour (a , u.second, u ); // fill Jug1
        Pour ( u.first , 0, u ); // Empty Jug2
        Pour (0 , u.second, u ); // Empty Jug1

        for (int ap = 0; ap <= max(a, b); ap ++) {
            // pour amount ap from Jug2 to Jug1
            int c = u.first + ap ;
            int d = u.second - ap ;
            // check if this state is possible
            if (( c == a && d >= 0) || ( d == 0 && c <= a )) Pour(c , d , u );
            // Pour amount ap from Jug 1 to Jug2
            c = u.first - ap ;
            d = u.second + ap ;
            // check if this state is possible
            if (( c == 0 && d <= b ) || ( d == b && c >= 0)) Pour (c , d , u );
        }
    }

    // no solutions
    if (!isSolvable) cout << -1;
}

/**
   The operations you can perform are:

   Empty a Jug, (X, Y)->(0, Y) Empty Jug 1
   Fill a Jug, (0, 0)->(X, 0) Fill Jug 1
   Pour water from one jug to the other until one of the jugs is either empty or full, (X, Y) -> (X-d, Y+d)
*/