#include <cstdio>
using namespace std;

int main() {
    register int N;
    unsigned int x;
    for (scanf("%d", &N); N; --N) {
        scanf("%u", &x);
        printf("%u\n", ~x);
    }
    return 0;
}
