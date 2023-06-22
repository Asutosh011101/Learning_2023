#include <stdio.h>

struct ComplexNumber {
    float realPart;
    float imaginaryPart;
};

void readComplex(struct ComplexNumber* c) {
    printf("Enter real part: ");
    scanf("%f", &(c->realPart));
    printf("Enter imaginary part: ");
    scanf("%f", &(c->imaginaryPart));
}

void writeComplex(struct ComplexNumber c) {
    printf("Complex number: %.2f + %.2fi\n", c.realPart, c.imaginaryPart);
}

struct ComplexNumber addComplex(struct ComplexNumber c1, struct ComplexNumber c2) {
    struct ComplexNumber result;
    result.realPart = c1.realPart + c2.realPart;
    result.imaginaryPart = c1.imaginaryPart + c2.imaginaryPart;
    return result;
}

struct ComplexNumber multiplyComplex(struct ComplexNumber c1, struct ComplexNumber c2) {
    struct ComplexNumber result;
    result.realPart = c1.realPart * c2.realPart - c1.imaginaryPart * c2.imaginaryPart;
    result.imaginaryPart = c1.realPart * c2.imaginaryPart + c1.imaginaryPart * c2.realPart;
    return result;
}

int main() {
    struct ComplexNumber complex1, complex2, sum, product;

    printf("Enter the first complex number:\n");
    readComplex(&complex1);

    printf("Enter the second complex number:\n");
    readComplex(&complex2);

    printf("\n");

    printf("First complex number: ");
    writeComplex(complex1);

    printf("Second complex number: ");
    writeComplex(complex2);

    sum = addComplex(complex1, complex2);
    printf("Sum of the two complex numbers: ");
    writeComplex(sum);

    product = multiplyComplex(complex1, complex2);
    printf("Product of the two complex numbers: ");
    writeComplex(product);

    return 0;
}
