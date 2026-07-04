/******************************************************************************
 * Project      : Battery Management System (BMS) Simulation
 * File         : thermal.h
 * Author       : Neha
 * Description  :
 * This header file defines the Thermal Management module of the
 * Battery Management System (BMS).
 *
 * The Thermal Management module continuously monitors the battery
 * temperature and controls the cooling fan to maintain the battery
 * within a safe operating temperature range.
 ******************************************************************************/

#ifndef THERMAL_H
#define THERMAL_H

/******************************************************************************
 * Thermal Structure
 *
 * Stores the current status of the battery cooling system.
 ******************************************************************************/

typedef struct
{
    /* Cooling Fan Status
       0 -> OFF
       1 -> ON
    */
    int coolingFan;

} Thermal;


/******************************************************************************
 * Function : Thermal_Init()
 *
 * Description:
 * Initializes the Thermal Management module.
 * The cooling fan is initially set to OFF.
 *
 * Parameters:
 *      thermal - Pointer to Thermal structure
 *
 * Returns:
 *      None
 ******************************************************************************/
void Thermal_Init(Thermal *thermal);


/******************************************************************************
 * Function : Thermal_Update()
 *
 * Description:
 * Monitors the battery temperature and updates the cooling fan status.
 * The cooling fan is turned ON when the battery temperature exceeds
 * the predefined threshold and turned OFF when the temperature returns
 * to a safe operating range.
 *
 * Parameters:
 *      thermal     - Pointer to Thermal structure
 *      temperature - Current battery temperature (°C)
 *
 * Returns:
 *      None
 ******************************************************************************/
void Thermal_Update(Thermal *thermal, float temperature);


/******************************************************************************
 * Function : Thermal_Display()
 *
 * Description:
 * Displays the current status of the cooling fan.
 *
 * Parameters:
 *      thermal - Pointer to Thermal structure
 *
 * Returns:
 *      None
 ******************************************************************************/
void Thermal_Display(const Thermal *thermal);

#endif /* THERMAL_H */