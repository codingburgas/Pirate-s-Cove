<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

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