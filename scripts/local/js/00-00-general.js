function cLog(...a) {
    console.log(...a);
}


function toggleActive(elementId) {
    cLog("ToggleID: %s", elementId);
    document.getElementById(elementId).classList.toggle("active");
}
