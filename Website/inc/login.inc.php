<?php 

if (isset($_POST['submit'])) {

	include 'functions.php';

	$email = $_POST['email'];
	$password = $_POST['password'];
	$repassword = $_POST['repassword'];

	loginUser($conn, $email, $password);

} else {
	header("Location: ../signup.php");
	exit();
}