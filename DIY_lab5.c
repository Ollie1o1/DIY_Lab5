#include <stdio.h>
#include <math.h>

double eucDistN(int n);

int main(){
    int n;
    double distance;

    printf("Enter the number of dimensions: ");
    scanf("%d", &n);

    distance = eucDistN(n);
    printf("Euclidean Distance: %.2lf\n", distance);
    
    return 0;
}

double eucDistN(int n){
    double vector1[100], vector2[100];
    double sum = 0;

    printf("Enter the dimensions for vector1: ");
    for(int i = 0; i < n; i++){
        scanf("%lf", &vector1[i]);
    }

    printf("Enter the dimensions for vector2: ");
     for(int i = 0; i < n; i++){
        scanf("%lf", &vector2[i]);
    }

    for(int i = 0; i < n; i++){
        //the 2 at the end is the syntax for raising the equation
        //to the power of 2
        sum += pow(vector1[i] - vector2[i], 2);
        //instead of sum = sum + .... you use sum += !!!
    }

    return sqrt(sum);
}