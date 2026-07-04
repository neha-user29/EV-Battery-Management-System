/******************************************************************************
 * Project      : Battery Management System (BMS) Simulation
 * File         : battery.c
 * Author       : Neha
 * Description  :
 * This source file implements the Battery module of the Battery Management
 * System (BMS).
 *
 * Responsibilities:
 *  - Initialize battery parameters
 *  - Simulate charging and discharging
 *  - Update State of Charge (SOC)
 *  - Update State of Health (SOH)
 *  - Monitor battery temperature
 *  - Control the cooling fan through the Thermal Management module
 *  - Display complete battery status
 ******************************************************************************/

#include <stdio.h>
#include "battery.h"

/******************************************************************************
 * Function : Battery_Init()
 *
 * Description:
 * Initializes the battery with default operating parameters and
 * initializes all associated modules (SOC, SOH and Thermal).
 *
 * Parameters:
 *      battery - Pointer to Battery structure
 *
 * Returns:
 *      None
 ******************************************************************************/
void Battery_Init(Battery *battery)
{
    /* Initialize battery electrical parameters */

    battery->voltage = 400.0f;
    battery->current = 0.0f;
    battery->temperature = 25.0f;
    battery->capacity = 50.0f;

    /* Initialize Battery Management Modules */

    SOC_Init(&battery->soc, battery->capacity);

    SOH_Init(&battery->soh);

    Thermal_Init(&battery->thermal);
}


/******************************************************************************
 * Function : Battery_Charge()
 *
 * Description:
 * Simulates battery charging.
 *
 * Operations performed:
 *      1. Update charging current
 *      2. Increase battery temperature
 *      3. Update State of Charge (SOC)
 *      4. Update State of Health (SOH)
 *      5. Update Thermal Management
 *
 * Parameters:
 *      battery - Pointer to Battery structure
 *      current - Charging current (A)
 *      hours   - Charging duration (Hours)
 *
 * Returns:
 *      None
 ******************************************************************************/
void Battery_Charge(Battery *battery, float current, float hours)
{
    /* Charging current is represented as negative */

    battery->current = -current;

    /* Simulate temperature rise during charging */

    battery->temperature += current * 0.03f * hours;

    /* Update Battery State of Charge */

    SOC_Charge(&battery->soc, current, hours);

    /* Update Battery State of Health */

    SOH_Update(&battery->soh);

    /* Update Cooling Fan Status */

    Thermal_Update(&battery->thermal, battery->temperature);

    printf("\nBattery Charging...\n");
}


/******************************************************************************
 * Function : Battery_Discharge()
 *
 * Description:
 * Simulates battery discharging.
 *
 * Operations performed:
 *      1. Update discharge current
 *      2. Increase battery temperature
 *      3. Update State of Charge (SOC)
 *      4. Update Thermal Management
 *
 * Parameters:
 *      battery - Pointer to Battery structure
 *      current - Discharging current (A)
 *      hours   - Discharging duration (Hours)
 *
 * Returns:
 *      None
 ******************************************************************************/
void Battery_Discharge(Battery *battery, float current, float hours)
{
    /* Positive current indicates battery discharge */

    battery->current = current;

    /* Simulate temperature rise during discharge */

    battery->temperature += current * 0.05f * hours;

    /* Update Battery State of Charge */

    SOC_Discharge(&battery->soc, current, hours);

    /* Update Cooling Fan Status */

    Thermal_Update(&battery->thermal, battery->temperature);

    printf("\nBattery Discharging...\n");
}


/******************************************************************************
 * Function : Battery_Display()
 *
 * Description:
 * Displays the complete battery status including:
 *
 *      - Voltage
 *      - Current
 *      - State of Charge (SOC)
 *      - State of Health (SOH)
 *      - Temperature
 *      - Cooling Fan Status
 *      - Battery Capacity
 *
 * If the battery temperature exceeds the safety limit,
 * a warning message is displayed.
 *
 * Parameters:
 *      battery - Pointer to Battery structure
 *
 * Returns:
 *      None
 ******************************************************************************/
void Battery_Display(const Battery *battery)
{
    printf("\n=========================================\n");
    printf("          BATTERY STATUS\n");
    printf("=========================================\n");

    printf("Voltage        : %.2f V\n", battery->voltage);

    printf("Current        : %.2f A\n", battery->current);

    /* Display Battery State of Charge */

    SOC_Display(&battery->soc);

    /* Display Battery State of Health */

    SOH_Display(&battery->soh);

    /* Display Battery Temperature */

    printf("Temperature    : %.2f C\n", battery->temperature);

    /* Display Cooling Fan Status */

    Thermal_Display(&battery->thermal);

    /* Display warning if battery temperature exceeds safe limit */

    if (battery->temperature >= 50.0f)
    {
        printf("Warning        : HIGH TEMPERATURE!\n");
    }

    /* Display Battery Capacity */

    printf("Capacity       : %.2f Ah\n", battery->capacity);

    printf("=========================================\n");
}