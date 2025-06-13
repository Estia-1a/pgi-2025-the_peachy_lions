#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();
void dimension (char *source_path);
void first_pixel (char *source_path);
void tenth_pixel (char *source_path);
void second_line(char *source_path);
void color_red (char *source_path);
void color_blue (char *source_path);
void color_green (char *source_path);
void min_component(char *source_path, char *value);
void max_component(char *source_path, char *value);
void max_pixel(char *source_path);
void min_pixel(char *source_path);
void grayscale_image(const char *input_filename, const char* output_filename);
#endif
