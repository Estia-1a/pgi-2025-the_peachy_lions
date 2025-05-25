#include <estia-image.h>
#include <stdio.h>
#include "utils.h"

pixelRGB* get_pixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y) {
    if (!data || x >= width || y >= height) {
        return NULL;
    }

    unsigned int index = (y * width + x) * n;

    return (pixelRGB*) &data[index];

}
#include "estia-image.h"

void print_pixel(char * filename, int x, int y) {
    unsigned char *data = NULL;
    int width, height, n;

    if (read_image_data (filename, &data, &width, &height, &n) != 0) {
        fprintf(stderr, "Failed to read image: %s\n", filename);
        return;
    }
    pixelRGB *pixel = get_pixel(data, width, height, n, x, y);

if (pixel) {
    printf("print_pixel (%d, %d) %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
} else {
    fprintf(stderr, "Pixel (%d, %d) is out of range or image data is NULL.\n", x, y);
}

free(data);
}
