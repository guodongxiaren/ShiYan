<?php
	require_once "AutoLoad.php";
	class Product{
		public $id;
		public $name;
		public $price;
		public $detail;


		public function addProduct(){
			$mysql = new MysqliUitl();
			$sql="insert into t_product(name, price, detail, is_del) values (?,?,?,?)";
			$arr = array($this->name, $this->price, $this->detail, '0');
			$result=$mysql->SQLInsert($sql,$arr);
			//var_dump($result);
			return $result;
		}

		public function deleteProduct($ids){
			$mysql = new MysqliUitl();
			$sql="update t_product set is_del = '1' where id in (".implode($ids, ",").")";
			$arr = array("");
			$result=$mysql->SQLDelete($sql,$arr);
			//var_dump($result);
			return $result;
		}

		public function updateProduct(){
			$mysql = new MysqliUitl();
			$sql = "update t_product set name=?, price=?, detail=? where id=?";
			$arr = array($this->name, $this->price, $this->detail, $this->id);
			$result=$mysql->SQLUpdate($sql,$arr);
			//var_dump($result);
			return $result;
		}

		public function updateProductDel($_id){
			$mysql = new MysqliUitl();
			$sql = "update t_product set is_del='1' where id={$_id}";
			$arr = array($this->name,$this->pay);
			$result=$mysql->SQLUpdate($sql,$arr);
			//var_dump($result);
			return $result;
		}
	
		public function listProduct($_start,$_pagenum){
			$mysql = new MysqliUitl();
			$sql="select id, name, price, detail from t_product where is_del='0' limit ".$_start.",".$_pagenum;
			$arr = array("");
			$result=$mysql->SQLSelect($sql,$arr);
			//var_dump($result);
			return $result;
		}

		public function countProduct(){
			$mysql = new MysqliUitl();
			$sql = "select count(*) from t_product where is_del='0' ";
			$arr = array("");
			$result=$mysql->SQLSelect($sql,$arr);
			//var_dump($result);
			return $result;
		}

		public function getProductNameID(){
			$mysql = new MysqliUitl();
			$sql = "select name, id from t_product where is_del='0' ";
			$arr = array("");
			$result = $mysql->SQLSelect($sql, $arr);
			return $result;
		}

		public function getProductPriceID(){
			$mysql = new MysqliUitl();
			$sql = "select price, id from t_product where is_del='0' ";
			$arr = array("");
			$result = $mysql->SQLSelect($sql, $arr);

			foreach ($result as $row){
				$arr1[$row[1]] = $row[0];
			}

			//var_dump(json_encode($arr1));
			return json_encode($arr1);
		}

		public function getDetail(){
			$mysql = new MysqliUitl();
			$sql = "select name, price, detail from t_product where id=? ";
			$arr = array($this->id);
			$result = $mysql->SQLSelect($sql, $arr);
			return $result;
		}

	}
?>
