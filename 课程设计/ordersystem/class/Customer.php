<?php
	require_once "../class/AutoLoad.php";
	class Customer{
		public $id;
		public $name;
		public $address;
		public $phone;

		public function addCustomer(){
			$mysql = new MysqliUitl();
			$sql="insert into t_customer(name, address, phone, is_del) values (?,?,?,?)";
			$arr = array($this->name, $this->address, $this->phone, '0');
			$result=$mysql->SQLInsert($sql,$arr);
			//var_dump($result);
			return $result;
		}

		public function deleteCustomer($ids){
			$mysql = new MysqliUitl();
			$sql="update t_customer set is_del = '1' where id in (".implode($ids, ",").")";
			$arr = array("");
			$result=$mysql->SQLDelete($sql,$arr);
			//var_dump($result);
			return $result;
		}

		public function updateCustomer(){
			$mysql = new MysqliUitl();
			$sql="update t_customer set name=?, address=?, phone=? where id=?";
			$arr = array($this->name, $this->address, $this->phone, $this->id);
			$result=$mysql->SQLUpdate($sql, $arr);
			//var_dump($result);
			return $result;
		}

		public function listCustomer($_start, $_pagenum){
			$mysql = new MysqliUitl();
			$sql="select * from t_customer where is_del='0' limit ".$_start.",".$_pagenum;
			$arr = array("");
			$result=$mysql->SQLSelect($sql,$arr);
			//var_dump($result);
			return $result;
		}

		public function  countCustomer(){
			$mysql = new MysqliUitl();
			$sql = "select count(*) from t_customer where is_del='0' ";
			$arr = array("");
			$result=$mysql->SQLSelect($sql, $arr);
			//var_dump($result);
			return $result;
		}

		public function getCustomerNameID(){
			$mysql = new MysqliUitl();
			$sql = "select name, id from t_customer where is_del='0' ";
			$arr = array("");
			$result = $mysql->SQLSelect($sql, $arr);
			return $result;
		}

		public function getDetail(){
			$mysql = new MysqliUitl();
			$sql = "select name, address, phone from t_customer where id=? ";
			$arr = array($this->id);
			$result = $mysql->SQLSelect($sql, $arr);
			return $result;
		}
	}
?>
