import { 
    log, 
    info, 
    warn, 
    error, 
    debug, 
    cLog 
} from './00-00-logging.js';

function toggleActive(elementId) {
    try {
        const element = document.getElementById(elementId);
        if (!element) {
            throw new Error(`Element with ID "${elementId}" not found.`);
        }
        const result = element.classList.toggle("active");
        cLog(log, `The active class was ${result ? "added to" : "removed from"} element with ID: ${elementId}`);
    } catch (err) {
        cLog(error, `Error toggling active class on element with ID: ${elementId}`, err.message);
    }
}