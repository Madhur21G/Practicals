#include "bits/stdc++.h"
using namespace std;

string XOR(string a, string b) {
    string result = "";
    for (int i = 1; i < b.length(); i++)
        result += (a[i] == b[i] ? '0' : '1');
    return result;
}

string mod2div(string dividend, string divisor) {
    int pick = divisor.length();
    string temp = dividend.substr(0, pick);
    while (pick < dividend.length()) {
        if (temp[0] == '1')
            temp = XOR(divisor, temp) + dividend[pick];
        else
            temp = XOR(string(pick, '0'), temp) + dividend[pick];
        pick += 1;
    }
    if (temp[0] == '1')
        temp = XOR(divisor, temp);
    else
        temp = XOR(string(pick, '0'), temp);
    return temp;
}

void encodeData(string data, string key) {
    int keyLen = key.length();
    string appendedData = data + string(keyLen - 1, '0');
    string remainder = mod2div(appendedData, key);
    string codeword = data + remainder;
    cout << "Remainder: " << remainder << endl;
    cout << "Encoded Data (Codeword): " << codeword << endl;
}

int main() {
    string data, key;
    cout << "Enter the data: ";
    cin >> data;
    cout << "Enter the divisor (generator polynomial): ";
    cin >> key;
    encodeData(data, key);
    return 0;
}
//Enter the data: 11010011101100
//Enter the divisor (generator polynomial): 1011