/******************************************************************************
 * Project      : Battery Management System (BMS) Simulation
 * File         : main.c
 * Author       : Neha
 * Description  :
 * This is the main application file for the Battery Management System (BMS)
 * simulation.
 *
 * The program provides a menu-driven interface that allows the user to:
 *  - Charge the battery
 *  - Discharge the battery
 *  - Display the battery status
 *  - Exit the application
 *
 * The Battery module internally manages:
 *  - State of Charge (SOC)
 *  - State of Health (SOH)
 *  - Thermal Management
 ******************************************************************************/

#include <stdio.h>
#include "battery.h"

/******************************************************************************
 * Function : main()
 *
 * Description:
 * Entry point of the Battery Management System simulation.
 *
 * The program continuously displays a menu and performs the selected
 * battery operation until the user chooses to exit.
 *
 * Returns:
 *      0 - Successful execution
 ******************************************************************************/

int main()
{
    /* Create Battery Object */

    Battery battery;

    /* User Menu Choice */

    int choice;

    /* User Inputs */

    float current;
    float hours;

    /* Initialize Battery */

    Battery_Init(&battery);

    /* Main Program Loop */

    while (1)
    {
        printf("\n=====================================\n");
        printf("      EV Battery Management System\n");
        printf("=====================================\n");

        printf("1. Charge Battery\n");
        printf("2. Discharge Battery\n");
        printf("3. Display Battery Status\n");
        printf("4. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            /*---------------- Charge Battery ----------------*/

            case 1:

                printf("\nEnter Charging Current (A): ");
                scanf("%f", &current);

                printf("Enter Charging Time (Hours): ");
                scanf("%f", &hours);

                Battery_Charge(&battery, current, hours);

                break;

            /*-------------- Discharge Battery ---------------*/

            case 2:

                printf("\nEnter Discharge Current (A): ");
                scanf("%f", &current);

                printf("Enter Discharge Time (Hours): ");
                scanf("%f", &hours);

                Battery_Discharge(&battery, current, hours);

                break;

            /*-------------- Display Battery -----------------*/

            case 3:

                Battery_Display(&battery);

                break;

            /*---------------- Exit Program ------------------*/

            case 4:

                printf("\nThank you for using the EV Battery Management System.\n");
                printf("Exiting Program...\n");

                return 0;

            /*-------------- Invalid Choice ------------------*/

            default:

                printf("\nInvalid Choice! Please enter a value between 1 and 4.\n");
        }
    }

    return 0;
}