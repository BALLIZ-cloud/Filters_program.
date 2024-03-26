// file name:CS112_A2_T3_s12_20231182_20231007_20231193.cpp
// this is a program contains some filters that the user can apply it on their photos
// Author: muhannad salah , section_s12
// Emails: /muhannad salah:smohand119@gmail.com/ /ahmed hatem:ahmedhatem10000@gmail.com/ /nour tohamyy:Nourtohamyy@gmail.com
// ID1: 20231182 – the part he did: the black and white filter and flipping filter
// ID2: 20231007 – the part he did: the grey scale filter and merge filter
// ID3: 20231193 – the part she did: the invert filter




#include <iostream>
using namespace std;
#include "Image_Class.h"
// Black and white filter
Image function(Image& );
// flipping filter by vertical axis
Image function_2(Image& );
// flipping by horizontal axis
Image function_3(Image& );
// gray scale function
Image function_4(Image& );
// invert function
Image function_5(Image& );
// merge function
Image function_6(Image& , Image& );
int main() {
while (true){
    string x;
    cout<<"Ahlan ya user ya hapipy ;)"<<endl;
    cout<<"please enter your choice"<<endl;
    cout<<"1) grey filter"<<"\n"<<"2) black and white filter"<<"\n"<<"3) invert filter"<<"\n"<<"4) flipping filter"<<"\n"<<"5) merge"<<"\n"<<"6) exit" <<endl;
    cin>>x;
    if(x=="1"){
        string z;
        cout<<"Hallo please enter image name:"<<endl;
        cin>>z;
        Image k(z);
        Image c= function_4(k);
        string l;
        cout<<"enter the name you want your image to saved as:"<<endl;
        cin>>l;
        c.saveImage(l);
        cout<<"the new filter applied successfully ;)."<<endl;

    }
    else if (x=="2"){
        string z;
        cout<<"Hallo please enter image name:"<<endl;
        cin>>z;
        Image k(z);
        Image c= function(k);
        string l;
        cout<<"enter the name you want your image to saved as:"<<endl;
        cin>>l;
        c.saveImage(l);
        cout<<"the new filter applied successfully ;)."<<endl;



    }
    else if (x=="3"){
        string z;
        cout<<"Hallo please enter image name:"<<endl;
        cin>>z;
        Image k(z);
        Image c= function_5(k);
        string l;
        cout<<"enter the name you want your image to saved as:"<<endl;
        cin>>l;
        c.saveImage(l);
        cout<<"the new filter applied successfully ;)."<<endl;

    }
    else if (x=="4"){
        string z;
        cout<<"Hallo please enter image name:"<<endl;
        cin>>z;
        Image k(z);
        int d;
        cout<<"please choose by which axis you want to flip your image:"<<endl;
        cout<<"1) vertical axis"<<"\n"<<"2) horizontal axis"<<endl;
        cin>>d;

        if (d == 2) {
            Image c = function_3(k);
            string l;
            cout << "enter the name you want your image to saved as:" << endl;
            cin >> l;
            c.saveImage(l);
            cout << "the new filter applied successfully ;)." << endl;
        }
        else {
            Image c = function_2(k);
            string l;
            cout << "enter the name you want your image to saved as:" << endl;
            cin >> l;
            c.saveImage(l);
            cout << "the new filter applied successfully ;)." << endl;
        }



    }
    else if (x=="5"){
        string z,w;
        cout<<"Hallo please enter image name:"<<endl;
        cin>>z;
        cout<<"please enter the other image name:"<<endl;
        cin>>w;
        Image k(z), r(w);
        Image c= function_6(k,r);
        string l;
        cout<<"enter the name you want your image to saved as:"<<endl;
        cin>>l;
        c.saveImage(l);
        cout<<"the new filter applied successfully ;)."<<endl;

    }
    else {
        exit;
    }



}
    return 0;
}
// black and white function
Image function(Image& x){
    for(int i = 0; i < x.width; ++i) {
        for(int j = 0; j < x.height; ++j) {
            for (int k = 0; k < x.channels; ++k) {
                x(i, j, k)=x(i,j,0);
            }
        }
    }

    return x;

}

// flipping vertical axis function
Image function_2(Image& w){
    Image f=w;
    for(int i =0; i <f.width/2; ++i) {
        for(int j = 0; j < f.height; ++j) {
            for (int k = 0; k < f.channels; ++k) {
                char h=f(i,j,k);
                f(i,j,k)=f(f.width-1-i,j,k);
                f(f.width-1-i,j,k)=h;


            }
        }
    }
    return f;
}

// flipping horizontal axis function
Image function_3(Image& x){
    Image f=x;
    for(int i =0; i <f.width; ++i) {
        for(int j = 0; j < f.height/2; ++j) {
            for (int k = 0; k < f.channels; ++k) {
                char h=f(i,j,k);
                f(i,j,k)=f(i,f.height-1-j,k);
                f(i,f.height-1-j,k)=h;


            }
        }
    }
    return f;
}

// gray scale function
Image function_4(Image& x) {
    for (int i = 0; i < x.width; ++i) {
        for (int j = 0; j < x.height; ++j) {
            unsigned int average;
            average = 0;


            for (int k = 0; k < x.channels; ++k) {
                average += x(i, j, k);

            }
            average = average / 3;
            for (int k = 0; k < x.channels; ++k) {
                x(i, j, k) = average;


            }

        }
    }

    return x;
}

// invert function
Image function_5(Image& x){
    for(int i = 0; i < x.width; ++i) {
        for(int j = 0; j < x.height; ++j) {
            unsigned  int inv = 0; // Initialize average value

            for (int k = 0; k < x.channels; ++k) {
                x (i,j,k) =  255- x(i, j, k); // Accumulate pixel values*/

            }
        }
    }

    return x;

}

// merge function
Image function_6(Image& x, Image& y){
    int merged_width = min(x.width, y.width);
    int merged_height = min(x.height, y.height);

    Image merged_image(merged_width, merged_height);


    for (int i = 0; i < merged_width; ++i) {
        for (int j = 0; j < merged_height; ++j) {
            for (int k = 0; k < 3; ++k) {
                merged_image.setPixel(i, j, k, (x(i, j, k) + y(i, j, k)) / 3);
            }
        }
    }


    return merged_image;

}