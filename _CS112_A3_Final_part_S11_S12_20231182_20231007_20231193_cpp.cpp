// file name:CS112_A2_T3_s12_20231182_20231007_20231193.cpp
// this is a program contains some filters that the user can apply it on their photos
// Author: muhannad salah , section_s12
// Emails: /muhannad salah:smohand119@gmail.com/ /ahmed hatem:ahmedhatem10000@gmail.com/ /nour tohamyy:Nourtohamyy@gmail.com
// ID1: 20231182 – the part he did: the black and white filter and flipping filter and crop filter
// and resize filter and bonuss** (natural sunlight filter)
// ID2: 20231007 – the part he did: the grey scale filter and merge filter and Brightness and darken filter and
// edge dettect filtrer and bonuss** (purple filter)
// ID3: 20231193 – the part he did: the invert filter and rotate filter and frame filter and blur filter
// and bonuss** (red effect filter)
// Github repo: https://github.com/BALLIZ-cloud/A3_Filters_program..git



#include <iostream>
using namespace std;
#include "Image_Class.h"
#include <cmath>

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
// crop function
Image function_7(Image& ,int z,int y );
// resize function
Image function_8(Image& ,int z,int y );
// frame filter
Image function_9(string filename , string filename2);
// blur filter
Image function_10(string filename,string filex);
// natural sunlight filter
Image function_11(Image& );
// rotate filter
Image function_12(string filename,string filex);
// red effect function
Image function_13(string filename , string filename2);
// Darkness filter
Image function_14(Image& x);
// Brightness filter
Image function_15(Image& x);
// edge detection function
double function_16( Image& img, int x, int y, int channel);
// purple filter
Image function_17(string filename, string filename2);
int main() {
    const double EDGE_THRESHOLD = 50.0;

    while (true){
    string x;
    cout<<"Ahlan ya user ya hapipy ;)"<<endl;
    cout<<"please enter your choice"<<endl;
    cout<<"1) grey filter"<<endl;
    cout<<"2) black and white filter"<<endl;
    cout<<"3) invert filter"<<endl;
    cout<<"4) flipping filter"<<endl;
    cout<<"5) merge function"<<endl;
    cout<<"6) crop function" <<endl;
    cout<<"7) resize function"<<endl;
    cout<<"8) frame filter"<<endl;
    cout<<"9) blur filter"<<endl;
    cout<<"10) sunlight filter"<<endl;
    cout<<"11) rotate filter"<<endl;
    cout<<"12) red effect function"<<endl;
    cout<<"13) Brightness and Darkness filter"<<endl;
    cout<<"14) edge detection filter"<<endl;
    cout<<"15) Purple filter"<<endl;
    cout<<"16) exit"<<endl;
    cin>>x;
    if(x=="1"){
        string z;
        cout<<"Hallo please enter image name:"<<endl;
        cin>>z;
        Image k(z);
        Image c= function_4(k);
        string l;
        cout<<"enter the name you want your image to be saved as:"<<endl;
        cin>>l;
        c.saveImage(l);
        cout<<"the new filter applied successfully ;)."<<endl;
        continue;

    }
    else if (x=="2"){
        string z;
        cout<<"Hallo please enter image name:"<<endl;
        cin>>z;
        Image k(z);
        Image c= function(k);
        string l;
        cout<<"enter the name you want your image to be saved as:"<<endl;
        cin>>l;
        c.saveImage(l);
        cout<<"the new filter applied successfully ;)."<<endl;
        continue;


    }
    else if (x=="3"){
        string z;
        cout<<"Hallo please enter image name:"<<endl;
        cin>>z;
        Image k(z);
        Image c= function_5(k);
        string l;
        cout<<"enter the name you want your image to be saved as:"<<endl;
        cin>>l;
        c.saveImage(l);
        cout<<"the new filter applied successfully ;)."<<endl;
        continue;

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
            cout << "enter the name you want your image to be saved as:" << endl;
            cin >> l;
            c.saveImage(l);
            cout << "the new filter applied successfully ;)." << endl;
            continue;
        }
        else {
            Image c = function_2(k);
            string l;
            cout << "enter the name you want your image to be saved as:" << endl;
            cin >> l;
            c.saveImage(l);
            cout << "the new filter applied successfully ;)." << endl;
            continue;
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
        cout<<"enter the name you want your image to be saved as:"<<endl;
        cin>>l;
        c.saveImage(l);
        cout<<"the new filter applied successfully ;)."<<endl;

    }
    else if (x=="6"){
        string z;
        int w,y;
        cout<<"Hallo please enter image name:"<<endl;
        cin>>z;
        cout<<"please enter the dimensions for your new image:"<<endl;
        cout<<"Width:"<<endl;
        cin>>w;
        cout<<"Lenth:"<<endl;
        cin>>y;
        Image k(z);
        Image c= function_7(k,w,y);
        string l;
        cout<<"enter the name you want your image to be saved as:"<<endl;
        cin>>l;
        c.saveImage(l);
        cout<<"the new filter applied successfully ;)."<<endl;


    }
    else if (x=="7"){
        string z;
        int w,y;
        cout<<"Hallo please enter image name:"<<endl;
        cin>>z;
        cout<<"please enter the dimensions for your new image:"<<endl;
        cout<<"Width:"<<endl;
        cin>>w;
        cout<<"Length:"<<endl;
        cin>>y;
        Image k(z);
        Image c= function_8(k,w,y);
        string l;
        cout<<"enter the name you want your image to be saved as:"<<endl;
        cin>>l;
        c.saveImage(l);
        cout<<"the new filter applied successfully ;)."<<endl;


    }
    else if (x=="8"){
        string filename;
        string filename2;
        cout << "Hallo please enter image name:"<<endl;
        cin >> filename;
        cout << "enter the name you want your image to be saved as:"<<endl;
        cin >> filename2;
        function_9(filename,filename2);
        cout<<"the new filter applied successfully ;)."<<endl;



    }
    else if (x=="9"){
        string filename;
        string filex;
        cout << "Hallo please enter image name:"<<endl;
        cin >> filename;
        cout << "enter the name you want your image to be saved as:"<<endl;
        cin >> filex;
        function_10(filename,filex);


    }
    else if (x=="10"){
        string z;
        cout<<"Hallo please enter image name:"<<endl;
        cin>>z;
        Image k(z);
        Image c= function_11(k);
        string l;
        cout<<"enter the name you want your image to be saved as:"<<endl;
        cin>>l;
        c.saveImage(l);
        cout<<"the new filter applied successfully ;)."<<endl;
    }
    else if (x=="11"){
        string filename;
        cout<<"Hallo please enter image name:"<<endl;
        cin >> filename;
        string filex;
        cout<<"enter the name you want your image to be saved as:"<<endl;
        cin >> filex;
        function_12(filename,filex);
        cout<<"the new filter applied successfully ;)."<<endl;

    }
    else if (x=="12"){
        string filename;
        string filename2;
        cout<<"Hallo please enter image name:"<<endl;
        cin >> filename;
        cout<<"enter the name you want your image to be saved as:"<<endl;
        cin >> filename2;
        function_13(filename,filename2);
        cout<<"the new filter applied successfully ;)."<<endl;

    }
    else if(x=="13"){
        string z;
        cout<<"Hallo please enter image name:"<<endl;
        cin>>z;
        Image k(z);
        int g;
        cout<<"what you like to do?"<<endl;
        cout<<"1) Brightness"<<endl;
        cout<<"2) darkness"<<endl;
        cin>>g;
        if(g==2){
            Image c= function_14(k);
            string l;
            cout<<"enter the name you want your image to be saved as:"<<endl;
            cin>>l;
            c.saveImage(l);
            cout<<"the new filter applied successfully ;)."<<endl;
        }
        else {
            Image c = function_15(k);
            string l;
            cout << "enter the name you want your image to be saved as:" << endl;
            cin >> l;
            c.saveImage(l);
            cout << "the new filter applied successfully ;)." << endl;
        }

    }
    else if(x=="14"){
        string z;
        cout << "Hello please enter image name: " << endl;
        cin >> z;

        Image k(z);

        // Create a new image to store the detected edges
        Image edgeImage(k.width, k.height);


        for (int i = 0; i < k.width; ++i) {
            for (int j = 0; j < k.height; ++j) {
                // Calculate edge strength using Sobel operator for grayscale
                double edgeStrength = function_16(k, i, j, 0);

                // Determine if it's an edge or not based on a threshold
                if (edgeStrength > EDGE_THRESHOLD) {
                    // Set pixel in edge image to highlight the edge (assigning white color)
                    edgeImage.setPixel(i, j, 0, 255); // Red channel
                    edgeImage.setPixel(i, j, 1, 255); // Green channel
                    edgeImage.setPixel(i, j, 2, 255); // Blue channel
                }
            }
        }
        // Save the edge image
        string g;
        cout<<"enter the name you want your image to be saved as"<<endl;
        cin>>g;
        string outputFileName = g;
        edgeImage.saveImage(outputFileName);

        cout << "the new filter applied successfully ;)." << endl;

    }
    else if (x=="15"){
        string filename;
        string filename2;
        cout << "Hello please enter image name: "<<endl;
        cin >> filename;

        cout<<"enter the name you want your image to be saved as"<<endl;
        cin >> filename2;

        function_17(filename, filename2);
        cout << "the new filter applied successfully ;)." << endl;

    }
    else if (x=="16")
        break;



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

// crop function
Image function_7(Image& x, int z, int y) {
    if (z <= 0 || y <= 0 || z > x.width || y > x.height) {
        cout << "Invalid dimensions for cropping." << endl;
        exit(1);
    }

    int startX = (x.width - z) / 2;
    int startY = (x.height - y) / 2;

    Image l(z,y);

    for (int i = 0; i < z; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < x.channels; ++k) {
                l(i, j, k) = x(startX + i, startY + j, k);
            }
        }
    }

    return l;
}

// resize function
Image function_8(Image& x, int z, int y) {
    int a, b;

    float startX = float(x.width) / z;
    float startY = float(x.height) / y;

    Image l(z, y);

    for (int i = 0; i < z; ++i) {
        for (int j = 0; j < y; ++j) {
            a = int(startX * i);
            b = int(startY * j);

            for (int k = 0; k < x.channels; ++k) {
                l(i, j, k) = x(a, b, k); // Use a and b here, not startX and startY
            }
        }
    }

    return l;
}

// frame filter
Image function_9(string filename , string filename2) {
    int type_frame;
    cout << "choose which frame do you want:"<<endl;
    cout<<" 1)simple frame: \n 2)fancy frame: \n"<<endl;
    cin >> type_frame;
    // Load the image to convert to grayscale
    Image image(filename);
    int frameWidth = image.width + 200;
    int frameHeight = image.height + 200;
    int startX = (frameWidth - image.width) / 2;
    int startY = (frameHeight - image.height) / 2;

    Image imageFrame(frameWidth, frameHeight);
    if (type_frame == 1) {


        for (int i = 0; i < frameWidth; ++i) {
            for (int j = 0; j < frameHeight; ++j) {
                for (int k = 0; k < 3; ++k) {
                    imageFrame(i, j, k) = 255;
                }
            }
        }


        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    imageFrame(startX + i, startY + j, k) = image(i, j, k);
                }
            }
        }
    }
    if (type_frame == 2) {
        int squareSize = 20;

        for (int i = 0; i < frameWidth; ++i) {
            for (int j = 0; j < frameHeight; ++j) {
                if ((i / squareSize + j / squareSize) % 2 == 0) {

                    for (int k = 0; k < 3; ++k) {
                        imageFrame(i, j, k) = 255;
                    }
                } else {

                    for (int k = 0; k < 3; ++k) {
                        imageFrame(i, j, k) = 0;
                    }
                }
            }
        }
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    imageFrame(startX + i, startY + j, k) = image(i, j, k);
                }
            }
        }


    }

    imageFrame.saveImage(filename2);


}

// blur filter
Image function_10(string filename,string filex) {
    Image image(filename);


    Image blurredImage(image.width, image.height);

    for (int i = 4; i < image.width - 4; ++i) {
        for (int j = 4; j < image.height - 4; ++j) {
            unsigned int sum[3] = {0};

            // Apply a 9x9 blur matrix
            for (int m = -4; m <= 4; ++m) {
                for (int n = -4; n <= 4; ++n) {
                    for (int k = 0; k < 3; ++k) {
                        int col = i + m;
                        int row = j + n;

                        // Accumulate pixel values for blur
                        sum[k] += image(col, row, k);
                    }
                }
            }


            for (int k = 0; k < 3; ++k) {
                sum[k] /= 81;
                blurredImage(i, j, k) = sum[k];
            }
        }
    }
    blurredImage.saveImage(filex);
}

// natral sunlight filter
Image function_11(Image& x) {
    for (int i = 0; i < x.width; ++i) {
        for (int j = 0; j < x.height; ++j) {

            int red = x.getPixel(i, j, 0);
            int green = x.getPixel(i, j, 1);
            int blue = x.getPixel(i, j, 2);



            int newRed = min(255, red + 70);
            int newGreen = min(255, green + 50);
            int newBlue = min(255, blue + 30);


            x.setPixel(i, j, 0, newRed);
            x.setPixel(i, j, 1, newGreen);
            x.setPixel(i, j, 2, newBlue);
        }
    }
    return x;
}

// rotate function
Image function_12(string filename,string filex){

    Image image(filename);

    int degree;
    cout << "Please enter the degree of rotation (90, 180, or 270):"<<endl;
    cin >> degree;

    if(degree == 90){
        Image image270(image.height, image.width);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {

                    image270(j, i, k) = image(i, j, k);
                }
            }
        }

        image270.saveImage(filex);
    }
    else if(degree == 180) {
        Image image180(image.width, image.height);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image180(image.width - 1 - i, image.height - 1 - j, k) = image(i, j, k);
                }
            }
        }

        image180.saveImage(filex);
    }
    else if (degree == 270) {
        Image image90(image.height, image.width);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {

                    image90(image.height - 1 - j, i, k) = image(i, j, k);
                }
            }
        }

        image90.saveImage(filex);
    }
    else{
        cout << "Invalid degree. Please enter 90, 180, or 270." << endl;
    }


}

// red effect function
Image function_13(string filename , string filename2) {
    Image image(filename);
    Image image2(image.width, image.width);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i,j,k)=255-image(i,j,k);
            }}}
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (k == 0) {
                    image(i, j, k) = 255;
                }
            }

        }

    }
    image.saveImage(filename2);
}

// Darkness filter
Image function_14(Image& x) {


    // Create an empty image with the same dimensions as the original image
    Image dark_image(x.width, x.height);

    // Darken the image by reducing pixel values by 50%
    for (int i = 0; i < x.width; ++i) {
        for (int j = 0; j < x.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Reduce pixel values by 50% to darken the image
                dark_image.setPixel(i, j, k, x(i, j, k) / 2);
            }
        }
    }


    return dark_image;
}

// Brightness filter
Image function_15(Image& x) {



    // Create an empty image with the same dimensions as the original image
    Image bright_image(x.width, x.height);


    float brightness_factor = 1.2; // Adjust this factor to control brightness
    for (int i = 0; i < x.width; ++i) {
        for (int j = 0; j < x.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Increase pixel values by the brightness factor to brighten the image
                int pixel_value = x(i, j, k) * brightness_factor;
                bright_image.setPixel(i, j, k, min(255, pixel_value));
            }
        }
    }


    return bright_image;
}

// edge detection function
double function_16( Image& img, int x, int y, int channel) {
    double gx = 0.0, gy = 0.0;

    // Sobel Operator
    double sobel1[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    double sobel2[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int nx = x + i;
            int ny = y + j;

            // Ensure the pixel is within bounds
            if (nx >= 0 && nx < img.width && ny >= 0 && ny < img.height) {
                gx += sobel1[i + 1][j + 1] * img.getPixel(nx, ny, channel);
                gy += sobel2[i + 1][j + 1] * img.getPixel(nx, ny, channel);
            }
        }
    }

    // Compute gradient magnitude
    return sqrt(gx * gx + gy * gy);
}

// purple filter
Image function_17(string filename, string filename2) {
    Image image(filename);
    Image image2(image.width, image.height);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int red = image(i, j, 0);
            int green = image(i, j, 1);
            int blue = image(i, j, 2);
            int newRed = red;
            int newGreen = green - 50;
            int newBlue = blue + 50;
            newRed = max(0, min(255, newRed));
            newGreen = max(0, min(255, newGreen));
            newBlue = max(0, min(255, newBlue));

            image2(i, j, 0) = newRed;
            image2(i, j, 1) = newGreen;
            image2(i, j, 2) = newBlue;

        }
    }

    // Save the modified image
    image2.saveImage(filename2);
    return image2;


}