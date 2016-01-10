<?php
	header('content-type:text/html;charset=utf-8');
	require_once "../class/AutoLoad.php";
	if(!empty($_POST['username']) && !empty($_POST['password'])){
		if(trim($_POST['username'])!=null && trim($_POST['password'])!=null){
			$username = $_POST['username'];
			$password = md5($_POST['password']);

			if(isLegal($username, $password)){
				echo "登录成功！";
				if(!$_SESSION['name']){
					session_start();
					$_SESSION['name']=$username;
					
					header('location:../manage.php');
				}
				
			}else{
				$err="用户名、密码不正确！";
				header('location:../index.php?err='.$err);
			}
		}else{
			$err="用户名、密码不能为空！";
			header('location:../index.php?err='.$err);
		}
	}else{
		$err="用户名、密码不能为空！";
		header('location:../index.php?err='.$err);
	}

	function isLegal($name, $password){
			$mysql = new MysqliUitl();
			$sql="select password from t_user where name=?";
			$arr = array($name);
			$result=$mysql->SQLSelect($sql,$arr);
			var_dump($result[0][0]);
			return $result[0][0] == $password;
	}
?>