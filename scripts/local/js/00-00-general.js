function toggleMenu() {
    let menuElement = document.getElementById("menu");
    
    switch(status) {
        case "menuClosed":
            menuElement.classList.add("active");
            break;
        default:
            menuElement.classList.remove("active");
    }
}
