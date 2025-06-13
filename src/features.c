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
}
void min_component(char *source_path, char *value) {
    unsigned char *data;
    int width, height, pixel;
    int result = read_image_data(source_path, &data, &width, &height, &pixel);

    if(result == 0){
        printf("ERREUR !\n");
        return;
    }

    int min_value = 255;  // Valeur max possible d’un canal R, G ou B
    int min_x = 0;
    int min_y = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel = y * width + x;
            int r = data[pixel * 3];
            int g = data[pixel * 3 + 1];
            int b = data[pixel * 3 + 2];
            int verif = 255;

            if (*value == 'R') {
                verif = r;
            } else if (*value == 'G') {
                verif = g;
            } else if (*value == 'B') {
                verif = b;
            }

            if (verif < min_value) {
                min_value = verif;
                min_x = x;
                min_y = y;
            }
        }
    }

    if (*value == 'R') {
        printf("min_component R (%d, %d): %d\n", min_x, min_y, min_value);
    } else if (*value == 'G') {
        printf("min_component G (%d, %d): %d\n", min_x, min_y, min_value);
    } else if (*value == 'B') {
        printf("min_component B (%d, %d): %d\n", min_x, min_y, min_value);
    }
}
void max_component(char *source_path, char *value) {
    unsigned char *data;
    int width, height, pixel;
    int result = read_image_data(source_path, &data, &width, &height, &pixel);
    
    if(result == 0){
        printf("ERREUR !\n");
        return;
    }

    int max_value = 0;
    int max_x = 0;
    int max_y = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel = y * width + x;
            int r = data[pixel * 3];
            int g = data[pixel * 3 + 1];
            int b = data[pixel * 3 + 2];
            int verif = 0;

            if (*value == 'R') {
                verif = r;
            } else if (*value == 'G') {
                verif = g;
            } else if (*value == 'B') {
                verif = b;
            }

            if (verif > max_value) {
                max_value = verif;
                max_x = x;
                max_y = y;
            }
        }
    }

    if (*value == 'R') {
        printf("max_component R (%d, %d): %d\n", max_x, max_y, max_value);
    } else if (*value == 'G') {
        printf("max_component G (%d, %d): %d\n", max_x, max_y, max_value);
    } else if (*value == 'B') {
        printf("max_component B (%d, %d): %d\n", max_x, max_y, max_value);
    }
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
void max_pixel(char *source_path) {
    unsigned char *data;
    int width, height, pixel;
    int result = read_image_data(source_path, &data, &width, &height, &pixel);

    if (result == 0) {
        printf("ERREUR !\n");
        return;
    }

    int max_sum = 0;
    int max_x = 0;
    int max_y = 0;
    int r_max = 0, g_max = 0, b_max = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel = y * width + x;
            int r = data[pixel * 3];
            int g = data[pixel * 3 + 1];
            int b = data[pixel * 3 + 2];
            int sum = r + g + b;

            if (sum > max_sum) {
                max_sum = sum;
                max_x = x;
                max_y = y;
                r_max = r;
                g_max = g;
                b_max = b;
            }
        }
    }

    printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, r_max, g_max, b_max);
}
void min_pixel(char *source_path) {
    unsigned char *data;
    int width, height, pixel;
    int result = read_image_data(source_path, &data, &width, &height, &pixel);
    if (result == 0) {
        printf("ERREUR !\n");
        return;
    }

    int min_sum = 255 * 3 + 1;
    int min_x = 0;
    int min_y = 0;
    int r_min = 0, g_min = 0, b_min = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel = y * width + x;
            int r = data[pixel * 3];
            int g = data[pixel * 3 + 1];
            int b = data[pixel * 3 + 2];
            int sum = r + g + b;

            if (sum < min_sum) {
                min_sum = sum;
                min_x = x;
                min_y = y;
                r_min = r;
                g_min = g;
                b_min = b;
            }
        }
    }

    printf("min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, r_min, g_min, b_min);
}
void grayscale_image(const char *input_filename, const char *output_filename) {
    unsigned char *data;
    int width, height, pixel;

    int result = read_image_data(input_filename, &data, &width, &height, &pixel);
    if (result == 0) {
        printf("ERREUR lors de la lecture de l'image.\n");
        return;
    }

    unsigned char *gray_data = malloc(width * height * 3);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int idx = (y * width + x) * 3;
            unsigned char r = data[idx];
            unsigned char g = data[idx + 1];
            unsigned char b = data[idx + 2];

            unsigned char gray = (r + g + b) / 3;

            gray_data[idx]     = gray;
            gray_data[idx + 1] = gray;
            gray_data[idx + 2] = gray;
        }
    }

    if (write_image_data(output_filename, gray_data, width, height)) {
        printf("A new image %s as a gray version of the input image\n", output_filename);
    } else {
        printf("Erreur lors de l'écriture de l'image.\n");
    }

    free(data);
    free(gray_data);
}