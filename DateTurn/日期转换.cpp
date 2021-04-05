#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>


using namespace std;

bool IsRunYear(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return true;
    return false;
}

int daytab[2][13] = { //���ڱ���¼ÿ�����ж����죨��ʵֻ�ж����б仯������29��ƽ��28��
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}
};
int main()
{
    int year, month, day;
    int outday;
    int i = 0;
    while (scanf("%4d %2d %2d", &year, &month, &day) != EOF)
    {
        outday = 0;
        for (i = 1; i < month; i++)
        {
            outday += daytab[IsRunYear(year)][i];
        }
        outday += day;
        cout << outday << endl;
    }
}