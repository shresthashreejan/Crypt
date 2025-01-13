#include <stdio.h>

int main() {
    int a;
    int *point;
    point = &a;
    int **double_point;
    double_point = &point;
    int ***triple_point;
    triple_point = &double_point;
    printf("%p", triple_point);
}