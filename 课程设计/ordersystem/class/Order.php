<?php
	require_once "AutoLoad.php";
	class Order{
		public $id;
		public $pid;
		public $cid;
		public $amount;
		public $order_time;
		public $delivery_time;

		public function addOrder(){
			$mysql = new MysqliUitl();
			$sql = "insert into t_order(pid, cid, amount, order_time, delivery_time) values (?,?,?,?,?)";
			$arr = array($this->pid, $this->cid, $this->amount, $this->order_time, $this->delivery_time);
			$result=$mysql->SQLInsert($sql,$arr);
			//var_dump($result);
			return $result;
		}

		public function deleteOrder($ids){
			$mysql = new MysqliUitl();
			$sql="update t_order set is_del = '1' where id in (".implode($ids, ",").")";
			$arr = array("");
			$result=$mysql->SQLDelete($sql,$arr);
			//var_dump($result);
			return $result;
		}

		public function updateOrder(){
			$mysql = new MysqliUitl();
			$sql="update t_order set cid=?, pid=?, amount=?, order_time=?, delivery_time=? where id=?";
			$arr = array($this->cid, $this->pid, $this->amount, $this->order_time, $this->delivery_time, $this->id);
			$result=$mysql->SQLUpdate($sql,$arr);
			//var_dump($result);
			return $result;
		}

		public function listOrder($_start,$_pagenum){
			$mysql = new MysqliUitl();
			$sql = "select t_order.id, t_customer.name, t_product.name, price, amount, price*amount, order_time, delivery_time from t_order, t_product, t_customer where t_order.is_del='0' and t_order.pid = t_product.id and t_order.cid = t_customer.id limit ".$_start.",".$_pagenum;
			$arr = array("");
			$result=$mysql->SQLSelect($sql,$arr);
			//var_dump($result);
			return $result;
		}

		public function listOrderByCid($_start,$_pagenum,$_cid){
			$mysql = new MysqliUitl();
			$sql = "select t_order.id, t_customer.name, t_product.name, price, amount, price*amount, order_time, delivery_time from t_order, t_product, t_customer where t_order.is_del='0' and t_order.pid = t_product.id and t_order.cid = t_customer.id and t_order.cid = {$_cid} limit ".$_start.",".$_pagenum;
			$arr = array("");
			$result=$mysql->SQLSelect($sql,$arr);
			//var_dump($result);
			return $result;
		}
		public function listOrderByPid($_start,$_pagenum,$_pid){
			$mysql = new MysqliUitl();
			$sql = "select t_order.id, t_customer.name, t_product.name, price, amount, price*amount, order_time, delivery_time from t_order, t_product, t_customer where t_order.is_del='0' and t_order.pid = t_product.id and t_order.cid = t_customer.id and t_order.pid = {$_pid} limit ".$_start.",".$_pagenum;
			$arr = array("");
			$result=$mysql->SQLSelect($sql,$arr);
			//var_dump($result);
			return $result;
		}

//      计数     
		public function countOrder(){
			$mysql = new MysqliUitl();
			$sql="select count(*) from t_order where is_del='0' ";
			$arr = array("");
			$result=$mysql->SQLSelect($sql,$arr);
			//var_dump($result);
			return $result;
		}
		public function countOrderByCid($_cid){
			$mysql = new MysqliUitl();
			$sql="select count(*) from t_order where is_del='0' and cid={$_cid}";
			$arr = array("");
			$result=$mysql->SQLSelect($sql,$arr);
			//var_dump($result);
			return $result;
		}
		public function countOrderByPid($_pid){
			$mysql = new MysqliUitl();
			$sql="select count(*) from t_order where is_del='0' and pid={$_pid}";
			$arr = array("");
			$result=$mysql->SQLSelect($sql,$arr);
			//var_dump($result);
			return $result;
		}

		public function getDetail(){
			$mysql = new MysqliUitl();
			$sql="select cid, pid, price, amount, price*amount as totalprice, order_time, delivery_time from t_order, t_product where t_order.id=? and pid=t_product.id ";
			$arr = array($this->id);
			$result=$mysql->SQLSelect($sql,$arr);
			//var_dump($result);
			return $result;
		}

		public function getTotalPriceByCid($_cid){
			$mysql = new MysqliUitl();
			$sql="select  sum(price*amount) from t_order, t_product, t_customer where t_order.is_del='0' and t_order.pid = t_product.id and t_order.cid = t_customer.id and t_order.cid = ?";
			$arr = array($_cid);
			$result=$mysql->SQLSelect($sql,$arr);
			//var_dump($result);
			return $result;
		}
	
	}
?>
