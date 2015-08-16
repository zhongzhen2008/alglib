#ifndef ALG_STRING_H_
#define ALG_STRING_H_

#include <string>
#include <vector>

using namespace std;

/** 字符串分割函数
*
*     @param str 待处理字符串
*     @param pattern 分割元素
*     @return    分割后的vector字符串数组
*/
vector<string> ALG_StringSplit(string str, string pattern)
{
    int pos;
    vector<string> result;
    str += pattern; //扩展字符串以方便操作
    int size = str.size();

    for (int i = 0; i < size; i++)
    {
        pos = str.find(pattern, i);
        if (pos < size)
        {
            string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}

/** 字符串Trim函数
*
*     @param str 待处理字符串
*     @param ch 待删除字符，缺省是空格
*     @return    无
*/
void ALG_StringTrimLeft(string& str, char ch = ' ')
{
    string::size_type pos = str.find_first_not_of(ch);
    if (pos != string::npos)
    {
        str.erase(0, pos);
    }
    else
    {
        str = "";
    }
}

void ALG_StringTrimRight(string& str, char ch = ' ')
{
    string::size_type pos = str.find_last_not_of(ch);
    if (pos != string::npos)
    {
        str.erase(pos + 1);
    }
    else
    {
        str = "";
    }
}

void ALG_StringTrim(string& str, char ch = ' ')
{
    ALG_StringTrimLeft(str, ch);
    ALG_StringTrimRight(str, ch);
}

#endif