<?php 

if (isset($_POST['submit'])) {

	$firstname = $_POST['firstname'];
	$lastname = $_POST['lastname'];
	$email = $_POST['email'];
	$subject = $_POST['subject'];

	mail($email, "Email from ".$firstname." ". $lastname."", $subject, 'From: piratescove@piratescove.maxprogress.bg');

	header("Location: ../index.php?mail=sended");
	exit();

} else {
	header("Location: ../index.php");
	exit();
}