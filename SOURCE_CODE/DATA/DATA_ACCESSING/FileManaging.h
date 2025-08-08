#ifndef FILEMANAGING_H
#define FILEMANAGING_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class FileManager{
private:
    vector<string> fileReader(const string& input);
    void fileWriter(const string& output, const vector<string>& input);

    friend class ParserStudent;
    friend class ParserTeacher;
    friend class ScoreParser;
    friend class ParserCourse;
    friend class ParserClassSection;
};



#endif