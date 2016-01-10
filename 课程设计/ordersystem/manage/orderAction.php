<?php
	require_once "../class/AutoLoad.php";
	$op     = $_GET['op'];

	$order = new Order();
	
	switch ($op) {
		case 'add':
			$order->cid  = $_POST['cid'];
			$order->pid  = $_POST['pid'];
			$order->amount = $_POST['amount'];
			$order->order_time = $_POST['order_time'];
			$order->delivery_time = $_POST['delivery_time'];

			$bool = $order->addOrder();
			break;
		case 'delete':
			$id = $_POST['id'];
		    $bool = $order->deleteOrder($id);
		    break;
		case 'update':
			$order->id   = $_GET['id']; 
			$order->cid  = $_POST['cid'];
			$order->pid  = $_POST['pid'];
			$order->amount = $_POST['amount'];
			$order->order_time = $_POST['order_time'];
			$order->delivery_time = $_POST['delivery_time'];

			$bool = $order->updateOrder();
			break;
	}
	
?>