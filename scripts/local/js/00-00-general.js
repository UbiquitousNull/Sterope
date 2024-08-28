function cLog(...a) {
    console.log(...a);
}


function toggleActive(elementId) {
    cLog("ToggleID: ", elementId);
    document.getElementById(elementId).classList.toggle("active");
}
