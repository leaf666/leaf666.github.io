if(document.getElementById("level"))
{
	var knle=document.getElementById("level").innerHTML;
	var kcle=level(getCookie("pw"));
	if(kcle >= knle)
		{
			var i=0;
			while(document.getElementsByTagName("article")[i])
				{
					document.getElementsByTagName("article")[i].style.display = "block";
					++i;
				}
		}
	else
		{
			window.location.replace("login.html?"+knle);
		}
}
function getCookie(c_name)
{
	if (document.cookie.length>0)
  	{
  		var c_start=document.cookie.indexOf(c_name + "=")
  		if (c_start!=-1)
  			{ 
					c_start=c_start + c_name.length+1 
    			c_end=document.cookie.indexOf(";",c_start)
    			if (c_end==-1) c_end=document.cookie.length
					return unescape(document.cookie.substring(c_start,c_end))
				}
		}
	return 0;
}
function level(pw)
{
	var le1=213*1000000+800*1000+613;
	le1 = le1*2;
	var le2=392*1000000+555*1000+396;
	le2 = le2*2;
	if(pw === le1)return 1;
	else if(pw === le2)return 2;
	else return 0;
}
function unk(a)
{
	a=(a*a)%1000000007;
	a=(a*a)%1000000007;
	a=(a*a)%1000000007;
	a=(a*a)%1000000007;
	return a;
}