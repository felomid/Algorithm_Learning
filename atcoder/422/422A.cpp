#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>  

#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define eb emplace_back
#define mp make_pair

typedef long long ll;
typedef std::pair<int,int> pii;
using std::cin;
using std::cout;
using std::endl;

int main(){
    int s, g;
    scanf("%d-%d", &s, &g);
    g++;
    if (g > 8) {
        s++;
        g = 1;
    }
    cout << s << '-' << g << endl;
    return 0;
}