var doc = document

function findPosX(obj) {
	var curleft = 0;
	if (obj.offsetParent) {
		do {
			curleft += obj.offsetLeft;
			// @disable-check M19
		} while (obj = obj.offsetParent);
	return curleft;
	}
}

function findPosY(obj) {
	var curtop = 0;
	if (obj.offsetParent) {
		do {
			curtop += obj.offsetTop;
			// @disable-check M19
		} while (obj = obj.offsetParent);
	return curtop;
	}
}

// This function is necessary for click function, we cannot click if the element is not visible
function scrollTo (obj) {
	window.scroll(
				findPosX(obj) - window.innerWidth / 2 + obj.innerWidth / 2,
				findPosY(obj) - window.innerHeight / 2 + obj.innerHeight / 2);
}

// Wait for dynamically content
//function wait_for (selector, needed, seconds) {
//	var times = 0;
//	var count = 0;
//	var last_count = 0;
//	while (count < needed && times < seconds) {
//		count = document.querySelectorAll(selector).length;
//		if (last_count == count)
//			times++;
//		else
//			times = 0;
//		console.log(times, last_count, count);
//		var time = new Date().getTime() + 1000;
//		while(new Date().getTime() < time);
//		last_count = count;
//	}
//	if (times >= seconds)
//		return false;
//	else
//		return true;
//}
