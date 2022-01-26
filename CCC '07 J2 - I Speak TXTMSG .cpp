#include <bits/stdc++.h>
using namespace std;

int Speak() {
    string x;
    while (cin >> x) {
        map<string, string> KeyPair = {{"CU",    "see you"},
                                       {":-)",   "I'm happy"},
                                       {":-(",   "I'm unhappy"},
                                       {";-)",   "wink"},
                                       {":-P",   "stick out my tongue"},
                                       {"(~.~)", "sleepy"},
                                       {"TA",    "totally awesome"},
                                       {"CCC",   "Canadian Computing Competition"},
                                       {"CUZ",   "because"},
                                       {"TY",    "thank-you"},
                                       {"YW",    "you're welcome"},
                                       {"TTYL",  "talk to you later"}};
        string result = KeyPair[x];
        cout << (result.length() == 0 ? x : result) << endl;
    }
    return 0;
}
