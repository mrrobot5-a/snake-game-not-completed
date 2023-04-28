#include<iostream>
#include<conio.h>//! for keyboard hit _kbhit()
#include<windows.h>
#include<ctime>
using namespace std;
enum direction{Top=1,Down,Right,Left};//* it must be all upper case
direction dir;
//* Variable
//*--------Map---------*//

int width=40; //* width of map
int height=20;//* height of map

//*--------Snake---------*//
int headx;
int heady;

//*--------fruit---------*//
int fruitx;
int fruity;
//*--------player---------*//
int score=0;
bool lose = false;
//* end of variable


//* function to generate fruit
void generateFruit(){
    fruitx= rand()%width;
    fruity= rand()%height;
}
//! end of generate fruit



//* function to setup the game 
void setup(){
    srand(time(0));
    //* we need to make the head of snake in the middle of map
    headx=width/2;
    heady=height/2;

    //* we need to appear fruits in random postion in map 
    generateFruit();   
}
//! end of setup

//* function to draw 
void draw(){
    system("cls");//*for clear treminal  
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(i==0 || i==height-1){
                cout<<"-"; //* to draw the width 
            }
            else if(j==0 || j==width-1){
                cout<<"#"; //* to draw the height  
            }
            else if (j==headx&& i==heady){
                cout<<"O";//* head of snake
            }
            else if(j==fruitx && i == fruity){
                cout<<"o";//* fruit
            }
            else{
                cout<<" ";
            }
        }//* end of small for
        cout<<endl;
    }//* end of big for


}
//! end of draw
//*function to take input 
void Input(){
    if(_kbhit()){
        char ch= _getch();
        switch (ch)
        {
        case 'w':
            dir=Top; 
            break;
        case 's':
            dir=Down; 
            break;
        case 'd':
            dir=Right; 
            break;
        case 'a':
            dir=Left; 
            break;
        }//*end of switch
    }//*end of if

    //******** MOVE********/
    switch(dir){
        case Top:
            heady--;
            break;
        case Down:
            heady++;
            break;
        case Right:
            headx++;
            break;
        case Left:
            headx--;
            break;
    }//*end of switch
    //* جملة اف لما التعبان يخبط فى اى حيطة يخسر
    if(heady>=height||heady<=0|headx>=width||headx<=0){
        lose = true;
    }

    if(headx==fruitx && heady==fruity){//* لما التعبان ياكل التفاحة اخفيها واظهرها فى مكان تاني
        generateFruit();
        score+=1;
    }




}
//! end of input function

//* function move


int main(){
    setup();
  while(!lose)
  {
    
    draw();
    Input();    
    Sleep(50);
  }  


}