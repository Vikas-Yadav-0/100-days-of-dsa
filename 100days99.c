#include <stdio.h>
#include <stdlib.h>

// Structure for car details
typedef struct {
    int position;
    int speed;
} Car;

// Function to compare cars by position in descending order
int compare(const void *a, const void *b) {
    return ((Car *)b)->position - ((Car *)a)->position;
}

// Function to find number of car fleets
int carFleet(int target, int position[], int speed[], int n) {

    Car cars[n];

    // Store position and speed together
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Sort cars by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0;

    for (int i = 0; i < n; i++) {

        // Time to reach target
        double time = (double)(target - cars[i].position) / cars[i].speed;

        // New fleet formed
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    return fleets;
}

int main() {
    int target, n;

    // Input target distance
    scanf("%d", &target);

    // Input number of cars
    scanf("%d", &n);

    int position[n], speed[n];

    // Input positions
    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }

    // Input speeds
    for (int i = 0; i < n; i++) {
        scanf("%d", &speed[i]);
    }

    // Output number of fleets
    printf("%d\n", carFleet(target, position, speed, n));

    return 0;
}