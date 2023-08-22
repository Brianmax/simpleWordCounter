#include <bits/stdc++.h>
using namespace std;
int main() {
    const char* filename = "file.txt";

    std::ifstream file(filename, std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    char byte;
    string word;
    vector<string> words;
    while (file.read(&byte, 1)) {
        stringstream ss;
        ss<<byte;
        string letter;
        ss>>letter;
        if(byte==32){
            words.push_back(word);
            word.clear();
        }
        else {
            word = word + letter;
        }
    }
    words.push_back(word); //Insert the last word
    std::map<std::string, int> mapWords;
    for(string w: words){
        mapWords[w]++;
    }
    file.close();
    return 0;
}
