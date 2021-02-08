#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main()
{
    // Decimal --> Binary
    std::string binary = std::bitset<8>(128).to_string(); //to binary
    std::cout<<binary<<"\n";
    // Binary --> Decimal
    unsigned long decimal = std::bitset<8>(binary).to_ulong();
    std::cout<<decimal<<"\n";
    return 0;
    


    // Hamming Distance
    int a = 5, b = 9;
    int c = a ^ b;
    int ans = 0;
    while (c > 0) {
        ans += c & 1;
        c >>= 1;
    }
    cout << ans;
    // Print: 2
    // 5: 0101, 9: 1001
    // => c = 1100 
    // => ans = 2 digits


    // L1 Distance
    
    return 0;
}
