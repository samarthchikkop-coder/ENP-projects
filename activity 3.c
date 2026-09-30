#include <stdio.h>

#define RECESSIVE_THRESHOLD 0.5
#define DOMINANT_THRESHOLD 0.9

#define CAN_H_RECESSIVE 2.5
#define CAN_L_RECESSIVE 2.5

#define CAN_H_DOMINANT 3.5
#define CAN_L_DOMINANT 1.5

int main()
{
    float CAN_H, CAN_L, Vdiff;
    int bit_rate;

    printf("HIGH-SPEED CAN VOLTAGE MONITOR\n");

    printf("Enter CAN_H voltage: ");
    scanf("%f", &CAN_H);

    printf("Enter CAN_L voltage: ");
    scanf("%f", &CAN_L);

    printf("Enter CAN bit rate (kbps): ");
    scanf("%d", &bit_rate);

    /* Calculate differential voltage */
    Vdiff = CAN_H - CAN_L;

    printf("\nCAN_H = %.2f V\n", CAN_H);
    printf("CAN_L = %.2f V\n", CAN_L);
    printf("Vdiff  = %.2f V\n", Vdiff);
    printf("Bit Rate = %d kbps\n", bit_rate);

    /* Determine CAN bus state */
    if (Vdiff < RECESSIVE_THRESHOLD)
    {
        printf("\nCAN BUS STATE : RECESSIVE\n");
    }
    else if (Vdiff > DOMINANT_THRESHOLD)
    {
        printf("\nCAN BUS STATE : DOMINANT\n");
    }
    else
    {
        printf("\nCAN BUS STATE : INVALID / NOISE REGION\n");
    }

    return 0;
}