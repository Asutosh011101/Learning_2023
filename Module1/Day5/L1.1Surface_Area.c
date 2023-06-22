#include <stdio.h>

struct Dimensions {
    float length;
    float width;
    float height;
};

float calculateVolume(struct Dimensions* dimensions) {
    return dimensions->length * dimensions->width * dimensions->height;
}

float calculateSurfaceArea(struct Dimensions* dimensions) {
    return 2 * (dimensions->length * dimensions->width + dimensions->length * dimensions->height + dimensions->width * dimensions->height);
}

int main() {
    struct Dimensions dimensions;
    struct Dimensions* dimensionsPtr = &dimensions;

    printf("Enter the dimensions of the box:\n");
    printf("Length: ");
    scanf("%f", &(dimensionsPtr->length));
    printf("Width: ");
    scanf("%f", &(dimensionsPtr->width));
    printf("Height: ");
    scanf("%f", &(dimensionsPtr->height));

    float volume = calculateVolume(dimensionsPtr);
    float surfaceArea = calculateSurfaceArea(dimensionsPtr);

    printf("\n");
    printf("Box Dimensions:\n");
    printf("Length: %.2f\n", dimensionsPtr->length);
    printf("Width: %.2f\n", dimensionsPtr->width);
    printf("Height: %.2f\n", dimensionsPtr->height);
    printf("\n");
    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    return 0;
}
