#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Here, you have to define pixelRGB struct and its functions:
 * - pixel* getPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y );
 * - void setPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y, pixelRGB* pixel);
 *
*/

typedef struct _pixelRGB {
  unsigned char R; //Valeur de rouge
  unsigned char G; //Valeur de vert
  unsigned char B; //Valeur de bleu
} pixelRGB ;

// Prototype de la fonction pour accéder à un pixel spécifique
pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y );

// Prototype de la fonction pour afficher un pixel
void print_pixel(char*filename, int x, int y);


#endif
