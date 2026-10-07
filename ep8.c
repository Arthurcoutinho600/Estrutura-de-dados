#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int width;
    int height;
    int max_value;
    unsigned char ***data;
} Image;

void write_image_to_ppm(const char *filename, Image *image)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        perror("Erro ao abrir o arquivo %s para escrita.\n");
        return;
    }

    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", image->width, image->height);
    fprintf(file, "%d\n", image->max_value);

    for (int i = 0; i < image->height; i++)
    {
        for (int j = 0; j < image->width; j++)
        {
            fprintf(file, "%d %d %d\n", 
                image->data[i][j][0], 
                image->data[i][j][1], 
                image->data[i][j][2]);
        }

    fprintf(file, "\n");
    }

    fclose(file);
}

void load_image_from_ppm(const char *filename, Image *image)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Erro: Não foi possível abrir o arquivo %s.\n", filename);
        exit(1);
    }

    char magic[3];
    if (fscanf(file, "%2s", magic) != 1) {
        perror("Erro: Não foi possível ler o numero magico\n");
        fclose(file);
        exit(1);
    }

    if (magic[0] != 'P' || magic[1] != '3') {
        perror("Erro: Formato de arquivo inválido. Esperado P3, encontrado\n");
        fclose(file);
        exit(1);
    }

    fclose(f);
    exit(1);
}

int width, height, max_value;
    if (fscanf(file, "%d %d", &width, &height) != 2) {
        perror("Erro: Não foi possível ler a largura e altura da imagem\n");
        fclose(file);
        exit(1);
    }

    if (fscanf(file, "%d", &max_value) != 1) {
        perror("Erro: Não foi possível ler o valor máximo de cor\n");
        fclose(file);
        exit(1);
    }

    if fscanf(max_value) != 255 {
        perror("Erro: Valor máximo de cor inválido. Esperado 255, encontrado\n");
        fclose(file);
        exit(1);
    }

    image->width = width;
    image->height = height;
    image->max_value = max_value;

    image->data = (unsigned char ***)malloc(height * sizeof(unsigned char **));
    if (!image->data) {
        perror("Erro: Falha na alocação de memória para a imagem\n");
        fclose(file);
        exit(1);
    }

    for (int j = 0; j < width; j++) {
        image->data[i][j] = (unsigned char **)malloc(width * sizeof(unsigned char *));
        if (!image->data[i][j]) {
            perror("Erro: Falha na alocação de memória para a imagem [%d][%d]\n", i, j);
            fclose(file);
            exit(1);
        }
        for (int i = 0; i < height; i++) {
            
            int r, g, b;
            if (fscanf(file, "%d %d %d", &r, &g, &b) != 3) {
                perror("Erro: Não foi possível ler os valores de cor para o pixel [%d][%d]\n", i, j);
                fclose(file);
                exit(1);
            }

            image->data[i][j][0] = (unsigned char)r;
            image->data[i][j][1] = (unsigned char)g;
            image->data[i][j][2] = (unsigned char)b;
        
        }

    fclose(file);
}

int main(void)
{
    Image image;
    load_image_from_ppm("input.ppm", &image);
    write_image_to_ppm("output.ppm", &image);

    // Free allocated memory
    for (int i = 0; i < image.height; i++)
    {
        for (int j = 0; j < image.width; j++)
        {
            free(image.data[i][j]);
        }
        free(image.data[i]);
    }
    free(image.data);

    return 0;
}