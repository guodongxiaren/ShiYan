<?php
	require_once "../class/AutoLoad.php";
	$op     = $_GET['op'];

	$product = new Product();

	switch ($op) {
		case 'add':
			$name   = $_POST['name'];
			$price  = $_POST['price'];
			$detail = $_POST['detail'];

			$product->name = $name;
			$product->price= $price;
			$product->detail=$detail;

			$bool = $product->addProduct();
			break;
		case 'delete':
			$id = $_POST['id'];
		    $bool = $product->deleteProduct($id);
		    break;
		case 'update':
			$id = $_GET['id'];
			$name   = $_POST['name'];
			$price  = $_POST['price'];
			$detail = $_POST['detail'];

			$product->id = $id;
			$product->name = $name;
			$product->price= $price;
			$product->detail=$detail;

			$bool = $product->updateProduct();
			break;
	}
	
?>