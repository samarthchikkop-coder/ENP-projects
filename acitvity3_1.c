#include <stdio.h>

int main()
{
    int media_type;
    int bit_rate, bus_length, node_count;
    int fault_type, noise_level, termination;

    printf("CAN Physical Media Selection\n");
    printf("1. Single Wire CAN\n");
    printf("2. Differential Twisted Pair CAN\n");
    printf("3. Twisted Pair with Screen\n");

    printf("Enter medium: ");
    scanf("%d", &media_type);

    printf("Enter bit rate (kbps): ");
    scanf("%d", &bit_rate);

    printf("Enter bus length (m): ");
    scanf("%d", &bus_length);

    printf("Enter number of nodes: ");
    scanf("%d", &node_count);

    printf("Fault type (0=No fault, 1=Open, 2=Short): ");
    scanf("%d", &fault_type);

    printf("Noise level (0-100%%): ");
    scanf("%d", &noise_level);

    printf("Termination (0=Absent, 1=Present): ");
    scanf("%d", &termination);

    printf("\n--- CAN BUS ANALYSIS ---\n");

    /* Display selected medium */
    if (media_type == 1)
    {
        printf("CAN Medium        : Single Wire CAN\n");
        printf("Noise Rejection   : LOW\n");
        printf("Radiation         : HIGH\n");
        printf("Recommended       : Low-speed/simple applications\n");
    }
    else if (media_type == 2)
    {
        printf("CAN Medium        : Differential Twisted Pair\n");
        printf("Noise Rejection   : HIGH\n");
        printf("Radiation         : LOW\n");
        printf("Recommended       : Automotive CAN applications\n");
    }
    else if (media_type == 3)
    {
        printf("CAN Medium        : Twisted Pair with Screen\n");
        printf("Noise Rejection   : VERY HIGH\n");
        printf("Radiation         : VERY LOW\n");
        printf("Recommended       : High-noise environments\n");
    }
    else
    {
        printf("Invalid medium\n");
        return 0;
    }

    printf("Bit Rate          : %d kbps\n", bit_rate);
    printf("Bus Length        : %d m\n", bus_length);
    printf("Nodes             : %d\n", node_count);

    /* Termination */
    if (termination == 1)
        printf("Termination       : OK\n");
    else
        printf("Termination       : FAULT\n");

    /* Fault analysis */
    if (fault_type == 1)
        printf("Fault Effect      : Open circuit detected\n");
    else if (fault_type == 2)
        printf("Fault Effect      : Short circuit detected\n");
    else
        printf("Fault Effect      : No fault\n");

    /* Noise analysis */
    if (noise_level > 70)
        printf("Noise Effect      : HIGH\n");
    else if (noise_level > 30)
        printf("Noise Effect      : MEDIUM\n");
    else
        printf("Noise Effect      : LOW\n");

    /* Overall bus status */
    if (fault_type != 0)
        printf("Bus Status        : UNSUITABLE\n");
    else if (termination == 0)
        printf("Bus Status        : UNSUITABLE\n");
    else if (bit_rate > 500 && media_type == 1)
        printf("Bus Status        : UNSUITABLE\n");
    else if (noise_level > 70 && media_type == 1)
        printf("Bus Status        : UNSUITABLE\n");
    else
        printf("Bus Status        : SUITABLE\n");

    return 0;
}