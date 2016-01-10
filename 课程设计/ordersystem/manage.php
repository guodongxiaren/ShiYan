<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-type" content="text/html;charset=utf-8;">
	<title>后台管理</title>
	<link rel="stylesheet" type="text/css" href="css/Style.css">
	<script type="text/javascript" src="js/li.js"></script>
</head>
<body>

	<div class="top">
		<div class="top_left">
			<img src="imgs/zlogo1.png">
			<p>订单管理系统</p>	
		</div>
		<div class="top_right">
			<div class="usermessage">
				<img src="imgs/user1.png">
				<?php
					session_start();
					if(@$_SESSION['name']){
						$name=$_SESSION['name'];
					    echo "<p>Hi,  {$name}</p>";
					    echo '<hr></hr>';
						echo '<a href="manage/quit.php">退出</a>';
					}else{
						echo '<p>您好！请您先</p>';
						echo '<hr></hr>';
						echo '<a href="index.php">登录</a>';
						header('location:index.php');
					}
				?>
				
			</div>
			<div class="seach">
				<input name="seach" type="text">
				<img src="imgs/seach.png">
			</div>
		</div>
	</div>
	<div class="body">
		<div class="body_left">
			<ul id="manage_ul">
				<li class="body_left_li" id="li1" onclick="isclick(1);"><a href="manage/orderList.php?page=1"  target="iframe"><img src="imgs/manage1.png" ><span>订单管理</span></a><ul style="display:none;">
						<li class="listli"><a href="manage/orderList.php?page=1" target="iframe">订单列表</a></li>
						<li class="listli"><a href="manage/orderAdd.php" target="iframe">添加订单</a></li>
						<li class="listli"><a href="manage/orderUpt.php?page=1" target="iframe">修改订单</a></li>
						<li class="listli"><a href="manage/orderDel.php?page=1" target="iframe">删除订单</a></li>
					</ul>
				</li>
				
				<li class="body_left_li" id="li2" onclick="isclick(2);"><a href="manage/productList.php?page=1" target="iframe"><img src="imgs/manage2.png" ><span>产品管理</span></a><ul style="display:none;">
						<li class="listli"><a href="manage/productList.php?page=1" target="iframe">产品列表</a></li>
						<li class="listli"><a href="manage/productAdd.php" target="iframe">添加产品</a></li>
						<li class="listli"><a href="manage/productUpt.php?page=1" target="iframe">修改产品</a></li>
						<li class="listli"><a href="manage/productDel.php?page=1" target="iframe">删除产品</a></li>
					</ul>
				</li>
					
				<li class="body_left_li" id="li3" onclick="isclick(3);"><a href="manage/customerList.php?page=1" target="iframe"><img src="imgs/manage3.png" ><span>客户管理</span></a><ul style="display:none;">
						<li class="listli"><a href="manage/customerList.php?page=1" target="iframe">客户列表</a></li>
						<li class="listli"><a href="manage/customerAdd.php" target="iframe">添加客户</a></li>
						<li class="listli"><a href="manage/customerUpt.php?page=1" target="iframe">修改客户</a></li>
						<li class="listli"><a href="manage/customerDel.php?page=1" target="iframe">删除客户</a></li>
					</ul>
				</li>
			</ul>
		</div>

		<div class="body_right">
			<iframe name="iframe" src="manage/orderList.php?page=1"></iframe>
		</div>
	</div>
	<div class="bottom">
		<p>CopyRight© 王维
		</br>学号: 6100212202
		</br>电话：180-7040-6603</p>
	</div>
</body>
</html>
