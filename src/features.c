#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void color_gray(char *source_path) {
    const char *image_out = "image_out.bmp";
    unsigned char *data;
    int width;
    int height;
    int channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    if (channel_count != 3) {
        fprintf(stderr, "Erreur: L'image doit avoir 3 canaux (RGB) pour la conversion en niveaux de gris.\n");
        free(data);
        return;
    }

    for (int i = 0; i < width * height * channel_count; i += channel_count) {
        unsigned char blue = data[i];
        unsigned char green = data[i + 1];
        unsigned char red = data[i + 2];

        unsigned char gray = (unsigned char)(0.299 * red + 0.587 * green + 0.114 * blue);

        data[i] = gray;
        data[i + 1] = gray;
        data[i + 2] = gray;
    }

    write_image_data(image_out, data, width, height);
    free(data);
}

void color_invert(char *source_path) {
    const char *image_out = "image_out.bmp";
    unsigned char *data;
    int width;
    int height;
    int channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    if (channel_count != 3) {
        fprintf(stderr, "Erreur: L'image doit avoir 3 canaux (RGB) pour inverser les couleurs.\n");
        free(data);
        return;
    }

    for (int i = 0; i < width * height * channel_count; i++) {
        data[i] = 255 - data[i];
    }

    write_image_data(image_out, data, width, height);
    free(data);
}
void rotate_acw(char *source_path) {
    const char *image_out = "image_out.bmp";
    unsigned char *data_in;
    unsigned char *data_out;
    int width_in;
    int height_in;
    int channel_count;

    if (read_image_data(source_path, &data_in, &width_in, &height_in, &channel_count) == 0) {
        fprintf(stderr, "Erreur: Impossible de lire l'image %s.\n", source_path);
        return;
    }

    if (channel_count != 3) {
        fprintf(stderr, "Erreur: L'image doit avoir 3 canaux (RGB) pour la rotation. Nombre de canaux: %d\n", channel_count);
        free(data_in);
        return;
    }

    int width_out = height_in;
    int height_out = width_in;

    data_out = (unsigned char *)malloc(width_out * height_out * channel_count * sizeof(unsigned char));
    if (data_out == NULL) {
        fprintf(stderr, "Erreur: Impossible d'allouer la mémoire pour l'image de sortie.\n");
        free(data_in);
        return;
    }

    for (int y_in = 0; y_in < height_in; y_in++) {
        for (int x_in = 0; x_in < width_in; x_in++) {
            int x_out = y_in;
            int y_out = (width_in - 1) - x_in;

            int index_in = (y_in * width_in + x_in) * channel_count;
            int index_out = (y_out * width_out + x_out) * channel_count;

            data_out[index_out + 0] = data_in[index_in + 0];
            data_out[index_out + 1] = data_in[index_in + 1];
            data_out[index_out + 2] = data_in[index_in + 2];
        }
    }

    write_image_data(image_out, data_out, width_out, height_out);

    free(data_in);
    free(data_out);
}

void scale_bilinear(char *source_path, float scale_factor) {
    const char *image_out = "image_out.bmp";
    unsigned char *data_in;
    unsigned char *data_out;
    int width_in;
    int height_in;
    int channel_count;

    if (read_image_data(source_path, &data_in, &width_in, &height_in, &channel_count) == 0) {
        fprintf(stderr, "Erreur: Impossible de lire l'image %s.\n", source_path);
        return;
    }

    if (channel_count != 3) {
        fprintf(stderr, "Erreur: L'image doit avoir 3 canaux (RGB) pour l'interpolation bilinéaire. Nombre de canaux: %d\n", channel_count);
        free(data_in);
        return;
    }

    int width_out = (int)roundf(width_in * scale_factor);
    int height_out = (int)roundf(height_in * scale_factor);

    data_out = (unsigned char *)malloc(width_out * height_out * channel_count * sizeof(unsigned char));
    if (data_out == NULL) {
        fprintf(stderr, "Erreur: Impossible d'allouer la mémoire pour l'image de sortie.\n");
        free(data_in);
        return;
    }

    for (int y_out = 0; y_out < height_out; y_out++) {
        for (int x_out = 0; x_out < width_out; x_out++) {
            float x_in_float = (float)x_out / scale_factor;
            float y_in_float = (float)y_out / scale_factor;

            int x1 = (int)floorf(x_in_float);
            int y1 = (int)floorf(y_in_float);
            int x2 = x1 + 1;
            int y2 = y1 + 1;

            float fx = x_in_float - x1;
            float fy = y_in_float - y1;

            for (int c = 0; c < channel_count; c++) {
                int val11 = (x1 >= 0 && x1 < width_in && y1 >= 0 && y1 < height_in) ? data_in[(y1 * width_in + x1) * channel_count + c] : 0;
                int val21 = (x2 >= 0 && x2 < width_in && y1 >= 0 && y1 < height_in) ? data_in[(y1 * width_in + x2) * channel_count + c] : 0;
                int val12 = (x1 >= 0 && x1 < width_in && y2 >= 0 && y2 < height_in) ? data_in[(y2 * width_in + x1) * channel_count + c] : 0;
                int val22 = (x2 >= 0 && x2 < width_in && y2 >= 0 && y2 < height_in) ? data_in[(y2 * width_in + x2) * channel_count + c] : 0;

                float interpolated_value =
                    val11 * (1 - fx) * (1 - fy) +
                    val21 * fx * (1 - fy) +
                    val12 * (1 - fx) * fy +
                    val22 * fx * fy;

                data_out[(y_out * width_out + x_out) * channel_count + c] = (unsigned char)roundf(interpolated_value);
            }
        }
    }

    write_image_data(image_out, data_out, width_out, height_out);

    free(data_in);
    free(data_out);
}