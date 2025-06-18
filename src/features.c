#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension (char *source_path) {
    int width, height, channel_count;
    unsigned char *data;
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (result) {
        printf("Dimension: %d, %d", width, height);
    } else {
        printf("ERREUR !");
    }
}
void first_pixel(char *source_path) {
    int width, height, channel_count, R, G, B;
    unsigned char *data;
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (result) {
        R = data[0];
    G = data[1];
    B = data[2];
    printf("first_pixel : %d, %d, %d", R, G, B);
    } else {
        printf("ERREUR !");
    }
}
void tenth_pixel(char *source_path) {
    int width, height, channel_count, R, G, B, n;
    n = 10;
    unsigned char *data;
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (result) {
    R = data[3*n];
    G = data[3*n+1];
    B = data[3*n+2];
    printf("tenth_pixel : %d, %d, %d", R, G, B);
    } else {
        printf("ERREUR !");
    }    
}
void second_line(char *source_path) {
    int width, height, channel_count, R, G, B;
    unsigned char *data;
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);
    if (result) {
    R = data[3*width];
    G = data[3*width+1];
    B = data[3*width+2];
    printf("second_line : %d, %d, %d", R, G, B);
    } else {
        printf("ERREUR !");
    }
/*void min_pixel(char * filename){
    if (read_image_data (filename, &data, &width, &height, &n) == 0) {
        printf(stderr, "Erreur: impossible de lire l'image: %s\n", filename);
    } else {

    }
}*/
}
void color_red(char *source_path) {
    const char * image_out = "image_out.bmp";
    unsigned char * data;
    int width;
    int height;
    int channel_count;
    read_image_data (source_path, &data, &width,&height, &channel_count);
    int a = width*height*3;
    int b = 1;
    int c = 2;
    while (b <a){
        data[b]=0;
        data[b]=0;
        b=b+3;}
    while (c<a)
    {
    data [c]=0;
    c=c+3;
    }
    write_image_data(image_out, data, width, height);
}
void color_green(char *source_path) {
    const char * image_out = "image_out.bmp";
    unsigned char * data;
    int width;
    int height;
    int channel_count;
    read_image_data (source_path, &data, &width,&height, &channel_count);
    int a = width*height*3;
    int b = 0;
    int c = 2;
    while (b <a){
        data[b]=0;
        data[b]=0;
        b=b+3;}
    while (c<a)
    {
    data [c]=0;
    c=c+3;
    }
    write_image_data(image_out, data, width, height);
}
void color_blue(char *source_path) {
   const char * image_out = "image_out.bmp";
    unsigned char * data;
    int width;
    int height;
    int channel_count;
    read_image_data (source_path, &data, &width,&height, &channel_count);
    int a = width*height*3;
    int b = 1;
    int c = 0;
    while (b <a){
        data[b]=0;
        data[b]=0;
        b=b+3;}
    while (c<a)
    {
    data [c]=0;
    c=c+3;
    }
    write_image_data(image_out, data, width, height);
}
void rotate_cw(char *source_path) {
    const char *image_out = "image_out.bmp";
    unsigned char *data_in;
    unsigned char *data_out;
    int width_in;
    int height_in;
    int channel_count;

    read_image_data(source_path, &data_in, &width_in, &height_in, &channel_count);

    int width_out = height_in;
    int height_out = width_in;

    data_out = (unsigned char *)malloc(width_out * height_out * channel_count * sizeof(unsigned char));
    if (data_out == NULL) {
        fprintf(stderr, "Failed to allocate memory for rotated image.\n");
        free(data_in);
        return;
    }

    for (int y = 0; y < height_in; ++y) {
        for (int x = 0; x < width_in; ++x) {
            int input_pixel_index = (y * width_in + x) * channel_count;

            // Nouvelle formule pour la rotation de 90 degrés dans le sens horaire
            // Le pixel (x, y) de l'entrée se déplace vers (new_x, new_y) en sortie
            // new_x = original_height - 1 - original_y
            // new_y = original_x
            int new_x = (height_in - 1) - y;
            int new_y = x;
            int output_pixel_index = (new_y * width_out + new_x) * channel_count;

            for (int c = 0; c < channel_count; ++c) {
                data_out[output_pixel_index + c] = data_in[input_pixel_index + c];
            }
        }
    }

    write_image_data(image_out, data_out, width_out, height_out);

    free(data_in);
    free(data_out);
}
