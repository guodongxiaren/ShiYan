<?php
	header('content-type:text/html;charset=utf-8;');
	require_once "AutoLoad.php";
	class MysqliUitl{
		public $dbname;
		public $username='root';
		public $password='';
		public $mysqli=null;
		public $mysqliStart=null;
		public $dsn="mysql:dbname=ordersystem;host=localhost";
		function __construct(){
			$this->getConnect();
		}

	/**************数据库连接***************/

		public function getConnect(){
			$mysqli = new PDO("$this->dsn","$this->username","$this->password");
			if($mysqli==null){
				echo "数据库连接错误，错误信息：";
			}else{
				//echo "连接数据库成功！";
				return $this->mysqli=$mysqli;
			}
		}
	/***************数据预处理*******************/
		public function SQL($sql,$arr){
			$mysqliStart=$this->mysqli->prepare($sql);
			foreach ($arr as $key => $value) {

					$mysqliStart->bindValue($key+1,$value);
			}
			return $this->mysqliStart=$mysqliStart;
		}

	/**************数据库查询*******************/
		
		public function SQLSelect($sql,$arr){
			$this->SQL($sql,$arr);
			$this->mysqliStart->execute();
			$result=$this->mysqliStart->fetchAll();
			//var_dump($result);
			if ($result) {
				return $result;
			}else{
				echo "数据库查询结果为空！";
			}
		}

	/*****************数据插入******************/	
		public function SQLInsert($sql,$arr){
			$this->SQL($sql,$arr);
			$bool=$this->mysqliStart->execute();
			//var_dump($bool);
			if($bool){
				echo "数据插入成功！";
				return $bool;
			}else{
				echo "数据插入失败！";
			}
		}

	/*****************数据修改*******************/
		public function SQLUpdate($sql,$arr){
			$this->SQL($sql,$arr);
			$bool=$this->mysqliStart->execute();
			if($bool){
				echo "数据修改成功！";
				return $bool;
			}else{
				echo "数据修改失败！";
			}
		}	
	/*****************数据删除*******************/
		public function SQLDelete($sql,$arr){
			$this->SQL($sql,$arr);
			$bool=$this->mysqliStart->execute();
			if($bool){
				echo "数据删除成功！";
				return $bool;
			}else{
				echo "数据删除失败！";
			}

		}
	}
?>
