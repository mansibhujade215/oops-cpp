#include <cstring>          // #include = adds a library; <cstring> = C-style string handling library
#include <fstream>          // #include = adds a library; <fstream> = file handling library
#include <iostream>         // #include = adds a library; <iostream> = input/output library

using namespace std;        // using = use; namespace = group of names; std = standard namespace


struct ImageMetadata {      // struct = creates a structure; ImageMetadata = structure name

    int width;              // int = integer number; width = image width
    int height;             // int = integer number; height = image height
    char format[10];        // char = character data type; format = character array of size 10
};


int main() {                 // main() = starting point of C++ program

    ImageMetadata image1{1920, 1080, "PNG"};
    // ImageMetadata = structure name
    // image1 = first object
    // 1920 = image width
    // 1080 = image height
    // "PNG" = image format


    ImageMetadata image2{1280, 720, "JPEG"};
    // image2 = second ImageMetadata object
    // 1280 = image width
    // 720 = image height
    // "JPEG" = image format


    ImageMetadata image3{3840, 2160, "PNG"};
    // image3 = third ImageMetadata object
    // 3840 = image width
    // 2160 = image height
    // "PNG" = image format


    ofstream output("images.bin", ios::binary);
    // ofstream = output file stream
    // output = file object
    // "images.bin" = binary file name
    // ios::binary = opens file in binary mode


    if (!output) {
    // if = checks a condition
    // !output = checks whether file opening failed

        cerr << "Unable to open binary file for writing." << endl;
        // cerr = error output stream
        // displays error message
        // endl = moves to next line

        return 1;
        // return = sends value back
        // 1 = indicates an error
    }


    output.write(reinterpret_cast<const char*>(&image1), sizeof(ImageMetadata));
    // output = output file stream
    // write() = writes raw binary data into file
    // reinterpret_cast = converts one pointer type into another pointer type
    // const char* = pointer to constant character data
    // &image1 = address of image1 object in memory
    // sizeof(ImageMetadata) = number of bytes occupied by ImageMetadata
    // complete statement = writes image1 as binary data


    output.write(reinterpret_cast<const char*>(&image2), sizeof(ImageMetadata));
    // writes image2 object into the binary file
    // &image2 = address of image2 in memory
    // sizeof(ImageMetadata) = size of one ImageMetadata record


    output.write(reinterpret_cast<const char*>(&image3), sizeof(ImageMetadata));
    // writes image3 object into the binary file
    // &image3 = address of image3 in memory
    // sizeof(ImageMetadata) = size of one record


    output.close();
    // close() = closes the binary file
    // output = file being closed


    ifstream input("images.bin", ios::binary);
    // ifstream = input file stream
    // input = input file object
    // "images.bin" = binary file name
    // ios::binary = opens file in binary reading mode


    if (!input) {
    // if = checks a condition
    // !input = checks whether file opening failed

        cerr << "Unable to open binary file for reading." << endl;
        // cerr = error output stream
        // displays error message
        // endl = moves to next line

        return 1;
        // 1 = indicates an error
    }


    ImageMetadata item{};
    // ImageMetadata = structure name
    // item = object used to store one record while reading
    // {} = value-initializes the object


    int recordNo = 1;
    // int = integer data type
    // recordNo = stores record number
    // 1 = first record number


    cout << "=== Image Metadata ===" << endl;
    // cout = displays output
    // "=== Image Metadata ===" = heading
    // endl = moves to next line


    while (input.read(reinterpret_cast<char*>(&item), sizeof(ImageMetadata))) {
    // while = repeats while reading is successful
    // input.read() = reads binary data from file
    // reinterpret_cast<char*> = converts address to character pointer
    // &item = address of item object in memory
    // sizeof(ImageMetadata) = number of bytes to read
    // loop continues as long as a complete record is successfully read


        cout << "Record " << recordNo++ << ": "
             << item.width << " x " << item.height
             << " | " << item.format << endl;
        // cout = displays output
        // "Record " = text
        // recordNo++ = displays current record number and then increases it by 1
        // item.width = displays image width
        // " x " = multiplication-style separator
        // item.height = displays image height
        // " | " = separator
        // item.format = displays image format
        // endl = moves to next line
    }
}