/******************************************************************************
 * Project      : Battery Management System (BMS) Simulation
 * File         : soh.c
 * Author       : Neha
 * Description  :
 * This source file implements the State of Health (SOH) module.
 *
 * The SOH module simulates battery aging by reducing the battery's
 * health after each charging cycle. It also keeps track of the total
 * number of charge cycles completed.
 *
 * Note:
 * This is a simplified SOH estimation model intended for educational
 * purposes. Real EV Battery Management Systems estimate SOH using
 * battery capacity fade, internal resistance measurements, temperature,
 * and advanced estimation algorithms.
 ******************************************************************************/

#include <stdio.h>
#include "soh.h"

/******************************************************************************
 * Function : SOH_Init()
 *
 * Description:
 * Initializes the State of Health module.
 * Sets the initial battery health to 100% and resets the charge
 * cycle counter.
 *
 * Parameters:
 *      soh - Pointer to SOH structure
 *
 * Returns:
 *      None
 ******************************************************************************/
void SOH_Init(SOH *soh)
{
    /* Initialize battery health */

    soh->soh = 100.0f;

    /* Reset charging cycle count */

    soh->cycles = 0;
}


/******************************************************************************
 * Function : SOH_Update()
 *
 * Description:
 * Simulates battery degradation by incrementing the charge cycle count
 * and reducing the State of Health after each charging cycle.
 *
 * In this simulation:
 *      - One charging operation represents one charge cycle.
 *      - Battery health decreases by 0.05% per cycle.
 *      - Minimum SOH is limited to 70%.
 *
 * Parameters:
 *      soh - Pointer to SOH structure
 *
 * Returns:
 *      None
 ******************************************************************************/
void SOH_Update(SOH *soh)
{
    /* Increment battery charge cycle */

    soh->cycles++;

    /* Simulate battery aging */

    soh->soh -= 0.05f;

    /* Prevent SOH from dropping below the minimum threshold */

    if (soh->soh < 70.0f)
    {
        soh->soh = 70.0f;
    }
}


/******************************************************************************
 * Function : SOH_Display()
 *
 * Description:
 * Displays the current battery State of Health and total charge cycles.
 *
 * Parameters:
 *      soh - Pointer to SOH structure
 *
 * Returns:
 *      None
 ******************************************************************************/
void SOH_Display(const SOH *soh)
{
    printf("SOH            : %.2f %%\n", soh->soh);
    printf("Charge Cycles  : %d\n", soh->cycles);
}