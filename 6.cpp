#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
bool gameOver;
const int widht=100;
const int height=20;
int x,y,fruitX,fruitY,score;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};
int tailX[100],tailY[100];
int nTail;
eDirection dir;

void setup()
{
    gameOver=false;
    dir=STOP;
    x=widht/2;
    y=height/2;
    fruitX=rand()%widht;
    fruitY=rand()%height;
    score=0;
}
void draw()
{
    system("CLS");//clear
    for(int i=0; i<widht+2; i++)
    {
        cout<<"#";
    }
    cout<<endl;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<widht; j++)
        {
            if(j==0)
                cout<<"#";
            if(i==y && j==x)
                cout<<"O";
            else if(i==fruitY && j==fruitX)
                cout<<"*";
            else
            {
                bool print=false;
                for(int k=0;k<nTail;k++)
                {
                    if(tailX[k]==j && tailY[k]==i)
                    {
                        cout<<"o";
                        print=true;
                    }
                }
                    if(!print)
                cout<<" ";
            }

            if(j==widht-1)
                cout<<"#";
        }
        cout<<endl;
    }
    for(int i=0; i<widht+2; i++)
    {
        cout<<"#";
    }
    cout<<endl<<"Score: "<<score<<endl;
}
void input()
{
    if(_kbhit())
    {
        switch(getch())
        {
        case 'a':
            dir=LEFT;
            break;
        case 'd':
            dir=RIGHT;
            break;
        case 'w':
            dir=UP;
            break;
        case 's':
            dir=DOWN;
            break;
        case 'x':
            gameOver=true;
            break;
        }
    }
}
void logic()
{
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<nTail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
        
    }
    switch(dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }
    /*if(x>widht || x<0 || y>height || y<0)
        gameOver=true;*///duvardan geçmesini istiyorsan bunu yap
        if(x>=widht)
            x=0;
        else if(x<0)
            x=widht-1;
        if(y>=height)
            y=0;
        else if(y<0)
            y=height-1;

        for(int i=0;i<nTail;i++)
        {
            if(tailX[i]==x && tailY[i]==y)
                gameOver=true;
        }
    if(x==fruitX && y==fruitY)
    {
        score+=10;
        fruitX=rand()%widht;
        fruitY=rand()%height;
        nTail++;
    }
}
void mainMenu()
{
    int s;
    cout<<"Seviye Sec 1-10"<<endl<<"->";
    cin>>s;
    setup();
    while(!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(100/s);
    }
    char ch;
    cout<<"Score="<<score<<endl;
    cout<<"Devam etmek istiyor musun! (E/e)"<<endl<<"->";
    cin>>ch;
    if(ch=='e' || ch=='E')
    {
        system("CLS");
        nTail=0;
        mainMenu();
    }
}
int main()
{
    mainMenu();
    system("CLS");
    cout<<"Game Over!";
    Sleep(2000);
    return 0;
}

