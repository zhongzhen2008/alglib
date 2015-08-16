#ifndef ALG_STRING_H_
#define ALG_STRING_H_

#include <string>
#include <vector>

using namespace std;

/** �ַ����ָ��
*
*     @param str �������ַ���
*     @param pattern �ָ�Ԫ��
*     @return    �ָ���vector�ַ�������
*/
vector<string> ALG_StringSplit(string str, string pattern)
{
    int pos;
    vector<string> result;
    str += pattern; //��չ�ַ����Է������
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

/** �ַ���Trim����
*
*     @param str �������ַ���
*     @param ch ��ɾ���ַ���ȱʡ�ǿո�
*     @return    ��
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