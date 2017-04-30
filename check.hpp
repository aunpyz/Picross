#ifndef CHECK_HPP
#define CHECK_HPP

#include<iostream>
bool check(const int* ans, const int* play, int s)
{
    bool c=true;
    while(s--)
    {
        if(play[s]==1&&!ans[s])
        {
            c=false;
            break;
        }
        if(ans[s]&&play[s]!=1)
        {
            c=false;
            break;
        }
    }
    return c;
}
#endif // CHECK_HPP
