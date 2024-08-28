function toggleMenu() {
    let menu = document.getElementById("menu");
    switch(menu.classList.contains("active")) {
        case true:
            menu.classList.remove("active");
            break;
        default:
            menu.classList.add("active");
    }
}
