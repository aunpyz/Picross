#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <algorithm>

using namespace std;

void table(int x) {
	for (int i=0;i<=10;i++) {
		if (i%2==0) {
			cout << "|";
		} else if (i%5==0&&x!=5) cout << "--";
		else cout << "##";
	} cout << endl;
}

void table2(int x) {
	for (int i=0;i<=10;i++) {
		if (i%2==0) {
			cout << "|";
		} else cout << "__";
	} cout << endl;
}

void table3(int x) {
	for (int i=0;i<=10;i++) {
		if (i%2==0) {
			cout << "|";
		}
		else if (i%3==0&&i!=9) cout << "##";
		else if (i%7==0) cout << "##";
		else cout << "--";
	} cout << endl;
}

void table4(int x) {
	for (int i=0;i<=10;i++) {
		if (i%2==0) {
			cout << "|";
		}
		else if (i%3==0&&i!=9) cout << "##";
		else if (i%7==0) cout << "##";
		else if (i%5==0) cout << "##";
		else cout << "--";
	} cout << endl;
}

void table5(int x) {
	for (int i=0;i<=10;i++) {
		if (i%2==0) {
			cout << "|";
		} else if (i%5==0) cout << "##";
		else cout << "--";
	} cout << endl;
}

void table6(int x) {
	for (int i=0;i<=10;i++) {
		if (i%2==0) {
			cout << "|";
		} else if (i%9==0) cout << "--";
		else cout << "##";
	} cout << endl;
}

void page1 () {
	system("cls");
	cout << "HOW TO PLAY PICROSS\n\n";
 	cout << "- Introduction -\n\n";
 	cout << "     3  4  4  4  1\n";
	cout << "2 2";
	table2(1);
	cout << "  4";
	table2(1);
	cout << "  4";
	table2(1);
	cout << "  3";
	table2(1);
	cout << "  1";
	table2(1);
	cout << "\n\n";
 	cout << "Each sequence of numbers in front of a line or above a column indicates \nhow many squares have to be blackend in this line or columns.\n\n";

}

void page2 () {
	system("cls");
	cout << "- Step one -\n\n";
 	cout << "     3  4  4  4  1\n";
	cout << "2 2";
	table(1);
	cout << "  4";
	table2(5);
	cout << "  4";
	table2(5);
	cout << "  3";
	table2(1);
	cout << "  1";
	table2(1);
	cout << "\n\n";
   	cout << "The number sequence in the first row is 2 2, that means that there are two series of two squares, those series being separated by AT LEAST one empty square.\n\n**press Z then click and drag left mouse button to fill the blank space**\n**press C and then click and drag left mouse button to clear any filled space into blank spaces.**\n\n";

}

void page3 () {
	system("cls");
	cout << "- Full line -\n\n";
 	cout << "     3  4  4  4  1\n";
	cout << "2 2";
	table(1);
	cout << "  4";
	table6(5);
	cout << "  4";
	table6(5);
	cout << "  3";
	table2(1);
	cout << "  1";
	table2(1);
	cout << endl;
 	cout << "\n\n";
	cout << "You must leave the last box of both rows empty.This is because these is a '1' above on top of the last column is already filled\n\n**press X and then click and drag left mouse button to mark that you don't use that specific space (optional, just to ensure you don't need this blank space)**\n\n";
}
void page4 () {
	system("cls");
	cout << "- Column -\n\n";
   	cout << "     3  4  4  4  1\n";
	cout << "2 2";
	table(1);
	cout << "  4";
	table6(5);
	cout << "  4";
	table6(5);
	cout << "  3";
	table2(1);
	cout << "  1";
	table2(1);
	cout << "\n\n";
	cout << "We have 2 columns with a 4 on top, beside the middle column. Those columns already have three black squares.\n\n";

}
void page5() {
	system("cls");
	cout << "Beginning of a column / line\n\n";
	cout << "     3  4  4  4  1\n";
	cout << "2 2";
	table(1);
	cout << "  4";
	table6(5);
	cout << "  4";
	table6(5);
	cout << "  3";
	table3(1);
	cout << "  1";
	table2(1);
	cout << "\n\n";
	cout << "Then we have middle column with a 4 and two black square in it. We just need to blacken the third and the fourth squares to find the solution for those columns.\n\n";

}
void page6() {
	system("cls");
	cout << "- Solving the puzzle -\n\n";
	cout << "     3  4  4  4  1\n";
	cout << "2 2";
	table(1);
	cout << "  4";
	table6(5);
	cout << "  4";
	table6(5);
	cout << "  3";
	table4(1);
	cout << "  1";
	table5(1);
	cout << "\n\n";
	cout << "Congratulations! You just solved your first picross puzzle! Now you can try to solve as much picross puzzles as you can!\n\n"; }

int how_to_play() {
	int page=1;
	string Next;
	while (true) {
		switch(page) {
			case 1 : page1();
					 break;
			case 2 : page2();
					 break;
			case 3 : page3();
					 break;
			case 4 : page4();
					 break;
			case 5 : page5();
					 break;
			case 6 : page6();
					 break;
		}
	cout << "Press N to go to Next Page\nPress B to go to previous Page\nor Press E to Exit\n : ";
	getline(cin,Next);

	transform(Next.begin(),Next.end(),Next.begin(),::toupper);

	if(Next=="N") {
		if(page==6)
        {
            cout<<"\nThis is the last page. Press any key to continue..";
            getch();
        }
		else page++;
	}
	else if (Next=="B") {
		if(page==1)
        {
            cout<<"\nThis is frist page. Press any key to continue..";
            getch();
        }
 		else page--;
	 }
	 else if(Next=="E"){
        cout<<"Enjoy PICROSS!! :D\n\nPress any key to continue..";
        getch();
        return 0;
	 }
	 else{
        cout<<"Wrong input please try again. Press any key to continue..";
        getch();
	 }
	}

}

