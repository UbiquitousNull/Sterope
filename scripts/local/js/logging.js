const log = "log";
const info = "info";
const warn = "warn";
const error = "error";
const debug = "debug";
export { log, info, warn, error, debug };

/**
 * Logs messages to the console using a specified console method.
 * 
 * @param {string} logType - The type of console log method to use (e.g., "log", "warn", "error").
 * @param {...any} message - The messages or objects to log to the console.
 * 
 * @example
 * // Using a valid logType:
 * cLog("log", "This is a standard log message.");
 * 
 * // Using an invalid logType:
 * cLog("invalidLogType", "This will trigger an error message.");
 * 
 * @throws {Error} If an invalid `logType` is provided, it logs an error message with details.
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
            ...message
        );
        console.groupEnd();
        return;
    }
    console[logType](...message);
}