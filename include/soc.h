/******************************************************************************
 * Project      : Battery Management System (BMS) Simulation
 * File         : soc.h
 * Author       : Neha
 * Description  :
 * This header file defines the State of Charge (SOC) module.
 *
 * The SOC module estimates the available battery charge using the
 * Coulomb Counting method. It provides functions to initialize,
 * update, and display the battery's State of Charge during charging
 * and discharging operations.
 ******************************************************************************/

#ifndef SOC_H
#define SOC_H

/******************************************************************************
 * SOC Structure
 *
 * Stores the battery State of Charge information.
 ******************************************************************************/

typedef struct
{
    /* State of Charge (%) */
    float soc;

    /* Battery Capacity (Ampere-hour) */
    float capacity;

} SOC;


/******************************************************************************
 * Function : SOC_Init()
 *
 * Description:
 * Initializes the State of Charge module.
 * Sets the initial SOC to 100% and stores the battery capacity.
 *
 * Parameters:
 *      soc      - Pointer to SOC structure
 *      capacity - Battery capacity (Ah)
 *
 * Returns:
 *      None
 ******************************************************************************/
void SOC_Init(SOC *soc, float capacity);


/******************************************************************************
 * Function : SOC_Charge()
 *
 * Description:
 * Updates the battery State of Charge during charging using the
 * Coulomb Counting method.
 *
 * Parameters:
 *      soc     - Pointer to SOC structure
 *      current - Charging current (A)
 *      hours   - Charging duration (Hours)
 *
 * Returns:
 *      None
 ******************************************************************************/
void SOC_Charge(SOC *soc, float current, float hours);


/******************************************************************************
 * Function : SOC_Discharge()
 *
 * Description:
 * Updates the battery State of Charge during discharging using the
 * Coulomb Counting method.
 *
 * Parameters:
 *      soc     - Pointer to SOC structure
 *      current - Discharging current (A)
 *      hours   - Discharging duration (Hours)
 *
 * Returns:
 *      None
 ******************************************************************************/
void SOC_Discharge(SOC *soc, float current, float hours);


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
void SOC_Display(const SOC *soc);

#endif /* SOC_H */