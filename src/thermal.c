/******************************************************************************
 * Project      : Battery Management System (BMS) Simulation
 * File         : thermal.c
 * Author       : Neha
 * Description  :
 * This source file implements the Thermal Management module of the
 * Battery Management System (BMS).
 *
 * The module continuously monitors the battery temperature and controls
 * the cooling fan to maintain a safe operating temperature.
 *
 * Cooling Strategy:
 *      - Cooling Fan ON  : Temperature >= 40°C
 *      - Cooling Fan OFF : Temperature <= 35°C
 *
 * This simple hysteresis prevents frequent ON/OFF switching of the fan.
 ******************************************************************************/

#include <stdio.h>
#include "thermal.h"

/******************************************************************************
 * Function : Thermal_Init()
 *
 * Description:
 * Initializes the Thermal Management module by turning the cooling fan OFF.
 *
 * Parameters:
 *      thermal - Pointer to Thermal structure
 *
 * Returns:
 *      None
 ******************************************************************************/
void Thermal_Init(Thermal *thermal)
{
    /* Cooling fan is OFF during initialization */

    thermal->coolingFan = 0;
}


/******************************************************************************
 * Function : Thermal_Update()
 *
 * Description:
 * Monitors the battery temperature and updates the cooling fan status.
 *
 * Logic:
 *      - Turn ON the cooling fan when temperature reaches or exceeds 40°C.
 *      - Turn OFF the cooling fan when temperature falls to 35°C or below.
 *
 * Using two different thresholds (40°C and 35°C) creates hysteresis,
 * reducing unnecessary fan switching.
 *
 * Parameters:
 *      thermal     - Pointer to Thermal structure
 *      temperature - Current battery temperature (°C)
 *
 * Returns:
 *      None
 ******************************************************************************/
void Thermal_Update(Thermal *thermal, float temperature)
{
    /* Turn ON cooling fan */

    if (temperature >= 40.0f)
    {
        thermal->coolingFan = 1;
    }

    /* Turn OFF cooling fan */

    if (temperature <= 35.0f)
    {
        thermal->coolingFan = 0;
    }
}


/******************************************************************************
 * Function : Thermal_Display()
 *
 * Description:
 * Displays the current status of the battery cooling fan.
 *
 * Parameters:
 *      thermal - Pointer to Thermal structure
 *
 * Returns:
 *      None
 ******************************************************************************/
void Thermal_Display(const Thermal *thermal)
{
    if (thermal->coolingFan)
    {
        printf("Cooling Fan    : ON\n");
    }
    else
    {
        printf("Cooling Fan    : OFF\n");
    }
}