/******************************************************************************
 * Project      : Battery Management System (BMS) Simulation
 * File         : soc.c
 * Author       : Neha
 * Description  :
 * This source file implements the State of Charge (SOC) module.
 *
 * The SOC module estimates the remaining battery charge using the
 * Coulomb Counting method. During charging and discharging, the SOC
 * value is updated based on battery current, charging/discharging time,
 * and battery capacity.
 ******************************************************************************/

#include <stdio.h>
#include "soc.h"

/******************************************************************************
 * Function : SOC_Init()
 *
 * Description:
 * Initializes the State of Charge module.
 * Sets the battery to a fully charged state (100%) and stores the
 * battery capacity for future SOC calculations.
 *
 * Parameters:
 *      soc      - Pointer to SOC structure
 *      capacity - Battery Capacity (Ah)
 *
 * Returns:
 *      None
 ******************************************************************************/
void SOC_Init(SOC *soc, float capacity)
{
    soc->soc = 100.0f;
    soc->capacity = capacity;
}


/******************************************************************************
 * Function : SOC_Charge()
 *
 * Description:
 * Updates the battery State of Charge during charging using the
 * Coulomb Counting method.
 *
 * Formula:
 *      SOC Change (%) =
 *      (Current × Time / Battery Capacity) × 100
 *
 * The SOC value is limited to a maximum of 100%.
 *
 * Parameters:
 *      soc     - Pointer to SOC structure
 *      current - Charging Current (A)
 *      hours   - Charging Duration (Hours)
 *
 * Returns:
 *      None
 ******************************************************************************/
void SOC_Charge(SOC *soc, float current, float hours)
{
    float change;

    /* Calculate SOC increase */

    change = (current * hours / soc->capacity) * 100.0f;

    /* Update SOC */

    soc->soc += change;

    /* Prevent SOC from exceeding 100% */

    if (soc->soc > 100.0f)
    {
        soc->soc = 100.0f;
    }
}


/******************************************************************************
 * Function : SOC_Discharge()
 *
 * Description:
 * Updates the battery State of Charge during discharging using the
 * Coulomb Counting method.
 *
 * Formula:
 *      SOC Change (%) =
 *      (Current × Time / Battery Capacity) × 100
 *
 * The SOC value is limited to a minimum of 0%.
 *
 * Parameters:
 *      soc     - Pointer to SOC structure
 *      current - Discharging Current (A)
 *      hours   - Discharging Duration (Hours)
 *
 * Returns:
 *      None
 ******************************************************************************/
void SOC_Discharge(SOC *soc, float current, float hours)
{
    float change;

    /* Calculate SOC decrease */

    change = (current * hours / soc->capacity) * 100.0f;

    /* Update SOC */

    soc->soc -= change;

    /* Prevent SOC from dropping below 0% */

    if (soc->soc < 0.0f)
    {
        soc->soc = 0.0f;
    }
}


/******************************************************************************
 * Function : SOC_Display()
 *
 * Description:
 * Displays the current State of Charge (SOC) of the battery.
 *
 * Parameters:
 *      soc - Pointer to SOC structure
 *
 * Returns:
 *      None
 ******************************************************************************/
void SOC_Display(const SOC *soc)
{
    printf("SOC            : %.2f %%\n", soc->soc);
}