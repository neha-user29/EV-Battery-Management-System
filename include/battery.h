/******************************************************************************
 * Project      : Battery Management System (BMS) Simulation
 * File         : battery.h
 * Author       : Neha
 * Description  :
 * This header file defines the Battery structure and the functions used to
 * initialize, charge, discharge, and display the battery status.
 *
 * The Battery structure combines:
 *  - Battery electrical parameters
 *  - State of Charge (SOC)
 *  - State of Health (SOH)
 *  - Thermal Management
 *
 * This modular design is similar to the architecture followed in embedded
 * Battery Management Systems (BMS) used in Electric Vehicles.
 ******************************************************************************/

#ifndef BATTERY_H
#define BATTERY_H

/* Include required module headers */

#include "soc.h"
#include "soh.h"
#include "thermal.h"

/******************************************************************************
 * Battery Structure
 *
 * Stores all battery-related information required by the Battery Management
 * System.
 ******************************************************************************/

typedef struct
{
    /* Battery Nominal Voltage (Volts) */
    float voltage;

    /* Battery Current (Amperes)
       Positive  -> Discharging
       Negative  -> Charging */
    float current;

    /* Battery Temperature (Degree Celsius) */
    float temperature;

    /* Battery Capacity (Ampere-hour) */
    float capacity;

    /* State of Charge Module */
    SOC soc;

    /* State of Health Module */
    SOH soh;

    /* Thermal Management Module */
    Thermal thermal;

} Battery;


/******************************************************************************
 * Function : Battery_Init()
 *
 * Description:
 * Initializes all battery parameters with default values and initializes
 * SOC, SOH and Thermal modules.
 *
 * Parameters:
 *      battery - Pointer to Battery structure
 *
 * Returns:
 *      None
 ******************************************************************************/
void Battery_Init(Battery *battery);


/******************************************************************************
 * Function : Battery_Charge()
 *
 * Description:
 * Simulates battery charging.
 * Updates:
 *      - Charging Current
 *      - Battery Temperature
 *      - State of Charge (SOC)
 *      - State of Health (SOH)
 *      - Thermal Management
 *
 * Parameters:
 *      battery - Pointer to Battery structure
 *      current - Charging current (A)
 *      hours   - Charging duration (Hours)
 *
 * Returns:
 *      None
 ******************************************************************************/
void Battery_Charge(Battery *battery, float current, float hours);


/******************************************************************************
 * Function : Battery_Discharge()
 *
 * Description:
 * Simulates battery discharging.
 * Updates:
 *      - Discharging Current
 *      - Battery Temperature
 *      - State of Charge (SOC)
 *      - Thermal Management
 *
 * Parameters:
 *      battery - Pointer to Battery structure
 *      current - Discharging current (A)
 *      hours   - Discharging duration (Hours)
 *
 * Returns:
 *      None
 ******************************************************************************/
void Battery_Discharge(Battery *battery, float current, float hours);


/******************************************************************************
 * Function : Battery_Display()
 *
 * Description:
 * Displays the complete battery status including:
 *      - Voltage
 *      - Current
 *      - State of Charge (SOC)
 *      - State of Health (SOH)
 *      - Temperature
 *      - Cooling Fan Status
 *      - Capacity
 *
 * Parameters:
 *      battery - Pointer to Battery structure
 *
 * Returns:
 *      None
 ******************************************************************************/
void Battery_Display(const Battery *battery);

#endif /* BATTERY_H */