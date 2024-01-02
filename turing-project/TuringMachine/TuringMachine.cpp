#include "TuringMachine.h"
using namespace std;

TuringMachine::TuringMachine(vector<string> &state, vector<string> &finalstate, string startstate, char blank, int tapenum, bool print):
start(startstate), blankchar(blank), print(print) 
{
    for(int i=0;i<state.size();i++){
        State s0(state[i], blankchar);
        statelst.insert(pair<string,State>(state[i], s0));
    }
    for(int i=0;i<finalstate.size();i++){
        statelst[finalstate[i]].setFinal(true);
    }
    for(int i=0;i<tapenum;i++){
        tapelst.push_back("");
        tapeidx.push_back(0);
        offset.push_back(0);
    }
}
void TuringMachine::loadTransRule(vector<string> rule){
    Trans trule(rule[4],rule[1],rule[2],rule[3],blankchar);
    statelst[rule[0]].loadTrans(trule);
}

string TuringMachine::getcharlst(){
    string charlst="";
    for(int i=0;i<tapelst.size();i++){
        charlst += tapelst[i][tapeidx[i]];
    }
    return charlst;
}
void TuringMachine::updatecharlst(string newlst, string movelst){
    for(int i=0;i<tapelst.size();i++){
        tapelst[i][tapeidx[i]]=newlst[i];
        if(movelst[i]=='l'){
            if(tapeidx[i]==0){
                tapelst[i]=blankchar+tapelst[i];
                offset[i]++;
            }
            else tapeidx[i]--;
        }
        else if(movelst[i]=='r'){
            tapeidx[i]++;
            if(tapeidx[i]==tapelst[i].length())tapelst[i]=tapelst[i]+blankchar;
        }
    }
}
bool TuringMachine::statetrans(){
    if(print)printstep();
    State s0=statelst[nowstate];
    string charlst=getcharlst();
    Trans rule;
    if(s0.getTrans(charlst, rule)){
        step++;
        updatecharlst(
            rule.getNewcharlst(charlst),
            rule.getMovelst()
        );
        nowstate=rule.getTarget();
        return true;
    }
    else return false;
}
void TuringMachine::reset(){
    step=0;
    nowstate = start;
    accept = false;
    for(int i=0;i<tapelst.size();i++){
        tapeidx[i]=0;
        tapelst[i]="_";
    }
}
bool TuringMachine::runTuringMachine(string str){
    reset();
    if(str!="")tapelst[0]=str;
    if(print)printinput();
    while(statetrans())
        if(statelst[nowstate].getFinal())accept=true;
    printfinal();
    return accept;
}
void TuringMachine::printstep(){
    vector<string> idx, tape, head;
    for(int i=0;i<tapelst.size();i++){
        string idxs="", tapes="", heads="";
        int start=tapelst[i].size(), end=0;
        for(int j=0;j<tapelst[i].size();j++){
            if(tapelst[i][j]!=blankchar){
                start=j;
                break;
            }
        }
        start=min(start, tapeidx[i]);
        for(int j=tapelst[i].size()-1;j>=0;j--){
            if(tapelst[i][j]!=blankchar){
                end=j+1;
                break;
            }
        }
        end=max(end, tapeidx[i]+1);
        for(int j=start;j<end;j++){
            int elen;
            char entry[20];
            sprintf(entry, "%d ", abs(j-offset[i]));
            idxs+=entry;
            elen=strlen(entry);
            entry[0]=tapelst[i][j];
            for(int k=1;k<elen;k++)entry[k]=' ';
            entry[elen]='\0';
            tapes+=entry;
            entry[0]=(j==tapeidx[i])? '^' : ' ';
            for(int k=1;k<elen;k++)entry[k]=' ';
            entry[elen]='\0';
            heads+=entry;
        }
        idx.push_back(idxs);
        tape.push_back(tapes);
        head.push_back(heads);
    }
    printf("Step   : %d\n", step);
    printf("State  : %s\n", nowstate.c_str());
    printf("Acc    : %s\n", accept? "Yes" : "No");
    for(int i=0;i<idx.size();i++){
        printf("Index%d : %s\n", i, idx[i].c_str());
        printf("Tape%d  : %s\n", i, tape[i].c_str());
        printf("Head%d  : %s\n", i, head[i].c_str());
    }
    printf("--------------------------------\n");
}
void TuringMachine::printfinal(){
    int start=tapelst[0].size(), end=0;
    for(int j=0;j<tapelst[0].size();j++){
        if(tapelst[0][j]!=blankchar){
            start=j;
            break;
        }
    }
    for(int j=tapelst[0].size()-1;j>=0;j--){
        if(tapelst[0][j]!=blankchar){
            end=j+1;
            break;
        }
    }
    string res="";
    for(int j=start;j<end;j++){
        res+=tapelst[0][j];
    }
    if(print){
        printf("%s\n", accept? "ACCEPTED" : "UNACCEPTED");
        printf("Result : %s\n", res.c_str());
        printf("==============END===============\n");
    }
    else{
        printf("(%s) %s\n", accept? "ACCEPTED" : "UNACCEPTED", res.c_str());
    }
}
void TuringMachine::printinput(){
    printf("Input : %s\n", tapelst[0].c_str());
    printf("==============RUN===============\n");
}