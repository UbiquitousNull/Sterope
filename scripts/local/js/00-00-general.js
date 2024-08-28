function toggleMenu()
{
	let status = document.getElementById("menuClosed").innerHTML;
	switch(status)
	{
		case "menuClosed":
			status = "menuOpen";
			break;
		default:
			status = "menuClosed";
	}
	document.getElementById("menuClosed").innerHTML = status;
}