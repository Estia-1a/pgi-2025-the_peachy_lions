#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "estia-image.h" 

// Fonction pour obtenir un pointeur vers un pixel spécifique (xx, y)
pixelRGB* get_pixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y) {
    if (!data || x >= width || y >= height) return NULL;
    // Calcul de l'indice dans le tableau de données
    unsigned int index = (y * width + x) * n;
    return (pixelRGB*) &data[index] ;
 }

// Fonction pour lire une image et afficher les composantes RGB d'un pixel (x, y)
void print_pixel(char * filename, int x, int y) {
    unsigned char *data = NULL;
    int width, height, n; // n = nombre de canaux (normalement 3 pour RGB)

        // Lecture des données de l'image
    if (read_image_data (filename, &data, &width, &height, &n) == 0) {
        fprintf(stderr, "Erreur: impossible de lire l'image: %s\n", filename);
        return;
}
    //Récupération du pixel à (x, y)
    pixelRGB *pixel = get_pixel(data, width, height, n, x, y);
    if (pixel) {
        //Affichage des composantes RGB
        printf("print_pixel (%d, %d) %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
    } else {
    fprintf(stderr, "Pixel (%d, %d) is out of range or image data is NULL.\n", x, y);
}
/*void min_pixel(char * filename){
    if (read_image_data (filename, &data, &width, &height, &n) == 0) {
        printf(stderr, "Erreur: impossible de lire l'image: %s\n", filename);
    } else {

    }
}*/

//Libération de la mémoire allouée pour l'image
free(data);

}