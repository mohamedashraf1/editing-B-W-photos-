// FCI – Programming 1 – 2018 - Assignment 3
// Program Name: demo2.cpp
// Last Modification Date: 13/04/2018
// Author1 and ID and Group: Mohamed Ashraf Mohamed-20170221-9
// Author2 and ID and Group: Mohamed sherif Mohamed-20170235-9
// Author3 and ID and Group: Mohamed el-taher abd el-hamid-20170223-9
// Teaching Assistant:Khadega Khaled
// Purpose:Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char new_image[SIZE][SIZE];
unsigned char Large_image[SIZE][SIZE];
int x=SIZE-1;

void loadImage ();
void saveImage ();
void BW ();
void flip();
void detect();
void mirror();
void Invert_image();
void Rotate_image();
void Enlarge_image();

int main()
{int choice ;
bool c=true;
while (c){
cout<<"ahlan ya user ya habibi \n"
    <<"please select a filter to apply or 0 to exit \n"
    <<"1-black and white filter \n"
    <<"2-invert filter \n"
    <<"3-merge filter \n"
    <<"4-flip image \n"
    <<"5-darken and lighten image \n"
    <<"6-rotate image \n"
    <<"7-detect image edge \n"
    <<"8-enlarge image \n"
    <<"9-shrink image \n"
    <<"10-mirror 1/2 image \n"
    <<"11-shuffle image \n";
cin>>choice ;
switch (choice){
case 0:
    c=false;
    break;
case 1 :
    loadImage();
    BW();
    saveImage();
    break;
case 2 :
    loadImage();
    Invert_image();
    saveImage();
    break;
case 3 :
    cout<<"not ready yet";
    break;
case 4 :
    loadImage();
    flip();
    saveImage();
    break;
case 5 :
    cout<<"not ready yet";
    break;
case 6 :
    int num;
    cout<<"1-Rotate 90.\n"
        <<"2-Rotate 180.\n"
        <<"3-Rotate 270.\n";
    cin>>num;
    switch (num){
    case 1:
        loadImage();
        Rotate_image();
        saveImage();
        break;
    case 2 :
        loadImage();
        Rotate_image();
        Rotate_image();
        saveImage();
        break;
    case 3 :
        loadImage();
        Rotate_image();
        Rotate_image();
        Rotate_image();
        saveImage();
        break;
    }
    break;
case 7 :
    loadImage();
    detect();
    saveImage();
    break;
case 8 :
    loadImage();
    Enlarge_image();
    saveImage();
    break;
case 9 :
    cout<<"not ready yet ";
    break;
case 10 :
    loadImage();
    mirror();
    saveImage();
    break;
}
}
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//_________________________________________
void BW() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

        if (image[i][j] > 127)
            image[i][j] = 255;
        else
            image[i][j] = 0;

    }
  }
}
//--------------------------------------------
void Invert_image()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            if(image[i][j]==255)
                image[i][j]=0;
            else if (image[i][j]==0)
                image[i][j]=255;
            else
                image[i][j]=255-image[i][j];
        }
    }
}

//--------------------------------------------
void flip(){
unsigned char temp[SIZE/2][SIZE];
unsigned char temp2[SIZE][SIZE/2];
int c;
cout<<"1-for horizontally flip \n";
cout<<"2-for vertically flip \n";
cin>>c;
if (c==1){
for (int i=0 ;i<SIZE/2; i++){
    for (int j=0; j<SIZE;j++){
            temp[i][j]=image[i][j];
            image[i][j]=image[256-i][256-j];
            image[256-i][256-j]=temp[i][j];
    }
}
for (int i=0 ;i<SIZE; i++){
    for (int j=0; j<SIZE/2;j++){
            temp2[i][j]=image[i][256-j];
            image[i][256-j]=image[i][j];
            image[i][j]=temp2[i][j];

    }
}
}
else {
 for (int i=0 ;i<SIZE; i++){
    for (int j=0; j<SIZE/2;j++){
            temp2[i][j]=image[i][256-j];
            image[i][256-j]=image[i][j];
            image[i][j]=temp2[i][j];

    }
}

}
}
//--------------------------------------------------------
void detect(){
bool temp[SIZE][SIZE];
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

        if (image[i][j] > 127)
            image[i][j] = 255;
        else
            image[i][j] = 0;
    }
  }
 for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
            temp[i][j]=image[i][j];
        if (image [i][j+1]==0 && image[i][j-1]==0 && image[i+1][j]==0 && image[i-1][j]==0 && image[i+1][j+1]==0 && image[i+1][j-1]==0 && image[i-1][j+1]==0 && image[i-1][j-1]==0){
                temp[i][j]=true;
             }

    }
  }
for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
            if (temp[i][j]==1){
                image[i][j]=255;
            }

    }
  }

}
//------------------------------------------------------------------
void Enlarge_image()
{
    int  choice;
    cout<<"1-First quarter.\n"
        <<"2-Second quarter.\n"
        <<"3-Third quarter.\n"
        <<"4-Forth quarter.\n";
    cin >> choice;
    if(choice==1)
    {
        int num1=0 , num2=0 ;
        for(int i=0 ; i<SIZE ; i+=2)
        {
            for(int j=0 ; j<SIZE ; j+=2)
            {
                Large_image[i][j]=image[num1][num2];
                Large_image[i+1][j]=image[num1][num2];
                Large_image[i][j+1]=image[num1][num2];
                Large_image[i+1][j+1]=image[num1][num2];
                num2++;
            }
            num2=0;
            num1++;
        }
    }
    else if (choice==2)
    {
        int num1=0 , num2=SIZE/2 ;
        for(int i=0 ; i<SIZE ; i+=2)
        {
            for(int j=0 ; j<SIZE ; j+=2)
            {
                Large_image[i][j]=image[num1][num2];
                Large_image[i+1][j]=image[num1][num2];
                Large_image[i][j+1]=image[num1][num2];
                Large_image[i+1][j+1]=image[num1][num2];
                num2++;
            }
            num2=SIZE/2;
            num1++;
        }
    }
    else if (choice==3)
    {
        int num1=SIZE/2 , num2=0 ;
        for(int i=0 ; i<SIZE ; i+=2)
        {
            for(int j=0 ; j<SIZE ; j+=2)
            {
                Large_image[i][j]=image[num1][num2];
                Large_image[i+1][j]=image[num1][num2];
                Large_image[i][j+1]=image[num1][num2];
                Large_image[i+1][j+1]=image[num1][num2];
                num2++;
            }
            num2=0;
            num1++;
        }
    }
    else if (choice==4)
    {
        int num1=SIZE/2 , num2=SIZE/2 ;
        for(int i=0 ; i<SIZE ; i+=2)
        {
            for(int j=0 ; j<SIZE ; j+=2)
            {
                Large_image[i][j]=image[num1][num2];
                Large_image[i+1][j]=image[num1][num2];
                Large_image[i][j+1]=image[num1][num2];
                Large_image[i+1][j+1]=image[num1][num2];
                num2++;
            }
            num2=SIZE/2;
            num1++;
        }
    }
    for(int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE; j++)
        {
            image[i][j]=Large_image[i][j];
        }
    }
}

//------------------------------------------------------------------
void  Rotate_image()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            new_image[i][j]=image[j][x];
        }
        x--;
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            image[i][j]=new_image[i][j];
        }
    }
}

//------------------------------------------------------------------
void mirror(){
int choice ;
cout<<"1-left 1/2 \n";
cout<<"2-right 1/2 \n";
cout<<"3-upper 1/2 \n";
cout<<"4-down 1/2 \n";
cin>>choice;
if (choice ==1){
unsigned char temp[SIZE][SIZE/2];
for (int i=0; i<SIZE; i++){
    for (int j=0 ;j<SIZE/2 ;j++){
        temp[i][j]=image[i][j];

    }
}
for (int i=0; i<SIZE; i++){
    for (int j=0 ;j<SIZE/2 ;j++){
        //temp[i][j]=image[i][j];
        image[i][j+128]=temp[i][128-j];
    }
}
}
else if (choice==2){
unsigned char temp[SIZE][SIZE];
unsigned char temp2[SIZE][SIZE/2];
for (int i=0; i<SIZE;i++){
    for (int j=0;j<SIZE;j++){
        temp[i][j]=image[i][j];

    }
}
 for (int i=0; i<SIZE;i++){
    for (int j=0;j<SIZE/2;j++){
        image[i][j]=temp[i][256-j];
    }
}
}
else if (choice==3){
unsigned char temp[SIZE][SIZE];
unsigned char temp2[SIZE][SIZE/2];
for (int i=0;i<SIZE;i++){
    for (int j=0;j<SIZE;j++){
        temp[i][j]=image[i][j];
    }
}
for (int i=0 ;i<SIZE; i++){
    for (int j=0; j<SIZE/2;j++){
            temp2[i][j]=temp[i][256-j];
            temp[i][256-j]=temp[i][j];
            temp[i][j]=temp2[i][j];

    }
}
for (int i=0;i<SIZE/2;i++){
    for (int j=0;j<SIZE;j++){
        image[i+128][j]=temp[128-i][256-j];
    }
}

}
else if (choice==4){
unsigned char temp[SIZE][SIZE];
unsigned char temp2[SIZE][SIZE/2];
for (int i=0; i<SIZE;i++){
    for (int j=0 ;j<SIZE; j++){
        temp[i][j]=image[i][j];
    }
}
for (int i=0 ;i<SIZE; i++){
    for (int j=0; j<SIZE/2;j++){
            temp2[i][j]=temp[i][256-j];
            temp[i][256-j]=temp[i][j];
            temp[i][j]=temp2[i][j];

    }
}
for (int i=0; i<SIZE/2;i++){
    for (int j=0 ;j<SIZE; j++){
        image[i][j]=temp[256-i][256-j];
    }
}
}
}
