#include "TuringMachine.h"
#include "ReadTMfile.h"
#include <bits/stdc++.h>

using namespace std;
int runTm(const char * filename, const char * input, bool print){
    //加载图灵机文件
    ReadTMfile reader(filename,input);
    //检查错误
    int res = reader.checkError();
    if(res == 13)
        if(print)reader.printInvInput();
        else fprintf(stderr, "illegal input string\n");
    if(res!=0)return res;
    //初始化图灵机
    vector<string> stateset = reader.getStateSet(), finalset = reader.getFinalSet();
    TuringMachine tm(stateset, finalset, 
    reader.getStartState(), 
    reader.getBlankChar(), 
    reader.getTapeNum(),
    print
    );
    //添加转移函数
    queue<vector<string> >rulelst = reader.getRuleList();
    while(!rulelst.empty()){
        tm.loadTransRule(rulelst.front());
        rulelst.pop();
    }
    //运行
    tm.runTuringMachine(reader.getInput());
    return 0;
}
int main(int argc, char * argv[]){
    if(argc==2&&(string(argv[1])=="--help"||string(argv[1])=="-h")){
        printf("usage: turing [-v|--verbose] [-h|--help] <tm> <input>\n");
        return 0;
    }
    else if(argc==3)return runTm(argv[1], argv[2], false);
    else if(argc==4&&(string(argv[1])=="--verbose"||string(argv[1])=="-v"))
        return runTm(argv[2], argv[3], true);
    else {
        printf("Invalid input args, usage: turing [-v|--verbose] [-h|--help] <tm> <input>\n");
        return -1;
    }
}