#include <bits/stdc++.h>
using namespace std;

// 2022年12月22日17点37分：支持定义整型变量，输出变量
// 2022年12月22日18点29分：支持行末注释，中文变量
// 2022年12月22日18点37分：特判未定义变量
// 2022年12月22日20点02分：实现赋值等
// 2022年12月23日09点46分：实现加法，变量加以及常数加
// 2022年12月23日12点57分：实现定义代码块，由于技术原因仅支持赋值操作；可能重写
// todo 实现加减乘除
// todo 实现初等函数
 
typedef long long llint;

struct Vars
{
    string name;
    string value;
};

struct Instu // 指令块
{

    string name;
    vector<string> lst;
};

struct BiTree{
    int c[114514];
};

vector<Vars>
    mem;

vector<Instu>
    ins;

void printCharA(char t[])
{
    for (int i = 0; i < strlen(t); i++)
        cout << t[i];
}

int sTi(string k)
{
    return atoi(k.c_str());
}

string excptInstr(string temp)
{
    int len = temp.size();
    string t = temp.substr(1, len - 1);

    // 行末注释

    int cur = 0;
    while (cur <= len && t[cur++] != '#')
        ;

    string str = t.substr(0, cur - 1);
    if (str[(int)str.size() - 1] == ' ')
        str.pop_back();

    return str;
}

int printValue()
{
    string con;
    getline(cin, con);
    string str = excptInstr(con);

    for (auto cur : mem)
        if (cur.name == str)
            return cout << cur.value << endl, 0;

    if (str[0] == '\"' && str[str.size() - 1] == '\"')
        return cout << str.substr(1, str.size() - 2) << endl, 0;

    return cout << "Undefine variable \'" << str << '\'' << endl, 0;
}
// print 和 find 功能好像差不多。。没用啊
Vars findVar(string k)
{
    // 查找叫做 k 的变量名的变量，返回变量对象
    for (auto cur : mem)
    {
        // cout << cur.name << ' ' << cur.value << endl;
        if (cur.name == k)
        {
            return cur;
        }
    }
    return (Vars){"NaN", "NaN"};
}

void addVar()
{
    // 处理字符串

    string temp;
    getline(cin, temp);
    int len = temp.size();
    string str = temp.substr(1, len - 1);

    // 处理变量名

    string name;
    int cur = 0;
    while (str[cur] != '\0' && str[cur] != '=')
    {
        name.push_back(str[cur++]);
    }

    char tail = name[(int)name.size() - 1];
    if (tail == ' ')
        name.pop_back();

    // 处理变量值，以字符串形式保存

    string ans;

    if (cur > (int)name.size())
        ans = str.substr(cur + 2, len - 1);
    else
        ans = "NaN";

    mem.push_back({name, ans});
}

void SbtNum()
{
    // pls a b 将 a 加上 b

    string con;
    getline(cin, con);
    string str = excptInstr(con);

    string f;

    int cur = 0;
    int n = str.size();
    while (cur < n && str[cur] != ' ')
        f.push_back(str[cur++]);

    string s;
    cur++;

    while (cur < n && str[cur] != '\0')
        s.push_back(str[cur++]);

    // cout << f << endl << s << endl;

    // 开始寻找

    string n1;

    for (auto cur : mem)
        if (cur.name == f)
            n1 = cur.value;

    // string n1 = ;

    int n11, n22;
    n11 = stoi(n1), n22 = stoi(s); // 摆烂 stoi，以后重写
    int sum = n11 - n22;

    string tmp;

    while (sum)
    {
        char c = (sum % 10) + '0';
        tmp.push_back(c);
        sum /= 10;
    }

    for (auto &cur : mem)
        if (cur.name == f)
            cur.value = tmp;
}

void SbtVar()
{

    string con;
    getline(cin, con);
    string str = excptInstr(con);

    string f;

    int cur = 0;
    int n = str.size();
    while (cur < n && str[cur] != ' ')
        f.push_back(str[cur++]);

    string s;
    cur++;

    while (cur < n && str[cur] != '\0')
        s.push_back(str[cur++]);

    // cout << f << endl << s << endl;

    // 开始寻找

    string n1;

    for (auto cur : mem)
        if (cur.name == f)
            n1 = cur.value;

    string n2;

    for (auto cur : mem)
        if (cur.name == s)
            n2 = cur.value;

    // string n1 = ;

    int n11, n22;
    n11 = stoi(n1), n22 = stoi(n2);
    int sum = n11 - n22;

    string tmp;

    while (sum)
    {
        char c = (sum % 10) + '0';
        tmp.push_back(c);
        sum /= 10;
    }

    for (auto &cur : mem)
        if (cur.name == f)
            cur.value = tmp;
}

void PlusNum()
{
    // pls a b 将 a 加上 b

    string con;
    getline(cin, con);
    string str = excptInstr(con);

    string f;

    int cur = 0;
    int n = str.size();
    while (cur < n && str[cur] != ' ')
        f.push_back(str[cur++]);

    string s;
    cur++;

    while (cur < n && str[cur] != '\0')
        s.push_back(str[cur++]);

    // cout << f << endl << s << endl;

    // 开始寻找

    string n1;

    for (auto cur : mem)
        if (cur.name == f)
            n1 = cur.value;

    // string n1 = ;

    int n11, n22;
    n11 = stoi(n1), n22 = stoi(s);
    int sum = n11 + n22;

    string tmp;

    while (sum)
    {
        char c = (sum % 10) + '0';
        tmp.push_back(c);
        sum /= 10;
    }

    for (auto &cur : mem)
        if (cur.name == f)
            cur.value = tmp;
}

void PlusVar()
{
    // pls a b 将 a 加上 b

    string con;
    getline(cin, con);
    string str = excptInstr(con);

    string f;

    int cur = 0;
    int n = str.size();
    while (cur < n && str[cur] != ' ')
        f.push_back(str[cur++]);

    string s;
    cur++;

    while (cur < n && str[cur] != '\0')
        s.push_back(str[cur++]);

    // cout << f << endl << s << endl;

    // 开始寻找

    string n1;

    for (auto cur : mem)
        if (cur.name == f)
            n1 = cur.value;

    string n2;

    for (auto cur : mem)
        if (cur.name == s)
            n2 = cur.value;

    // string n1 = ;

    int n11, n22;
    n11 = stoi(n1), n22 = stoi(n2);
    int sum = n11 + n22;

    string tmp;

    while (sum)
    {
        char c = (sum % 10) + '0';
        tmp.push_back(c);
        sum /= 10;
    }

    for (auto &cur : mem)
        if (cur.name == f)
            cur.value = tmp;
}

void EqualNum()
{
    // 函数内解析，枯了呜呜呜
    string con;
    getline(cin, con);
    string str = excptInstr(con);

    string name;

    int cur = 0;
    int n = str.size();
    while (cur < n && str[cur] != ' ')
        name.push_back(str[cur++]);

    // name = str.substr(0, cur); // substr 容易越界错误
    // cout << name << endl;

    cur = n - 1;
    while (cur >= 0 && str[cur--] != ' ')
        ;
    string val;
    val = str.substr(cur + 2, n - 1);
    // cout << val << endl;

    for (auto &cur : mem)
        if (cur.name == name)
            cur.value = val;

    // mem.push_back({name, val});
}

void EqualVar()
{
    // 赋值函数
    string con;
    getline(cin, con);
    string str = excptInstr(con);

    // cout << str << endl;

    string f, s;
    int cur = 0;
    int n = str.size();

    while (cur < n && str[cur++] != ' ')
        ;
    f = str.substr(0, cur - 1);
    s = str.substr(cur, n - 1);

    // cout << f << endl << s << endl;

    Vars curl = findVar(s);

    for (auto &cur : mem) // 指针！！！
        if (cur.name == f)
            cur.value = curl.value;
}

int EqualDef(string sub)
{
    // 粗浅的实现一下，等于常数
    // 找到变量以及常数值

    int n = sub.size();
    string tmp = sub.substr(2, n - 1);

    // cout << tmp << endl;

    string varname;
    int cur = 0;
    while (cur < n && tmp[cur] != ' ')
        cur++;
    varname = tmp.substr(0, cur);

    // cout << varname << endl; 成功解析

    string val;
    cur = n;
    while (cur >= 0 && tmp[cur] != ' ')
        cur--;
    val = tmp.substr(cur + 1, n - 1);

    // cout << val << endl;

    for (auto &pos : mem)
    {
        if (pos.name == varname)
        {
            pos.value = val;
            return 0;
        }
    }

    return cout << "Undefine variable \'" << varname << '\'' << endl, 0;
}

int runFunc()
{
    // 四则运算重写了呜呜呜，先写一个 print 阿巴阿巴

    string con;
    getline(cin, con);
    string str = excptInstr(con);

    string funcName;
    int cur = 0;
    int n = str.size();
    while (cur < n && str[cur] != ':')
        funcName.push_back(str[cur++]);

    if (funcName[funcName.size() - 1] == ' ')
        funcName.pop_back();

    for (auto pos : ins)
    {
        vector<string> tv;
        tv = pos.lst;
        for (auto pi : tv)
        {
            // cout << pi << endl; // 此时命令是 pi

            // 目前代码块内部只能赋值

            if (pi[0] == '=')
                EqualDef(pi);

            else
                return cout << "Undefine Function Action", 0;
        }
    }
}

int defineFunc()
{
    string con;
    getline(cin, con);
    string str = excptInstr(con);

    // cout << str << endl;

    string funcName;
    int cur = 0;
    int n = str.size();
    while (cur < n && str[cur] != ':')
        funcName.push_back(str[cur++]);

    if (funcName[funcName.size() - 1] == ' ')
        funcName.pop_back();

    // cout << funcName << endl;

    // 解析每个分号，代码块格式定很严谨

    if (str[n - 1] != '}')
        return cout << "Function Error : You may lost \'}\'" << endl, 0;

    cur = n - 2;
    string listCmd;
    while (cur >= 0 && str[cur] != '{')
        cur--;
    if (cur == 0)
        return cout << "Function Error : You may lost \'{\'" << endl, 0;
    listCmd = str.substr(cur, n - 2);
    // if (listCmd[])

    // cout << listCmd << endl;

    // 分块

    n = listCmd.size();
    cur = 1;
    vector<string> tv;

    string tmp;
    while (cur < n - 1)
    {

        if (listCmd[cur] == ';')
        {
            if (tmp[0] == ' ')
                tv.push_back(tmp.substr(1, tmp.size() - 1));
            else
                tv.push_back(tmp);
            tmp.clear();
        }
        else
        {
            tmp += listCmd[cur];
        }
        cur++;
    }

    ins.push_back({funcName, tv});
}

int main(int argc, char *argv[], char *envp[])
{

    freopen("input.tree", "r", stdin);
    freopen("output.out", "w", stdout);

    string insType;
    // string op;

    while (cin >> insType)
    {
        // 如何实现注释系统

        if (insType == "#")
            continue;

        // 解析关键字，区别注释系统

        // if (insType == "tr")
        // {
        //     BuildTree();
        // }

        if (insType == "def")
        {
            defineFunc();
        }

        if (insType == "int" || insType == "itn" || insType == "tni" || insType == "tin" || insType == "nti" || insType == "nit")
        {
            addVar();
        }

        if (insType == "print")
        {
            printValue();
        }
        // 等号是 变量赋值
        if (insType == "equ")
        {
            EqualVar();
        }
        if (insType == "pls")
        {
            PlusVar();
        }
        if (insType == "+")
        {
            PlusNum();
        }
        if (insType == "=")
        {
            EqualNum();
        }
        if (insType == "sbt")
        {
            SbtVar();
        }
        if (insType == "-")
        {
            SbtNum();
        }
        if (insType == "run")
        {
            runFunc();
        }
    }

    return 0;
}