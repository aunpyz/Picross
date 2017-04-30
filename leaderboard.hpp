#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP

#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

string IntToStr(int);
void showScore(int);
string name;

bool setScore(int time,int board)
{
    cin.ignore();
    string textline;
	ifstream source;
	string filename = "score" + IntToStr(board) + ".txt";
	char n[50];
	int t;
	vector<string> place;

	source.open(filename.c_str());

	if(!source){//create file first time
        cout << "What's your name (only 3 characters): ";
        getline(cin,name);
        if(name=="")
            name="XXX";
        ofstream outFile;
        filename="score" + IntToStr(board) +".txt";
        outFile.open(filename.c_str(), std::ios_base::app | std::ios_base::out);
        outFile << name << ", " << time << "s\n..., 3600s\n..., 3600s\n" ;
        outFile.close();
        source.close();
        return 1;
	}


    int i=0;
    while(getline(source,textline)){ //check if it already has.(out of while(1)loop)

			char * text = new char[textline.size() + 1];
			copy(textline.begin(), textline.end(), text);
			text[textline.size()] = '\0';
            sscanf(text,"%[^,], %ds",n,&t);


            place.push_back(textline);

			if(name==string(n)&&time==t){
                return 0;
			}

			delete[] text;
            i++;
    }

    stringstream ss;
    ss << time;
    string curr = name + ", " + ss.str();
    int c=0;
    for(int i=0;i<3&&c==0;i++){
        string temp = place.at(i);
        char * text = new char[temp.size() + 1];
        copy(temp.begin(), temp.end(), text);
        text[temp.size()] = '\0';
        sscanf(text,"%[^,], %ds",n,&t);
        if(time<t&&i==0){
            cout << "What's your name (only 3 characters): ";
            getline(cin,name);
            if(name=="")
                name="XXX";
            string curr = name + ", " + ss.str() + "s";
            place.erase(place.begin()+2);
            place.insert(place.begin()+2,place[1]);
            place.erase(place.begin()+1);
            place.insert(place.begin()+1,place[0]);
            place.erase(place.begin());
            place.insert(place.begin()+0,curr);
            c++;
        }else if(time<t&&i==1){
            cout << "What's your name (only 3 characters): ";
            getline(cin,name);
            if(name=="")
                name="XXX";
            string curr = name + ", " + ss.str() + "s";
            place.erase(place.begin()+2);
            place.insert(place.begin()+2,place[1]);
            place.erase(place.begin()+1);
            place.insert(place.begin()+1,curr);
            c++;
        }else if(time<t&&i==2){
            cout << "What's your name (only 3 characters): ";
            getline(cin,name);
            if(name=="")
                name="XXX";
            string curr = name + ", " + ss.str() + "s";
            place.erase(place.begin()+2);
            place.insert(place.begin()+2,curr);
            c++;
        }else if(i==2){
            return 0;
        }
    }

    ofstream outFile;//copy
    filename="score" + IntToStr(board) +".txt";
    //cout<< filename << "  \n";
    outFile.open(filename.c_str());
    //outFile.open(filename.c_str(),ios::app);
    outFile << place[0] << endl << place[1] << endl << place[2] << endl ;
    outFile.close();
	source.close();
	return 1;
}


string IntToStr(int n)
{
    stringstream result;
    result << n;
    return result.str();
}

void showScore(int x)
{
    string textline;
	ifstream source;
	string filename = "score" + IntToStr(x) + ".txt";
	char n[50];
	int t;
	source.open(filename.c_str());

	if(source){
        cout << "name" << setw(35) << "score\n";
        while(getline(source,textline)){
            char * text = new char[textline.size() + 1];
            copy(textline.begin(), textline.end(), text);
            text[textline.size()] = '\0';
            sscanf(text,"%[^,], %ds",n,&t);
            cout << n << ":" << setw(30) << t/60 << "m " << t%60 << "s \n";

            delete[] text;
        }
    }else cout << "There isn't anyone play this size before\n";
}

#endif // LEADERBOARD_HPP
