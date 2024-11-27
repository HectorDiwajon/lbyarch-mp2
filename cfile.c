#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declaration for assembly
void imgCvtGrayInttoFloat(int num_elements, int *intPixels, float *floatPixels, int divisor);

int main() {
	int i, j;
	int divisor = 255;
	int height, width;
	
	printf("Input Height: ");
	scanf("%d", &height);
	
	printf("Input Width: ");
	scanf("%d", &width);
	
    int num_elements = height * width;
    int intPixels[height][width];
    float* floatPixels = (float*)malloc(num_elements*sizeof(float));
    
    
    for (i = 0; i < height; i++) {
		printf("Enter value for Row %d: ", i+1);
        for (j = 0; j < width; j++) {
            if (j == width - 1) {
                scanf("%d", &intPixels[i][j]);
            } else {
                scanf("%d,", &intPixels[i][j]);
            }
        }
    }
	
	// For Verification - Delete when Submitting
    printf("\nThe 2D array inputted is:\n");
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

	i = 0, j = 0;
	
	float floatArray[height][width];
	
    // Convert 1d array to 2d array
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            floatArray[i][j] = floatPixels[i * width + j];
//            printf("[%d][%d] %.2f = %.2f \n", i+1, j+1, floatArray[i][j], floatPixels[i * width + j]);
        }
    }
    i = 0, j = 0;
    printf("Converted floating-point pixel values:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%.2f ", floatArray[i][j]);
        }
        printf("\n");
    }
        
    // Print execution time
    printf("Execution time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

