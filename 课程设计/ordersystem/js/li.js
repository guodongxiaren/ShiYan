	var li1=null;
	var li2=null;
	var li3=null;
	window.onload=function(){
		li1=document.getElementById('li1');
		li2=document.getElementById('li2');
		li3=document.getElementById('li3');
		//alert(li1.childNodes[1]);
	}
	function isclick(num){
		switch (num){
			case 1:
				li2.childNodes[1].style.display='none';
				li2.style.backgroundColor='rgb(10,129,211)';
				li3.childNodes[1].style.display='none';
				li3.style.backgroundColor='rgb(10,129,211)';
				if(li1.childNodes[1].style.display=='none'){
					li1.style.backgroundColor='#EEE';
					li1.childNodes[0].style.color='#555';
					li1.childNodes[1].style.display='block';
				}else{
					li1.style.backgroundColor='rgb(10,129,211)';
					li1.childNodes[0].style.color='#FFF';
					li1.childNodes[1].style.display='none';
				}
				break;
			case 2:
				li1.childNodes[1].style.display='none';
				li1.style.backgroundColor='rgb(10,129,211)';
				li3.childNodes[1].style.display='none';
				li3.style.backgroundColor='rgb(10,129,211)';
				if(li2.childNodes[1].style.display=='none'){
					li2.style.backgroundColor='#EEE';
					li2.childNodes[0].style.color='#555';
					li2.childNodes[1].style.display='block';
				}else{
					li2.style.backgroundColor='rgb(10,129,211)';
					li2.childNodes[0].style.color='#FFF';
					li2.childNodes[1].style.display='none';
				}
				break;
			case 3:
				li1.childNodes[1].style.display='none';
				li1.style.backgroundColor='rgb(10,129,211)';
				li2.childNodes[1].style.display='none';
				li2.style.backgroundColor='rgb(10,129,211)';
				if(li3.childNodes[1].style.display=='none'){
					li3.style.backgroundColor='#EEE';
					li3.childNodes[0].style.color='#555';
					li3.childNodes[1].style.display='block';
				}else{
					li3.style.backgroundColor='rgb(10,129,211)';
					li3.childNodes[0].style.color='#FFF';
					li3.childNodes[1].style.display='none';
				}
				break;
			
		}
	}