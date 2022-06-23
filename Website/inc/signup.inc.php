<?php 

if (isset($_POST['submit'])) {

	include 'functions.php';

	$email = $_POST['email'];
	$password = $_POST['password'];
	$repassword = $_POST['repassword'];

	if (enoughtCharacter($password)) {
		header("Location: ../signup.php?error=lowcharacters");
		exit();
	}

	if (samePassword($password, $repassword)) {
		header("Location: ../signup.php?error=notsamepwd");
		exit();
	}

	if (createUser($conn, $email, $password)) {
		session_start();
		header("Location: ../settings.php?login=success");
		exit();
	}

} else {
	header("Location: ../signup.php");
	exit();
}