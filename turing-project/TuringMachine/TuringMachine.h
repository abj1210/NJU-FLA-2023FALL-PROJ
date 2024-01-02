#ifndef TM
#define TM

#include <map>
#include <vector>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
class TuringMachine
{
private:
    class Charlst : public string{
        char blankchar;
    public:
        //构造函数
        Charlst(){};
        Charlst(string str,char blankchar);
        //重载相等号
        bool operator==(const Charlst str) const;
        //更新字符列表
        string format(string str);
    };
    class Trans{
        //目标状态
        string target;
        //转移字符列表,新字符列表
        Charlst charlst, newlst;
        //读写头移动列表
        string movelst;
    public:
        //构造函数
        Trans(){};
        Trans(string target, string charlst, string newlst, string movelst,char blankchar);
        //判断相等
        bool eq(Charlst cl);
        //获取新字符列表
        string getNewcharlst(string str);
        //获取目标状态
        string getTarget();
        //获取移动列表
        string getMovelst();
    };
    class State
    {
        //状态名
        string name;
        char blankchar;
        //是否为终态
        bool finalstate;
        //转移规则集
        vector<Trans> translst;
    public:
        //构造函数
        State(){};
        State(string name, char blankchar);
        //设置最终状态
        void setFinal(bool finalstate);
        //获取最终状态
        bool getFinal();
        //加载转移规则
        void loadTrans(Trans transrule);
        //获取转移规则
        bool getTrans(string charlst, Trans &rule);
    };
    //运行步数
    int step;
    //状态映射
    map<string, State> statelst;
    //纸带集
    vector<string> tapelst;
    //读写头位置,偏移量
    vector<int> tapeidx, offset;
    //当前状态
    string nowstate;
    //初始状态
    const string start;
    //空字符
    const char blankchar;
    //是否接收串
    bool accept;
    //是否打印详细信息
    bool print;
    //获取当前读写头指向的字符列表
    string getcharlst();
    //更新纸带字符
    void updatecharlst(string newlst, string movelst);
    //进行一部状态转移
    bool statetrans();
    //重置图灵机
    void reset();
    //打印步骤信息
    void printstep();
    //打印最终信息
    void printfinal();
    //打印输入信息
    void printinput();
public:
    //图灵机初始化
    TuringMachine(vector<string> &state, vector<string> &finalstate, string startstate, char blank, int tapenum, bool print);
    //加载转移规则
    void loadTransRule(vector<string> rule);
    //运行图灵机
    bool runTuringMachine(string str);
};

#endif