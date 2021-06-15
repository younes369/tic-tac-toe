#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    vector<int> vect{10, 20, 30, 50, 70, 80};
    auto it = find(vect.begin(), vect.end(), 20);
    vect.erase(it);
    auto it2 = find(vect.begin(), vect.end(), 80);
    vect.erase(it2);

    cout << vect[(vect.size() - 1)];
}