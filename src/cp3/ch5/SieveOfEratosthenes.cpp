#include <bitset>                                                       // compact STL for Sieve, better than vector<bool>!
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;                                                         // ll is defined as: typedef long long ll;
bitset<10000010> bs;                                                    // 10^7 should be enough for most cases
vi primes;                                                              // compact list of primes in form of vector<int>

// O(N * loglogN)
void sieve(ll upperbound) {                                             // create list of primes in [0..upperbound]
    _sieve_size = upperbound + 1;                                       // add 1 to include upperbound
    bs.set();                                                           // set all bits to 1
    bs[0] = bs[1] = 0;                                                  // except index 0 and 1

    for (ll i = 2; i <= _sieve_size; i++) 
    if (bs[i]) {                                
        for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;         // cross out multiples of i starting from i * i!
        primes.push_back((int)i);                                       // add this prime to the list of primes
    } 
} // call this method in main method


bool isPrime(ll N) {                                                    // a good enough deterministic prime tester
    if (N <= _sieve_size) return bs[N];                                 // O(1) for small primes
    for (int i = 0; i < (int)primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;                                                        // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in vi "primes")^2

int main() {
    sieve(10000000);                                                    // can go up to 10^7 (need few seconds)
    printf("%d\n", isPrime(2147483647));                                // 10-digits prime
    printf("%d\n", isPrime(136117223861LL));                            // not a prime, 104729*1299709
    
    return 0;
}