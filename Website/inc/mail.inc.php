<?php 

if (isset($_POST['submit'])) {

	$firstname = $_POST['firstname'];
	$lastname = $_POST['lastname'];
	$email = $_POST['email'];
	$subject = $_POST['subject'];

	mail("piratescove@piratescove.maxprogress.bg", "Email from ".$firstname." ". $lastname."", $subject, "From: ". $email ."");

	header("Location: ../index.php?mail=sended");
	exit();

} else {
	header("Location: ../index.php");
	exit();
}