#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "BMP24RGBto8GSfns.h"

int main(int argc, char *argv[]) {
    FILE *input = fopen(argv[1], "rb");
    FILE *output = fopen(argv[2], "wb");
    extern uint8_t header[54];

    struct BMPfile BMP;                 //declare a struct for the original RGB BMP file
    struct gray_BMPfile NEW_BMP;        //declare a struct for the new gray scale BMP file

    BMP.head = read_header(input);     //read the header from the input file
    BMP.data = read_data(input);       //read the RGB color from the input file

    NEW_BMP.head = BMP.head;           //copy header information to the gray scale header struct

    //modify the header information according to the format of gray scale BMP file
    NEW_BMP.head.BMPbits_per_pixel = 8;
    NEW_BMP.head.BMPnumber_color_used = 256;
    NEW_BMP.head.BMPdata_offset = 1078;
    NEW_BMP.head.BMPpixeldata_size = NEW_BMP.head.BMPbitmap_width*NEW_BMP.head.BMPbitmap_height;
    NEW_BMP.head.BMPfile_len = 54 + 4*256 + (NEW_BMP.head.BMPbitmap_width+gray_padding(NEW_BMP.head.BMPbitmap_width))*NEW_BMP.head.BMPbitmap_height;

    NEW_BMP.data = transform_color(BMP);    //transform the color data from RGB to gray scale
    write_gray_BMP(NEW_BMP, output);        //write the information to the output file

    fclose(input);
    fclose(output);
    return 0;
}