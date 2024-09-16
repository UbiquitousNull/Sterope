/** 
 *  No1 most useless wrapper lol.
 */

/**
 * Different types of console logging methods available.
 * @type {string}
 */
const log = "log";

/**
 * Represents the `info` console logging method.
 * @type {string}
 */
const info = "info";

/**
 * Represents the `warn' console logging method.
 * @type {string}
 */
const warn = "warn";

/**
 * Represents the 'error' console logging method.
 * @type {string}
 */
const error = "error";

/**
 * Represents the 'debug' console logging method.
 * @type {string}
 */
const debug = "debug";

/**
 * @typedef {string} logtype
 * @description A type of console method. Must be one of the following values:
 * - `'log'` for standard log messages.
 * - `'info'` for informational messages.
 * - `'warn'` for warnings.
 * - `'error'` for error messages.
 * - `'debug'` for debug messages.
 */
export { log, info, warn, error, debug };

/**
 * Logs a message to the console using the specified console method.
 * 
 * @param {(logtype | string)} logType - The type of console method to use.
 * This should be one of the following string values:
 * - `'log'` for standard log messages.
 * - `'info'` for informational messages.
 * - `'warn'` for warnings.
 * - `'error'` for error messages.
 * - `'debug'` for debug messages.
 * @param {...any} message - The message(s) to log. Accepts one or more arguments of any type.
 *
 * @returns {void}
 *
 * @example 
 * cLog(info, 'This is an info message');
 * // Logs an information message
 * 
 * @example 
 * cLog(warn, 'Warning:', someVariable, 'Check the value');
 * // Logs a warning with logType variable and multiple arguments
 * 
 * @example 
 * cLog("warn", `Warning: ${someVariable}, Check the value`);
 * // logs a warning using a string literal for logType with backtick syntax message argument
 *
 * @example 
 * cLog('invalidMethod', 'This method does not exist');
 * // Handles an invalid console method
 */
export function cLog(logType, ...message) {
    if (typeof console[logType] !== "function") {
        console.groupCollapsed(
            `%cInvalid console method: %c${logType}%c (Expand for details)`,
            "color: inherit;", "color: red; font-weight: bold;", "color: inherit;"
        );
        console.error(
            `%cInvalid console method: %c${logType}%c\nContents: `,
            "color: inherit;", "color: red; font-weight: bold;", "color: inherit;",
            ...message, `Please use a valid ${logType}`
        );
        console.groupEnd();
        return;
    }
    console[logType](...message);
}
