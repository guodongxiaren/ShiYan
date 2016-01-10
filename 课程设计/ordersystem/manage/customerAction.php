<?php
	require_once "../class/AutoLoad.php";
	$op = $_GET['op'];
	//var_dump($op);

	$customer = new Customer();


	switch ($op) {
		case 'add':
			$name    = $_POST['name'];
			$phone   = $_POST['phone'];
			$address = $_POST['address'];

			$customer->name = $name;
			$customer->phone= $phone;
			$customer->address=$address;

			$bool = $customer->addCustomer();
			break;
		case 'delete':
			$id = $_POST['id'];
		    $bool = $customer->deleteCustomer($id);
		    break;
		case 'update':
			$id = $_GET['id'];
			$name    = $_POST['name'];
			$phone   = $_POST['phone'];
			$address = $_POST['address'];

			$customer->id = $id;
			$customer->name = $name;
			$customer->phone= $phone;
			$customer->address=$address;
			$bool = $customer->updateCustomer();
			break;
	}
	
?>