/*
 * Copyright (C) 2014 Glyptodon LLC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _GUAC_CLIENT_TYPES_H
#define _GUAC_CLIENT_TYPES_H

/**
 * Type definitions related to the Guacamole client structure, guac_client.
 *
 * @file client-types.h
 */

/**
 * Guacamole proxy client.
 *
 * Represents a Guacamole proxy client (the client which communicates to
 * a server on behalf of Guacamole, on behalf of the web-client).
 */
typedef struct guac_client guac_client;

/**
 * Possible current states of the Guacamole client. Currently, the only
 * two states are GUAC_CLIENT_RUNNING and GUAC_CLIENT_STOPPING.
 */
typedef enum guac_client_state {

    /**
     * The state of the client from when it has been allocated by the main
     * daemon until it is killed or disconnected.
     */
    GUAC_CLIENT_RUNNING,

    /**
     * The state of the client when a stop has been requested, signalling the
     * I/O threads to shutdown.
     */
    GUAC_CLIENT_STOPPING

} guac_client_state;

/**
 * All supported log levels used by the logging subsystem of each Guacamole
 * client. These log levels correspond to the log levels defined by RFC 5424.
 */
typedef enum guac_client_log_level {

    /**
     * Emergencies which render the system unusable.
     */
    GUAC_LOG_EMERGENCY = 0,

    /**
     * The system may be usable, but the current state is dangerous enough that
     * action must be taken immediately.
     */
    GUAC_LOG_ALERT = 1,

    /**
     * Critically-important messages.
     */
    GUAC_LOG_CRITICAL = 2,

    /**
     * General errors: important, but not necessarily critically so.
     */
    GUAC_LOG_ERROR = 3,

    /**
     * Non-fatal conditions that are likely unintentional.
     */
    GUAC_LOG_WARNING = 4,

    /**
     * Significant but normal conditions.
     */
    GUAC_LOG_NOTICE = 5,

    /**
     * Normal conditions that may be interesting but in most cases should be
     * ignored.
     */
    GUAC_LOG_INFO = 6,

    /**
     * Informational messages that are too frequent or too detailed for a more
     * severe log level, but can be useful for debugging.
     */
    GUAC_LOG_DEBUG = 7

} guac_client_log_level;

/**
 * Information exposed by the remote client during the connection handshake
 * which can be used by a client plugin.
 */
typedef struct guac_client_info guac_client_info;

#endif

