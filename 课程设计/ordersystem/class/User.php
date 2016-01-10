<?php
	require_once "AutoLoad.php";
	class User{
		public $name;
		public $password;
		public $power;

		public function Selectuser(){
			$mysql = new MysqliUitl();
			$sql="select * from usertable where name=?";
			$arr = array("$this->name");
			echo "$this->name";
			$result=$mysql->SQLSelect($sql,$arr);
			var_dump($result);
			return $result[0]['password'];
		}
	}
?>