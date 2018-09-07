// Web NM v. 1.0.0
// 01.04.2014-xx.xx.2014, 13.04.2017-05.2017, 04.05.2018-xx.xx.xxxx

// @disable-check M127
(function (){
	console.error("nm test");

	document.onmousedown = function (ev) {
		console.error(ev.x + " x - y " + ev.y);
	};

	function nm (selector, all) {
		// @disable-check M307
		if (!(this instanceof nm)) return new nm (selector, all);

		if (typeof selector === 'string') {
			var els = !!all ? document.querySelectorAll (selector) : [document.querySelector (selector)];

			for (var i in els) {
				this[i] = els[i];
			}
			this.length = els.length;
		}
		else if (selector instanceof Element) {
			this[0] = selector;
			this.length = 1;
		}
		else if (selector instanceof Array || selector instanceof NodeList) {
			this.length = selector.length;
			
			for (i in selector) {
				if (selector[i] instanceof Element) {
					this[i] = selector[i];
				}
			}
		}
		else {
			// The rest of contructors are despercated
			this.length = 0;
		}

		return this;
	}

	nm.prototype = {
		name: "Web NM",
		version: "1.0.0",
		author: "lixcode",
		constructor: nm,

		add : function (elements) {
			if (!(elements instanceof nm)) {
				elements = nm (elements);
			}

			for (var i = 0; i < elements.length; i++) {
				this[this.length + i] = elements[i];
			}
			this.length += elements.length;

			return this;
		},

		copy : function () {
			var ret = nm();

			for (var i = 0; i < length; i++) {
				ret[i] = this[i];
			}

			return ret;
		},

		collect : function (func, filter) {
			var ret = [];

			for (var i = 0; i < this.length; i++) {
				var res = func.call (this[i], i);

				if (!filter || (ret.indexOf(res) == -1) && !!res) {
					ret.push(res);
				}
			};

			if (ret.length > 1 && !filter) {
				for (i in ret) {
					if (typeof ret[i] !== "string") {
						ret[i] = String(ret[i]);
					}
				}
			}

			return ret.length == 1 ? ret[0] : ret;
		},

		each : function (func) {
			for (var i = 0; i < this.length; i++) {
				func.call (this[i], i);
			};
			return this;
		},

		add_class : function (className){
			return this.each (function () {
				this.classList.add (className);
			});
		},

		has_class : function (className) {
			return this[0].classList.contains (className);
		},

		remove_class : function (className) {
			return this.each (function () {
				this.classList.remove (className);
			});
		},

		switch_class : function (className) {
			return this.each (function () {
				this.classList.toggle (className);
			});
		},

		attr : function (name, value, setMode){
			if (!!setMode){
				return this.each (function (){
					this.setAttribute (name,value);
				});
			}
			else {
				return this.collect(function() {
					return this.getAttribute (name);
				});
			}
		},

		data : function (name,value,setMode){
			if (!!setMode) {
				this.each (function () {
					this.dataset[name] = value;
				});
				return this;
			}
			else {
				return this.collect(function (){
					return this.dataset[name];
				});
			}
		},

		css: function (field, value) {
			if (typeof value === 'string') {
				return this.each (function () {
					this.style[field] = value;
				});
			}
			else {
				return this.collect(function (){
					var style = window.getComputedStyle (this[0]);
					return style[field];
				});
			}
		},

		closest : function (selector){
			return nm(this.collect(function (){
				return this.closest(selector);
			}, true));
		},

		filter : function (selector){
			return nm(this.collect(function (){
				return this.matches (selector) ? this : null;
			}, true));
		},

		filterByContent : function (str, fragment) {
			return !!fragment
					? nm(this.collect(function () {
						return this.innerText.indexOf(str) >= 0
								? this
								: null;
					}, true))
					: nm(this.collect(function () {
						return this.innerText.trim() === str
								? this
								: null;
					}, true));
		},

		next : function () {
			return nm(this.collect(function(){
				return this.nextElementSibling;
			}), true);
		},

		prev : function () {
			return nm(this.collect(function(){
				return this.previousElementSibling;
			}), true);
		},

		parent : function () {
			return nm(this.collect(function(){
				return this.parentNode;
			}), true);
		},

		child : function (i) {
			return nm(this.collect(function(){
				return this.children[i];
			}), true);
		},

		qs : function (selectorString) {
			return nm(this.collect(function (){
				return this.querySelector(selectorString);
			}), true);
		},

		qsAll : function (selectorString) {
			var arr = this.collect(function (){
				return this.querySelectorAll(selectorString);
			});

			var ret = nm();

			for (var i in arr) {
				ret.add(arr[i]);
			}

			return ret;
		},

		get : function (index) {
			return nm(this[index]);
		},

		remove : function (){
			this.each (function (){
				this.parentNode.removeChild (this);
			});
			return nm();
		},

		removeAttr : function (attrName){
			return this.each (function (){
				this.removeAttribute (attrName);
				return this;
			});
		},

		prop : function (name, value, setMode) {
			if (!!setMode) {
				return this.each (function () {
					this[name] = value;
				});
			}
			else {
				return this.collect(function (){
					return this[name];
				});
			}
		},

		html : function (code, setMode) {
			if (!!setMode) {
				return this.each (function () {
					this.innerHTML = code;
				});
			}
			else {
				return this.collect(function (){
					return this.innerHTML;
				});
			}
		},

		text : function (str, setMode) {
			if (!!setMode) {
				return this.each (function () {
					this.innerText = str;
				});
			}
			else {
				return this.collect(function (){
					return this.innerText;
				});
			}
		},

		width: function (number, setMode) {
			if (!!setMode) {
				return this.each (function () {
					this.style.width = number + "px";
				});
			}
			else {
				return this.collect(function (){
					return this.offsetWidth;
				});
			}
		},

		height: function (number, setMode) {
			if (!!setMode) {
				return this.each (function () {
					this.style.height = number + "px";
				});
			}
			else {
				return this.collect(function (){
					return this.offsetHeight;
				});
			}
		},

		x: function (number, setMode) {
			if (!!setMode) {
				return this.each (function () {
					this.style.left = number + "px";
				});
			}
			else {
				return this.collect(function (){
					return this.offsetLeft;
				});
			}
		},

		y: function (number, setMode) {
			if (!!setMode) {
				return this.each (function () {
					this.style.top = number + "px";
				});
			}
			else {
				return this.collect(function (){
					return this.offsetTop;
				});
			}
		},

		visible: function () {
			var rect = this[0].getBoundingClientRect();
			var right = window.innerWidth;
			var bottom = window.innerHeight;

			console.error(rect.top + " " + rect.right + " " + rect.top + " " + rect.left);

			return !(rect.bottom < 0 || rect.top >= bottom ||
					rect.right < 0 || rect.left >= right);
		},

		clickable: function () {
			var point = this.screenPos();

			if (document.elementsFromPoint(point.x, point.y).includes(this[0])) {

				console.error("Element position " + point.x + " " + point.y);
				return point;
			}
			else {
				console.error("Element not clickable " + point.x + " " + point.y);
				return {x:-1, y:-1};
			}
		},

		scrollTo: function () {
			var rect = this[0].getBoundingClientRect();
			var right = window.innerWidth;
			var bottom = window.innerHeight;

			var point = {
				x: (rect.left + rect.right - right) / 2,
				y: (rect.top + rect.bottom - bottom) / 2
			};

			window.scrollTo(point.x, point.y);
		},

		screenPos: function () {
			var rect = this[0].getBoundingClientRect();
			var right = window.innerWidth;
			var bottom = window.innerHeight;

			function point_on_screen(x, y) {
				return x >= 0 && x < right && y >= 0 && y < bottom;
			}

			var point = {
				x: (rect.left + rect.right) / 2,
				y: (rect.top + rect.bottom) / 2
			};

			if (point_on_screen(point.x, point.y)) {
				return point;
			}
			console.error("Wrong point " + point.x + " " + point.y);

			point.x = rect.left + 1;
			point.y = rect.top + 1;

			if (point_on_screen(point.x, point.y)) {
				return point;
			}
			console.error("Wrong point " + point.x + " " + point.y);

			point.x = rect.right - 1;

			if (point_on_screen(point.x, point.y)) {
				return point;
			}
			console.error("Wrong point " + point.x + " " + point.y);

			point.y = rect.bottom - 1;

			if (point_on_screen(point.x, point.y)) {
				return point;
			}
			console.error("Wrong point " + point.x + " " + point.y);

			point.x = rect.left + 1;

			console.error("final point " + point.x + " " + point.y);
			return point;
		},

		clickNow: function () {
			if (!this.visible()) {
				this.scrollTo();
				console.error("Not Visible");
			}

			return this.clickable();
		},

		moveCursorToEnd: function () {
			return this.each(function () {
				this.selectionStart = this.selectionEnd = this.value.length;
			});
		}
	}

	window.nm = nm;
	window.icL = {
		links: [],
		crossfire: {}
	}

	console.error("icL reseted!");

	document.addEventListener("DOMContentLoaded", function(event) {
		console.log("DOM_Ready");
	  });
}());
