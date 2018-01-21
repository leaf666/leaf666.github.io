// JavaScript Document
var lneed = document.getElementById("level").innerHTML;
var attempt = 0;
lneed = Number(lneed);
if (lneed > 0){kon();}
function kon() {
	"use strict";
	document.getElementById("karticle").style.display = "none";
	var fpanel = document.getElementsByClassName("panel-body")[0];
	var panel = document.createElement("div");
	fpanel.appendChild(panel);
	panel.setAttribute("id", "kpass");
	var plead = document.createElement("p");
	var input = document.createElement("input");
	var padd = document.createElement("div");
	var button = document.createElement("button");
	panel.appendChild(plead);
	plead.setAttribute("class", "text-center");
	plead.innerHTML = "本帖子需要" + lneed + "级及以上权限<br>请验证您的身份";
	panel.appendChild(input);
	input.setAttribute("id", "pword");
	input.setAttribute("class", "form-control text-center center-block");
	input.setAttribute("type", "password");
	input.setAttribute("style", "max-width: 360px");
	input.setAttribute("placeholder", "请输入" + lneed + "级及以上密码");
	panel.appendChild(padd);
	padd.setAttribute("id", "add");
	padd.setAttribute("style", "max-width: 360px");
	panel.appendChild(button);
	button.setAttribute("class", "btn btn-primary center-block");
	button.innerHTML = "确认";
	button.setAttribute("onClick", "kact()");
}

function kact() {
	"use strict";
	var x = Number(document.getElementById("pword").value);
	var lread = 0;
	var l1 = Number("1666");
	var l2 = Number("1621");
	var l3 = Number("886686");
	if (x === l1) {lread = 1;}
	if (x === l2) {lread = 2;}
	if (x === l3) {lread = 3;}
	if (lread === 0) {
		var y = document.getElementById("add");
		y.setAttribute("class", "alert alert-danger alert-dismissable center-block");
		if (attempt === 0) {
			y.innerHTML = "猜的好，现在请输入正确密码。";
			attempt++;
		} else {y.innerHTML = y.innerHTML + "<br>" + "猜的好，现在请输入正确密码。";}
		re();
	}
	if (lread !== 0 && lread < lneed) {
		var y = document.getElementById("add");
		y.setAttribute("class", "alert alert-danger alert-dismissable center-block");
		y.innerHTML = "你的权限不足，本贴需要" + lneed + "级及以上权限。";
		re();
	}
	if (lread >= lneed) {
		var y = document.getElementById("add");
		y.setAttribute("class", "alert alert-success alert-dismissable center-block");
		y.innerHTML = "密码正确，欢迎！";
		window.setTimeout(ok, 800);
	}

}

function re() {
	"use strict";
	document.getElementById("pword").value = "";
}

function ok() {
	"use strict";
	document.getElementById("karticle").style.display = "block";
	document.getElementById("kpass").style.display = "none";
}
