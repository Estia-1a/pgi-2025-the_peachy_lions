#include <estia-image.h>
#include <stdio.h>

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
    int width;
    int height;
    int channel_count;
    unsigned *data;
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);
    if(result) {
    printf ("dimensions: %d, %d", width, height);
    } else {
    printf("erreur: ");
    }
}
void first_pixel(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image : %s\n", source_path);
        return;
    }

    if (data == NULL || channel_count < 3) {
        fprintf(stderr, "Données d'image invalides ou image sans composantes RGB suffisantes.\n");
        return;
    }

    int R = data[0];
    int G = data[1];
    int B = data[2];

    printf("first_pixel: %d, %d, %d\n", R, G, B);
}
void tenth_pixel(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0, n = 10;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image : %s\n", source_path);
        return;
    }

    if (data == NULL || channel_count < 3) {
        fprintf(stderr, "Données d'image invalides ou image sans composantes RGB suffisantes.\n");
        return;
    }

    int R = data[3*n];
    int G = data[3*n+1];
    int B = data[3*n+2];

    printf("first_pixel: %d, %d, %d\n", R, G, B);
}
void second_line(char *source_path) {
    unsigned char *data = NULL;
    int width = 0, height = 0, channel_count = 0;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        fprintf(stderr, "Erreur lors de la lecture de l'image : %s\n", source_path);
        return;
    }

    if (data == NULL || channel_count < 3) {
        fprintf(stderr, "Données d'image invalides ou image sans composantes RGB suffisantes.\n");
        return;
    }

    int R = data[3*width];
    int G = data[3*width+1];
    int B = data[3*width+2];

    printf("first_pixel: %d, %d, %d\n", R, G, B);
}