/** 
    @file 
    @brief Header file for the EPS Application Message IDs. Message IDs are implemented 
           with the following range:
                Command base   = 0x1800   (messages telling an app to act)
                Telemetry base = 0x0800   (messages reporting app state)

                EPS_APP uses topic ID 0xCA/0xCB, verified unused across all apps and
                the cosmos plugin (gap 0xCA-0xF9 between the CS/app cluster and SBN).
*/

# ifndef EPS_APP_MSGIDS_H
# define EPS_APP_MSGIDS_H

# define EPS_APP_CMD_MID        0x18CA
# define EPS_APP_SEND_HK_MID    0x18CB
# define EPS_APP_HK_TLM_MID     0x08CA

# endif /* EPS_APP_MSGIDS_H */
