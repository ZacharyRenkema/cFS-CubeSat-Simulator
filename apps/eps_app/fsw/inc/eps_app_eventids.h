/**
 * @file
 *
 * Define EPS App Events IDs
 */
#ifndef EPS_APP_EVENTS_H
#define EPS_APP_EVENTS_H

#define EPS_APP_RESERVED_EID    0  /**< \brief Reserved, not used */
#define EPS_APP_INIT_INF_EID    1  /**< \brief App initialized (informational) */
#define EPS_APP_CC_ERR_EID      2  /**< \brief Invalid command code (error) */
#define EPS_APP_NOOP_INF_EID    3  /**< \brief NOOP command received (informational) */
#define EPS_APP_RESET_INF_EID   4  /**< \brief Reset counters command received (informational) */
#define EPS_APP_MID_ERR_EID     5  /**< \brief Unexpected message ID on pipe (error) */
#define EPS_APP_CMD_LEN_ERR_EID 6  /**< \brief Command with invalid length (error) */
#define EPS_APP_PIPE_ERR_EID    7  /**< \brief SB pipe read error in main loop (error) */
#define EPS_APP_CR_PIPE_ERR_EID 8  /**< \brief Error creating SB command pipe (error) */
#define EPS_APP_SUB_HK_ERR_EID  9  /**< \brief Error subscribing to SEND_HK (error) */
#define EPS_APP_SUB_CMD_ERR_EID 10 /**< \brief Error subscribing to commands (error) */

#endif /* EPS_APP_EVENTS_H */