<!DOCTYPE html>
<html>
<head>
	<meta http-equiv="Content-type" content="text/html;charset=utf-8;">
	<title>登录</title>
	<link rel="stylesheet" type="text/css" href="css/Style.css">
</head>
<body>
	<div class="login">
		<div class="login_center">
			<div class="login_center_left">
				<img src="imgs/zlogo1.png" class="zlog01">
				<p class="top_p">订单服务系统</p>
			</div>
		</div>
		<form id="loginform" action="manage/loginactive.php" method="post">
			<p>Login</p>
			<table>
				<tr><td>Username:</td></tr>
				<tr><td><input type="text" name="username" /></td></tr>
				<tr><td>Password:</td></tr>
				<tr><td><input type="password" name="password" /></td></tr>
				<?php
					if(@$_GET['err']){
						echo '<tr><td>'.$_GET['err'].'正确的用户名：admin 密码：admin</td></tr>';
					}
				?>
			</table>
			<button class="login_button"  id="submit" onclick="submit();">Login</button>
			<button class="login_button"><a href="manage.php">Close</a></button>
		</form>
	</div>
</body>
</html>
