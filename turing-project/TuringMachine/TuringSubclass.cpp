#include "TuringMachine.h"
#include <algorithm>
using namespace std;
TuringMachine::Charlst::Charlst(string str,char blankchar):
    string(str),blankchar(blankchar){}
bool TuringMachine::Charlst::operator==(const TuringMachine::Charlst str) const{
    for(int i=0;i<this->length();i++){
        if((*this)[i]=='*'){
            if(str[i]==blankchar)return false;
        }
        else if(str[i]=='*'){
            if((*this)[i]==blankchar)return false;
        }
        else{
            if(str[i]!=(*this)[i])return false;
        }
    }
    return true;
}
string TuringMachine::Charlst::format(string str){
    string newstr="";
    for(int i=0;i<str.length();i++){
        if((*this)[i]!='*')newstr+=(*this)[i];
        else newstr+=str[i];
    }
    return newstr;
}

TuringMachine::Trans::Trans(string target, string charlst, string newlst, string movelst,const char blankchar):
    target(target), charlst(charlst, blankchar), newlst(newlst, blankchar), movelst(movelst) {}
bool TuringMachine::Trans::eq(TuringMachine::Charlst cl){
    return this->charlst==cl;
}
string TuringMachine::Trans::getNewcharlst(string str){
    return newlst.format(str);
}
string TuringMachine::Trans::getTarget(){
    return target;
}
string TuringMachine::Trans::getMovelst(){
    return movelst;
}

TuringMachine::State::State(string name, const char blankchar):
    name(name), blankchar(blankchar), finalstate(false){};
void TuringMachine::State::setFinal(bool finalstate){
    this->finalstate = finalstate; 
}
bool TuringMachine::State::getFinal(){
    return this->finalstate;
}
void TuringMachine::State::loadTrans(TuringMachine::Trans transrule){
    translst.push_back(transrule);
}
bool TuringMachine::State::getTrans(string charlst, TuringMachine::Trans &rule){
    vector<TuringMachine::Trans>::iterator it;
    for(it=translst.begin();it!=translst.end();++it)
         if(it->eq(Charlst(charlst,blankchar)))break;
    if(it==translst.end())return false;
    else {
        rule = *it;
        return true;
    }
}