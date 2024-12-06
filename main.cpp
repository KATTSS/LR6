#include <iostream>
#include <cstdio>
void chech(char *buf, int bufsize, char *ps, int &pssize);
int main()
{
    char *s = new char[81];
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && i < 81)
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    // Катя лапочка <3

    i = 0;
    char *ps = new char[81];
    char *buf = new char[81];

    int pssize = 0;
    for (int j = 0; j < 81; j++)
    {

        if (s[j] == '-' || isdigit(s[j]) == true || s[j] == '.')
        {
            buf[i++] = s[j];
        }
        else
        {

            chech(buf, i, ps, pssize);
            buf[0] = '\0';
            i = 0;
        }
    }
    std::cout << ps;
    delete[] s;
    delete[] ps;
    delete[] buf;
    return 0;
}
void chech(char *buf, int bufsize, char *ps, int &pssize)
{

    int countminus = 0;
    int countpoint = 0;
    if (buf[0] == '.')
        return;
    for (int i = 0; i < bufsize; ++i)
    {

        if (buf[i] == '-' && isdigit(buf[i + 1]) == true)
            ++countminus;
        if (buf[i] == '.')
        {

            ++countpoint;
            if (isdigit(buf[i + 1]) != true || isdigit(buf[i - 1]) != true)
            {
                // ps[0] = '\0';
                //  pssize = 0;
                return;
            }
        }
        if (buf[i] == '-' && (isdigit(buf[i + 1]) == false || isdigit(buf[i-1])==true))
            return;
        if (countminus > 1 || (buf[i] == '-' && !isdigit(buf[i + 1]) && isdigit(buf[i - 1] == true)) || countpoint > 1)
        {   // {   ps[0] = '\0';
            // pssize = 0;
            return;
        }
        // if (countpoint == 0)
        // {
        //     ps[pssize++] = '.';
        //     ps[pssize++] = '0';
        // }
    }
    for (int k = 0; k < bufsize; ++k)
    {
        ps[pssize++] = buf[k];
    }
    // if (pssize > 0 && ps[pssize - 1] == '-')
    // {
    //     pssize -= 2;
    // }

    // if (countpoint != 1)
    //         return;
    if (buf[0] != '\0')
        ps[pssize++] = ' ';
}