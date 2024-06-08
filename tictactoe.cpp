#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;
class TicTacToe{
    public:

    //var declarartion
    unordered_set<char> set;
    int i,j;

    //resetting grid
    void reset(vector<vector<char>>& grid){
        for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        grid[i][j]=' ';
        return;
    }

    //displaying grid numbering system
    void displaydef(){
        int c=1;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(!j)
                cout<<" "<<c<<" | ";
                else if(j==2)
                cout<<c<<" ";
                else
                cout<<c<<" | ";
                c++;
            }
            if(i<2)
            cout<<"\n-----------\n";
        }
    }

    //display current grid status
    void display(vector<vector<char>>& grid){
        system("clear");
        cout<<"Enter valid number (range: 1-9): \n";
        cout<<'\n';
        for(i=0;i<3;i++){
            cout<<" "<<grid[i][0]<<" | ";
            cout<<grid[i][1]<<" | ";
            cout<<grid[i][2]<<" ";
            if(i<2)
            cout<<"\n-----------\n";
        }
        cout<<'\n';
        return;
    }

    //checking game status
    int play(vector<vector<char>>& grid){
        int r[3]={0,0,0},c[3]={0,0,0},d1=0,d2=0;
        set.clear();
        for(i=0;i<3;i++){
            if(grid[i][0]==grid[i][1]&&grid[i][1]==grid[i][2]){
                if(grid[i][0]=='x')
                return 1;
                if(grid[i][0]=='o')
                return 2;
            }
            else{
                set.insert(grid[i][0]);
                set.insert(grid[i][1]);
                set.insert(grid[i][2]);
                if(set.find('x')!=set.end()&&set.find('o')!=set.end())
                r[i]++;
            }
        }
        set.clear();
        for(i=0;i<3;i++){
            if(grid[0][i]==grid[1][i]&&grid[1][i]==grid[2][i]){
                if(grid[0][i]=='x')
                return 1;
                if(grid[0][i]=='o')
                return 2;
            }
            else{
                set.insert(grid[0][i]);
                set.insert(grid[1][i]);
                set.insert(grid[2][i]);
                if(set.find('x')!=set.end()&&set.find('o')!=set.end())
                c[i]++;
            }
        }
        set.clear();
        set.insert(grid[0][0]);
        set.insert(grid[1][1]);
        set.insert(grid[2][2]);
        if(set.size()==1){
            if(set.find('x')!=set.end())
            return 1;
            if(set.find('o')!=set.end())
            return 2;
            set.clear();
        }
        else if(set.find('x')!=set.end()&&set.find('o')!=set.end())
        d1++;
        set.clear();
        set.insert(grid[0][2]);
        set.insert(grid[1][1]);
        set.insert(grid[2][0]);
        if(set.size()==1){
            if(set.find('x')!=set.end())
            return 1;
            if(set.find('o')!=set.end())
            return 2;
            set.clear();
        }
        else if(set.find('x')!=set.end()&&set.find('o')!=set.end())
        d2++;
        set.clear();
        if(r[0]&&r[1]&&r[2]&&c[0]&&c[1]&&c[2]&&d1&&d2)
        return -1;
        return 0;
    }

    //setting user input
    void setindex(vector<vector<char>>& grid,int k,int c){
        grid[number(k).first][number(k).second]=c?'o':'x';
        return;
    }

    //determining grid index
    pair<int,int> number(int k){
        vector<pair<int,int>> vec={{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
        return vec[k-1];
    }

    //game menu
    void start(){
        vector<vector<char>> grid(3,vector<char>(3,' '));
        cout<<"TIC-TAC-TOE\n===========\n";
        char p;
        cout<<"1. Enter \"y\" or \"Y\" to begin.\n";
        cout<<"2. Enter \"n\" or \"N\" to exit.\n";
        cin>>p;
        system("clear");
        if(p=='y'||p=='Y')
        while(1){
            cout<<"New Game\n-----------------------\n";
            int c=0;
            cout<<"Grid numbering system:\n\n";
            displaydef();
            cout<<"\n\n-----------------------\n";
            while(!play(grid)){
                if(c){
                    cout<<"\nEnter valid number (range: 1-9): \n";
                    cout<<"Player O:\n";
                    int a;
                    while(1){
                        cin>>a;
                        if(grid[number(a).first][number(a).second]==' ')
                        break;
                        cout<<"Invalid Response\n";
                    }
                    setindex(grid,a,c);
                    display(grid);
                    int k=play(grid);
                    if(k==1){
                        cout<<"\nPlayer X Wins\n";
                    }
                    else if(k==-1){
                        cout<<"\nDraw\n";
                    }
                    else if(k==2){
                        cout<<"\nPlayer O Wins\n";
                    }
                    else{
                        ;
                    }
                }
                else{
                    cout<<"\nEnter valid number (range: 1-9): \n";
                    cout<<"Player X:\n";
                    int a;
                    while(1){
                        cin>>a;
                        if(grid[number(a).first][number(a).second]==' ')
                        break;
                        cout<<"Invalid Response\n";
                    }
                    setindex(grid,a,c);
                    display(grid);
                    int k=play(grid);
                    if(k==1){
                        cout<<"\nPlayer X Wins\n";
                    }
                    else if(k==-1){
                        cout<<"\nDraw\n";
                    }
                    else if(k==2){
                        cout<<"\nPlayer O Wins\n";
                    }
                    else{
                        ;
                    }
                }
                c=(c+1)%2;
            }
            char ch;
            cout<<"\nGame ended! Do you want to continue?(Y/n):";
            cin>>ch;
            if(ch=='n'||ch=='N')
            break;
            else{
                system("clear");
                reset(grid);
            }
        }
        cout<<"Thank you for playing!!\n";
    }
};
int main(){
    TicTacToe obj;
    obj.start();
    return 0;
}