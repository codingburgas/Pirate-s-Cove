<?php

require "db.php";

$email = $_GET['email'];
$whichItem = $_GET['whichItem'];
$item = $_GET['item'];

if ($conn) {
	$sql = "UPDATE users SET ".$whichItem." = '".$item."' WHERE `email` = '".$email."'";
	$result = mysqli_query($conn, $sql);

	if ($result) {
		echo "Your item has been added to your inventory. You can close this tab now!";
	}
}