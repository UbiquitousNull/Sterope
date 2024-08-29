const log = "log";
const info = "info";
const warn = "warn";
const error = "error";
const debug = "debug";
export { log, info, warn, error, debug };

export function cLog(b, ...a) {
    if (typeof console[b] !== "function") {
        console.groupCollapsed(
            `%cInvalid console method: %c${b}%c (Expand for details)`,
            "color: inherit;", "color: red; font-weight: bold;", "color: inherit;"
        );
        console.error(
            `%cInvalid console method: %c${b}%c\nContents:`,
            "color: inherit;", "color: red; font-weight: bold;", "color: inherit;",
            ...a
        );
        console.groupEnd();
        return;
    }
    console[b](...a);
}