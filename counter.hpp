#ifndef COUNTER_HPP
#define COUNTER_HPP

#include<iostream>
#include"game.hpp"

using namespace std;

void row(const int* table, int arrSize, Game* hint)
{
    int col=(arrSize+1)/2;
    int r[arrSize*col];

    int count=0;
    int rc=col-1;
    bool ifZero=true;

    //cout<<"row\n";
    for(int i=0;i<arrSize;i++)
    {
        for(int j=arrSize-1;j>=0;j--)
        {
            while(table[j+i*arrSize]==0&&j>=0)
                j--;
            while(table[j+i*arrSize]==1&&j>=0)
            {
                count++;
                j--;
            }
            if(count)
            {
                //std::cout<<count<<' ';
                r[i*col+rc--]=count;
                count=0;
                ifZero=false;
            }
            if(ifZero)
            {
                //std::cout<<'0';
                r[i*col+rc--]=count;
            }
        }
        ifZero=true;
        while(rc>=0)
            r[i*col+rc--]=101;
        rc=col-1;
        //std::cout<<std::endl;
    }
    if(!hint->rowHint("rowset.png",sf::Vector2u(32,32),r,col,arrSize))
        return;
}

void column(const int* table, int arrSize, Game* hint)
{
    int row=(arrSize+1)/2;
    int c[arrSize*row];

    int count=0;
    int cc=row-1;
    bool ifZero=true;

    //cout<<"column\n";
    for(int i=0;i<arrSize;i++)
    {
        for(int j=arrSize-1;j>=0;j--)
        {
            while(table[i+j*arrSize]==0&&j>=0)
                j--;
            while(table[i+j*arrSize]==1&&j>=0)
            {
                count++;
                j--;
            }
            if(count)
            {
                //cout<<count<<' ';
                c[i+arrSize*cc--]=count;
                count=0;
                ifZero=false;
            }
            if(ifZero)
            {
                //cout<<0;
                c[i+arrSize*cc--]=count;
            }
        }
        ifZero=true;
        while(cc>=0)
            c[i+arrSize*cc--]=101;
        cc=row-1;
        //cout<<endl;
    }
    if(!hint->columnHint("columnset.png",sf::Vector2u(32,32),c,arrSize,row))
        return;
}
#endif // COUNTER_HPP
