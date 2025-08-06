#include "FileManaging.h"

using namespace std;

vector<string> FileManager::fileReader(const string& input){
    const string path = "../STORAGE/";      // duong dan den thu muc STORAGE
    string fullPath = path + input;

    ifstream fin(fullPath);
    if(!fin){
        std::cerr << "Không thể mở file: " << fullPath << std::endl;
        return;
    }

    string line = "";
    vector<string> result;
    while(getline(fin, line)){
        result.push_back(line);
    }
    fin.close();
    return result;
}

void FileManager::fileWriter(const string& output, const vector<string>& input){
    const string path = "../STORAGE/";      // duong dan den thu muc STORAGE
    string fullPath = path + output;

    ofstream fout(fullPath);
    if(!fout){
        std::cerr << "Không thể mở file: " << fullPath << std::endl;
        return;
    }

    for(string line : input){
        fout << line << '\n';
    }
    fout.close();
}