#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

// available hashes: MD5, SHA1, SHA256

using namespace std;

int main(int, char**)
{   
    string clear = "password";
    hash<string> hasher;
    cout << hasher(clear);
    return 0;
}
