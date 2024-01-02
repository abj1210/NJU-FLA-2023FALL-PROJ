#include "ReadTMfile.h"
#include <string.h>
using namespace std;
vector<string> ReadTMfile::readrule(string str,string split){
    vector<string> res;
    size_t pos = 0;
    while ((pos = str.find(split)) != string::npos) {
        res.push_back(str.substr(0, pos));
        str.erase(0, pos + 1);
    }
    res.push_back(str);
    return res;
}
bool ReadTMfile::readline(char * buf){
    while(true){
        if(fgets(buf, 1024, file)==NULL){
            errorno = 2;
            return false;
        }
        line++;
        if(buf[0]!='\n'&&buf[0]!=';')break;
    }
    if(buf[strlen(buf)-1]!='\n'){
        errorno = 3;
        return false;
    }
    return true;
}
bool ReadTMfile::readStateSet(){
    char buf[1024], setlst[1024];
    if(!readline(buf))return false;
    if(sscanf(buf, "#Q = {%[a-zA-Z0-9_,]}\n", setlst)!=1){
        errorno = 4;
        return false;
    }
    string str(setlst);
    stateset = readrule(str, ",");
    for(int i=0;i<stateset.size();i++){
        STset.insert(stateset[i]);
    }
    return true;
}
bool ReadTMfile::readCharSet(char mode){
    char buf[1024], setlst[1024];
    if(!readline(buf))return false;
    if(mode=='S'){
        if(sscanf(buf, "#S = {%[^ ;{}*_]}\n", setlst)!=1){
            errorno = 4;
            return false;
        }
    }
    else{
        if(sscanf(buf, "#G = {%[^ ;{}*]}\n", setlst)!=1){
            errorno = 4;
            return false;
        }
    }
    string str(setlst);
    vector<string> strset = readrule(str, ",");
    for(int i=0;i<strset.size();i++){
        if(strset[i].length()!=1){
            errorno = 5;
            return false;
        }
        if(mode=='S')Sset.insert(strset[i][0]);
        else Gset.insert(strset[i][0]);
    }
    return true;
}
bool ReadTMfile::readStartState(){
    char buf[1024], str[1024];
    if(!readline(buf))return false;
    if(sscanf(buf, "#q0 = %s\n", str)!=1){
        errorno = 4;
        return false;
    }
    start = str;
    if(STset.find(start)==STset.end()){
        errorno = 6;
        return false;
    }
    return true;
}
bool ReadTMfile::readBlankChar(){
    char buf[1024];
    if(!readline(buf))return false;
    if(sscanf(buf, "#B = %c\n", &blankchar)!=1){
        errorno = 4;
        return false;
    }
    return true;
}
bool ReadTMfile::readFinalSet(){
    char buf[1024], setlst[1024];
    if(!readline(buf))return false;
    if(sscanf(buf, "#F = {%[a-zA-Z0-9_,]}\n", setlst)!=1){
        errorno = 4;
        return false;
    }
    string str(setlst);
    finalset = readrule(str, ",");
    for(int i=0;i<finalset.size();i++){
        if(STset.find(finalset[i])==STset.end()){
            errorno = 7;
            return false;
        }
    }
    return true;
}
bool ReadTMfile::readTapeNum(){
    char buf[1024];
    if(!readline(buf))return false;
    if(sscanf(buf, "#N = %d\n", &tapenum)!=1){
        errorno = 4;
        return false;
    }
    if(tapenum<=0){
        errorno = 8;
        return false;
    }
    return true;
}
bool ReadTMfile::pushTransRule(){
    char buf[1024];
    if(!readline(buf))return false;
    buf[strlen(buf)-1]='\0';
    vector<string> rule=readrule(buf, " ");
    if(rule.size()<5){
        errorno = 4;
        return false;
    }
    if(STset.find(rule[0])==STset.end()){
        errorno = 9;
        return false;
    }
    if(STset.find(rule[4])==STset.end()){
        errorno = 9;
        return false;
    }
    if(rule[1].length()!=tapenum||rule[2].length()!=tapenum||rule[3].length()!=tapenum){
        errorno = 10;
        return false;
    }
    for(int i=0;i<tapenum;i++){
        if(Gset.find(rule[1][i])==Gset.end()){
            errorno = 14;
            return false;
        }
        if(Gset.find(rule[2][i])==Gset.end()){
            errorno = 11;
            return false;
        }
        if(rule[3][i]!='l'&&rule[3][i]!='r'&&rule[3][i]!='*'){
            errorno = 12;
            return false;
        }
    }
    rulelst.push(rule);
    return true;
}
bool ReadTMfile::checkInput(){
    for(int i=0;i<input.length();i++){
        if(Sset.find(input[i])==Sset.end()){
            errorno = 13;
            step = i;
            return false;
        }
    }
    return true;
}
ReadTMfile::ReadTMfile(const char * filename, const char * input):
input(input), line(0)
{
    file = fopen(filename, "r");
    if(file == NULL){
        errorno = 1;
        return ;
    }
    Gset.insert('*');
    if(!readStateSet())return ;
    if(!readCharSet('S'))return ;
    if(!readCharSet('G'))return ;
    if(!readStartState())return ;
    if(!readBlankChar())return ;
    if(!readFinalSet())return ;
    if(!readTapeNum())return ;
    while(pushTransRule());
    if(errorno == 2)errorno = 0;
    else if(errorno !=0)return ;
    if(!checkInput())return ;
    return ;
}
int ReadTMfile::checkError(){
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
    13:Invalid input
    */
#ifndef HW
    switch (errorno)
    {
    case 0:
        fprintf(stderr, "File check OK!");
        break;
    case 1:
        fprintf(stderr, "File not found!");
        break;
    case 2:
        fprintf(stderr, "File too short!");
        break;    
    case 3:
        fprintf(stderr, "Buffer overflow!");
        break;
    case 4:
        fprintf(stderr, "Syntax error!");
        break;
    case 5:
        fprintf(stderr, "Invalid char!");
        break;
    case 6:
        fprintf(stderr, "Start state not found!");
        break;
    case 7:
        fprintf(stderr, "Final state not found!");
        break;
    case 8:
        fprintf(stderr, "Invalid tape number!");
        break;
    case 9:
        fprintf(stderr, "State not found!");
        break;
    case 10:
        fprintf(stderr, "Tape num not match!");
        break;
    case 11:
        fprintf(stderr, "Char not found!");
        break;
    case 12:
        fprintf(stderr, "Invalid movement!");
        break;
    case 13:
        fprintf(stderr, "Invalid input!");
        break;
    default:
        fprintf(stderr, "??? This is a unknown error %d!", errorno);
        break;
    }
    if(errorno != 0)fprintf(stderr, " At line %d.\n", line);
#else
    if(errorno!=0&&errorno!=13)fprintf(stderr, " syntax error\n");
#endif
    return errorno;
}
void ReadTMfile::printInvInput(){
    fprintf(stderr, "Input : %s\n", input.c_str());
    fprintf(stderr, "==============ERR===============\n");
    fprintf(stderr, "Error : Symbol \"%c\" in input is not defined in the set of input symbols\n", input[step]);
    fprintf(stderr, "Input : %s\n", input.c_str());
    string str="        ";
    for(int i=0;i<step;i++)str+=" ";
    str+="^";
    fprintf(stderr, "%s\n", str.c_str());
    fprintf(stderr, "==============END===============\n");
}