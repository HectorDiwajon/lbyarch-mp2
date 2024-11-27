#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declaration for assembly
void imgCvtGrayInttoFloat(int num_elements, int *intPixels, float *floatPixels, int divisor);

int main() {
	int i, j;
	int divisor = 255;
    int height = 3, width = 4; // Example dimensions
    int num_elements = height * width;
    int intPixels[height][width];
    float* floatPixels = (float*)malloc(num_elements*sizeof(float));
	
	
	printf("Input Height: ");
	scanf("%d", &height);;
	
	printf("Input Width: ");
	scanf("%d", &width);
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("Enter value for intPixels[%d][%d]: ", i+1, j+1);
            scanf("%d", &intPixels[i][j]);
        }
    }

	
	// For Verification - Delete when Submitting
    printf("The 2D array inputted is:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", intPixels[i][j]);
        }
        printf("\n");
    }
    // Timing the execution
    clock_t start = clock();
	
    // Call the assembly function
    imgCvtGrayInttoFloat(num_elements, intPixels, floatPixels, divisor);
    clock_t end = clock();
    
	printf("\n\n");

    // Print the output
    printf("Converted floating-point pixel values:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%.2f ", floatPixels[i * width + j]);
        }
        printf("\n");
    }
    

    // Print execution time
    printf("Execution time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

