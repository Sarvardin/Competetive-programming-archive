#include <iostream>


#include <string>
#include <algorithm> // Required for std::transform
#include <cctype>    // Required for std::tolower

int main() {

    int n;
    std::cin >> n;
    std::string str;
    for (int i = 0; i < n; i++) {
        std::cin >> str;

    // Convert the string to lowercase in-place
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
    if (str == "yes") {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }


    }
    
    return 0;
}
    