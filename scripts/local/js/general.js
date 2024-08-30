import { 
    log, 
    info, 
    warn, 
    error, 
    debug, 
    cLog 
} from './logging.js';

function toggleActive(elementId) {
    try {
        const element = document.getElementById(elementId);
        if (!element) { throw new Error(`Element with ID "${elementId}" not found.`); }

        const result = element.classList.toggle("active");
        cLog(log, `The active class was ${result ? "added to" : "removed from"} element with ID: ${elementId}`);
        element.style.transform = "translateX(100vw)";

    } catch (err) { cLog(error, `Error toggling active class on element with ID: ${elementId}`, err.message); }
}

document.querySelectorAll('[toggleId]').forEach(element => {
    element.addEventListener('click', (event) => {
        toggleActive(event.target.getAttribute('toggleId'));
    });
});