<?php

require "db.php";

$email = $_GET['email'];
$password = $_GET['password'];

if ($conn) {
	$sql = "INSERT INTO users (email, password) VALUES ('". $email . "','". $password ."')";
	$result = mysqli_query($conn, $sql);

	if ($result) {
		echo "Your account has been created. You can now login in the console application and close this tab!";
	}
}