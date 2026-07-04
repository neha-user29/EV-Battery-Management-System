/******************************************************************************
 * Project      : Battery Management System (BMS) Simulation
 * File         : soh.h
 * Author       : Neha
 * Description  :
 * This header file defines the State of Health (SOH) module.
 *
 * The SOH module estimates the overall health of the battery by
 * tracking charge cycles and simulating battery aging. It provides
 * functions to initialize, update, and display the battery's
 * State of Health.
 ******************************************************************************/

#ifndef SOH_H
#define SOH_H

/******************************************************************************
 * SOH Structure
 *
 * Stores the battery health information.
 ******************************************************************************/

typedef struct
{
    /* State of Health (%) */
    float soh;

    /* Number of completed charging cycles */
    int cycles;

} SOH;


/******************************************************************************
 * Function : SOH_Init()
 *
 * Description:
 * Initializes the State of Health module.
 * Sets the initial SOH to 100% and resets the charge cycle count.
 *
 * Parameters:
 *      soh - Pointer to SOH structure
 *
 * Returns:
 *      None
 ******************************************************************************/
void SOH_Init(SOH *soh);


/******************************************************************************
 * Function : SOH_Update()
 *
 * Description:
 * Simulates battery aging by reducing the State of Health after
 * each charging cycle and increments the cycle count.
 *
 * Parameters:
 *      soh - Pointer to SOH structure
 *
 * Returns:
 *      None
 ******************************************************************************/
void SOH_Update(SOH *soh);


/******************************************************************************
 * Function : SOH_Display()
 *
 * Description:
 * Displays the current State of Health and the total number of
 * charging cycles completed.
 *
 * Parameters:
 *      soh - Pointer to SOH structure
 *
 * Returns:
 *      None
 ******************************************************************************/
void SOH_Display(const SOH *soh);

#endif /* SOH_H */