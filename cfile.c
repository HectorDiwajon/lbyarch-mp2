#include <stdio.h>

extern void imgCvtGrayInttoFloat(int a);

int main() 
{
    int height, width, i, j;
    
    scanf("%d %d", &height, &width);
    
    int array[height][width];

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (j == width - 1) {
                // For the last element in a row
                scanf("%d", &array[i][j]);
            } else {
                // For all other elements
                scanf("%d,", &array[i][j]);
            }
        }
    }
    
    // For Verification - Delete when Submitting
    printf("The 2D array is:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
	
	// Convert Int to Float for Array
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
			int a = array[i][j];
            imgCvtGrayInttoFloat(a);
        }
    }
	
	//Prints Final Array
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
