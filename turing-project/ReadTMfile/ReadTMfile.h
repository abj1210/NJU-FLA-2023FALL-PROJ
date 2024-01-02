#ifndef RTF
#define RTF

#define HW

#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stdio.h>
using namespace std;
class ReadTMfile
{
private:
        vector<string> stateset, finalset;
        set<char> Sset, Gset;
        set<string> STset;
        string start, input;
        int tapenum;
        char blankchar;
        queue<vector<string> > rulelst;
        FILE *file;
        int line, step;
        /*
        0:No error
        1:File not found
        2:File too short
        3:Buffer overflow
        4:Syntax error
        5:Invalid char
        6:Start state not found
        7:Final state not found
        8:Invalid tape number
        9:State not found
        10:Tape num not match
        11:Char not found
        12:Invalid movement
        */
        int errorno;
        vector<string> readrule(string str,string split);
        bool readline(char * buf);
        bool readStateSet();
        bool readCharSet(char mode);
        bool readStartState();
        bool readBlankChar();
        bool readFinalSet();
        bool readTapeNum();
        bool pushTransRule();
        bool checkInput();
public:
    ReadTMfile(const char * filename, const char * input);
    vector<string> getStateSet(){return stateset;};
    string getStartState(){return start;};
    char getBlankChar(){return blankchar;};
    vector<string> getFinalSet(){return finalset;};
    int getTapeNum(){return tapenum;};
    queue<vector<string> > getRuleList(){return rulelst;};
    int checkError();
    string getInput(){return input;};
    void printInvInput();
};


#endif