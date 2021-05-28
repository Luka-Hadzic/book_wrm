#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << ":::::::::   ::::::::   ::::::::  :::    :::           :::       ::: :::::::::  ::::    ::::  \n";
    cout << ":+:    :+: :+:    :+: :+:    :+: :+:   :+:            :+:       :+: :+:    :+: +:+:+: :+:+:+ \n";
    cout << "+:+    +:+ +:+    +:+ +:+    +:+ +:+  +:+             +:+       +:+ +:+    +:+ +:+ +:+:+ +:+ \n";
    cout << "+#++:++#+  +#+    +:+ +#+    +:+ +#++:++              +#+  +:+  +#+ +#++:++#:  +#+  +:+  +#+ \n";
    cout << "+#+    +#+ +#+    +#+ +#+    +#+ +#+  +#+             +#+ +#+#+ +#+ +#+    +#+ +#+       +#+ \n";
    cout << "#+#    #+# #+#    #+# #+#    #+# #+#   #+#             #+#+# #+#+#  #+#    #+# #+#       #+# \n";
    cout << "#########   ########   ########  ###    ### ##########  ###   ###   ###    ### ###       ### \n";

    cout << "Welcome to book_wrm, a bure force dictionary attack program\n";
    cout << "Type the hash bellow:\n";
    string hash_str;
    cin >> hash_str;

    // prepare file and all dependancies 
    string line;
    int rockyou_count;

    ifstream rockyou ("rockyou.txt");
    cout << "reading from rockyou wordlist..." << '\n';

    // itterate thru file and just count the numer of lines for mem alocation l8r 
    while (getline(rockyou, line))
    {
        rockyou_count++;
    }
    rockyou.close();
    cout << "read " << rockyou_count << " lines.\n";
    
    cout << "read total of " << rockyou_count << " lines.\n";

    // start alocating mem for plaintext passwords
    cout << "allocating memory...\n";
    string * clear_mem;
    clear_mem = new (nothrow) string[rockyou_count];

    string * hash_mem;
    hash_mem = new (nothrow) string[rockyou_count];

    // check if mem could be alocated
    if (clear_mem == nullptr || hash_mem == nullptr)
    {
        cout << "memory could not be reserved.\n";
    } else {
        cout << "memory reserved.\n";

        ifstream rockyoutwo ("rockyou.txt");
        cout << "adding rockyou plaintext to memory...\n";
        int count = 0;

        // actually read from file and write into mem
        while (getline(rockyoutwo, line))
        {
            clear_mem[count] = line;
            count++;
        }
        rockyoutwo.close();
        count = 0;

        ifstream rockyouthree ("rockyou_hash.txt");
        cout << "adding rockyou ciphertext to memory...\n";

        // read from pre hashed list and add to diffrent block of mem
        while (getline(rockyouthree, line))
        {
            hash_mem[count] = line;
            count++;
        }
        rockyouthree.close();
        count = 0;

        int index = -1;

        // comprison fucntion, exits as soon as a match is found
        for (size_t i = 0; i < rockyou_count; i++)
        {
            if (hash_str == hash_mem[i])
            {
                cout << "Match found\n";
                index = i;
                i = rockyou_count;
            }
        }

        if (index == -1)
        {
            cout << "Could not find hash, try a larger wordlist\n";
        } else 
        {
            cout << "Password found, hash " << hash_str << " correlates to '" << clear_mem[index] << "'\n";
        }
        
        
    }

    // release the mallocs
    delete[] clear_mem;
    delete[] hash_mem;

    return 0;
}