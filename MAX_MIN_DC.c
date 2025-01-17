#include<stdio.h>
#include<conio.h>

int max, min;
int a[100];


void maxmin(int i, int j) {
    int max1, min1, mid;
    if(i == j) {                          
        max = min = a[i];
    } else {
        if(i == j - 1) {                
            if(a[i] < a[j]) {
                max = a[j];
                min = a[i];
            } else {
                max = a[i];
                min = a[j];
            }
        } else {                              
            mid = (i + j) / 2;
            maxmin(i, mid);           
            max1 = max;
            min1 = min;
            maxmin(mid + 1, j);   
            if(max < max1)
                max = max1;
            if(min > min1)
                min = min1;
        }
    }
}

int main() {
    int i, num;
    float average = 0;
    clrscr();
    printf("\nEnter the total number of numbers : ");
    scanf("%d", &num);

    printf("Enter the numbers : \n");
    for(i = 0; i < num; i++)
        scanf("%d", &a[i]);

    max = a[0];
    min = a[0];

    maxmin(0, num - 1);  

    
    for(i = 0; i < num; i++)
        average += a[i];
    average /= num;

  
    printf("Minimum element in the array : %d\n", min);
    printf("Maximum element in the array : %d\n", max);
    printf("Average of the elements in the array: %.2f\n", average);
    printf("Range of the elements in the array: %d\n", max - min);

    getch();	
    return 0;
}
