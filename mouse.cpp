//this is a mouse macro program
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <iostream>

using std::cout;


POINT p; //pointer for position (global)



void show() {
HWND hwnd = GetConsoleWindow();
SetWindowPos(
    hwnd,
    HWND_TOPMOST,
    25,
    25,
    110,
    200,
    0
);
}

void checkpos() {
GetCursorPos(&p); //get current mouse position
}


void LclickD() {
mouse_event(MOUSEEVENTF_LEFTDOWN , 0, 0, 0, 0); // Left click Down
}
void LclickU() {
mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);// Left click up
}
void RclickD() {
mouse_event(MOUSEEVENTF_RIGHTDOWN , 0, 0, 0, 0); // Right click down
}
void RclickU() {
mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0); // Right click up
}


int main() {//

const int con = 1000; // the array sizes

int mclick[con]; //changing left or righ click into a number
int xpos[con]; //click x position array
int ypos[con]; //click y position array
int clicknum = 0;
int tvarx = 0;
int tvary = 0;
int crnt = 0;
int tvar = 0;
int cur = 0; //current number in array
int tx = 0;
int ty = 0;
int x = 0;

show();
// I didn't have to do all of these newlines but I decided to make the window
// pretty small, and I was thinking I may just hide the window while it is 
// recording- but there are bigger issues

cout <<"this is a\nmouse \nrecording\nprogram \nhold CTRL \nto Record \nthen hit \nescape to \nplay back";

while (1) {
cur = 0;
clicknum = 0;


    while (cur < con) {


if (GetAsyncKeyState(VK_ESCAPE) != 0) {//
                                 break;
                                 }//if

    if (GetAsyncKeyState(VK_CONTROL) != 0) {


if((GetAsyncKeyState(VK_LBUTTON) != 0) && (GetAsyncKeyState(VK_RBUTTON) != 0)){
                                 mclick[cur] = 3;
                                 }
else if((GetAsyncKeyState(VK_LBUTTON) != 0)){
                                 mclick[cur] = 1;
                                 }
else if((GetAsyncKeyState(VK_RBUTTON) != 0)){
                                 mclick[cur] = 2;
                                 }
else {
                                 mclick[cur] = 0;
                                 }
checkpos();

cout << "\n" << p.x << " " << p.y << " " << mclick[cur] << "\n"; //output x and y coordinates
cout << cur << "/" << con << "\n"; //output the current array number/total number


xpos[cur] = p.x; // input current mouse position int array
ypos[cur] = p.y; //                ''

cur++; // increment the array number


}
Beep(10,10); // this was for debugging early on
Sleep (100);
}



clicknum = cur;
cur = 0;
for (int z = 0; z < clicknum; z++){//



tvar = 0;
SetCursorPos(xpos[cur],ypos[cur]); // set the mouse to current array state


cout << xpos[cur] << "  " << ypos[cur] << "  " << mclick[cur] << "\n"; // output mouse state

//This is one of the bigger issues with the program, but I'm not sure how to proceed without
//using the x variable which I would like to demolish

 if (x == 1 && mclick[cur] != 1){  
       if ((mclick[cur] != 1) && (mclick[cur] != 3)) 
       {
                        LclickU();

                        x = 0;
                        }
                        }
 else if (x == 2 && mclick[cur] != 1){
       if ((mclick[cur] != 2) || (mclick[cur] != 3))
       {

                        RclickU();
                        x = 0;
                        }
                        }
 else if (x == 3 && mclick[cur] != 3){
       if ((mclick[cur] != 1 || mclick[cur] != 2) || (mclick[cur] != 3))
       {


                        LclickU();
                        RclickU();
                        x = 0;
                        }
                        }

     if (mclick[cur] == 1){
     LclickD();

     x = 1;
     }
     else if (mclick[cur] == 2){
          RclickD();

          x = 2;
          }
     else if (mclick[cur] == 3){
          LclickD();
          RclickD();


          x = 3;
          }


         cur++;
      Sleep(50);
      }


}
// We should never reach this
system("pause");

return 0;

}
