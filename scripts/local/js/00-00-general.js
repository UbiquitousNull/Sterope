function cLog(...a) {
    console.log(...a);
}


function toggleActive(elementId) {
    cLog("%s : ToggleID", elementId);
    document.getElementById(elementId).classList.toggle("active");
}
