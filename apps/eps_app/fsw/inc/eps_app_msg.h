/**
 * @file
 *   Specification for the EPS_APP command and telemetry message data types.
 */
#ifndef EPS_APP_MSG_H
#define EPS_APP_MSG_H

#include "cfe_msg_hdr.h"
#include "eps_app_msgids.h"

/*
** Command structs - header only 
*/
typedef struct
{
    CFE_MSG_CommandHeader_t CommandHeader;
} EPS_APP_NoopCmd_t;

typedef struct
{
    CFE_MSG_CommandHeader_t CommandHeader;
} EPS_APP_ResetCountersCmd_t;

typedef struct
{
    CFE_MSG_CommandHeader_t CommandHeader;
} EPS_APP_SendHkCmd_t;

/*
** Housekeeping telemetry payload - the actual EPS data
*/
typedef struct
{
    uint8 CommandCounter;       /**< \brief Count of valid commands received */
    uint8 CommandErrorCounter;  /**< \brief Count of invalid commands received */

    float BatteryVoltage;       /**< \brief Simulated battery voltage in volts */
    float BatteryCurrent;       /**< \brief Simulated battery current in amps */
    float StateOfCharge;        /**< \brief Simulated battery state of charge in percent */
    float BatteryTemp;          /**< \brief Simulated battery temperature in degrees Celsius */
} EPS_APP_HkTlm_Payload_t;

/*
** Full housekeeping telemetry packet: header + payload
*/
typedef struct
{
    CFE_MSG_TelemetryHeader_t TelemetryHeader;
    EPS_APP_HkTlm_Payload_t   Payload;
} EPS_APP_HkTlm_t;

#endif /* EPS_APP_MSG_H */