#ifndef CHECKCHECK_HPP
#define CHECKCHECK_HPP

#include <iostream>

int numSwitch(int);
int checkCheck(int,int);

bool checkMain(const int* ans,int* playS,int x)
{
    int nub=0;
    int temp;
    for(int i=0;i<x*x;i++){

        temp=numSwitch(*(playS+i));

        nub+=checkCheck(*(ans+i),temp);

    }


    if(nub==0){
        return true;
    }else{
        return false;
    }

}

int numSwitch(int temp)
{
    switch(temp){
        case 0:
                return temp=0;
        case 1:
                return temp=1;
        case 2:
                return temp=0;
    }
    return -1;
}

int checkCheck(int ans,int temp)
{
    if(ans==temp){
        return 0;
    }else
        return 1;
}

#endif // CHECKCHECK_HPP
