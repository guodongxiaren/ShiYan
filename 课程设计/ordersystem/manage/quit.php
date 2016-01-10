<?php
	session_start();
	session_unset($_SESSION['name']);
	header('location:../login.php');
?>